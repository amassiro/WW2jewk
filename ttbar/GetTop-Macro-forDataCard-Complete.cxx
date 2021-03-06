#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TLine.h"
#include "TROOT.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "THStack.h"
#include "TRandom3.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TPaveStats.h"
#include "TText.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "test/TDRStyle.cc"
#include "test/Read.cc"
// #include "test/WW2jewk/ttbar/plotUtils.C"

#include <iomanip>


///---- transform a std::vector of string into a string with proper (*) &&
std::string Compact(std::vector <std::string> vCut) {
 std::string totalString;
 for (int iCut=0; iCut<vCut.size(); iCut++) {
  totalString.append ( " ( " );
  totalString.append ( vCut.at(iCut) );
  totalString.append ( " ) " );
  if (iCut != (vCut.size()-1)) {
   totalString.append ( " && " );
  }
 }  
 return totalString;
}



///---- clear map -> set to 0
void Clear(std::vector <std::vector <double> > & vNumbers) {
 int nZone = vNumbers.size();
 for (int iZone=0; iZone<nZone; iZone++) {
  int nBin = (vNumbers.at(iZone)).size();
  for (int iBin=0; iBin<nBin; iBin++) {
   (vNumbers.at(iZone)).at(iBin) = 0;
  }
 }
}


///---- error on ratio
double ErrorRatio (double num, double errnum, double den, double errden) {
 double result = 0;
 if (den != 0) {
  double tempnum = errnum / den;
  double tempden = errden * num / den / den;
  result = sqrt ( (tempnum * tempnum) + (tempden * tempden) );
 }
 return result;
}


///---- less than "string" creator
std::string LessThan (std::string variable, double value) {
 std::string result;
 std::ostringstream cutDefinition;
 cutDefinition << variable;
 cutDefinition << "<";
 cutDefinition << value;
 result = cutDefinition.str();
 return result;
}

///---- more than "string" creator
std::string MoreThan (std::string variable, double value) {
 std::string result;
 std::ostringstream cutDefinition;
 cutDefinition << variable;
 cutDefinition << ">";
 cutDefinition << value;
 result = cutDefinition.str();
 return result;
}


//-------------------------------
//---- pt and eta dependence ----
//-------------------------------

//----------------------------------------
//---- allow tche threshod definition ----
//----------------------------------------

