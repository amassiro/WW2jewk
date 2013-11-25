// 
// Write the Ree and Rmumu with their errors
// 

{
 std::string nameFileRMC = "test/Latinos12/DYRinout/result-MC-R-Reval.txt";
 std::string nameFileR   = "test/Latinos12/DYRinout/result-R-Reval.txt";
 
 std::cout << "cat " << nameFileR << std::endl;
 
 #include <iomanip>
 
 ///--------------------------------------------------------------
 
 std::cout << " ---> read rate <---- " << std::endl;
 
 int numMass = 9;
 Double_t x_vals[80] =     {20+1.25, 22.5+1.25, 25+1.25, 27.5+1.25, 30+2.5, 35+2.5, 40+2.5, 45+2.5, 50+2.5};
 Double_t err_x_vals[80] = {1.25   ,      1.25,    1.25,      1.25,    2.5,    2.5,    2.5,    2.5,    2.5};
 

 double Ree[100];
 double errRee[100];
 double errSystRee[100];
 double Rmumu[100];
 double errRmumu[100];
 double errSystRmumu[100];
 
 
 std::ifstream FileRate (nameFileR.c_str()); 
 
 int nLine = 0;
 std::string buffer; 
 while(!FileRate.eof()) {
  getline(FileRate,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine == 0) {
    nLine ++;
   }
   else {
    double tempRate;
    
    line >> tempRate;     
    Rmumu[nLine-1] = tempRate;
    line >> tempRate;     
    errRmumu[nLine-1] = tempRate;
    line >> tempRate;     
    errSystRmumu[nLine-1] = tempRate;
    line >> tempRate;     
    Ree[nLine-1] = tempRate;
    line >> tempRate;     
    errRee[nLine-1] = tempRate;
    line >> tempRate;     
    errSystRee[nLine-1] = tempRate;
      
    nLine ++;
   }
  }
 }
 
 
 
 
 
 double MC_Ree[100];
 double MC_errRee[100];
 double MC_errSystRee[100];
 double MC_Rmumu[100];
 double MC_errRmumu[100];
 double MC_errSystRmumu[100];
 
 
 std::ifstream MC_FileRate (nameFileRMC.c_str()); 
 
 nLine = 0;
 std::string buffer; 
 while(!MC_FileRate.eof()) {
  getline(MC_FileRate,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine == 0) {
    nLine ++;
   }
   else {
    double tempRate;
    
    line >> tempRate;     
    MC_Rmumu[nLine-1] = tempRate;
    line >> tempRate;     
    MC_errRmumu[nLine-1] = tempRate;
    line >> tempRate;     
    MC_errSystRmumu[nLine-1] = tempRate;
    line >> tempRate;     
    MC_Ree[nLine-1] = tempRate;
    line >> tempRate;     
    MC_errRee[nLine-1] = tempRate;
    line >> tempRate;     
    MC_errSystRee[nLine-1] = tempRate;
    
    nLine ++;
   }
  }
 }
 
 
 ///---- plot to screen ----
 
 
 std::cout << std::endl;
 std::cout << std::endl;
 
 std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
 
 for (int iWP = 0; iWP < numMass; iWP++) {
  std::cout << std::setprecision(-1) << std::setw(7) << x_vals[iWP] << "    & " ;
  
  std::cout << std::setprecision(3) << std::setw(7) << Rmumu[iWP] << " $\\pm$ ";
  std::cout << std::setprecision(3) << std::setw(7) << errRmumu[iWP] << " $\\pm$ ";
  std::cout << std::setprecision(2) << std::setw(7) << fabs(errSystRmumu[iWP])*Rmumu[iWP] << " & ";
  
  std::cout << std::setprecision(3) << std::setw(7) << Ree[iWP] << " $\\pm$ ";
  std::cout << std::setprecision(3) << std::setw(7) << errRee[iWP] << " $\\pm$ ";
  std::cout << std::setprecision(2) << std::setw(7) << fabs(errSystRee[iWP])*Ree[iWP] << "  ";
  
  std::cout << " \\\\ " << std::endl;
  
 }
 
 
 std::cout << std::endl;
 std::cout << std::endl;
 
 
 
 
 TCanvas* cRee = new TCanvas ("cRee","cRee");

 TGraphErrors* gRee = new TGraphErrors(numMass,x_vals,Ree,err_x_vals,errRee);
 
 gRee->SetTitle("R_{ee}");
 gRee->SetFillStyle(0);
 gRee->SetMarkerColor(kRed);
 gRee->SetLineColor(kRed);
 gRee->SetLineWidth(2);
 gRee->SetMarkerStyle(20);
