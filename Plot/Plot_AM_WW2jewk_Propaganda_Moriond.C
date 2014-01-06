#include "TString.h"
#include "TH1F.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TFile.h"

#include "PlotVHqqHggH.C"


//---- Filter bins ----
TH1F* FilterBins(std::vector<int> binsToSelect, TH1F* inputTH) {
 int numbin = binsToSelect.size();
 
 TString name = Form ("%s_new",inputTH->GetName());
 TString title = Form ("%s",inputTH->GetTitle());
 
 TH1F* newTH = new TH1F (name,title,numbin,0,numbin);
 for (int i=0; i< binsToSelect.size(); i++) {
  newTH->SetBinContent (i+1, inputTH->GetBinContent(binsToSelect.at(i)));
  newTH->SetBinError   (i+1, inputTH->GetBinError(binsToSelect.at(i)));
 }
 
 return newTH;
}

TGraphAsymmErrors* FilterBins(std::vector<int> binsToSelect, TGraphAsymmErrors* inputGR) {
 int numbin = binsToSelect.size();
 
 TString name = Form ("%s_new",inputGR->GetName());
 TString title = Form ("%s",inputGR->GetTitle());
 
 TGraphAsymmErrors* newGR = new TGraphAsymmErrors();
 newGR -> SetName (name);
 
 for (int i=0; i< binsToSelect.size(); i++) {
  
  double X = i+0.5;
  double Y = (inputGR->GetY()) [binsToSelect.at(i)-1];
  
  double errXUp      = inputGR->GetErrorXhigh(binsToSelect.at(i)-1);
  double errXDown    = inputGR->GetErrorXlow(binsToSelect.at(i)-1);
  double errYUp      = inputGR->GetErrorYhigh(binsToSelect.at(i)-1);
  double errYDown    = inputGR->GetErrorYlow(binsToSelect.at(i)-1);
  
  newGR->SetPoint(i, X, Y);
  newGR->SetPointError(i, errXDown, errXUp, errYDown, errYUp);
  
  //     std::cout << " i = " << i << " X = " << X << " Y = " << Y << std::endl;
 }
 
 return newGR;
}