int GetTop_Macro_forDataCard_Complete(int iWP, std::string suffix = "of", std::string whatAnalysis = "cut", bool doEnrichToGetEvents = false, int binCutPt = 0, int binTCHE = 0) {
 
 std::cout << std::endl;
 std::cout << " ============== " << std::endl;
 std::cout << " Top datadriven " << std::endl;
 std::cout << " ============== " << std::endl;
 std::cout << std::endl;
 
 std::cout << " whatAnalysis = " << whatAnalysis << std::endl;
 
 int _debug = 0;
 //  int _debug = 1;
//  int _debug = 4;
 //---- 0 = no debug
 
 std::string inputDirectory = "output_Latinos_tree_2012_2orMoreJet2012_MVA_added"; // "output_Latinos_tree_2012_2orMoreJet2012_Top";
 std::string fileSamples = "test/WW2jewk/ttbar/datacard/SamplesH.txt";
 
 std::string treeName = "latino";
 std::string inputBeginningFile = "latino_";
 
 double LUMI = 19365.;
 
 
 std::vector <std::string> v_commonCut_WW; 
 
 v_commonCut_WW.push_back("pt1>20");
 v_commonCut_WW.push_back("pt2>20"); // >10
 v_commonCut_WW.push_back("(ch1*ch2)<0");
 
 v_commonCut_WW.push_back("trigger==1.");
 v_commonCut_WW.push_back("pfmet>20.");
 
 v_commonCut_WW.push_back("mll>50");
 
 v_commonCut_WW.push_back("(zveto==1||!sameflav)");
 v_commonCut_WW.push_back("mpmet>20.");
 v_commonCut_WW.push_back("bveto_mu==1");
 v_commonCut_WW.push_back("nextra==0");
//  v_commonCut_WW.push_back("(bveto_ip==1 && nbjettche==0)");
 v_commonCut_WW.push_back("bveto_ip==1");
 v_commonCut_WW.push_back("(!sameflav || pfmet > 45.0)");
 v_commonCut_WW.push_back("(dphilljetjet<pi/180.*165. || !sameflav )");
 
 
 //---- >=2 jets
 v_commonCut_WW.push_back("njet >= 2");
 
 
 //---- jet pt ranges (begin) ----
 double minpt = -1;
 double maxpt = -1;
 
 // ---- cut based
// //  if ( binCutPt == 0) {
// //   minpt = 30;
// //   maxpt = 70;
// //  }
// //  if ( binCutPt == 1) {
// //   minpt = 70;
// // //   maxpt = 100;
// //   maxpt = -1;
// //  }
// //  if ( binCutPt == 2) {
// //   minpt = 100;
// //   maxpt = -1;
// //  }
// 
// //  if ( binCutPt == 0) {
// //   minpt = 30;
// //   maxpt = 50;
// //  }
// //  if ( binCutPt == 1) {
// //   minpt = 50;
// //   maxpt = 70;
// //   //   maxpt = -1;
// //  }
// //  if ( binCutPt == 2) {
// //   minpt = 70;
// //   maxpt = 100;
// //  }
// //  if ( binCutPt == 3) {
// //   minpt = 100;
// //   maxpt = -1;
// //  }
// 
//  if ( binCutPt == 0) {
//   minpt = 30;
//   maxpt = 50;
//  }
//  if ( binCutPt == 1) {
//   minpt = 50;
//   maxpt = 70;
//  }
//  if ( binCutPt == 2) {
//   minpt = 70;
//   maxpt = -1;
// //   maxpt = 100;
//  }
// //  if ( binCutPt == 3) {
// //   minpt = 100;
// //   maxpt = -1;
// //  }
//  
//  
//  
//  if ( binCutPt == 4) {
//   minpt = 30;
//   maxpt = 70;
//  }
//  if ( binCutPt == 5) {
//   minpt = 70;
//   maxpt = -1;
//  }
 
 
 
 //---- shape analysis
 
 if ( binCutPt == 0) {
  minpt = 30;
  maxpt = 50;
 }
 if ( binCutPt == 1) {
  minpt = 50;
  maxpt = 70;
 }
 if ( binCutPt == 2) {
  minpt = 70;
  maxpt = 110;
 }
 if ( binCutPt == 3) {
  minpt = 110;
  maxpt = 150;
 }
 if ( binCutPt == 4) {
  minpt = 150;
  maxpt = 200;
 }
 if ( binCutPt == 5) {
  minpt = 200;
  maxpt = -1;
 }

 
 //---- cut based analysis
 
 if ( binCutPt == 10) {
  minpt =  30;
  maxpt = 100;
 }
 if ( binCutPt == 11) {
  minpt = 100;
  maxpt =  -1;
 }
 
 
 std::ostringstream binjetptDefinition;
 binjetptDefinition << " ( ";
 binjetptDefinition << "((abs(jeteta1)<abs(jeteta2))*(jetpt1)+((abs(jeteta1)>=abs(jeteta2))*(jetpt2))) >= " << minpt;
 binjetptDefinition << " && ";
 if (maxpt != -1) {
  binjetptDefinition << "((abs(jeteta1)<abs(jeteta2))*(jetpt1)+((abs(jeteta1)>=abs(jeteta2))*(jetpt2))) < " << maxpt;
 } 
 else {
  binjetptDefinition << " 1 " ;
 }
 binjetptDefinition << " ) ";
 v_commonCut_WW.push_back(binjetptDefinition.str());
 
 //---- jet pt ranges (end) ----
 
 
 std::string commonCut_WW = Compact(v_commonCut_WW);
 std::cout << " commonCut_WW = " << commonCut_WW << std::endl;
 
 std::string TopEnrichedCut_WW = "(!sameflav)";
 
 
 
 std::vector <std::string> v_commonCut_Higgs; 

 v_commonCut_Higgs.push_back(commonCut_WW); 
 
 
 
 //---- what kind of analysis ----
 if (whatAnalysis == "WW") {
  //---- WW level, no additional cuts w.r.t "commonCut_WW"
  v_commonCut_Higgs.push_back("1");
 }
 
 if (whatAnalysis == "cut") {
//   v_commonCut_Higgs.push_back("njetvbf==0");
//   v_commonCut_Higgs.push_back("mjj>200");
//   v_commonCut_Higgs.push_back("detajj>1.0");
  v_commonCut_Higgs.push_back("mjj>350");
  v_commonCut_Higgs.push_back("detajj>0.5");
  v_commonCut_Higgs.push_back("BDTG_weights_testVariables_MVAWW2jewk > 0.40");  //---- 0.55   0.30  0.40  -0.10 = crazy test!
 }
 
 if (whatAnalysis == "shape") {
//   v_commonCut_Higgs.push_back("njetvbf==0");
//   v_commonCut_Higgs.push_back("mjj>200");
//   v_commonCut_Higgs.push_back("detajj>1.0");
  v_commonCut_Higgs.push_back("mjj>350"); //---- 400
  v_commonCut_Higgs.push_back("detajj>0.5");
 }  

 //---- what kind of analysis (end) ----
 

 //---- select different flavour or same flavour
 if (suffix == "of") {
  v_commonCut_Higgs.push_back("!sameflav");
 }
 if (suffix == "sf") {
  v_commonCut_Higgs.push_back("sameflav");
 } 
 
 
 
 std::string commonCut_Higgs = Compact(v_commonCut_Higgs);
 std::cout << " commonCut_Higgs = " << commonCut_Higgs << std::endl;
 
 
 std::vector < std::string > vnameSample;
 char *nameSample[300];
 char *nameHumanReadable[300];
 char* xsectionName[300];
 
 int numberOfSamples = ReadFile(fileSamples.c_str(), nameSample, nameHumanReadable, xsectionName); 
 int nSample = numberOfSamples;
 
 char NameNormalization[300][300];
 for (int iSample=0; iSample<nSample; iSample++) {    
  vnameSample.push_back(nameHumanReadable[iSample]);
  
  if (vnameSample.at(vnameSample.size()-1) != "DATA") {
   sprintf (NameNormalization[iSample], "(%s) *  %f / 1000. ", xsectionName[iSample], LUMI);
  }
  else {
   sprintf (NameNormalization[iSample], "(run!=201191)");
  }
 }
 
 std::vector <double> etaBins;
 etaBins.push_back (0.0);
 etaBins.push_back (0.5);
 etaBins.push_back (1.0);
 etaBins.push_back (1.5);
 etaBins.push_back (2.0); //--> before disabled
 etaBins.push_back (2.5);
 etaBins.push_back (300.0);
 int nBin = etaBins.size() - 1 ;
 int nBin_MAX = nBin-1 ; //---- last bin has eta>2.5 --> always bvetoed? --> check!!
 std::vector <std::string> binCut; 
 
 for (int iBin=0; iBin<nBin; iBin++) {
  std::ostringstream binDefinition;
  binDefinition << " ( ";
  binDefinition << "((abs(jeteta1)<abs(jeteta2))*abs(jeteta1)+((abs(jeteta1)>=abs(jeteta2))*abs(jeteta2))) > " << etaBins.at(iBin);
  binDefinition << " && ";
  binDefinition << "((abs(jeteta1)<abs(jeteta2))*abs(jeteta1)+((abs(jeteta1)>=abs(jeteta2))*abs(jeteta2))) < " << etaBins.at(iBin+1);
  binDefinition << " ) ";
  binCut.push_back(binDefinition.str());
 }
 
 //----- zone        bin
 std::vector < std::vector <double> > DD_Top;
 std::vector < std::vector <double> > Top;
 std::vector < std::vector <double> > Other;
 std::vector < std::vector <double> > DATA; 
 std::vector < std::vector <double> > DATA_Sub; 
 
 std::vector < std::vector <double> > err_DD_Top;
 std::vector < std::vector <double> > err_Top;
 std::vector < std::vector <double> > err_Other;
 std::vector < std::vector <double> > err_DATA; 
 std::vector < std::vector <double> > err_DATA_Sub; 
 
 //-----  bin
 std::vector <double> eff_Top;
 std::vector <double> err_eff_Top;
 std::vector <double> eff_Top_Higgs;
 std::vector <double> err_eff_Top_Higgs;
 std::vector <double> eff_DATA;
 std::vector <double> err_eff_DATA;
 
 
 ///---- zones:
 ///---- AB    ---> 1! jet btagged and it is the most central or no jet btagged
 ///---- B     ---> 1! jet btagged and it is the most central
 ///---- A     ---> no jet btagged
 
 
 
 //---- definition TCHE threshold ----
 //  binTCHE == 0 --> thresholdTCHE = 1.00 - 2.10;
 //  binTCHE == 1 --> thresholdTCHE = 1.00; 

 //  binTCHE == 2 --> thresholdTCHE = 1.00 for CJ, 1.00-2.10 for FJ 
 //  binTCHE == 3 --> thresholdTCHE = 1.00 for FJ, 1.00-2.10 for CJ
 
 
 std::vector <std::string> zoneCut; 
 if (binTCHE == 0) {
//   ///--- AB
//   zoneCut.push_back("nbjettche==0 || (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10))) )");
//   ///--- B
//   zoneCut.push_back("                 nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10))) ");
//   ///--- A
//   zoneCut.push_back("nbjettche==0");
//   

//   ///--- AB
//   zoneCut.push_back("(nbjettche==0 && jettche1>=1.00 && jettche2>=1.00) || (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10))) )");
//   ///--- B
//   zoneCut.push_back("                                                      (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10))) )");
//   ///--- A
//   zoneCut.push_back("(nbjettche==0 && jettche1>=1.00 && jettche2>=1.00)");

  ///--- AB
  zoneCut.push_back("(nbjettche==0 && jettche1>=1.00 && jettche2>=1.00) || (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10)))  &&  (((abs(jeteta1)<abs(jeteta2))  && (jettche2>=1.00)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche1>=1.00))) )");
  ///--- B
  zoneCut.push_back("                                                      (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10)))  &&  (((abs(jeteta1)<abs(jeteta2))  && (jettche2>=1.00)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche1>=1.00))) )");
  ///--- A
  zoneCut.push_back("(nbjettche==0 && jettche1>=1.00 && jettche2>=1.00)");
  
 }
 
 if (binTCHE == 1) {
//   ///--- AB
//   zoneCut.push_back("(nbjettche==0 && jettche1<1.00 && jettche2<1.00) || (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10))) )");
//   ///--- B
//   zoneCut.push_back("                                                    (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10))) )");
//   ///--- A
//   zoneCut.push_back("(nbjettche==0 && jettche1<1.00 && jettche2<1.00)");

  ///--- AB
  zoneCut.push_back("(nbjettche==0 && jettche1<1.00 && jettche2<1.00) || (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10)))  &&  (((abs(jeteta1)<abs(jeteta2))  && (jettche2<1.00)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche1<1.00)))  )");
  ///--- B
  zoneCut.push_back("                                                    (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche2>2.10)))  &&  (((abs(jeteta1)<abs(jeteta2))  && (jettche2<1.00)) || ((abs(jeteta1)>=abs(jeteta2)) && (jettche1<1.00)))  )");
  ///--- A
  zoneCut.push_back("(nbjettche==0 && jettche1<1.00 && jettche2<1.00)");
  
 }

 if (binTCHE == 2) {
  ///--- AB
  zoneCut.push_back("((nbjettche==0 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1<1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche2<1.00)))       \
                                    && (((abs(jeteta1)<abs(jeteta2))  && (jettche2>1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche1>1.00))) \
                      ) || \
                     (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche2>2.10)))       \
                                   && (((abs(jeteta1)<abs(jeteta2))  && (jettche2>1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche1>1.00))) \
                     ))");  
  ///--- B
  zoneCut.push_back("(nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>2.10)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche2>2.10)))       \
                                   && (((abs(jeteta1)<abs(jeteta2))  && (jettche2>1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche1>1.00))) \
                     )");
  ///--- A
  zoneCut.push_back("(nbjettche==0 && (((abs(jeteta1)<abs(jeteta2))  && (jettche1<1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche2<1.00)))       \
                                   && (((abs(jeteta1)<abs(jeteta2))  && (jettche2>1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche1>1.00))) \
                     )");  
 }

  if (binTCHE == 3) {
  ///--- AB
  zoneCut.push_back("((nbjettche==0 && (((abs(jeteta1)<abs(jeteta2))  && (jettche2<1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche1<1.00)))       \
                                    && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche2>1.00))) \
                      ) || \
                     (nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche2>2.10)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche1>2.10)))       \
                                   && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche2>1.00))) \
                     ))");  
  ///--- B
  zoneCut.push_back("(nbjettche==1 && (((abs(jeteta1)<abs(jeteta2))  && (jettche2>2.10)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche1>2.10)))       \
                                   && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche2>1.00))) \
                     )");
  ///--- A
  zoneCut.push_back("(nbjettche==0 && (((abs(jeteta1)<abs(jeteta2))  && (jettche2<1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche1<1.00)))       \
                                   && (((abs(jeteta1)<abs(jeteta2))  && (jettche1>1.00)) || ((abs(jeteta1)>=abs(jeteta2))  && (jettche2>1.00))) \
                     )");  
 }
 int nZone = zoneCut.size();
 
 
 
 
 
 ///---- prepare map ----
 for (int iZone=0; iZone<nZone; iZone++) {
  std::vector <double> zone_temp;
  std::vector <double> err_zone_temp;
  for (int iBin=0; iBin<nBin; iBin++) {
   zone_temp.push_back(0);
   err_zone_temp.push_back(0);
  }
  DD_Top.push_back     (zone_temp);
  err_DD_Top.push_back (err_zone_temp);
  Top.push_back     (zone_temp);
  err_Top.push_back (err_zone_temp);
  Other.push_back     (zone_temp);
  err_Other.push_back (err_zone_temp);
  DATA.push_back     (zone_temp);
  err_DATA.push_back (err_zone_temp);  
  DATA_Sub.push_back     (zone_temp);
  err_DATA_Sub.push_back     (zone_temp);
 }
 for (int iBin=0; iBin<nBin; iBin++) {
  eff_Top_Higgs.push_back(0);
  err_eff_Top_Higgs.push_back(0);
  eff_Top.push_back(0);
  err_eff_Top.push_back(0);
  eff_DATA.push_back(0);
  err_eff_DATA.push_back(0);
 }
 
 
 //  TTree::SetDirectory(0);
 TH1F histo("histo","histo",1,0,2);
 histo.Sumw2();
 //  histo.SetDirectory(0);
 
 
 
 ///---- check if efficiencies have already been calculated ---> it saves time!!! x2 speed!!!
 
 TString nameFileInEff = Form ("test/WW2jewk/ttbar/result-eff-%s-%s-pt-%d-tche-%d.txt",whatAnalysis.c_str(),suffix.c_str(),binCutPt,binTCHE);
 std::cout << " cat " << nameFileInEff.Data() << std::endl;
 std::cout << std::endl;

 
 std::ifstream myfileEffIn (nameFileInEff.Data()); 
 
 if (myfileEffIn.is_open()) {
  std::string buffer;
  double value;  
  for (int iBin=0; iBin<nBin; iBin++) { 
   getline(myfileEffIn,buffer);
   std::cout << "buffer = " << buffer << std::endl;
   if (buffer != ""){ ///---> save from empty line at the end!
    std::stringstream line( buffer );      

    line >> value; 
    std::cout << value << " ";
    eff_Top.at(iBin) = value;

    line >> value; 
    std::cout << value << " ";
    err_eff_Top.at(iBin) = value;
    
    line >> value; 
    std::cout << value << " ";
    eff_DATA.at(iBin) = value;
    
    line >> value; 
    std::cout << value << " ";
    err_eff_DATA.at(iBin) = value;
    
    std::cout << std::endl;
   }  
  }
 }
 else
 {
  ///---- if efficiencies have not already been calculated, then, calculate them!
  
  
  ///---- fill maps ----
  for (int iSample=0; iSample<nSample; iSample++) {    
   char nameFile[20000];
   sprintf(nameFile,"%s/%s%s.root",inputDirectory.c_str(),inputBeginningFile.c_str(),nameSample[iSample]);  
   if (_debug >= 2)  std::cout << " nameFile[" << iSample << "] = " << nameFile << std::endl;
   TFile* f = new TFile(nameFile, "READ");
   TTree* treeJetLepVect = (TTree*)f->Get(treeName.c_str());   
   char nameTreeJetLep[41];
   sprintf(nameTreeJetLep,"treeJetLep_%d",iSample); 
   treeJetLepVect->SetName(nameTreeJetLep);
   
   for (int iZone=0; iZone<nZone; iZone++) {
    if (_debug >= 2) std:cout << ">>>> iZone = " << iZone << " :: " << nZone << std::endl;
    for (int iBin=0; iBin<nBin; iBin++) {
     std::string effective_cut;
     std::string normalization = NameNormalization[iSample];
     if (_debug >= 2) std::cout << " normalization = " << normalization << std::endl;
     effective_cut.append ( normalization );
     effective_cut.append ( " * ( " );
     
     effective_cut.append ( " ( " );
     effective_cut.append ( zoneCut.at(iZone) );  //---- which zone: AB, B, A
     effective_cut.append ( " ) " );
     effective_cut.append ( " && " );
     effective_cut.append ( " ( " );
     effective_cut.append ( binCut.at(iBin) );  //---- which eta bin
     effective_cut.append ( " ) " );
     effective_cut.append ( " && " );
     effective_cut.append ( " ( " );
     effective_cut.append ( commonCut_WW );  //---- WW level 
     effective_cut.append ( " ) " );  
     effective_cut.append ( " && " );
     effective_cut.append ( " ( " );
     effective_cut.append ( TopEnrichedCut_WW );  //---- Top enriched level 
     effective_cut.append ( " ) " );  
     
     
     
     
     effective_cut.append ( " ) " );
     
     if (_debug >= 2) std::cout << " effective_cut[" << iSample << "::" << nSample << "][" << iZone << "::" << nZone << "][" << iBin << "::" << nBin << "] = " << effective_cut << std::endl;
     
     histo.Reset();
     histo.SetDirectory(gDirectory);
     treeJetLepVect -> Draw ("1 >> histo",effective_cut.c_str(),"goff");
     
     double error_integral;
     double integral = histo.IntegralAndError(0, 2, error_integral);
     
     if (_debug >= 2) std::cout << " vnameSample.at(" << iSample << ") = " << vnameSample.at(iSample) << std::endl;
     
     if (vnameSample.at(iSample) == "top") {
      Top.at(iZone).at(iBin)     += integral;
      double temp_err = (err_Top.at(iZone)).at(iBin);
      (err_Top.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
     }
     
     if (vnameSample.at(iSample) == "VV-DY-Fake") {
      (Other.at(iZone)).at(iBin)     += integral;
      double temp_err = (err_Other.at(iZone)).at(iBin);
      (err_Other.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
     }
     
     if (vnameSample.at(iSample) == "DATA") {
      (DATA.at(iZone)).at(iBin)     += integral;     
      double temp_err = (err_DATA.at(iZone)).at(iBin);
      (err_DATA.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
     }
     
    }
   } 
  }
  
  ///---- data with MC subtracted ----
  for (int iZone=0; iZone<nZone; iZone++) {
   for (int iBin=0; iBin<nBin; iBin++) {
    (DATA_Sub.at(iZone)).at(iBin)     = ( (DATA.at(iZone)).at(iBin) - (Other.at(iZone)).at(iBin) );
    (err_DATA_Sub.at(iZone)).at(iBin) = sqrt( (err_DATA.at(iZone)).at(iBin)*(err_DATA.at(iZone)).at(iBin) + (err_Other.at(iZone)).at(iBin)*(err_Other.at(iZone)).at(iBin) );
    
    //---- no negative events!!!
    if ((DATA_Sub.at(iZone)).at(iBin) < 0  ||  (DATA.at(iZone)).at(iBin) == 0) {
     (DATA_Sub.at(iZone)).at(iBin) = 0;
     (err_DATA_Sub.at(iZone)).at(iBin) = 0;
    }
   }
  }
  
  
  std::cout << std::endl;
  std::cout << " calculate efficiency " << std::endl;
  
  ///---- calculate efficiency ----
  
  ///---- zones:
  ///---- AB    ---> 1! jet btagged and it is the most central or no jet btagged
  ///---- B     ---> 1! jet btagged and it is the most central
  ///---- A     ---> no jet btagged
  
  for (int iBin=0; iBin<nBin; iBin++) {
   
   ///----    eff =       B               /           AB       
   
   if (Top.at(0).at(iBin)) {
    eff_Top.at(iBin) = Top.at(1).at(iBin) / Top.at(0).at(iBin);
    double errNum = err_Top.at(1).at(iBin) / Top.at(0).at(iBin);
    double errDen = err_Top.at(0).at(iBin) * Top.at(1).at(iBin) / Top.at(0).at(iBin) / Top.at(0).at(iBin);
    err_eff_Top.at(iBin) =  sqrt(errNum*errNum + errDen*errDen);
   }
   else {
    eff_Top.at(iBin) = 0;
    err_eff_Top.at(iBin) = 0;
   }
   
   if ( (DATA_Sub.at(0)).at(iBin) != 0) {
    eff_DATA.at(iBin) = (DATA_Sub.at(1)).at(iBin) / (DATA_Sub.at(0)).at(iBin);
    double errNum = (err_DATA_Sub.at(1)).at(iBin) / (DATA_Sub.at(0)).at(iBin);
    double errDen = (err_DATA_Sub.at(0)).at(iBin) * (DATA_Sub.at(1)).at(iBin) / (DATA_Sub.at(0)).at(iBin) / (DATA_Sub.at(0)).at(iBin);
    err_eff_DATA.at(iBin) =  sqrt(errNum*errNum + errDen*errDen);
    
    std::cout << " (DATA_Sub.at(0)).at(" << iBin <<") = " << (DATA_Sub.at(0)).at(iBin) ;
    std::cout << " (DATA_Sub.at(1)).at(" << iBin <<") = " << (DATA_Sub.at(1)).at(iBin) ;
    std::cout << "         eff_DATA.at(" << iBin <<") = " << eff_DATA.at(iBin) ;
    std::cout << std::endl;
    
   }
   else 
   {
    eff_DATA.at(iBin) = 0;
    err_eff_DATA.at(iBin) = 0;
   }
   
   if (_debug >= 1) std::cout << " eff_Top [" << iBin << "] = " << eff_Top.at(iBin)  << " +/- " << err_eff_Top.at(iBin)  << std::endl;
   if (_debug >= 1) std::cout << " eff_DATA[" << iBin << "] = " << eff_DATA.at(iBin) << " +/- " << err_eff_DATA.at(iBin) << std::endl;
   
  }
  
  
  
  
  ///---- save efficiency in a file: data and MC ----
  
  std::cout << std::endl;
  std::cout << " save efficiency " << std::endl;
  
  
  TString nameFileOutEff = Form ("test/WW2jewk/ttbar/result-eff-%s-%s-pt-%d-tche-%d.txt",whatAnalysis.c_str(),suffix.c_str(),binCutPt,binTCHE);
  std::cout << " cat " << nameFileOutEff.Data() << std::endl;
  std::cout << std::endl;
  
  std::ofstream myfileEff; 
  //  myfileAll.open (nameFileOut.Data(),std::fstream::app);
  myfileEff.open (nameFileOutEff.Data());
  for (int iBin=0; iBin<nBin; iBin++) { 
   myfileEff << std::setw (11) << eff_Top.at(iBin)       << "   " ;
   myfileEff << std::setw (11) << err_eff_Top.at(iBin)                  << "   " ;  
   myfileEff << std::setw (11) << eff_DATA.at(iBin)                  << "   " ;  
   myfileEff << std::setw (11) << err_eff_DATA.at(iBin)              << "   " ;  
   myfileEff << std::endl;
  }
  myfileEff.close();
  
 }
 
 
 
 ///---- apply efficiency ----
 
 std::cout << std::endl;
 std::cout << " apply efficiency " << std::endl;
 
 ///---- zones:
 ///---- AB    ---> 1! jet btagged and it is the most central or no jet btagged
 ///---- B     ---> 1! jet btagged and it is the most central
 ///---- A     ---> no jet btagged
 
 Clear(Top);
 Clear(Other);
 Clear(DATA);
 Clear(DATA_Sub);
 
 Clear(err_Top);
 Clear(err_Other);
 Clear(err_DATA);
 Clear(err_DATA_Sub);
 
 
 ///---- fill maps ----
 for (int iSample=0; iSample<nSample; iSample++) {    
  char nameFile[20000];
  sprintf(nameFile,"%s/%s%s.root",inputDirectory.c_str(),inputBeginningFile.c_str(),nameSample[iSample]);  
  if (_debug >= 2)  std::cout << " nameFile[" << iSample << "] = " << nameFile << std::endl;
  TFile* f = new TFile(nameFile, "READ");
  TTree* treeJetLepVect = (TTree*)f->Get(treeName.c_str());   
  char nameTreeJetLep[41];
  sprintf(nameTreeJetLep,"treeJetLep_%d",iSample); 
  treeJetLepVect->SetName(nameTreeJetLep);
  
  for (int iZone=0; iZone<nZone; iZone++) {
   if (_debug >= 2) std:cout << ">>>> iZone = " << iZone << " :: " << nZone << std::endl;
   for (int iBin=0; iBin<nBin; iBin++) {
    std::string effective_cut;
    std::string normalization = NameNormalization[iSample];
    if (_debug >= 2) std::cout << " normalization = " << normalization << std::endl;
    effective_cut.append ( normalization );
    effective_cut.append ( " * ( " );
    
    effective_cut.append ( " ( " );
    effective_cut.append ( zoneCut.at(iZone) );  //---- which zone: AB, B, A
    effective_cut.append ( " ) " );
    effective_cut.append ( " && " );
    effective_cut.append ( " ( " );
    effective_cut.append ( binCut.at(iBin) );  //---- which eta bin
    effective_cut.append ( " ) " );
    effective_cut.append ( " && " );
    effective_cut.append ( " ( " );
    effective_cut.append ( commonCut_Higgs );  //---- Higgs level 
    effective_cut.append ( " ) " );    
    
    effective_cut.append ( " ) " );
    
    if (_debug >= 2) std::cout << " effective_cut[" << iSample << "::" << nSample << "][" << iZone << "::" << nZone << "][" << iBin << "::" << nBin << "] = " << effective_cut << std::endl;
    
    histo.Reset();
    histo.SetDirectory(gDirectory);
    treeJetLepVect -> Draw ("1 >> histo",effective_cut.c_str(),"goff");
    
    double error_integral;
    double integral = histo.IntegralAndError(0, 2, error_integral);
    
    if (_debug >= 2) std::cout << " vnameSample.at(" << iSample << ") = " << vnameSample.at(iSample) << std::endl;
    
    if (vnameSample.at(iSample) == "top") {
     Top.at(iZone).at(iBin)     += integral;
     double temp_err = (err_Top.at(iZone)).at(iBin);
     (err_Top.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
    }
    
    if (vnameSample.at(iSample) == "VV-DY-Fake") {
     (Other.at(iZone)).at(iBin)     += integral;
     double temp_err = (err_Other.at(iZone)).at(iBin);
     (err_Other.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
    }
    
    if (vnameSample.at(iSample) == "DATA") {
     (DATA.at(iZone)).at(iBin)     += integral;     
     double temp_err = (err_DATA.at(iZone)).at(iBin);
     (err_DATA.at(iZone)).at(iBin) = sqrt(temp_err*temp_err + error_integral*error_integral);
    }
    
   }
  } 
 }
 
 ///---- data with MC subtracted ----
 for (int iZone=0; iZone<nZone; iZone++) {
  for (int iBin=0; iBin<nBin; iBin++) {
   float temp_data = (DATA.at(iZone)).at(iBin);
   (DATA_Sub.at(iZone)).at(iBin)     = ( (DATA.at(iZone)).at(iBin) - (Other.at(iZone)).at(iBin) );
   (err_DATA_Sub.at(iZone)).at(iBin) = sqrt( (err_DATA.at(iZone)).at(iBin)*(err_DATA.at(iZone)).at(iBin) + (err_Other.at(iZone)).at(iBin)*(err_Other.at(iZone)).at(iBin) );
  
   //---- no negative events!!!
   if ((DATA_Sub.at(iZone)).at(iBin) < 0  ||  (DATA.at(iZone)).at(iBin) == 0) {
    if (temp_data == 0) { //---- if there were at least 1 event in b-tagged region, use it!
     (DATA_Sub.at(iZone)).at(iBin) = 0;
     (err_DATA_Sub.at(iZone)).at(iBin) = 0;
    }
    else {
     (DATA_Sub.at(iZone)).at(iBin) = 1; //---- not temp_data because I still need to subtract other backgrounds!
//      (err_DATA_Sub.at(iZone)).at(iBin) = (err_DATA.at(iZone)).at(iBin);
     }
   }
  }
 }
 
 
 std::cout << std::endl;
 
 
 ///---- calculate efficiency: for MC only !!! ----
 
 for (int iBin=0; iBin<nBin; iBin++) {
  ///----       B               /           AB         
  if (Top.at(0).at(iBin)) {
   eff_Top_Higgs.at(iBin) = Top.at(1).at(iBin) / Top.at(0).at(iBin);
   double errNum = err_Top.at(1).at(iBin) / Top.at(0).at(iBin);
   double errDen = err_Top.at(0).at(iBin) * Top.at(1).at(iBin) / Top.at(0).at(iBin) / Top.at(0).at(iBin);
   err_eff_Top_Higgs.at(iBin) =  sqrt(errNum*errNum + errDen*errDen);
  }
  else {
   eff_Top_Higgs.at(iBin) = 0;
   err_eff_Top_Higgs.at(iBin) = 0;
  }
 }
  
  ///---- save efficiency in a file: data and MC ----
  
  std::cout << std::endl;
  std::cout << " save efficiency " << std::endl;
  
  TString nameFileOutEffHiggs = Form ("test/WW2jewk/ttbar/result-eff-%s-%s-pt-%d-tche-%d-%d.txt",whatAnalysis.c_str(),suffix.c_str(),binCutPt,binTCHE,iWP);
  std::cout << " cat " << nameFileOutEffHiggs.Data() << std::endl;
  std::cout << std::endl;
  
  std::ofstream myfileEffHiggs; 
  myfileEffHiggs.open (nameFileOutEffHiggs.Data());
  for (int iBin=0; iBin<nBin; iBin++) { 
   myfileEffHiggs << std::setw (11) << eff_DATA.at(iBin)                  << "   " ;  
   myfileEffHiggs << std::setw (11) << err_eff_DATA.at(iBin)              << "   " ;  
   myfileEffHiggs << std::setw (11) << eff_Top.at(iBin)       << "   " ;
   myfileEffHiggs << std::setw (11) << err_eff_Top.at(iBin)                  << "   " ;  
   myfileEffHiggs << std::setw (11) << eff_Top_Higgs.at(iBin)       << "   " ;
   myfileEffHiggs << std::setw (11) << err_eff_Top_Higgs.at(iBin)                  << "   " ;  
   myfileEffHiggs << std::endl;
  }
  myfileEffHiggs.close();
  
  
 ///---- plot to screen information ----
 
 for (int iBin=0; iBin<nBin; iBin++) {
  std::cout << " eff_DATA.at(" << iBin << ")= " <<  eff_DATA.at(iBin) ;
  std::cout << " ; eff_Top.at(" << iBin << ")= " <<  eff_Top.at(iBin) ;
  std::cout << " ; eff_Top_Higgs.at(" << iBin << ")= " <<  eff_Top_Higgs.at(iBin) ;
  std::cout << " +/- " <<  err_eff_Top_Higgs.at(iBin) ;
  std::cout << std::endl;
 }

 ///---- correct eff_DATA using variation in MC ----
 ///---- and add error on it! ----
 
 for (int iBin=0; iBin<nBin_MAX; iBin++) {
  if (eff_DATA.at(iBin) != 0) {
   if ( (eff_Top.at(iBin) != 0) && (eff_Top_Higgs.at(iBin != 0)) ) {
    //---- done pt dependent
    
    double additional_error = eff_DATA.at(iBin) * (eff_Top_Higgs.at(iBin) - eff_Top.at(iBin)) / (eff_Top_Higgs.at(iBin) + eff_Top.at(iBin)) * 2.;
    eff_DATA.at(iBin)     = eff_DATA.at(iBin) * eff_Top_Higgs.at(iBin) / eff_Top.at(iBin);
    err_eff_DATA.at(iBin) = err_eff_DATA.at(iBin) * eff_Top_Higgs.at(iBin) / eff_Top.at(iBin); //---- scale the error according to new efficiency
    err_eff_DATA.at(iBin) = sqrt( err_eff_DATA.at(iBin)*err_eff_DATA.at(iBin) + additional_error/2.*additional_error/2. ); //---- add the "efficiency variation" as a systematic error on eff_DATA (thus an error on alpha!)
   }
  }
 }
 ///---- use efficiency to measure data driven Top ----
 
 for (int iBin=0; iBin<nBin_MAX; iBin++) {
  ///----    efficiency =       B               /           AB       
  ///----            AB =     B (data subtracted)   /   efficiency
  if (eff_DATA.at(iBin)) {
   (DD_Top.at(0)).at(iBin) = (DATA_Sub.at(1)).at(iBin) / eff_DATA.at(iBin);
   //---- remove DATA statistics error ----
   //   if (Alpha != 0) {
    //    err_Alpha = Alpha * sqrt ( err_Alpha/Alpha*err_Alpha/Alpha - 1./Ncontrol ) ;
   //   }
//    (err_DD_Top.at(0)).at(iBin) = ErrorRatio ((DATA_Sub.at(1)).at(iBin), (err_DATA_Sub.at(1)).at(iBin), eff_DATA.at(iBin), err_eff_DATA.at(iBin));
   (err_DD_Top.at(0)).at(iBin) = ErrorRatio ((DATA_Sub.at(1)).at(iBin),                             0, eff_DATA.at(iBin), err_eff_DATA.at(iBin));
   std::cout << "  eff_DATA.at(" << iBin << ") = " <<  eff_DATA.at(iBin);
   std::cout << " +/- " <<  err_eff_DATA.at(iBin);
   std::cout << "  DATA.at(Zone = 1) = " <<  (DATA.at(1)).at(iBin);
   std::cout << "  DATA_Sub = " <<  (DATA_Sub.at(1)).at(iBin);
   std::cout << "  +/- " <<  (err_DATA_Sub.at(1)).at(iBin);
   std::cout << "  (Other.at(1)).at(" << iBin << ") = " << (Other.at(1)).at(iBin);
   std::cout << "; DD_Top.at(0).at(" << iBin << ") = " << (DD_Top.at(0)).at(iBin);
   std::cout << "; err_DD_Top = " << (err_DD_Top.at(0)).at(iBin) << std::endl;
  }
  else {
   std::cout << " ### efficiency = 0 for " << iBin << std::endl;
  } 
 }

 //---- calculate global scale factor ----
 double totalTop_Central_DD = 0;
 double err_totalTop_Central_DD = 0;
 double totalTop_Central    = 0;
 for (int iBin=0; iBin<nBin_MAX; iBin++) {
  totalTop_Central        += (       Top.at(0)).at(iBin);
  totalTop_Central_DD     += (    DD_Top.at(0)).at(iBin);
  err_totalTop_Central_DD += ((err_DD_Top.at(0)).at(iBin)*(err_DD_Top.at(0)).at(iBin));
 }
 err_totalTop_Central_DD = sqrt(err_totalTop_Central_DD);
 
 double GlobalSF = 1.;
 double err_GlobalSF = 1.;
 if (totalTop_Central != 0) {
  GlobalSF     =     totalTop_Central_DD / totalTop_Central ;
  err_GlobalSF = err_totalTop_Central_DD / totalTop_Central ;
 }
 std::cout << std::endl;
 std::cout << " GlobalSF = " << GlobalSF << " +/- " << err_GlobalSF << std::endl;
 std::cout << " totalTop_Central    = " << totalTop_Central    << std::endl;
 std::cout << " totalTop_Central_DD = " << totalTop_Central_DD << " +/- " << err_totalTop_Central_DD << std::endl;
 
 double totalTop_Forward = 0;
 for (int iBin=nBin_MAX; iBin<nBin; iBin++) {
  totalTop_Forward += (Top.at(0)).at(iBin);
  
  std::cout << "  eff_DATA.at(" << iBin << ") = " <<  eff_DATA.at(iBin);
  std::cout << "  DATA.at(1) = " <<  (DATA.at(1)).at(iBin);
  std::cout << "  DATA_Sub = " <<  (DATA_Sub.at(1)).at(iBin);
//   std::cout << "; DD_Top.at(0).at(" << iBin << ") = " << (DD_Top.at(0)).at(iBin);
//   std::cout << "; err_DD_Top = " << (err_DD_Top.at(0)).at(iBin) << std::endl;
  
 }
 
 double totalTop_Central_Forward;
 totalTop_Central_Forward = totalTop_Central + totalTop_Forward;
 
 double DD_totalTop_Central_Forward;
 DD_totalTop_Central_Forward = totalTop_Central_Forward * GlobalSF;
 double err_DD_totalTop_Central_Forward;
 err_DD_totalTop_Central_Forward = totalTop_Central_Forward * err_GlobalSF;
 
 ///---- for datacard ----
 double Ncontrol = 0;
 for (int iBin=0; iBin<nBin_MAX; iBin++) {
  Ncontrol += (DATA.at(1)).at(iBin);
 }
 double Ncontrol_Sub = 0;
 for (int iBin=0; iBin<nBin_MAX; iBin++) {
  Ncontrol_Sub += (DATA_Sub.at(1)).at(iBin);
 } 

 //---- only the bvetoed region is "btag+bvetoed" - "btagged"
 double DD_totalTop;
 DD_totalTop = DD_totalTop_Central_Forward - Ncontrol_Sub;
 double err_DD_totalTop;
 err_DD_totalTop = err_DD_totalTop_Central_Forward;
 

 std::cout << std::endl;
 std::cout << std::endl;
 
 double Alpha = 0;
 double err_Alpha = 0;
 if (Ncontrol != 0) {
  Alpha     =     DD_totalTop / Ncontrol;
  err_Alpha = err_DD_totalTop / Ncontrol;
  std::cout << " Alpha      = " << Alpha        << std::endl;
  std::cout << " err_Alpha  = " << err_Alpha    << std::endl;
   
  //---- add MC subtraction as an error --> 100% error on MC subtraction!!! ----
  //---- ---> NB: scaled by alpha -> already in "err_Alpha" calculation
  double additional_error_MC_sub = (Ncontrol_Sub - Ncontrol) / (Ncontrol);
  err_Alpha = Alpha * sqrt ( err_Alpha/Alpha*err_Alpha/Alpha + additional_error_MC_sub*additional_error_MC_sub ) ;
 }
 else {
  std::cout << " ### ERROR: Scale Factor = 0 " << std::endl;
  gApplication->Terminate(0);
 }
 
 
 std::cout << std::endl;
 std::cout << " ###################### " << std::endl;
 std::cout << " GlobalSF   = " << GlobalSF     << std::endl;
 std::cout << " Alpha      = " << Alpha        << std::endl;
 std::cout << " err_Alpha  = " << err_Alpha    << std::endl;
 std::cout << " Ncontrol   = " << Ncontrol     << std::endl; 
 std::cout << " ###################### " << std::endl;
 std::cout << std::endl;

 
  
 TString nameFileOut = Form ("test/WW2jewk/ttbar/result-%s-%s-pt-%d-tche-%d-%d.txt",whatAnalysis.c_str(),suffix.c_str(),binCutPt,binTCHE,iWP);
 std::cout << " cat " << nameFileOut.Data() << std::endl;
 std::cout << std::endl;
 
 std::ofstream myfileAll; 
//  myfileAll.open (nameFileOut.Data(),std::fstream::app);
 myfileAll.open (nameFileOut.Data());
//  myfileAll                   << mH[iWP]                << "   " ;
 myfileAll                   << iWP                    << "   " ;
 myfileAll << std::setw (11) << Ncontrol               << "   " ;  
 myfileAll << std::setw (11) << Alpha                  << "   " ;  
 myfileAll << std::setw (11) << err_Alpha              << "   " ;  
 myfileAll << std::endl;
 myfileAll.close();
 
 
 
 nameFileOut = Form ("test/WW2jewk/ttbar/result-SF-%s-%s-pt-%d-tche-%d-%d.txt",whatAnalysis.c_str(),suffix.c_str(),binCutPt,binTCHE,iWP);
 std::cout << " cat " << nameFileOut.Data() << std::endl;
 std::cout << std::endl;
 
 std::ofstream myfileAllSF; 
 myfileAllSF.open (nameFileOut.Data());
//  myfileAllSF << std::setw (11) << mH[iWP]                << "   " ;
 myfileAllSF << std::setw (11) << iWP                    << "   " ;
 myfileAllSF << std::setw (11) << GlobalSF               << "   " ;  
 myfileAllSF << std::setw (11) << err_GlobalSF           << "   " ;  
 myfileAllSF << std::endl;
 myfileAllSF.close();
 
 gApplication->Terminate(0);
 
}


