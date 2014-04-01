// to compile:
//   c++ -o ntupleMaker.exe `root-config --glibs --cflags` `lhapdf-config --cppflags  --ldflags` -lm ntupleMaker.cpp
//
// to use:
//   ./ntupleMaker.exe fileLHE    outputFileRoot
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <assert.h>


#include "LHEF.h"


#include "LHAPDF/LHAPDF.h"



#include "TNtuple.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include "Math/Vector3D.h"
#include "Math/Vector4D.h"


struct ptsort: public std::binary_function<TLorentzVector, TLorentzVector, bool> {
 bool operator () (const TLorentzVector & x, const TLorentzVector & y) {
  return  (x.Perp () < y.Perp () ) ;
 }
} ;

TLorentzVector buildP (const LHEF::HEPEUP & event, int iPart) {
 TLorentzVector dummy ;
 dummy.SetPxPyPzE (
   event.PUP.at (iPart).at (0), // px
   event.PUP.at (iPart).at (1), // py
   event.PUP.at (iPart).at (2), // pz
   event.PUP.at (iPart).at (3) // E
   ) ;
 return dummy ;
}




void fillNtuple (std::string fileNameLHE,  TNtuple & ntuple) {
 std::ifstream ifs (fileNameLHE.c_str ()) ;
 LHEF::Reader reader (ifs) ;

 long ieve = 0 ;
 long selected = 0 ;
 double jetsNum = 0. ;

 std::cout << " reading " << fileNameLHE << std::endl;

 int numb;
 int numbInput;
 
 // loop over events
 while ( reader.readEvent () ) {
  ieve++;
  if (ieve % 10000 == 0) std::cout << "event " << ieve << "\n" ;

  TLorentzVector Higgs;
  int iPartHiggs = -1;
  float mH = 0;

  std::vector<int> finalJets ;
  std::vector<TLorentzVector> v_f_quarks_gluons ;
  std::vector<TLorentzVector> v_f_quarks ;
  std::vector<TLorentzVector> v_f_leptons ;
  std::vector<TLorentzVector> v_f_neutrinos ;

  // loop over particles in the event
  // and fill the variables of leptons and quarks
  for (int iPart = 0 ; iPart < reader.hepeup.IDUP.size (); ++iPart) {

   // look for the Higgs
   if (abs (reader.hepeup.IDUP.at (iPart)) == 25) {
    iPartHiggs = iPart;
    Higgs.SetPxPyPzE  (
      reader.hepeup.PUP.at (iPart).at (0), // px
      reader.hepeup.PUP.at (iPart).at (1), // py
      reader.hepeup.PUP.at (iPart).at (2), // pz
      reader.hepeup.PUP.at (iPart).at (3) // E
      );
    mH = Higgs.M();
   }

   // outgoing particles
   if (reader.hepeup.ISTUP.at (iPart) == 1) {
    // quarks or gluons
    if (abs (reader.hepeup.IDUP.at (iPart)) < 7 || abs (reader.hepeup.IDUP.at (iPart)) == 21) {
     finalJets.push_back (iPart) ;
     TLorentzVector dummy (
       reader.hepeup.PUP.at (iPart).at (0), // px
       reader.hepeup.PUP.at (iPart).at (1), // py
       reader.hepeup.PUP.at (iPart).at (2), // pz
       reader.hepeup.PUP.at (iPart).at (3) // E
       ) ;
     if ( abs (reader.hepeup.IDUP.at (iPart)) != 21 ) {
       v_f_quarks.push_back (dummy) ;
     }
     v_f_quarks_gluons.push_back (dummy) ;
    } // quarks or gluons
    else if (abs (reader.hepeup.IDUP.at (iPart)) == 11 || abs (reader.hepeup.IDUP.at (iPart)) == 13 || abs (reader.hepeup.IDUP.at (iPart)) == 15) {  // e = 11,   mu = 13,   tau = 15
     TLorentzVector dummy (
       reader.hepeup.PUP.at (iPart).at (0), // px
       reader.hepeup.PUP.at (iPart).at (1), // py
       reader.hepeup.PUP.at (iPart).at (2), // pz
       reader.hepeup.PUP.at (iPart).at (3) // E
       ) ;
     v_f_leptons.push_back (dummy) ;
    }
    else if (abs (reader.hepeup.IDUP.at (iPart)) == 12 || abs (reader.hepeup.IDUP.at (iPart)) == 14 || abs (reader.hepeup.IDUP.at (iPart)) == 16) { // ve = 12,   vmu = 14,   vtau = 16
     TLorentzVector dummy
       (
       reader.hepeup.PUP.at (iPart).at (0), // px
       reader.hepeup.PUP.at (iPart).at (1), // py
       reader.hepeup.PUP.at (iPart).at (2), // pz
       reader.hepeup.PUP.at (iPart).at (3) // E
       ) ;
     v_f_neutrinos.push_back (dummy) ;
    }
   } // outgoing particles
  } // loop over particles in the event


  //---- b quarks
  numb = 0;
  // loop over particles in the event
  for (unsigned int  iPart = 0 ; iPart < reader.hepeup.IDUP.size (); iPart++) {
   // outgoing particles
   if (reader.hepeup.ISTUP.at (iPart) == 1) {
    // b quarks
    if (abs (reader.hepeup.IDUP.at (iPart)) == 5) {
     numb++;
    }
   }
  }

  numbInput = 0;
  // loop over particles in the event
  for (unsigned int  iPart = 0 ; iPart < reader.hepeup.IDUP.size (); iPart++) {
   // ingoing particles
   if (reader.hepeup.ISTUP.at (iPart) == -1) {
    // b quarks
    if (abs (reader.hepeup.IDUP.at (iPart)) == 5) {
     numbInput++;
    }
   }
  }
  
  
  
  if (v_f_leptons.size () != 2) {
   std::cout << " what !?!?!?! Not 2 leptons? Are you kidding?" << std::endl;
   continue;
  }


  // sorting in pt
  sort (v_f_quarks_gluons.rbegin (), v_f_quarks_gluons.rend (), ptsort ()) ;
  sort (v_f_quarks.rbegin (), v_f_quarks.rend (), ptsort ()) ;
  sort (v_f_leptons.rbegin (), v_f_leptons.rend (), ptsort ()) ;

  TLorentzVector diLepton = v_f_leptons.at (0) + v_f_leptons.at (1) ;
  TLorentzVector missingEnergy = v_f_neutrinos.at (0) + v_f_neutrinos.at (1) ;

  TLorentzVector dilepton_plus_dineutrinos = v_f_leptons.at (0) + v_f_leptons.at (1) + v_f_neutrinos.at (0) + v_f_neutrinos.at (1) ;

  // the sum pf the two quarks

//   float jetpt1 = -99;
//   if (v_f_quarks.size()>0) jetpt1 = v_f_quarks.at (0).Pt ();
//   float jetpt2 = -99;
//   if (v_f_quarks.size()>1) jetpt2 = v_f_quarks.at (1).Pt ();
// 
//   float mjj = -999;
//   if (v_f_quarks.size()>1) {
//    TLorentzVector diJet = v_f_quarks.at (0) + v_f_quarks.at (1) ;
//    mjj = diJet.M();
//   }

  float jetpt1 = -99;
  if (v_f_quarks_gluons.size()>0) jetpt1 = v_f_quarks_gluons.at (0).Pt ();
  float jetpt2 = -99;
  if (v_f_quarks_gluons.size()>1) jetpt2 = v_f_quarks_gluons.at (1).Pt ();
  
  float mjj = -999;
  if (v_f_quarks_gluons.size()>1) {
   TLorentzVector diJet = v_f_quarks_gluons.at (0) + v_f_quarks_gluons.at (1) ;
   mjj = diJet.M();
  }
  
  float mqq = -999;
  if (v_f_quarks.size()>1) {
   TLorentzVector diJet_quarks = v_f_quarks.at (0) + v_f_quarks.at (1) ;
   mqq = diJet_quarks.M();
  }
  
  
  ntuple.Fill (
    jetpt1,
    jetpt2,
    v_f_leptons.at (0).Pt (),
    v_f_leptons.at (1).Pt (),
    dilepton_plus_dineutrinos.M(),
    diLepton.M(),
    mjj,
    numb,
    numbInput,
    mqq
  ) ;

 } // loop over events

}



int main (int argc, char **argv) { 
 // Open a stream connected to an event file:
 if (argc < 3) exit (1) ;

 std::cout << " Input  LHE  =" << argv[1] << std::endl;
 std::cout << " Output ROOT =" << argv[2] << std::endl;

 
 const int SUBSET = 0 ;
 const std::string NAME = "cteq6ll" ; //"cteq6l1"

 LHAPDF::initPDFSet (NAME, LHAPDF::LHPDF, SUBSET) ;
 const int NUMBER = LHAPDF::numberPDF () ;

 LHAPDF::initPDF (0) ;


 TNtuple ntu ("ntu", "ntu", "jetpt1:jetpt2:pt1:pt2:mWW:mll:mjj:numb:numbInput:mqq");
 fillNtuple (argv[1], ntu) ;

 TFile output (argv[2], "recreate") ;
 output.cd() ;
 ntu.Write();
 output.Close();

}



