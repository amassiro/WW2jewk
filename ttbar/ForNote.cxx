// 
// Write expected number of events in the format
//    number +/- error
// 

{

//  std::string nameFile = "test/WW2jewk/ttbar/result-forNote-0.txt"; // ---- @ mH = 125, WP = 2 -- CJ

 //---- tight bveto <1.0
//  std::string nameFile = "test/WW2jewk/ttbar/result-eff-cut-of-pt-10-tche-1-0.txt";  //  [30-70]
//  std::string nameFile = "test/WW2jewk/ttbar/result-eff-cut-of-pt-11-tche-1-0.txt";     //  [70,-]  
 
 //---- loose bveto 1.0 < b < 2.1
//  std::string nameFile = "test/WW2jewk/ttbar/result-eff-cut-of-pt-10-tche-0-0.txt";  //  [30-70]
 std::string nameFile = "test/WW2jewk/ttbar/result-eff-cut-of-pt-11-tche-0-0.txt";     //  [70,-]  
 
 
 
 #include <iomanip>
 ///--------------------------------------------------------------
 
 std::cout << " ---> read <---- " << std::endl;
 std::vector<double> etaMin;
 std::vector<double> etaMax;
 std::vector<double> effDATA;
 std::vector<double> erreffDATA;
 std::vector<double> effMC_CR;
 std::vector<double> erreffMC_CR;
 std::vector<double> effMC_SR;
 std::vector<double> erreffMC_SR;
 
 
 etaMin.push_back (0.0);
 etaMin.push_back (0.5);
 etaMin.push_back (1.0);
 etaMin.push_back (1.5);
 etaMin.push_back (2.0); //--> before disabled
//  etaMin.push_back (2.5);
 
 etaMax.push_back (0.5);
 etaMax.push_back (1.0);
 etaMax.push_back (1.5);
 etaMax.push_back (2.0); //--> before disabled
 etaMax.push_back (2.5);
 
 
//  myfileEffHiggs << std::setw (11) << eff_DATA.at(iBin)                  << "   " ;  
//  myfileEffHiggs << std::setw (11) << err_eff_DATA.at(iBin)              << "   " ;  
//  myfileEffHiggs << std::setw (11) << eff_Top.at(iBin)       << "   " ;
//  myfileEffHiggs << std::setw (11) << err_eff_Top.at(iBin)                  << "   " ;  
//  myfileEffHiggs << std::setw (11) << eff_Top_Higgs.at(iBin)       << "   " ;
//  myfileEffHiggs << std::setw (11) << err_eff_Top_Higgs.at(iBin)                  << "   " ;  
 
 
 std::ifstream FileRate (nameFile.c_str()); 
 
 std::string buffer; 
 while(!FileRate.eof()) {
  getline(FileRate,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   double temp;
   line >> temp;
   effDATA.push_back(temp);
   line >> temp;
   erreffDATA.push_back(temp);
   line >> temp;
   effMC_CR.push_back(temp);
   line >> temp;
   erreffMC_CR.push_back(temp);
   line >> temp;
   effMC_SR.push_back(temp);
   line >> temp;
   erreffMC_SR.push_back(temp);
  }
 }
 
 
 ///---- plot to screen ----
  
 for (int iEta = 0; iEta < etaMin.size(); iEta++) {
  std::cout << " " << std::setprecision(2) << std::setw (11) << etaMin.at(iEta);
  std::cout << " $<$ $|\\eta|$ $<$ " << std::setprecision(2) << std::setw (11) << etaMax.at(iEta);
  std::cout << " & " ;
  std::cout << " " << std::setprecision(2) << std::setw (11) << effDATA.at(iEta);
  std::cout << " $\\pm$ " << std::setprecision(2) << std::setw (11) << erreffDATA.at(iEta);
  std::cout << " & " ;
  std::cout << " " << std::setprecision(2) << std::setw (11) << effMC_CR.at(iEta);
  std::cout << " $\\pm$ " << std::setprecision(2) << std::setw (11) << erreffMC_CR.at(iEta);
  std::cout << " & " ;
  std::cout << " " << std::setprecision(2) << std::setw (11) << effMC_SR.at(iEta);
  std::cout << " $\\pm$ " << std::setprecision(2) << std::setw (11) << erreffMC_SR.at(iEta);
  std::cout << " \\\\ " ;
  std::cout << std::endl;
 }
 
 
//  0   - 0.5           & YYY $\pm$ YYY \\
//  0.5 - 1.0           & YYY $\pm$ YYY \\
//  1.0 - 1.5           & YYY $\pm$ YYY \\
//  1.5 - 2.5           & YYY $\pm$ YYY \\
 
 
 std::cout << std::endl;
 std::cout << std::endl;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
 
 
/* 
 int associationNum[80]   = {  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,   11,   12,   13,   14,   15,   16,   17};
 Double_t x_vals_fake[80] = {110,   115,   120,   125,   130,   135,   140,   145,   150,   155,   160,   170,   180,   190,   200,   250,    300};
 Double_t x_vals[80]      = {110,   115,   120,   125,   130,   135,   140,   145,   150,   155,   160,   170,   180,   190,   200,   250,    300};
 int NumWP = 17;
 
 
 
 std::string nameFileRate = "test/WW2jewk/ttbar/result-value.txt";
 std::string nameFileSyst = "test/WW2jewk/ttbar/result-syst.txt";
 std::string nameFileSyst_Method = "test/WW2jewk/ttbar/result-syst-method.txt";
 std::string nameFileSyst_Stat = "test/WW2jewk/ttbar/result-syst-stat.txt";
 std::string nameFileSyst_CR_Stat = "test/WW2jewk/ttbar/result-syst-CR-stat.txt";
 std::string nameFileSyst_MCSub = Form("test/WW2jewk/ttbar/result-syst-MCSub.txt");
 
 
 std::cout << "cat " << nameFileRate << std::endl;
 std::cout << "cat " << nameFileSyst << std::endl;
 std::cout << "cat " << nameFileSyst_Method  << std::endl;
 std::cout << "cat " << nameFileSyst_Stat    << std::endl;
 std::cout << "cat " << nameFileSyst_CR_Stat << std::endl;
 std::cout << "cat " << nameFileSyst_MCSub   << std::endl;
 
 ///--------------------------------------------------------------
 
 std::cout << " ---> read rate <---- " << std::endl;
 std::vector<double> rate[100];
 std::vector<string> nameSamples;
 std::ifstream FileRate (nameFileRate.c_str()); 
 
 int nLine = 0;
 std::string buffer; 
 while(!FileRate.eof()) {
  getline(FileRate,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine == 0) {
    std::string tempString;
    while ( line >> tempString ) {
     nameSamples.push_back(tempString);
    }
    nLine ++;
   }
   else {
    double tempRate;
    int iSample = 0;
    while ( line >> tempRate ) {
     rate[iSample].push_back(tempRate);
     iSample++;
    }
    nLine ++;
   }
  }
 }
 
 std::cout << " ---> read systematics <---- " << std::endl;
 std::vector<double> syst[100];
 std::ifstream FileSyst (nameFileSyst.c_str()); 
 
 nLine = 0;
 while(!FileSyst.eof()) {
  getline(FileSyst,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine == 0) {
    nLine ++;
   }
   else {
    double tempSyst;
    int iSample = 0;
    while ( line >> tempSyst ) {
     syst[iSample].push_back(tempSyst);
     iSample++;
    }
    nLine ++;
   }
  }
 }
 
 
 
 
 std::cout << " ---> read systematics Method <---- " << std::endl;
 std::vector<double> syst_Method[100];
 std::ifstream FileSyst_Method (nameFileSyst_Method.c_str()); 
 
 nLine = 0;
 while(!FileSyst_Method.eof()) {
  getline(FileSyst_Method,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine == 0) {
    nLine ++;
   }
   else {
    double tempSyst;
    int iSample = 0;
    while ( line >> tempSyst ) {
     syst_Method[iSample].push_back(tempSyst);
     iSample++;
    }
    nLine ++;
   }
  }
 }
 
 
 std::cout << " ---> read systematics Stat <---- " << std::endl;
 std::vector<double> syst_Stat[100];
 std::ifstream FileSyst_Stat (nameFileSyst_Stat.c_str()); 
 
 nLine = 0;
 while(!FileSyst_Stat.eof()) {
  getline(FileSyst_Stat,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine == 0) {
    nLine ++;
   }
   else {
    double tempSyst;
    int iSample = 0;
    while ( line >> tempSyst ) {
     syst_Stat[iSample].push_back(tempSyst);
     iSample++;
    }
    nLine ++;
   }
  }
 }
 
 
 std::cout << " ---> read systematics CR Stat <---- " << std::endl;
 std::vector<double> syst_CR_Stat[100];
 std::ifstream FileSyst_CR_Stat (nameFileSyst_CR_Stat.c_str()); 
 
 nLine = 0;
 while(!FileSyst_CR_Stat.eof()) {
  getline(FileSyst_CR_Stat,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine == 0) {
    nLine ++;
   }
   else {
    double tempSyst;
    int iSample = 0;
    while ( line >> tempSyst ) {
     syst_CR_Stat[iSample].push_back(tempSyst);
     iSample++;
    }
    nLine ++;
   }
  }
 }
 
 
 std::cout << " ---> read systematics MC subtraction <---- " << std::endl;
 std::vector<double> syst_MCSub[100];
 std::ifstream FileSyst_MCSub (nameFileSyst_MCSub.c_str()); 
 
 nLine = 0;
 while(!FileSyst_MCSub.eof()) {
  getline(FileSyst_MCSub,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (nLine == 0) {
    nLine ++;
   }
   else {
    double tempSyst;
    int iSample = 0;
    while ( line >> tempSyst ) {
     syst_MCSub[iSample].push_back(tempSyst);
     iSample++;
    }
    nLine ++;
   }
  }
 }
 
 
 
 
 
 
 
 
 ///---- plot to screen ----
 
 for (int iSample = 0; iSample < nameSamples.size(); iSample++) {
  std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
  std::cout << " Sample = " <<  nameSamples.at(iSample) << std::endl;
  
  for (int iWP = 0; iWP < NumWP; iWP++) {
   std::cout << " iWP = " << iWP+1 << " :: " << std::setprecision(2) << rate[iSample].at(associationNum[iWP]) << " +/- ";
   if (rate[iSample].at(associationNum[iWP]) != 0) {
    std::cout << std::setprecision(2) << rate[iSample].at(associationNum[iWP]) * (syst[iSample].at(associationNum[iWP])-1.) << std::endl;
   }
   else {
    std::cout << std::setprecision(2) << (1.- syst[iSample].at(associationNum[iWP]))*100 << " % " << std::endl;
   }
  }
 }
 std::cout << std::endl;   std::cout << std::endl;
 std::cout << std::endl;   std::cout << std::endl;
 std::cout << std::endl;   std::cout << std::endl;
 
 
 for (int iSample = 0; iSample < nameSamples.size(); iSample++) {
  for (int iWP = 0; iWP < (2*NumWP); iWP++) {
   
   if (iWP<14) {
    std::cout << std::setprecision(-1) << std::setw(7) << x_vals_fake[associationNum[iWP]] << "    & " ;
    std::cout << std::setprecision(3) << rate[iSample].at(associationNum[iWP]) << " $\\pm$ ";
    if (rate[iSample].at(associationNum[iWP]) != 0) {
     std::cout << std::setprecision(3)  << std::setw(7) << rate[iSample].at(associationNum[iWP]) * sqrt(   (syst[iSample].at(associationNum[iWP])-1.) * (syst[iSample].at(associationNum[iWP])-1.) +  (syst_MCSub[iSample].at(associationNum[iWP])-1.) * (syst_MCSub[iSample].at(associationNum[iWP])-1.) );
     std::cout << " \\\\ " << std::endl;
    }
    else {
     std::cout << std::setprecision(3) << (1.- syst[iSample].at(associationNum[iWP]))*100 << " % "  << " \\\\ " << std::endl;
    }
   }
   else  {
    std::cout << std::setprecision(-1) << std::setw(7) << x_vals_fake[associationNum[iWP-14]] << "    & " ;
    std::cout << std::setprecision(3) << rate[iSample].at(associationNum[iWP-14]+14) << " $\\pm$ ";
    if (rate[iSample].at(associationNum[iWP-14]+14) != 0) {
     std::cout << std::setprecision(3)  << std::setw(7) << rate[iSample].at(associationNum[iWP-14]+14) * sqrt(   (syst[iSample].at(associationNum[iWP-14]+14)-1.) * (syst[iSample].at(associationNum[iWP-14]+14)-1.) +  (syst_MCSub[iSample].at(associationNum[iWP-14]+14)-1.) * (syst_MCSub[iSample].at(associationNum[iWP-14]+14)-1.) );
     std::cout << " \\\\ " << std::endl;
    }
    else {
     std::cout << std::setprecision(3) << (1.- syst[iSample].at(associationNum[iWP-14]+14))*100 << " % "  << " \\\\ " << std::endl;
    }
    
    
   }
  }
   
 }
 
 
 std::cout << std::endl;
 std::cout << std::endl;
 
 
 
 
 
 
 
 std::cout << std::endl;   std::cout << std::endl;
 std::cout << std::endl;   std::cout << std::endl;
 std::cout << std::endl;   std::cout << std::endl;
 
 
 for (int iSample = 0; iSample < nameSamples.size(); iSample++) {
  for (int iWP = 0; iWP < rate[iSample].size() / 2.; iWP++) {
//    for (int iWP = 0; iWP < rate[iSample].size(); iWP++) {
   std::cout << std::setprecision(-1) << std::setw(7) << x_vals_fake[associationNum[iWP]] << "    & " ;
   std::cout << std::setprecision(2)  << std::setw(7) << rate[iSample].at(associationNum[iWP]) << " $\\pm$ ";
//    std::cout << std::setprecision(2)  << std::setw(7) << rate[iSample].at(associationNum[iWP]) * (syst[iSample].at(associationNum[iWP])-1.) ;
   std::cout << std::setprecision(2)  << std::setw(7) << rate[iSample].at(associationNum[iWP]) * sqrt(   (syst[iSample].at(associationNum[iWP])-1.) * (syst[iSample].at(associationNum[iWP])-1.) +    (fabs(rate[iSample].at(associationNum[iWP]) - rate[iSample].at(associationNum[iWP]+rate[iSample].size() / 2.)) / rate[iSample].at(associationNum[iWP]) / 2.) * (fabs(rate[iSample].at(associationNum[iWP]) - rate[iSample].at(associationNum[iWP]+rate[iSample].size() / 2.)) / rate[iSample].at(associationNum[iWP]) / 2.) +     (syst_MCSub[iSample].at(associationNum[iWP])-1.) * (syst_MCSub[iSample].at(associationNum[iWP])-1.) );
   
   std::cout << "  &  ";
   std::cout << std::setprecision(2)  << std::setw(7) << rate[iSample].at(associationNum[iWP]) / syst_Stat[iSample].at(associationNum[iWP]) ;
   std::cout << "  &  ";
   std::cout << std::setprecision(2)  << std::setw(7) << (syst_CR_Stat[iSample].at(associationNum[iWP])-1.)*100.  << " \\% ";
   std::cout << "  &  ";
   std::cout << std::setprecision(2)  << std::setw(7) << (syst_Method[iSample].at(associationNum[iWP])-1.)*100. << " \\% ";
   std::cout << "  &  ";
   std::cout << std::setprecision(2)  << std::setw(7) << fabs(rate[iSample].at(associationNum[iWP]) - rate[iSample].at(associationNum[iWP]+rate[iSample].size() / 2.)) / rate[iSample].at(associationNum[iWP]) / 2. * 100. << " \\% ";
   std::cout << "  &  ";
   std::cout << std::setprecision(2)  << std::setw(7) << (syst_MCSub[iSample].at(associationNum[iWP])-1.)*100. << " \\% ";
   std::cout << " \\\\ " << std::endl;   
  }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 std::cout << std::endl;   std::cout << std::endl;
 std::cout << std::endl;   std::cout << std::endl;
 std::cout << std::endl;   std::cout << std::endl;
 
 
 for (int iSample = 0; iSample < nameSamples.size(); iSample++) {
  for (int iWP = 0; iWP < rate[iSample].size() / 2.; iWP++) {
   //    for (int iWP = 0; iWP < rate[iSample].size(); iWP++) {
    std::cout << std::setprecision(-1) << std::setw(7) << x_vals_fake[associationNum[iWP]] << "    & " ;

    std::cout << std::setprecision(2)  << std::setw(7) << rate[iSample].at(associationNum[iWP]) / syst_Stat[iSample].at(associationNum[iWP]) ;
    std::cout << "  &  ";
    std::cout << std::setprecision(2)  << std::setw(7) << (syst_CR_Stat[iSample].at(associationNum[iWP])-1.)*100.  << " \\% ";
    std::cout << "  &  ";
    std::cout << std::setprecision(2)  << std::setw(7) << (syst_Method[iSample].at(associationNum[iWP])-1.)*100. << " \\% ";
    std::cout << "  &  ";
    std::cout << std::setprecision(2)  << std::setw(7) << fabs(rate[iSample].at(associationNum[iWP]) - rate[iSample].at(associationNum[iWP]+rate[iSample].size() / 2.)) / rate[iSample].at(associationNum[iWP]) / 2. * 100. << " \\% ";
    std::cout << "  &  ";
    std::cout << std::setprecision(2)  << std::setw(7) << (syst_MCSub[iSample].at(associationNum[iWP])-1.)*100. << " \\% ";
    std::cout << " \\\\ " << std::endl;   
   }
  }*/
  
  
  
 
  
 std::cout << std::endl;   std::cout << std::endl;
 std::cout << std::endl;   std::cout << std::endl;
 std::cout << std::endl;   std::cout << std::endl;
 
 gApplication->Terminate(0);
 
}