//  gRee->GetXaxis()->SetTitle("mpmet>(20+(17+nvtx/2.)*(X-0.5)) & mpmet<(20+(17+nvtx/2.)*(X+0.5))");
 gRee->GetXaxis()->SetTitle("pfmet");
 gRee->GetYaxis()->SetTitle("R^{ee}");
 gRee->Draw("AP");
 cRee->SetGrid();
 
 TGraphErrors* MC_gRee = new TGraphErrors(numMass,x_vals,MC_Ree,err_x_vals,MC_errRee);
 MC_gRee->SetTitle("MC R_{ee}");
 MC_gRee->SetFillStyle(0);
 MC_gRee->SetMarkerColor(kRed);
 MC_gRee->SetLineColor(kRed);
 MC_gRee->SetLineWidth(2);
 MC_gRee->SetLineStyle(2);
 MC_gRee->SetMarkerStyle(21);
 MC_gRee->GetXaxis()->SetTitle("pfmet");
 MC_gRee->GetYaxis()->SetTitle("R^{ee}");
 MC_gRee->Draw("Psame");
 cRee->SetGrid();
 
 cRee->BuildLegend();
 
//  TLine* lRee = new TLine (1,-0.15,1,0.2);
//  lRee->SetLineWidth(4);
//  lRee->SetLineColor(kGreen);
//  lRee->Draw("L");
 
//  TPaveText *ptee = new TPaveText(1.01,-0.15,1.4,-0.10);
//  ptee->SetFillColor(kGreen);
//  ptee->AddText("Signal Region");
//  ptee->Draw();
 
//  TF1* fRee = new TF1 ("fRee","[0]",0,1.0);
//  fRee->SetLineColor(kRed);
//  fRee->SetLineStyle(2);
//  gRee->Fit(fRee,"RMEQ");
 
 
 
 TCanvas* cRmumu = new TCanvas ("cRmumu","cRmumu");
 TGraphErrors* gRmumu = new TGraphErrors(numMass,x_vals,Rmumu,err_x_vals,errRmumu);
 
 gRmumu->SetTitle("R_{#mu#mu}");
 gRmumu->SetFillStyle(0);
 gRmumu->SetMarkerColor(kBlue);
 gRmumu->SetLineColor(kBlue);
 gRmumu->SetLineWidth(2);
 gRmumu->SetMarkerStyle(20);
//  gRmumu->GetXaxis()->SetTitle("mpmet>(20+(17+nvtx/2.)*(X-0.5)) & mpmet<(20+(17+nvtx/2.)*(X+0.5))");
 gRmumu->GetXaxis()->SetTitle("pfmet");
 gRmumu->GetYaxis()->SetTitle("R^{#mu#mu}");
 gRmumu->Draw("AP");
 cRmumu->SetGrid();

 TGraphErrors* MC_gRmumu = new TGraphErrors(numMass,x_vals,MC_Rmumu,err_x_vals,MC_errRmumu);
 MC_gRmumu->SetTitle("MC R_{#mu#mu}");
 MC_gRmumu->SetFillStyle(0);
 MC_gRmumu->SetMarkerColor(kBlue);
 MC_gRmumu->SetLineColor(kBlue);
 MC_gRmumu->SetLineWidth(2);
 MC_gRmumu->SetLineStyle(2);
 MC_gRmumu->SetMarkerStyle(21);
 MC_gRmumu->GetXaxis()->SetTitle("pfmet");
 MC_gRmumu->GetYaxis()->SetTitle("R^{#mu#mu}");
 MC_gRmumu->Draw("Psame");
 
 cRmumu->BuildLegend();
 
//  TLine* lRmumu = new TLine (1,-0.2,1,0.25);
//  lRmumu->SetLineWidth(4);
//  lRmumu->SetLineColor(kGreen);
//  lRmumu->Draw("L");
 
//  TPaveText *ptmumu = new TPaveText(1.01,-0.20,1.4,-0.15);
//  ptmumu->SetFillColor(kGreen);
//  ptmumu->AddText("Signal Region");
//  ptmumu->Draw();
 
//  TF1* fRmumu = new TF1 ("fRmumu","[0]",0,1.0);
//  fRmumu->SetLineColor(kBlue);
//  fRmumu->SetLineStyle(2);
//  gRmumu->Fit(fRmumu,"RMEQ");
 
 
 
}