void Plot_AM_WW2jewk_Propaganda_Moriond() {
 
//   TString folder = Form("sig/");
//   TString nameChannel = Form ("of_2j/");
//   TString cutNameBefore = Form("sig/%shisto_",nameChannel.Data());
 
 TString folder = Form("init/");
 TString nameChannel = Form ("of_2j/");
 TString cutNameBefore = Form("init/%shisto_",nameChannel.Data());
 
 //  TString folder = Form("bkg/");
 //  TString nameChannel = Form ("of_vh2j/");
 //  TString cutNameBefore = Form("bkg/%shisto_",nameChannel.Data());
 
 
 //                            cut_variable 
 TString cutNameAfter  = Form("");
 
 gROOT->LoadMacro("PlotVHqqHggH.C+");
 gInterpreter->ExecuteMacro("LatinoStyle2.C");
 
 //  TCanvas* c1 = new TCanvas("mll","mll",500,600);
 TCanvas* c1 = new TCanvas("mll","mll",550,660);

 TFile* f[10];
 
 f[0] = new TFile("postFit-WW2jewk/WWewk-error.root");
//  f[0] = new TFile("postFit-WW2jewk/WWewk-error-signal-injection.root"); --> not working in mkAutopsy.py
 
 
 PlotVHqqHggH* hs = new PlotVHqqHggH();
 
 hs->setLabel("mva");
 
 //  hs->setLumi(20);
 //  hs->setLumi(200);
 //  hs->addLabel("#splitline{      WHSC}{     #sqrt{s} = 13 TeV}");
  
 hs->setLumi(19.4);
 hs->addLabel("#splitline{     WWewk}{     #sqrt{s} = 8 TeV}");
//  
 TString name;
 
 std::vector<int> vectColourBkg;        
 std::vector<double> vectSystBkg;       
 std::vector<double> vectScaleBkg;      
 std::vector<std::string> vectNameBkg;  
 std::vector<double> vectNormalizationBkg; 
 std::vector<TH1F*> vectTHBkg;          
 
 std::vector<int> vectColourSig;      
 std::vector<double> vectSystSig;       
 std::vector<double> vectScaleSig;      
 std::vector<std::string> vectNameSig;  
 std::vector<double> vectNormalizationSig; 
 std::vector<TH1F*> vectTHSig;          
 
 
 std::vector<int> binsToSelect; 
 
 int NMAXX = 20;  
//  int NMAXX = 9;  
 int NMAXY = 1;  
 
 int minNY = 0;
 int minNX = 0;
 
 //---- all ----
 int NX = NMAXX;
 int NY = NMAXY;
 
 
 
 for (int iFile = 0; iFile<1; iFile++) {
  
  std::cout << "iFile = " << iFile << std::endl;
  
  ///---- project along X : sum over Y
  for (int iY=minNY; iY<NY; iY++){
   binsToSelect.clear();
   for (int iX=minNX; iX<NX; iX++){
    binsToSelect.push_back (iX*NMAXY+iY+1);
    std::cout << " iX*NY+iY+1 = " << iX*NY+iY+1 << std::endl;
   }
   
   ///==== signal (begin) ====
   
   //---- second file :: 0 jet bin
   
   name = Form("%sWWewk%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameSig.push_back ("WWewk");
   vectColourSig.push_back(633);
   vectScaleSig.push_back(1.0000);
   vectNormalizationSig.push_back(0.018);
     
   
   ///==== signal (end)  ====
   
   name = Form("%sData%s",cutNameBefore.Data(),cutNameAfter.Data());
   hs->setDataHist (FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)));
   
   ///==== background (begin)  ====
   
   //---- second file :: 0 jet bin
   
      
   name = Form("%sggH%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("H m_{H}=125");
   vectColourBkg.push_back(6);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.719);  
   
   name = Form("%sqqH%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("H m_{H}=125");
   vectColourBkg.push_back(6);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(2.565);
   
   
   name = Form("%sVV%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("WZ/ZZ");
   vectColourBkg.push_back(858);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.281);
   
   name = Form("%sWJet%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("W+jets");
   vectColourBkg.push_back(921);
   vectSystBkg.push_back(0.36);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.667);
   
   name = Form("%sVg%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("V+#gamma/V+#gamma*");
   vectColourBkg.push_back(616+1);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   name = Form("%sVgS%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("V+#gamma/V+#gamma*");
   vectColourBkg.push_back(616+2);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   
   name = Form("%sTop%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("Top");
   vectColourBkg.push_back(400);
   vectSystBkg.push_back(0.07);
   vectScaleBkg.push_back(0.85);
   vectNormalizationBkg.push_back(5.654);
   
   name = Form("%sDYTT%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("DYTT");
   vectColourBkg.push_back(418);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.377);
   
   name = Form("%sWW%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("WW");
   vectColourBkg.push_back(851);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(2.256);
   
   name = Form("%sggWW%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("WW");
   vectColourBkg.push_back(853);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(2.256);
   
//    name = Form("%sVVV%s",cutNameBefore.Data(),cutNameAfter.Data());
//    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//    vectNameBkg.push_back ("VVV");
//    vectColourBkg.push_back(854);
//    vectSystBkg.push_back(0.00);
//    vectScaleBkg.push_back(1.0000);
//    vectNormalizationBkg.push_back(2.256);
   
   ///==== background (end)  ====
   
//    hs->setBlindBinSx(10);
   hs->setBlindBinSx(0);
//    hs->setBlindBinDx(10);
   hs->setBlindBinDx(0);
   
   hs->setCutSx(-999,">");
   hs->setCutDx(-999,"<");
   
   name = Form("%s%smodel_errs",folder.Data(),nameChannel.Data()); 
   std::cout << " name = " << name.Data() << std::endl;  
   
   hs->set_ErrorBand( *(FilterBins(binsToSelect, (TGraphAsymmErrors*) f[iFile]->Get(name))) );  
   
  }
 }
 
 std::cout << " * end iFile * " << std::endl;
 
 hs->set_vectTHBkg     (vectTHBkg);      
 hs->set_vectNameBkg   (vectNameBkg);    
 hs->set_vectColourBkg (vectColourBkg);  
 hs->set_vectSystBkg   (vectSystBkg);    
 hs->set_vectScaleBkg  (vectScaleBkg);   
 
 hs->set_vectTHSig     (vectTHSig);      
 hs->set_vectNameSig   (vectNameSig);    
 hs->set_vectColourSig (vectColourSig);  
//  hs->set_vectScaleSig  (vectScaleSig);   
 
 

//  hs->addWeight(NY-minNY); //---- add S/(S+B) weight ---> used only for propaganda plot and data-background
//  hs->addWeight1D(NY-minNY); //---- add S/(S+B) weight ---> used only for propaganda plot and data-background
 
 hs->prepare();
 
 hs->mergeSamples(); //---- merge trees with the same name! ---- to be called after "prepare" !
 
 hs->set_addSignalOnBackground(1); // 1 = signal over background , 0 = signal on its own
 
 hs->set_mergeSignal(0);    // 1 = merge signal in 1 bin, 0 = let different signals as it is
 
 hs->setMass(125); 
 
// hs->set_plotSigAlone(true); //---- false = "do not plot signal not-stacked to the background
 
 
 hs->set_doLabelNumber ( false ) ;
 
 ///==== draw ====
  
 TCanvas* c1bis = new TCanvas("bkgSub","bkgSub",500,500);
 
//  hs->setUnits ("GeV");
 double vedges[] = {-1.0,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0};
//  double vedges[] = {-1.0, -0.5, 0.0, 0.2, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
 std::vector<double> vEdges (vedges, vedges + sizeof(vedges) / sizeof(double) );
 hs->set_vectEdges(vEdges);
 hs->set_divide(0); //---- if 1 then divide by bin width
 //   hs->set_divide(1); //---- if 1 then divide by bin width
  
 //----  canvas, rebin, div, shadow, background subtracted canvas ----
 hs->Draw(c1,1,true,true,c1bis);
 
 c1->Print("mll.pdf");
 c1->Print("mll.png");
 c1->Print("mll.eps");
 
 c1bis->Print("bkgSub_mll.pdf");
 c1bis->Print("bkgSub_mll.png");
 c1bis->Print("bkgSub_mll.eps");
 
}




