// 
// Write expected number of events in the format
//    number +/- error
// 

{
 
 #include <iomanip>
 
 std::string buffer;
 int iLine =0; 
 
 
 int nMass = 28;
 Double_t x_vals[40] = {110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 170, 180, 190, 200, 250, 300, 350, 400, 450, 500, 550, 600, 700, 800, 900, 1000, -1, -1};
 
 
 
 ///--------------------------------------------------------------
 
 std::cout << " ---> read <---- " << std::endl;
 

 
 ///----  
 ///----     __ \ \ \   / 
 ///----    |   | \   /  
 ///----    |   |    |   
 ///----   ____/    _|   
 ///----                 
 
 std::string nameFileR = "test/Latinos12/DYRinout/result-R.txt";
 
 std::cout << "cat " << nameFileR << std::endl;
 
 double Ree[100];
 double errRee[100];
 double errSystRee[100];
 double Rmumu[100];
 double errRmumu[100];
 double errSystRmumu[100];
 
 std::ifstream FileRate (nameFileR.c_str()); 
 iLine = 0;
 while(!FileRate.eof()) {
  getline(FileRate,buffer);
  std::stringstream line( buffer );      
  if (buffer != ""  && buffer.at(0) != '#') {
   if (iLine == 0) {
    iLine ++;
   }
   else {
    double tempRate;
    
    line >> tempRate;     
    Rmumu[iLine-1] = tempRate;
    line >> tempRate;     
    errRmumu[iLine-1] = tempRate;
    line >> tempRate;     
    errSystRmumu[iLine-1] = tempRate;
    line >> tempRate;     
    Ree[iLine-1] = tempRate;
    line >> tempRate;     
    errRee[iLine-1] = tempRate;
    line >> tempRate;     
    errSystRee[iLine-1] = tempRate;
    
    iLine ++;
   }
  }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 std::vector<double> SystDY;
 
 std::cout << " DY mm " << std::endl;
 
 ///----                          
 ///----     __ `__ \   __ `__ \  
 ///----     |   |   |  |   |   | 
 ///----    _|  _|  _| _|  _|  _| 
 ///----                         
 
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 std::ifstream FileSystDY_method_mumu ("test/Latinos12/DYRinout/result-syst-method-mumu.txt"); 
 std::vector<double> SystDY_method_mumu;
 
 iLine =0; 
 while(!FileSystDY_method_mumu.eof()) {
  getline(FileSystDY_method_mumu,buffer);
  std::stringstream line( buffer );      
  if (iLine != 0){
   if (buffer != ""  && buffer.at(0) != '#') {
    
    double tempValueDY;
    line >> tempValueDY;
    SystDY_method_mumu.push_back(tempValueDY);
   }
  }
  iLine++;
 } 
 
 
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 std::ifstream FileSystDY_stat_mumu ("test/Latinos12/DYRinout/result-syst-stat-mumu.txt"); 
 std::vector<double> SystDY_stat_mumu;
 
 iLine =0; 
 while(!FileSystDY_stat_mumu.eof()) {
  getline(FileSystDY_stat_mumu,buffer);
  std::stringstream line( buffer );      
  if (iLine != 0){
   if (buffer != ""  && buffer.at(0) != '#') {
    
    double tempValueDY;
    line >> tempValueDY;
    SystDY_stat_mumu.push_back(tempValueDY);
   }
  }
  iLine++;
 } 
 
 
 
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 std::ifstream FileSystDYValueDY_mumu ("test/Latinos12/DYRinout/result-value-mumu.txt"); 
 std::vector<double> ValueDY_mumu;
 
 iLine =0; 
 while(!FileSystDYValueDY_mumu.eof()) {
  getline(FileSystDYValueDY_mumu,buffer);
  std::stringstream line( buffer );      
  if (iLine != 0){
   if (buffer != ""  && buffer.at(0) != '#') {
    
    double tempValueDY;
    line >> tempValueDY;
    ValueDY_mumu.push_back(tempValueDY);
   }
  }
  iLine++;
 }
 
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
 for (int iMass = 0; iMass<nMass; iMass++) {
  double SR_B  = ValueDY_mumu.at(iMass) / SystDY_stat_mumu.at(iMass) ;
  double alpha = SystDY_stat_mumu.at(iMass);
  double err_alpha = (SystDY_method_mumu.at(iMass) - 1.000) * alpha;

  double value = ValueDY_mumu.at(iMass);
  double error = sqrt(err_alpha/alpha*value*err_alpha/alpha*value + value*value/SR_B);
  
  std::cout << "   "     << std::setprecision(-1) << std::setw (5) << x_vals[iMass] ;
  std::cout << " & "     << std::setprecision(3)  << std::setw (7) << Rmumu[iMass] ;
  std::cout << " $\\pm$ "<< std::setprecision(1)  << std::setw (7) << errRmumu[iMass] ;
  std::cout << " $\\pm$ "<< std::setprecision(1)  << std::setw (7) << fabs(errSystRmumu[iMass]) * Rmumu[iMass];
  std::cout << " & "     << std::setprecision(-1) << std::setw (7) << int(SR_B+0.1);
  std::cout << " & "     << std::setprecision(3)  << std::setw (7) << value ;
  std::cout << " $\\pm$ "<< std::setprecision(3)  << std::setw (7) << error ;
  std::cout << " \\\\ " ;
  std::cout << std::endl;
 }
 
 
 
 std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 
 for (int iMass = 0; iMass<nMass; iMass++) {
  double SR_B  = ValueDY_mumu.at(iMass) / SystDY_stat_mumu.at(iMass) ;
  double alpha = SystDY_stat_mumu.at(iMass);
  double err_alpha = (SystDY_method_mumu.at(iMass) - 1.000) * alpha;
  
  double value = ValueDY_mumu.at(iMass);
  double error = sqrt(err_alpha/alpha*value*err_alpha/alpha*value + value*value/SR_B);
  
  std::cout << "   "     << std::setprecision(-1) << std::setw (5) << x_vals[iMass] ;
  std::cout << " & "     << std::setprecision(-1) << std::setw (7) << int(SR_B+0.1);
  std::cout << " & "     << std::setprecision(3)  << std::setw (7) << Rmumu[iMass] ;
  std::cout << " $\\pm$ "<< std::setprecision(2)  << std::setw (7) << errRmumu[iMass] ;
  std::cout << " $\\pm$ "<< std::setprecision(2)  << std::setw (7) << fabs(errSystRmumu[iMass]) * Rmumu[iMass];
  std::cout << " & "     << std::setprecision(3)  << std::setw (7) << value ;
  std::cout << " $\\pm$ "<< std::setprecision(3)  << std::setw (7) << error ;
  std::cout << " \\\\ " ;
  std::cout << std::endl;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 ///----                   
 ///----        _ \   _ \ 
 ///----        __/   __/ 
 ///----      \___| \___| 
 ///----                  
 
 
 std::cout << " DY ee " << std::endl;
 
 
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 std::ifstream FileSystDY_method_ee ("test/Latinos12/DYRinout/result-syst-method-ee.txt"); 
 std::vector<double> SystDY_method_ee;
 
 iLine =0; 
 while(!FileSystDY_method_ee.eof()) {
  getline(FileSystDY_method_ee,buffer);
  std::stringstream line( buffer );      
  if (iLine != 0){
   if (buffer != ""  && buffer.at(0) != '#') {
    
    double tempValueDY;
    line >> tempValueDY;
    SystDY_method_ee.push_back(tempValueDY);
   }
  }
  iLine++;
 } 
 
 
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 std::ifstream FileSystDY_stat_ee ("test/Latinos12/DYRinout/result-syst-stat-ee.txt"); 
 std::vector<double> SystDY_stat_ee;
 
 iLine =0; 
 while(!FileSystDY_stat_ee.eof()) {
  getline(FileSystDY_stat_ee,buffer);
  std::stringstream line( buffer );      
  if (iLine != 0){
   if (buffer != ""  && buffer.at(0) != '#') {
    
    double tempValueDY;
    line >> tempValueDY;
    SystDY_stat_ee.push_back(tempValueDY);
   }
  }
  iLine++;
 } 
 
 
 
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 std::ifstream FileSystDYValueDY_ee ("test/Latinos12/DYRinout/result-value-ee.txt"); 
 std::vector<double> ValueDY_ee;
 
 iLine =0; 
 while(!FileSystDYValueDY_ee.eof()) {
  getline(FileSystDYValueDY_ee,buffer);
  std::stringstream line( buffer );      
  if (iLine != 0){
   if (buffer != ""  && buffer.at(0) != '#') {
    
    double tempValueDY;
    line >> tempValueDY;
    ValueDY_ee.push_back(tempValueDY);
   }
  }
  iLine++;
 }
 
 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
 for (int iMass = 0; iMass<nMass; iMass++) {
  double SR_B  = ValueDY_ee.at(iMass) / SystDY_stat_ee.at(iMass) ;
  double alpha = SystDY_stat_ee.at(iMass);
  double err_alpha = (SystDY_method_ee.at(iMass) - 1.000) * alpha;
  
  double value = ValueDY_ee.at(iMass);
  double error = sqrt(err_alpha/alpha*value*err_alpha/alpha*value + value*value/SR_B);
  
  std::cout << "   "     << std::setprecision(-1) << std::setw (5) << x_vals[iMass] ;
  std::cout << " & "     << std::setprecision(3)  << std::setw (7) << Ree[iMass] ;
  std::cout << " $\\pm$ "<< std::setprecision(1)  << std::setw (7) << errRee[iMass] ;
  std::cout << " $\\pm$ "<< std::setprecision(1)  << std::setw (7) << fabs(errSystRee[iMass]) * Ree[iMass] ;
  std::cout << " & "     << std::setprecision(-1) << std::setw (7) << int(SR_B+0.1);
  std::cout << " & "     << std::setprecision(3)  << std::setw (7) << value ;
  std::cout << " $\\pm$ "<< std::setprecision(3)  << std::setw (7) << error ;
  std::cout << " \\\\ " ;
  std::cout << std::endl;
 }
 
 std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 
 
 for (int iMass = 0; iMass<nMass; iMass++) {
  double SR_B  = ValueDY_ee.at(iMass) / SystDY_stat_ee.at(iMass) ;
  double alpha = SystDY_stat_ee.at(iMass);
  double err_alpha = (SystDY_method_ee.at(iMass) - 1.000) * alpha;
  
  double value = ValueDY_ee.at(iMass);
  double error = sqrt(err_alpha/alpha*value*err_alpha/alpha*value + value*value/SR_B);
  
  std::cout << "   "     << std::setprecision(-1) << std::setw (5) << x_vals[iMass] ;
  std::cout << " & "     << std::setprecision(-1) << std::setw (7) << int(SR_B+0.1);
  std::cout << " & "     << std::setprecision(3)  << std::setw (7) << Ree[iMass] ;
  std::cout << " $\\pm$ "<< std::setprecision(2)  << std::setw (7) << errRee[iMass] ;
  std::cout << " $\\pm$ "<< std::setprecision(2)  << std::setw (7) << fabs(errSystRee[iMass]) * Ree[iMass] ;
  std::cout << " & "     << std::setprecision(3)  << std::setw (7) << value ;
  std::cout << " $\\pm$ "<< std::setprecision(3)  << std::setw (7) << error ;
  std::cout << " & "     << std::setprecision(3)  << std::setw (7) << alpha ;
  std::cout << " $\\pm$ "<< std::setprecision(2)  << std::setw (7) << err_alpha ;
  
  std::cout << " \\\\ " ;
  
  std::cout << std::endl;
 }
 
  
  
  ///----                                                        
  ///----       __ `__ \   __ `__ \         |         _ \   _ \ 
  ///----       |   |   |  |   |   |     _   _|       __/   __/ 
  ///----      _|  _|  _| _|  _|  _|       _|       \___| \___| 
  ///----                                        
  
 
 
 for (int iMass = 0; iMass<nMass; iMass++) {
//   double SR_B  = ValueDY_ee.at(iMass) / SystDY_stat_ee.at(iMass) + ValueDY_mumu.at(iMass) / SystDY_stat_mumu.at(iMass);
//   double SR_A  = ValueDY_ee.at(iMass) + ValueDY_mumu.at(iMass);
//   double alpha = SR_A / SR_B;
//   
//   double alpha_ee   = SystDY_stat_ee.at(iMass);
//   double alpha_mumu = SystDY_stat_mumu.at(iMass);  
//   double err_alpha_ee   = (SystDY_method_ee.at(iMass)   - 1.000) * alpha_ee;
//   double err_alpha_mumu = (SystDY_method_mumu.at(iMass) - 1.000) * alpha_mumu;
//   
//   
//   double err_alpha = sqrt( err_alpha_ee*err_alpha_ee + err_alpha_mumu*err_alpha_mumu ); 
//   myfileDY << x_vals[iMass] << "   " << int(SR_B+0.1)  << "   " << alpha << "   " << err_alpha << std::endl;
 }
 
  
  
 std::cout << std::endl;   std::cout << std::endl;
 std::cout << std::endl;   std::cout << std::endl;
 std::cout << std::endl;   std::cout << std::endl;
 
 gApplication->Terminate(0);
 
}






