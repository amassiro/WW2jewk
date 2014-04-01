//----------------------------
//---- draw distributions ----
//----------------------------

void DrawMGtestB(std::string var = "mWW", int NBIN = 1000, int MIN = 0, int MAX = 1000, std::string varHR = "mWW") {
  
 gStyle->SetOptStat(0);
 
 TString name1;
 name1 = Form ("QCD_MG_bquarks_kincuts_1M.root");
 
 TString name2;
 name2 = Form ("QCD_MG.root");
 
 
 
 TFile* f1 = new TFile (name1.Data(),"READ"); // ---- QCD w/  b
 TFile* f2 = new TFile (name2.Data(),"READ"); // ---- QCD w/o b
 
 std::cout << " name QCD w/  b   = " << name1.Data() << std::endl;
 std::cout << " name QCD w/o b   = " << name2.Data() << std::endl;
 
 TNtuple* t1 = (TNtuple*) f1->Get ("ntu");
 TNtuple* t2 = (TNtuple*) f2->Get ("ntu");
 
 TH1F* h_mWW_1 = new TH1F("h_mWW_1","EW MG",NBIN,MIN,MAX);
 TH1F* h_mWW_2 = new TH1F("h_mWW_2","QCD MG",NBIN,MIN,MAX);
 TH1F* h_Ratio = new TH1F("h_mWW_ratio","h_mWW_ratio MG",NBIN,MIN,MAX);
 TH1F* h_Subtraction = new TH1F("h_Subtraction","h_Subtraction MG",NBIN,MIN,MAX);
 
 h_mWW_1->GetXaxis()->SetTitle(varHR.c_str());
 h_mWW_2->GetXaxis()->SetTitle(varHR.c_str());
 h_Ratio->GetXaxis()->SetTitle(varHR.c_str());
 h_Subtraction->GetXaxis()->SetTitle(varHR.c_str());
 
 h_mWW_1->GetYaxis()->SetTitle("fb");
 h_mWW_2->GetYaxis()->SetTitle("fb");
 h_Subtraction->GetYaxis()->SetTitle("fb");
 
//  0.008021 +- 2.212e-05 pb  EWK
//  0.1663 +- 0.0003664 pb    QCD
//  0.1743 +- 0.0003675 pb    EWKQCD
 
//  with 10k events                    with 1M events
//  0.008021 +- 2.212e-05 pb  EWK        0.008115 +- 2.12e-06 pb
//  0.1663 +- 0.0003664 pb    QCD        0.1668 +- 5.003e-05 pb
//  0.1743 +- 0.0003675 pb    EWKQCD     0.1754 +- 5.231e-05 pb
 
  gROOT->ProcessLine ("float xsecQCD[100] = {0.1668};");
 
 
//  with b-quarks
//  0.1102 +- 7.409e-05 pb    EWK     
//  14.62 +- 0.007497 pb      QCD     
//  14.69 +- 0.007549 pb      EWKQCD  

 //  gROOT->ProcessLine ("float xsecEW[100] = {0.1102};");
 //  gROOT->ProcessLine ("float xsecQCD[100] = {14.62};");
 //  gROOT->ProcessLine ("float xsecEWQCD[100] = {14.69};");
 
//  with b-quarks and
//  ptb > 20
//  mjj > 200
//  mbb > 200
//  
//  3.993 +- 0.002638 pb    QCD     
//  4.05 +- 0.002666 pb     EWKQCD  

 //  gROOT->ProcessLine ("float xsecEW[100] = {0.1102};"); 
 //  gROOT->ProcessLine ("float xsecQCD[100] = {3.993};");
 //  gROOT->ProcessLine ("float xsecEWQCD[100] = {4.05};");
  
//  with b-quarks and
//  ptj > 30
//  ptb > 30
//  mjj > 300
//  mbb > 300
//  
//  1.5 +- 0.0009995 pb    QCD     
//  1.544 +- 0.001016 pb     EWKQCD  

 //  gROOT->ProcessLine ("float xsecEW[100] = {0.1102};");
 //  gROOT->ProcessLine ("float xsecQCD[100] = {1.5};");
//   gROOT->ProcessLine ("float xsecEWQCD[100] = {1.544};");
 
 
 //---- 1M events
 //  1.50144           pb    QCD     
 //   ### pb     EWKQCD  
  
//  gROOT->ProcessLine ("float xsecEW[100] = {0.1102};");
 gROOT->ProcessLine ("float xsecQCDwithoutB[100] = {1.50144};");
//  gROOT->ProcessLine ("float xsecEWQCD[100] = {1.###};");
  


 
//  gROOT->ProcessLine ("float xsecEW[100] = {0.0080983};");
// //  gROOT->ProcessLine ("float xsecEW[100] = {0.008115};");
 
 
//  TString cut = Form ("jetpt1>30 && jetpt2>30 && mjj>300 && pt1>20 && pt2>20 && mll>8");
 TString cut = Form ("jetpt1>30 && jetpt2>30 && mjj>300 && pt1>20 && pt2>20 && mll>8 && numb==0");
 
 
 int tot_1 = t1 -> GetEntries();
 int tot_2 = t2 -> GetEntries();
 
 std::cout << std::endl;
 std::cout << " tot_1 = " << tot_1 << std::endl;
 std::cout << " tot_2 = " << tot_2 << std::endl;
 
//  TString weightWithXsecEW    = Form ("(%s) * (%f) * (%f) * (numb==0)",cut.Data(),xsecQCD[0],1000./tot_1);
 TString weightWithXsecEW    = Form ("(%s) * (%f) * (%f)            ",cut.Data(),xsecQCD[0],1000./tot_1);
 TString weightWithXsecQCD   = Form ("(%s) * (%f) * (%f)            ",cut.Data(),xsecQCDwithoutB[0],1000./tot_2);
 
 h_mWW_1->Sumw2();
 h_mWW_2->Sumw2();
 
 TString toDraw;
 toDraw = Form ("%s >> h_mWW_1",var.c_str());
 std::cout << " weight = " << weightWithXsecEW.Data() << std::endl;
 t1->Draw(toDraw.Data(),weightWithXsecEW.Data(),"goff");
 
 toDraw = Form ("%s >> h_mWW_2",var.c_str());
 std::cout << " weight = " << weightWithXsecQCD.Data() << std::endl;
 t2->Draw(toDraw.Data(),weightWithXsecQCD.Data(), "goff");
 
 
 h_mWW_1->SetLineColor(kBlue);  //---- with b
 h_mWW_2->SetLineColor(kRed);   //---- without b

 h_mWW_1->SetFillColor(kBlue);
 h_mWW_2->SetFillColor(kRed); 
 
 h_mWW_1->SetFillStyle(3001);
 h_mWW_2->SetFillStyle(3003); 
 
 h_mWW_1->SetLineStyle(1);
 h_mWW_2->SetLineStyle(2);
 
 h_mWW_1->SetLineWidth(2);
 h_mWW_2->SetLineWidth(2);
 
 TLegend* leg = new TLegend(0.5,0.7,0.9,0.9);
 leg->AddEntry(h_mWW_1,"qcd w/  b","l");
 leg->AddEntry(h_mWW_2,"qcd w/o b","l");
 leg->SetFillStyle(0);


 for (int iBin = 0; iBin < h_mWW_1->GetNbinsX(); iBin++) {
  float ewk = h_mWW_1->GetBinContent(iBin+1);
  float qcd = h_mWW_2->GetBinContent(iBin+1);  
  float error_ewk = h_mWW_1->GetBinError(iBin+1);  
  float error_qcd = h_mWW_2->GetBinError(iBin+1);  
  if (ewk != 0) {
//    h_Ratio -> SetBinContent (iBin+1, (ewk - qcd) / ewk);
   h_Ratio -> SetBinContent (iBin+1, qcd / ewk);
  }
  else {
   h_Ratio -> SetBinContent (iBin+1, 0);
  }
  
  h_Subtraction -> SetBinContent (iBin+1, ewk - qcd);
  h_Subtraction -> SetBinError   (iBin+1, sqrt(error_ewk*error_ewk - error_qcd*error_qcd));
 }
 
 
 
 TCanvas* cc_All = new TCanvas("cc_All","cc_All",800,600);
 h_mWW_1->GetYaxis()->SetRangeUser(0.01,h_mWW_1->GetMaximum()*1.5);
 h_mWW_1 -> Draw();
 h_mWW_2 -> Draw("same");
 h_mWW_1 -> Draw("E2same");
 h_mWW_2 -> Draw("E2same");
 leg->Draw();
 cc_All->SetGrid();
 
 
 TCanvas* cc_Sub = new TCanvas("cc_Sub","cc_Sub",800,600);
 h_Subtraction->GetYaxis()->SetRangeUser(h_Subtraction->GetMinimum()-10.,h_Subtraction->GetMaximum()*2.5);
 h_Subtraction->SetFillStyle(3005);
 h_Subtraction->SetFillColor(kMagenta);
 h_Subtraction->SetLineColor(kMagenta);
 h_Subtraction->SetLineStyle(2);
 h_Subtraction->SetLineWidth(3);
 h_Subtraction -> Draw();
 h_Subtraction -> Draw("E2same");
 cc_Sub->SetGrid();

 
 TCanvas* cc_Ratio = new TCanvas("cc_Ratio","cc_Ratio",800,600);
 h_Ratio->SetLineColor(kGreen);
 h_Ratio->SetLineStyle(1);
 h_Ratio->SetLineWidth(2);
 h_Ratio -> Draw();
 cc_Ratio->SetGrid();
 
 std::cout << std::endl;
 std::cout << " --------------------------- " << std::endl;
 std::cout << " qcd w/  b   = " << h_mWW_1->Integral() << std::endl;
 std::cout << " qcd w/o b   = " << h_mWW_2->Integral() << std::endl;
 std::cout << " --------------------------- " << std::endl;
 std::cout << std::endl; 
}