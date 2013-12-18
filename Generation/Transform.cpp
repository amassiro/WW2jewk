// c++ -o Transform.exe `root-config --glibs --cflags` -lm Transform.cpp
#include "LHEF.h"
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "TLorentzVector.h"


int main (int argc, char ** argv) {
 if(argc < 3) {
  std::cout << "Usage: " << argv[0] << " input.lhe output.lhe" << std::endl ;
  return -1;
 }

 std::ifstream ifs (argv[1]) ;
 LHEF::Reader reader (ifs) ;

 std::ofstream outputStream (argv[2]) ;
 LHEF::Writer writer (outputStream) ;

 writer.headerBlock () << reader.headerBlock ;
 writer.initComments () << reader.initComments ;
 writer.heprup = reader.heprup ;
 writer.init () ;

// mu massless?
// float k2 = 0.1056583715 * 0.1056583715 - 1.77682 * 1.77682 ; // GeV -3.14592562093

 //---- k_AB : transform A into B
 float k_mt = 0. - 1.77682 * 1.77682 ; // GeV -3.14592562093
 float k_me = 0.;
 float k_mm = 0.;

 float k_et = 0. - 1.77682 * 1.77682 ; // GeV -3.14592562093
 float k_ee = 0.;
 float k_em = 0.;

 float k1[9];
 float k2[9];
 int pdgid1[9];
 int pdgid2[9];

 // e = 11
 // m = 13
 // t = 15

 //---- starting =  e+    m-
 //                -11    13

 //                         +                             -
 k1[0] = k_ee; pdgid1[0] = -11; k2[0] = k_me; pdgid2[0] = 11;
 k1[1] = k_ee; pdgid1[1] = -11; k2[1] = k_mt; pdgid2[1] = 15;
 k1[2] = k_em; pdgid1[2] = -13; k2[2] = k_me; pdgid2[2] = 11;
 k1[3] = k_em; pdgid1[3] = -13; k2[3] = k_mm; pdgid2[3] = 13;
 k1[4] = k_em; pdgid1[4] = -13; k2[4] = k_mt; pdgid2[4] = 15;
 k1[5] = k_et; pdgid1[5] = -15; k2[5] = k_me; pdgid2[5] = 11;
 k1[6] = k_et; pdgid1[6] = -15; k2[6] = k_mm; pdgid2[6] = 13;
 k1[7] = k_et; pdgid1[7] = -15; k2[7] = k_mt; pdgid2[7] = 15;
 k1[8] = k_ee; pdgid1[8] = -11; k2[8] = k_mm; pdgid2[8] = 13;


 int count = 0 ;
  // loop over input events (begin)
 while (reader.readEvent ()) {
  count++ ;
  if ( reader.outsideBlock.length ()) std::cout << reader.outsideBlock;

  int iWhat = count%9;
  
  // loop over particles in the event
  for (int iPart = 0 ; iPart < reader.hepeup.IDUP.size (); ++iPart) {
           // outgoing particles
   if (reader.hepeup.ISTUP.at (iPart) == 1) {
    //---- e+     -11      ve = 12
    if ( reader.hepeup.IDUP.at (iPart) == -11) {
     TLorentzVector dummy
       (
       reader.hepeup.PUP.at (iPart).at (0), // px
       reader.hepeup.PUP.at (iPart).at (1), // py
       reader.hepeup.PUP.at (iPart).at (2), // pz
       reader.hepeup.PUP.at (iPart).at (3) // E
       ) ;
     float p2 = dummy.Vect ().Mag2 () ;

     float scale = sqrt (1 + k1[iWhat] / p2) ;
     if (p2 < (-1 * k1[iWhat])) {
      std::cout << "warning: p2 is smaller than the mass difference " << p2 << std::endl ;
      scale = 1 ;
     }
     reader.hepeup.PUP.at (iPart).at (0) *= scale ; // px
     reader.hepeup.PUP.at (iPart).at (1) *= scale ; // py
     reader.hepeup.PUP.at (iPart).at (2) *= scale ; // pz

     reader.hepeup.IDUP.at (iPart) = pdgid1[iWhat] ;
    }
    if (reader.hepeup.IDUP.at (iPart) == 12) {
     reader.hepeup.IDUP.at (iPart) = -pdgid1[iWhat]+1 ; // neutrinos!   +12 -> +12, +14, +16
    }

    //---- m-     +13       ~vm = -14
    if ( reader.hepeup.IDUP.at (iPart) == 13) {
     TLorentzVector dummy
       (
       reader.hepeup.PUP.at (iPart).at (0), // px
     reader.hepeup.PUP.at (iPart).at (1), // py
     reader.hepeup.PUP.at (iPart).at (2), // pz
     reader.hepeup.PUP.at (iPart).at (3) // E
       ) ;
     float p2 = dummy.Vect ().Mag2 () ;

     float scale = sqrt (1 + k2[iWhat] / p2) ;
     if (p2 < (-1 * k2[iWhat])) {
      std::cout << "warning: p2 is smaller than the mass difference " << p2 << std::endl ;
      scale = 1 ;
     }
     reader.hepeup.PUP.at (iPart).at (0) *= scale ; // px
     reader.hepeup.PUP.at (iPart).at (1) *= scale ; // py
     reader.hepeup.PUP.at (iPart).at (2) *= scale ; // pz

     reader.hepeup.IDUP.at (iPart) = pdgid2[iWhat] ;
    }
    if (reader.hepeup.IDUP.at (iPart) == -14) {
     reader.hepeup.IDUP.at (iPart) = -pdgid2[iWhat]-1 ; // anti-neutrinos!   -14 -> -12, -14, -16
    }

   } // outgoing particles
  } // loop over particles in the event
  writer.eventComments () << reader.eventComments ;
  writer.hepeup = reader.hepeup ;
  bool written = writer.writeEvent () ;
  if (!written) {
   std::cout << "warning: event " << count << " not written" << std::endl ;
  }

 } // loop over input events (end)

 std::cout << "end loop over " << count << " events" << std::endl ;
 return 0 ;
}

