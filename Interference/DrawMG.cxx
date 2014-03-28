//----------------------------
//---- draw distributions ----
//----------------------------

void DrawMG(std::string var = "mWW", int NBIN = 1000, int MIN = 0, int MAX = 1000, std::string varHR = "mWW") {
  
 gStyle->SetOptStat(0);
 
 TString name1;
//  name1 = Form ("EWK_MG.root");
//  name1 = Form ("EWK_MG_100k_BRHWW.root");
 name1 = Form ("EWK_MG_bquarks.root");
 
 TString name2;
//  name2 = Form ("QCD_MG.root");
//  name2 = Form ("QCD_MG_bquarks.root");
//  name2 = Form ("QCD_MG_bquarks_kincuts.root");
 name2 = Form ("QCD_MG_bquarks_kincuts_1M.root");
 
 TString name3;
//  name3 = Form ("EWKQCD_MG.root");
//  name3 = Form ("EWKQCD_MG_bquarks.root");
 name3 = Form ("EWKQCD_MG_bquarks_kincuts.root");
//  name3 = Form ("EWKQCD_MG_bquarks_kincuts_1M.root");
 
 
 TFile* f1 = new TFile (name1.Data(),"READ"); // ---- EW
 TFile* f2 = new TFile (name2.Data(),"READ"); // ---- QCD
 TFile* f3 = new TFile (name3.Data(),"READ"); // ---- EW+QCD
 
 std::cout << " name EW     = " << name1.Data() << std::endl;
 std::cout << " name QCD    = " << name2.Data() << std::endl;
 std::cout << " name EW+QCD = " << name3.Data() << std::endl;
 
 TNtuple* t1 = (TNtuple*) f1->Get ("ntu");
 TNtuple* t2 = (TNtuple*) f2->Get ("ntu");
 TNtuple* t3 = (TNtuple*) f3->Get ("ntu");
 
 TH1F* h_mWW_1 = new TH1F("h_mWW_1","EW MG",NBIN,MIN,MAX);
 TH1F* h_mWW_2 = new TH1F("h_mWW_2","QCD MG",NBIN,MIN,MAX);
 TH1F* h_mWW_3 = new TH1F("h_mWW_3","EW+QCD MG",NBIN,MIN,MAX);
 TH1F* h_Ratio = new TH1F("h_mWW_ratio","h_mWW_ratio MG",NBIN,MIN,MAX);
 TH1F* h_Subtraction = new TH1F("h_Subtraction","h_Subtraction MG",NBIN,MIN,MAX);
 TH1F* h_I = new TH1F("h_I","h_I",NBIN,MIN,MAX);
 
 h_mWW_1->GetXaxis()->SetTitle(varHR.c_str());
 h_mWW_2->GetXaxis()->SetTitle(varHR.c_str());
 h_mWW_3->GetXaxis()->SetTitle(varHR.c_str());
 h_Ratio->GetXaxis()->SetTitle(varHR.c_str());
 h_Subtraction->GetXaxis()->SetTitle(varHR.c_str());
 h_I->GetXaxis()->SetTitle(varHR.c_str());
 
 h_mWW_1->GetYaxis()->SetTitle("fb");
 h_mWW_2->GetYaxis()->SetTitle("fb");
 h_mWW_3->GetYaxis()->SetTitle("fb");
 h_Subtraction->GetYaxis()->SetTitle("fb");
 h_I->GetYaxis()->SetTitle("fb");
 
//  0.008021 +- 2.212e-05 pb  EWK
//  0.1663 +- 0.0003664 pb    QCD
//  0.1743 +- 0.0003675 pb    EWKQCD
 
//  with 10k events                    with 1M events
//  0.008021 +- 2.212e-05 pb  EWK        0.008115 +- 2.12e-06 pb
//  0.1663 +- 0.0003664 pb    QCD        0.1668 +- 5.003e-05 pb
//  0.1743 +- 0.0003675 pb    EWKQCD     0.1754 +- 5.231e-05 pb
 
//   gROOT->ProcessLine ("float xsecEW[100] = {0.008115};");
//   gROOT->ProcessLine ("float xsecQCD[100] = {0.1668};");
//   gROOT->ProcessLine ("float xsecEWQCD[100] = {0.1754};");
 
 
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
  gROOT->ProcessLine ("float xsecEWQCD[100] = {1.544};");
 
 
 //---- 1M events
 //  1.50144           pb    QCD     
 //   ### pb     EWKQCD  
  
 gROOT->ProcessLine ("float xsecEW[100] = {0.1102};");
 gROOT->ProcessLine ("float xsecQCD[100] = {1.50144};");
//  gROOT->ProcessLine ("float xsecEWQCD[100] = {1.###};");
  


 
//  gROOT->ProcessLine ("float xsecEW[100] = {0.0080983};");
// //  gROOT->ProcessLine ("float xsecEW[100] = {0.008115};");
 
 
//  TString cut = Form ("jetpt1>30 && jetpt2>30 && mWW>130");
//  TString cut = Form ("jetpt1>30 && jetpt2>30");
//  TString cut = Form ("jetpt1>30 && jetpt2>30 && mjj>200");
 TString cut = Form ("jetpt1>30 && jetpt2>30 && mjj>300 && pt1>20 && pt2>20 && mll>8");
//  TString cut = Form ("jetpt1>20 && jetpt2>20 && mjj>300 && pt1>20 && pt2>20 && mll>8");
 //  TString cut = Form ("jetpt1>30 && jetpt2>30");
 //  TString cut = Form ("1");
 
 int tot_1 = t1 -> GetEntries();
 int tot_2 = t2 -> GetEntries();
 int tot_3 = t3 -> GetEntries();
 
 std::cout << std::endl;
 std::cout << " tot_1 = " << tot_1 << std::endl;
 std::cout << " tot_2 = " << tot_2 << std::endl;
 std::cout << " tot_3 = " << tot_3 << std::endl;
 
 TString weightWithXsecEW    = Form ("(%s) * (%f) * (%f)",cut.Data(),xsecEW[0],1000./tot_1);
 TString weightWithXsecQCD   = Form ("(%s) * (%f) * (%f)",cut.Data(),xsecQCD[0],1000./tot_2);
 TString weightWithXsecEWQCD = Form ("(%s) * (%f) * (%f)",cut.Data(),xsecEWQCD[0],1000./tot_3);
 
 TString toDraw;
 toDraw = Form ("%s >> h_mWW_1",var.c_str());
 std::cout << " weight = " << weightWithXsecEW.Data() << std::endl;
 t1->Draw(toDraw.Data(),weightWithXsecEW.Data(),"goff");
 
 toDraw = Form ("%s >> h_mWW_2",var.c_str());
 std::cout << " weight = " << weightWithXsecQCD.Data() << std::endl;
 t2->Draw(toDraw.Data(),weightWithXsecQCD.Data(), "goff");
 
 toDraw = Form ("%s >> h_mWW_3",var.c_str());
 std::cout << " weight = " << weightWithXsecEWQCD.Data() << std::endl;
 t3->Draw(toDraw.Data(),weightWithXsecEWQCD.Data(), "goff");
 
 h_mWW_1->SetLineColor(kBlue);  //---- ewk
 h_mWW_2->SetLineColor(kRed);   //---- qcd
 h_mWW_3->SetLineColor(kGreen); //---- ewk+qcd
 
 h_mWW_1->SetLineStyle(1);
 h_mWW_2->SetLineStyle(2);
 h_mWW_3->SetLineStyle(2);
 
 h_mWW_1->SetLineWidth(2);
 h_mWW_2->SetLineWidth(2);
 h_mWW_3->SetLineWidth(4);
 
 TLegend* leg = new TLegend(0.5,0.7,0.9,0.9);
 leg->AddEntry(h_mWW_1,"ewk","l");
 leg->AddEntry(h_mWW_2,"qcd","l");
 leg->AddEntry(h_mWW_3,"ewk+qcd","l");
 leg->SetFillStyle(0);


 TLegend* leg2 = new TLegend(0.5,0.7,0.9,0.9);
 leg2->AddEntry(h_mWW_1,"ewk","l");
 leg2->AddEntry(h_Subtraction,"ewk+interference","l");
 leg2->SetFillStyle(0);

 
 for (int iBin = 0; iBin < h_mWW_1->GetNbinsX(); iBin++) {
  float ewk = h_mWW_1->GetBinContent(iBin+1);
  float qcd = h_mWW_2->GetBinContent(iBin+1);  
  float ewkqcd = h_mWW_3->GetBinContent(iBin+1);
  h_I -> SetBinContent (iBin+1, ewkqcd - ewk - qcd);
  if (ewk != 0) h_Ratio -> SetBinContent (iBin+1, (ewkqcd - qcd) / ewk);
  else h_Ratio -> SetBinContent (iBin+1, 0);
  h_Subtraction -> SetBinContent (iBin+1, ewkqcd - qcd);
 }
 
 
 
 TCanvas* cc_All = new TCanvas("cc_All","cc_All",800,600);
 h_mWW_3->GetYaxis()->SetRangeUser(0.01,h_mWW_3->GetMaximum()*1.5);
 h_mWW_3 -> Draw();  //---- ewk+qcd
 h_mWW_1 -> Draw("same"); //---- ewk
 h_mWW_2 -> Draw("same"); //---- qcd
 leg->Draw();
 cc_All->SetGrid();
 
 
 TCanvas* cc_I = new TCanvas("cc_I","cc_I",800,600);
 h_I->GetYaxis()->SetRangeUser(h_I->GetMinimum()-10.,h_I->GetMaximum()*2.5);
 h_I->SetLineColor(kMagenta);
 h_I->SetLineStyle(1);
 h_I->SetLineWidth(2);
 h_I -> Draw();
 cc_I->SetGrid();
 
 
 TCanvas* cc_Sub = new TCanvas("cc_Sub","cc_Sub",800,600);
 h_Subtraction->GetYaxis()->SetRangeUser(h_Subtraction->GetMinimum()-10.,h_Subtraction->GetMaximum()*2.5);
 h_Subtraction->SetLineColor(kMagenta);
 h_Subtraction->SetLineStyle(2);
 h_Subtraction->SetLineWidth(3);
 h_Subtraction -> Draw();
 h_mWW_1 -> Draw("same");
 leg2->Draw();
 cc_Sub->SetGrid();

 
 TCanvas* cc_Ratio = new TCanvas("cc_Ratio","cc_Ratio",800,600);
 h_Ratio->SetLineColor(kGreen);
 h_Ratio->SetLineStyle(1);
 h_Ratio->SetLineWidth(2);
 h_Ratio -> Draw();
 cc_Ratio->SetGrid();
 
 std::cout << std::endl;
 std::cout << " --------------------------- " << std::endl;
 std::cout << " ewk     = " << h_mWW_1->Integral() << std::endl;
 std::cout << " qcd     = " << h_mWW_2->Integral() << std::endl;
 std::cout << " ewkqcd  = " << h_mWW_3->Integral() << std::endl;
 std::cout << " ewk+qcd = " << h_mWW_1->Integral() + h_mWW_2->Integral() << std::endl;
 std::cout << " --------------------------- " << std::endl;
 std::cout << std::endl; 
}