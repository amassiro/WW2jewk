// 
// Write expected number of events in the format
//    number +/- error
// 
//    for ee and mumu separately
//

{
 std::string nameFileR = "test/Latinos12/DYRinout/result-R.txt";
 
 std::string nameFileRate_ee = "test/Latinos12/DYRinout/result-value-ee.txt";
 std::string nameFileSyst_ee = "test/Latinos12/DYRinout/result-syst-ee.txt";
 std::string nameFileSyst_Stat_ee = "test/Latinos12/DYRinout/result-syst-stat-ee.txt";
 std::string nameFileSyst_Method_ee = "test/Latinos12/DYRinout/result-syst-method-ee.txt";
 
 std::string nameFileRate_mumu = "test/Latinos12/DYRinout/result-value-mumu.txt";
 std::string nameFileSyst_mumu = "test/Latinos12/DYRinout/result-syst-mumu.txt";
 std::string nameFileSyst_Stat_mumu = "test/Latinos12/DYRinout/result-syst-stat-mumu.txt";
 std::string nameFileSyst_Method_mumu = "test/Latinos12/DYRinout/result-syst-method-mumu.txt";
 
 std::cout << "cat " << nameFileRate_ee << std::endl;
 std::cout << "cat " << nameFileSyst_ee << std::endl;
 std::cout << "cat " << nameFileSyst_Stat_ee << std::endl;
 std::cout << "cat " << nameFileSyst_Method_ee << std::endl;
 
 std::cout << "cat " << nameFileRate_mumu << std::endl;
 std::cout << "cat " << nameFileSyst_mumu << std::endl;
 std::cout << "cat " << nameFileSyst_Stat_mumu << std::endl;
 std::cout << "cat " << nameFileSyst_Method_mumu << std::endl;
 
 #include <iomanip>
 
 ///--------------------------------------------------------------
 
 std::cout << " ---> read rate <---- " << std::endl;
 Double_t x_vals[40]      = {110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 170, 180, 190, 200, 250, 300, 350, 400, 450, 500, 550, 600, 700, 800, 900, 1000, -1, -1};
 Double_t x_vals_fake[40] = {110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 170, 180, 190, 200, 250, 300, 350, 400, 450, 500, 550, 600, 700, 800, 900, 1000, -1, -1};
 int associationNum[80]   = {  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33};
 int NumWP = 27;
 
//  Double_t x_vals[80] = {120, 130, 140, 150, 160, 170, 180, 190};
 std::string buffer; 
 
 
 ///---- ee ----
 std::vector<double> rate_ee[100];
 std::vector<string> nameSamples_ee;
 std::ifstream FileRate_ee (nameFileRate_ee.c_str()); 
 
 int nLine_ee = 0;
 while(!FileRate_ee.eof()) {
  getline(FileRate_ee,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine_ee == 0) {
    std::string tempString;
    while ( line >> tempString ) {
     nameSamples_ee.push_back(tempString);
    }
    nLine_ee ++;
   }
   else {
    double tempRate;
    int iSample = 0;
    while ( line >> tempRate ) {
     rate_ee[iSample].push_back(tempRate);
     iSample++;
    }
    nLine_ee ++;
   }
  }
 }
 
 std::cout << " ---> read systematics <---- " << std::endl;
 std::vector<double> syst_ee[100];
 std::ifstream FileSyst_ee (nameFileSyst_ee.c_str()); 
 
 nLine_ee = 0;
 while(!FileSyst_ee.eof()) {
  getline(FileSyst_ee,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine_ee == 0) {
    nLine_ee ++;
   }
   else {
    double tempSyst;
    int iSample = 0;
    while ( line >> tempSyst ) {
     syst_ee[iSample].push_back(tempSyst);
     iSample++;
    }
    nLine_ee ++;
   }
  }
 }
 
 
 
 std::vector<double> syst_Stat_ee[100];
 std::ifstream FileSyst_Stat_ee (nameFileSyst_Stat_ee.c_str()); 
 
 nLine_ee = 0;
 while(!FileSyst_Stat_ee.eof()) {
  getline(FileSyst_Stat_ee,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine_ee == 0) {
    nLine_ee ++;
   }
   else {
    double tempSyst_Stat;
    int iSample = 0;
    while ( line >> tempSyst_Stat ) {
     syst_Stat_ee[iSample].push_back(tempSyst_Stat);
     iSample++;
    }
    nLine_ee ++;
   }
  }
 }
 
 
 
 std::vector<double> syst_Method_ee[100];
 std::ifstream FileSyst_Method_ee (nameFileSyst_Method_ee.c_str()); 
 
 nLine_ee = 0;
 while(!FileSyst_Method_ee.eof()) {
  getline(FileSyst_Method_ee,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine_ee == 0) {
    nLine_ee ++;
   }
   else {
    double tempSyst_Method;
    int iSample = 0;
    while ( line >> tempSyst_Method ) {
     syst_Method_ee[iSample].push_back(tempSyst_Method);
     iSample++;
    }
    nLine_ee ++;
   }
  }
 }
 
 
 
 
 
 
 
 
 
 ///---- mumu ----
 std::vector<double> rate_mumu[100];
 std::vector<string> nameSamples_mumu;
 std::ifstream FileRate_mumu (nameFileRate_mumu.c_str()); 
 
 int nLine_mumu = 0;
 while(!FileRate_mumu.eof()) {
  getline(FileRate_mumu,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine_mumu == 0) {
    std::string tempString;
    while ( line >> tempString ) {
     nameSamples_mumu.push_back(tempString);
    }
    nLine_mumu ++;
   }
   else {
    double tempRate;
    int iSample = 0;
    while ( line >> tempRate ) {
     rate_mumu[iSample].push_back(tempRate);
     iSample++;
    }
    nLine_mumu ++;
   }
  }
 }
 
 std::cout << " ---> read systematics <---- " << std::endl;
 std::vector<double> syst_mumu[100];
 std::ifstream FileSyst_mumu (nameFileSyst_mumu.c_str()); 
 
 nLine_mumu = 0;
 while(!FileSyst_mumu.eof()) {
  getline(FileSyst_mumu,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine_mumu == 0) {
    nLine_mumu ++;
   }
   else {
    double tempSyst;
    int iSample = 0;
    while ( line >> tempSyst ) {
     syst_mumu[iSample].push_back(tempSyst);
     iSample++;
    }
    nLine_mumu ++;
   }
  }
 }
 
 
 
 std::vector<double> syst_Stat_mumu[100];
 std::ifstream FileSyst_Stat_mumu (nameFileSyst_Stat_mumu.c_str()); 
 
 nLine_mumu = 0;
 while(!FileSyst_Stat_mumu.eof()) {
  getline(FileSyst_Stat_mumu,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine_mumu == 0) {
    nLine_mumu ++;
   }
   else {
    double tempSyst_Stat;
    int iSample = 0;
    while ( line >> tempSyst_Stat ) {
     syst_Stat_mumu[iSample].push_back(tempSyst_Stat);
     iSample++;
    }
    nLine_mumu ++;
   }
  }
 }
 
 
 
 std::vector<double> syst_Method_mumu[100];
 std::ifstream FileSyst_Method_mumu (nameFileSyst_Method_mumu.c_str()); 
 
 nLine_mumu = 0;
 while(!FileSyst_Method_mumu.eof()) {
  getline(FileSyst_Method_mumu,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine_mumu == 0) {
    nLine_mumu ++;
   }
   else {
    double tempSyst_Method;
    int iSample = 0;
    while ( line >> tempSyst_Method ) {
     syst_Method_mumu[iSample].push_back(tempSyst_Method);
     iSample++;
    }
    nLine_mumu ++;
   }
  }
 }
 
 
 
 ///---- R ----
 
 double Ree[100];
 double errRee[100];
 double errSystRee[100];
 double Rmumu[100];
 double errRmumu[100];
 double errSystRmumu[100];
 
 std::ifstream FileRate_R (nameFileR.c_str()); 

 int nLine = 0;
 while(!FileRate_R.eof()) {
  getline(FileRate_R,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine == 0) {
    nLine ++;
   }
   else {
    double tempRate;

//     line >> tempRate;     
//     Ree[nLine-1] = tempRate;
//     line >> tempRate;     
//     errRee[nLine-1] = tempRate;
//     line >> tempRate;     
//     errSystRee[nLine-1] = tempRate;    
//     line >> tempRate;     
//     Rmumu[nLine-1] = tempRate;
//     line >> tempRate;     
//     errRmumu[nLine-1] = tempRate;
//     line >> tempRate;     
//     errSystRmumu[nLine-1] = tempRate;
    
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
 
 
 
 
 
 
 
 
 ///---- plot to screen ----

 
//  for (int iSample = 0; iSample < nameSamples_ee.size(); iSample++) {
//   std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
//   std::cout << " Sample = " <<  nameSamples_ee.at(iSample) << " and " <<  nameSamples_mumu.at(iSample) << std::endl;
//   std::cout << std::endl;
//   
//   for (int iWP = 0; iWP < rate_ee[iSample].size(); iWP++) {
//    std::cout << std::setprecision(-1) << std::setw(7) << x_vals[iWP] << "    & " ;
//    std::cout << std::setprecision(3) << std::setw(7) << rate_mumu[iSample].at(iWP) << " $\\pm$ ";
//    std::cout << std::setprecision(2) << std::setw(7) << rate_mumu[iSample].at(iWP) * (syst_mumu[iSample].at(iWP)-1.) << "   ";
//    std::cout << "  & " ;
//    std::cout << std::setprecision(2) << std::setw(7) << rate_mumu[iSample].at(iWP) / syst_Stat_mumu[iSample].at(iWP);
//    std::cout << "  & " ;
// //    std::cout << std::setprecision(3) << std::setw(7) << syst_Stat_mumu[iSample].at(iWP);
// //    std::cout << "  $\\pm$ " ;
// //    std::cout << std::setprecision(3) << std::setw(7) << (syst_Method_mumu[iSample].at(iWP) - 1.) * syst_Stat_mumu[iSample].at(iWP);   
//    std::cout << std::setprecision(3) << std::setw(7) << Rmumu[iWP] << " $\\pm$ ";
//    std::cout << std::setprecision(3) << std::setw(7) << sqrt(errRmumu[iWP]*errRmumu[iWP] + fabs(errSystRmumu[iWP])*Rmumu[iWP]*fabs(errSystRmumu[iWP])*Rmumu[iWP]) << "  ";
//    
//    std::cout << "  & " ;
//    
//    std::cout << std::setprecision(3) << std::setw(7) << rate_ee[iSample].at(iWP) << " $\\pm$ ";
//    std::cout << std::setprecision(2) << std::setw(7) << rate_ee[iSample].at(iWP) * (syst_ee[iSample].at(iWP)-1.) << "   ";
//    std::cout << "  & " ;
//    std::cout << std::setprecision(2) << std::setw(7) << rate_ee[iSample].at(iWP) / syst_Stat_ee[iSample].at(iWP);
//    std::cout << "  & " ;
// //    std::cout << std::setprecision(3) << std::setw(7) << syst_Stat_ee[iSample].at(iWP);
// //    std::cout << "  $\\pm$ " ;
// //    std::cout << std::setprecision(3) << std::setw(7) << (syst_Method_ee[iSample].at(iWP) - 1.) * syst_Stat_ee[iSample].at(iWP);
//    std::cout << std::setprecision(3) << std::setw(7) << Ree[iWP] << " $\\pm$ ";
//    std::cout << std::setprecision(3) << std::setw(7) << sqrt(errRee[iWP]*errRee[iWP] + fabs(errSystRee[iWP])*Ree[iWP]*fabs(errSystRee[iWP])*Ree[iWP]) << "  ";
//    std::cout << " \\\\ " << std::endl;
//    
//   }
//  }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 for (int iSample = 0; iSample < nameSamples_ee.size(); iSample++) {
  std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
  std::cout << " Sample = " <<  nameSamples_ee.at(iSample) << " and " <<  nameSamples_mumu.at(iSample) << std::endl;
  std::cout << std::endl;
  
  for (int iWP = 0; iWP < NumWP; iWP++) {
   std::cout << std::setprecision(-1) << std::setw(7) << x_vals_fake[associationNum[iWP]] << "    & " ;
   std::cout << std::setprecision(3) << std::setw(7) << rate_mumu[iSample].at(associationNum[iWP]) << " $\\pm$ ";
//    std::cout << std::setprecision(2) << std::setw(7) << rate_mumu[iSample].at(associationNum[iWP]) * (syst_mumu[iSample].at(associationNum[iWP])-1.) << "   ";
   std::cout << std::setprecision(2) << std::setw(7) << rate_mumu[iSample].at(associationNum[iWP]) *  sqrt(1. / (rate_mumu[iSample].at(associationNum[iWP]) / syst_Stat_mumu[iSample].at(associationNum[iWP])) +     (syst_Method_mumu[iSample].at(associationNum[iWP]) - 1.)*(syst_Method_mumu[iSample].at(associationNum[iWP]) - 1.) );
   std::cout << "   ";
      
   std::cout << "  & " ;
   std::cout << std::setprecision(2) << std::setw(7) << rate_mumu[iSample].at(associationNum[iWP]) / syst_Stat_mumu[iSample].at(associationNum[iWP]);
   std::cout << "  & " ;
   std::cout << std::setprecision(3) << std::setw(7) << Rmumu[associationNum[iWP]] << " $\\pm$ ";
   std::cout << std::setprecision(3) << std::setw(7) << sqrt(errRmumu[associationNum[iWP]]*errRmumu[associationNum[iWP]] + fabs(errSystRmumu[associationNum[iWP]])*Rmumu[associationNum[iWP]]*fabs(errSystRmumu[associationNum[iWP]])*Rmumu[associationNum[iWP]]) << "  ";
   
   std::cout << "  & " ;
   
   std::cout << std::setprecision(3) << std::setw(7) << rate_ee[iSample].at(associationNum[iWP]) << " $\\pm$ ";
//    std::cout << std::setprecision(2) << std::setw(7) << rate_ee[iSample].at(associationNum[iWP]) * (syst_ee[iSample].at(associationNum[iWP])-1.) << "   ";
   std::cout << std::setprecision(2) << std::setw(7) << rate_ee[iSample].at(associationNum[iWP]) *  sqrt(1. / (rate_ee[iSample].at(associationNum[iWP]) / syst_Stat_ee[iSample].at(associationNum[iWP])) +     (syst_Method_ee[iSample].at(associationNum[iWP]) - 1.)*(syst_Method_ee[iSample].at(associationNum[iWP]) - 1.) );
   
   std::cout << "  & " ;
   std::cout << std::setprecision(2) << std::setw(7) << rate_ee[iSample].at(associationNum[iWP]) / syst_Stat_ee[iSample].at(associationNum[iWP]);
   std::cout << "  & " ;
   std::cout << std::setprecision(3) << std::setw(7) << Ree[associationNum[iWP]] << " $\\pm$ ";
   std::cout << std::setprecision(3) << std::setw(7) << sqrt(errRee[associationNum[iWP]]*errRee[associationNum[iWP]] + fabs(errSystRee[associationNum[iWP]])*Ree[associationNum[iWP]]*fabs(errSystRee[associationNum[iWP]])*Ree[associationNum[iWP]]) << "  ";
   std::cout << " \\\\ " << std::endl;
   
  }
 }
 
 
 
 
 std::cout << std::endl;
 std::cout << std::endl;
 
 
 
 std::cout << std::endl;
 std::cout << std::endl;
 
 gApplication->Terminate(0);
 
}






