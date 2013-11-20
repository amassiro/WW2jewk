{
 
//  TFile *f0 = TFile::Open("/home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/output_Latinos_tree_2012_2orMoreJet2012_Top/latino_DATA.root");
//  TTree* latino = (TTree*) f0->Get("latino");
 
 
//  fisher = 1.3491*log(mjj)-0.01163*(jeteta1*jeteta2)+1.433*detajj-12.647
//  cut optimized >3.8   --> 5 events
//  cut optimized >0     --> 10 events



 TString toDraw;
 TString Cut = Form("baseW*puW*effW*triggW*(pt1>20 && pt2>10 && (ch1*ch2)<0 && trigger==1. && pfmet>20. && mll>12 && (zveto==1||!sameflav) && mpmet>20. && bveto_mu==1 && nextra==0 && (bveto_ip==1 && nbjettche==0) && ptll>45.000000 && (njet==0 || njet==1 || (dphilljetjet<pi/180.*165. || !sameflav )  ) && ( !sameflav || ( (njet!=0 || dymva1>0.88) && (njet!=1 || dymva1>0.84) && ( njet==0 || njet==1 || (pfmet > 45.0)) ) ) && abs(eta1 - (jeteta1+jeteta2)/2)/detajj < 0.5 && abs(eta2 - (jeteta1+jeteta2)/2)/detajj < 0.5 && dphill < 100*pi/180 && pt1 > 23.0 && pt2 > 10.0 && ((sameflav && (mth > 30.0 && mth < 123.0) && mll<43.0) || (!sameflav && (mth > 50.0 && mth < 125.0)))    && (njet >= 2 && njet <= 3 && (jetpt3 <= 30 || !(jetpt3 > 30 && (  (jeteta1-jeteta3 > 0 && jeteta2-jeteta3 < 0) || (jeteta2-jeteta3 > 0 && jeteta1-jeteta3 < 0)))))  )");

 TFile *f0 = TFile::Open("/home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/output_Latinos_tree_2012_2orMoreJet2012_Top/latino_2125_vbfToH125toWWTo2LAndTau2Nu.root");
 TTree* latinoVBF = (TTree*) f0->Get("latino");
 TH2F* histo_VBF = new TH2F ("histo_VBF","histo_VBF",60,100,3000,24,0,8);
 toDraw = Form("detajj:mjj >> histo_VBF");
 latinoVBF->Draw(toDraw.Data(),Cut.Data(),"goff");
 TH2F* histo_VBF_log = new TH2F ("histo_VBF_log","histo_VBF_log",60,4,15,24,0,8);
 toDraw = Form("detajj:log(mjj) >> histo_VBF_log");
 latinoVBF->Draw(toDraw.Data(),Cut.Data(),"goff");
 
 
 TFile *f1 = TFile::Open("/home/andrea/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/output_Latinos_tree_2012_2orMoreJet2012_Top/latino_019_TTTo2L2Nu2B.root");
 TTree* latinoTop = (TTree*) f1->Get("latino");
 TH2F* histo_Top = new TH2F ("histo_Top","histo_Top",60,100,3000,24,0,8);
 toDraw = Form("detajj:mjj >> histo_Top");
 latinoTop->Draw(toDraw.Data(),Cut.Data(),"goff");
 TH2F* histo_Top_log = new TH2F ("histo_Top_log","histo_Top_log",60,4,15,24,0,8);
 toDraw = Form("detajj:log(mjj) >> histo_Top_log");
 latinoTop->Draw(toDraw.Data(),Cut.Data(),"goff");
 
 
 
 

 TCanvas cc3;
 TF3 *f3 = new TF3("f3","1.3491*x-0.01163*y+1.433*z-12.647-3.8",4,15,-20,20,0,8);
//  f3->SetClippingBoxOn(0,0,0);
 f3->SetFillColor(30);
 f3->SetLineColor(15);
 f3->Draw("FBBB");
 f3->GetXaxis()->SetTitle("log(m_{jj})");
 f3->GetYaxis()->SetTitle("#eta_{j1}*#eta_{j2}");
 f3->GetZaxis()->SetTitle("#Delta#eta_{jj}");
 f3->Draw("FBBB");

 
 
//  TCanvas cc2xy;
// //  TF2 *f2xy = new TF2("f2xy","1.3491*x-0.01163*y-12.647+4",0,10,-20,20);
//  TF2 *f2xy = new TF2("f2xy","1.3491*x-0.01163*y-12.647-3.8",0,10,-20,20);
//  f2xy->SetContour(10);
//  f2xy->SetContourLevel(-2,2); 
//  f2xy->GetXaxis()->SetTitle("log(m_{jj})");
//  f2xy->GetYaxis()->SetTitle("#eta_{j1}*#eta_{j2}");
//  f2xy->Draw();    
 

 TCanvas cc2xz;
//  TF2 *f2xz = new TF2("f2xz","1.3491*x+1.433*y-12.647-2",0,10,0,8);
 TF2 *f2xz = new TF2("f2xz","1.3491*x+1.433*y-12.647-0",4,15,0,8);
//  f2xz->SsetContour(10);
//  f2xz->SetContourLevel(-2,2); 
 
 f2xz->SetContour(1);
 f2xz->SetContourLevel(0,1);
 
 f2xz->GetXaxis()->SetTitle("log(m_{jj})");
 f2xz->GetYaxis()->SetTitle("#Delta#eta_{jj}");
 f2xz->Draw();    
 

 
 
 
 
 
 
 TCanvas cc2xz_yeslog;
 //  TF2 *f2xz = new TF2("f2xz","1.3491*x+1.433*y-12.647-2",0,10,0,8);
 TF2 *f2xz_yeslog = new TF2("f2xz_yeslog","1.3491*x+1.433*y-12.647-0",4,15,0,8);
 f2xz_yeslog->SetContour(12);
 f2xz_yeslog->SetContourLevel(0,-1.0); 
 f2xz_yeslog->SetContourLevel(1,-0.5); 
 f2xz_yeslog->SetContourLevel(2,0.0); 
 f2xz_yeslog->SetContourLevel(3,0.5); 
 f2xz_yeslog->SetContourLevel(4,1.0); 
 f2xz_yeslog->SetContourLevel(5,1.5); 
 f2xz_yeslog->SetContourLevel(6,2.0); 
 f2xz_yeslog->SetContourLevel(7,2.5); 
 f2xz_yeslog->SetContourLevel(8,3.0); 
 f2xz_yeslog->SetContourLevel(9,3.5); 
 f2xz_yeslog->SetContourLevel(10,4.0); 
 f2xz_yeslog->SetContourLevel(11,4.5); 
//  f2xz_yeslog->SetContourLevel(12,5.0); 
 
 
 //  f2xz_yeslog->SetContour(1);
 //  f2xz_yeslog->SetContourLevel(0,1);
 
 f2xz_yeslog->GetXaxis()->SetTitle("log m_{jj}");
 f2xz_yeslog->GetYaxis()->SetTitle("#Delta#eta_{jj}");
 f2xz_yeslog->Draw();    
 
 TF2* f2xz_yeslog_new = (TF2*) f2xz_yeslog->Clone("f2xz_yeslog_new");
 f2xz_yeslog_new->SetContour(3);
 f2xz_yeslog_new->SetContourLevel(0,1.0); 
 f2xz_yeslog_new->SetContourLevel(1,3.0); 
 f2xz_yeslog_new->SetContourLevel(2,5.0); 
 f2xz_yeslog_new->SetLineColor(kRed);
 f2xz_yeslog_new->SetLineWidth(3);
 f2xz_yeslog_new->Draw("same");    
 
 
 
 
 
 
 
 TCanvas cc2xz_nolog;
 //  TF2 *f2xz = new TF2("f2xz","1.3491*x+1.433*y-12.647-2",0,10,0,8);
 TF2 *f2xz_nolog = new TF2("f2xz_nolog","1.3491*log(x)+1.433*y-12.647-0",100,3000,0,8);
 f2xz_nolog->SetContour(12);
 f2xz_nolog->SetContourLevel(0,-1.0); 
 f2xz_nolog->SetContourLevel(1,-0.5); 
 f2xz_nolog->SetContourLevel(2,0.0); 
 f2xz_nolog->SetContourLevel(3,0.5); 
 f2xz_nolog->SetContourLevel(4,1.0); 
 f2xz_nolog->SetContourLevel(5,1.5); 
 f2xz_nolog->SetContourLevel(6,2.0); 
 f2xz_nolog->SetContourLevel(7,2.5); 
 f2xz_nolog->SetContourLevel(8,3.0); 
 f2xz_nolog->SetContourLevel(9,3.5); 
 f2xz_nolog->SetContourLevel(10,4.0); 
 f2xz_nolog->SetContourLevel(11,4.5); 
//  f2xz_nolog->SetContourLevel(12,5.0); 
 
  
//  f2xz_nolog->SetContour(1);
//  f2xz_nolog->SetContourLevel(0,1);
 
 f2xz_nolog->GetXaxis()->SetTitle("m_{jj} [GeV]");
 f2xz_nolog->GetYaxis()->SetTitle("#Delta#eta_{jj}");
 f2xz_nolog->Draw();    
 
 TF2* f2xz_nolog_new = (TF2*) f2xz_nolog->Clone("f2xz_nolog_new");
 f2xz_nolog_new->SetContour(3);
 f2xz_nolog_new->SetContourLevel(0,1.0); 
 f2xz_nolog_new->SetContourLevel(1,3.0); 
 f2xz_nolog_new->SetContourLevel(2,5.0); 
 f2xz_nolog_new->SetLineColor(kRed);
 f2xz_nolog_new->SetLineWidth(3);
 f2xz_nolog_new->Draw("same");    
 
 
 
 TCanvas cc2xz_nolog_Top;
 f2xz_nolog->Draw();    
 histo_Top->Draw("colzsame");
 f2xz_nolog->Draw("same");    
 f2xz_nolog_new->Draw("same");    
 
 TCanvas cc2xz_nolog_VBF;
 f2xz_nolog->Draw();    
 histo_VBF->Draw("colzsame");
 f2xz_nolog->Draw("same");    
 f2xz_nolog_new->Draw("same");    
 
 
 
 TCanvas cc2xz_yeslog_Top;
 f2xz_yeslog->Draw();    
 histo_Top_log->Draw("colzsame");
 f2xz_yeslog->Draw("same");    
 f2xz_yeslog_new->Draw("same");    
 
 TCanvas cc2xz_yeslog_VBF;
 f2xz_yeslog->Draw();    
 histo_VBF_log->Draw("colzsame");
 f2xz_yeslog->Draw("same");    
 f2xz_yeslog_new->Draw("same");    
 
 
//  TCanvas cc2yz;
// //  TF2 *f2yz = new TF2("f2yz","-0.01163*x+1.433*y-12.647+7",-20,20,0,8);
//  TF2 *f2yz = new TF2("f2yz","-0.01163*x+1.433*y-12.647+3.8",-20,20,0,8);
//  f2yz->SetContour(10);
//  f2yz->SetContourLevel(-2,2); 
//  f2yz->GetXaxis()->SetTitle("#eta_{j1}*#eta_{j2}");
//  f2yz->GetYaxis()->SetTitle("#Delta#eta_{jj}");
//  f2yz->Draw();
 
 
 
 
 
 
 
 
//  f2->SetContour(1)
//  f2->SetContourLevel(0,1) 
//  f2->Draw()    
 
//  TF2 *f2 = new TF2("f2","1.3491*x-0.01163*y+1.433*z",-2,2,-2,2);
//  f2->SetContour(1)
//  f2->SetContourLevel(0,1) 
//  f2->Draw()    
 
 
 
 
//  TTree* latino = new TTree();
//  
// //  1.3491*log(mjj)-0.01163*(jeteta1*jeteta2)+1.433*detajj
//  
//  
//  float logmjj;
//  float etajj;
//  float detajj;
//  float fisher;
//  
//  latino->Branch("logmjj",&logmjj,"logmjj/F");
//  latino->Branch("etajj",&etajj,"etajj/F");
//  latino->Branch("detajj",&detajj,"detajj/F");
//  latino->Branch("fisher",&fisher,"fisher/F");
//  
//  
//  std::string varX = "#Delta#eta_{jj}";
//  std::string varY = "log(m_{jj})";
//  std::string varX = "detajj";
//  std::string varY = "logmjj";
//  
//  
//  
//  int nEvent = 10000;
//  for (int iEvent = 0; iEvent<nEvent; iEvent++) {
//   logmjj = gRandom->Uniform(0,20); 
//   detajj = gRandom->Uniform(0,6); 
//   etajj  = gRandom->Uniform(-3,3); 
//   fisher =  1.3491*logmjj-0.01163*etajj+1.433*detajj;
//   latino->Fill(fisher);
//  }
//  
//  
//  TCanvas* cc = new TCanvas ("cc","",800,500);
//  
//  TH2F* histo = new TH2F("histo","",20,0,100,20,0,100);
//  
//  TString toDraw = Form ("%s:%s >> histo",varY.c_str(), varX.c_str());
//  latino->Draw(toDraw.Data());
//  
// //  histo->Draw("isoZ");
// //  histo->Draw("col");
//  
//  
//  histo->GetXaxis()->SetTitle(varX.c_str());
//  histo->GetYaxis()->SetTitle(varY.c_str());
//  
//  
//  int TotalConts = 3;
//  
//  Double_t levels[100] = {1,20,100};
//  gStyle->SetOptStat(0);
//  histo -> SetContour (TotalConts,levels);
//  histo -> Draw ("CONT Z LIST");
//  gPad->Update();
//  
//  TObjArray* conts = (TObjArray*)  gROOT->GetListOfSpecials()->FindObject("contours");
//  histo -> Draw ("COLZ");
//  
//  Double_t x0, y0, z0; 
//  for (int i = 0; i < TotalConts; i++){
//   contLevel = (TList*) conts->At(i);
//   z0 = levels[i];
//   
//   // Get first graph from list on curves on this level
//   curv = (TGraph*) contLevel->First();
//   for(int j = 0; j < contLevel->GetSize(); j++){
//    curv->GetPoint(0, x0, y0);
//    if (z0<0) curv->SetLineColor(kRed);
//    if (z0>0) curv->SetLineColor(kBlue);
// 
//    // Draw clones of the graphs to avoid deletions in case the 1st
//    // pad is redrawn.
//    
//    gc = (TGraph*)curv->Clone();
//    gc -> SetTitle ("");
//    gc->SetLineColor(kBlack);
//    gc->SetLineWidth(4);
//    gc->Draw("C");
//    curv = (TGraph*)contLevel->After(curv); // Get Next graph
//   }
//  }
 
 
}