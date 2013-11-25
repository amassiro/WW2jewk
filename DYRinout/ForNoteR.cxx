// 
// Write the Ree and Rmumu with their errors
// 

{
 std::string nameFileR = "test/Latinos12/DYRinout/result-R.txt";
 
 std::cout << "cat " << nameFileR << std::endl;
 
 #include <iomanip>
 
 ///--------------------------------------------------------------
 
 std::cout << " ---> read rate <---- " << std::endl;
 Double_t x_vals[40] = {110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 170, 180, 190, 200, 250, 300, 350, 400, 450, 500, 550, 600, 700, 800, 900, 1000, -1, -1};
 
 double Ree[100];
 double errRee[100];
 double errSystRee[100];
 double Rmumu[100];
 double errRmumu[100];
 double errSystRmumu[100];
 
 int nMass = 28;
 
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
 
 
 
 
 
 ///---- plot to screen ----
 
 
 std::cout << std::endl;
 std::cout << std::endl;
 
 std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
 
 
 
 for (int iWP = 0; iWP < nMass; iWP++) {
  std::cout << std::setprecision(-1) << std::setw(7) << x_vals[iWP] << "    & " ;
  
  std::cout << std::setprecision(3) << std::setw(7) << Rmumu[iWP] << " $\\pm$ ";
  std::cout << std::setprecision(3) << std::setw(7) << errRmumu[iWP] << " $\\pm$ ";
  std::cout << std::setprecision(2) << std::setw(7) << fabs(errSystRmumu[iWP])*Rmumu[iWP] << " & ";
//   std::cout << std::setprecision(2) << std::setw(7) << fabs(errSystRmumu[iWP])*100. << " %   & ";
  
  std::cout << std::setprecision(3) << std::setw(7) << Ree[iWP] << " $\\pm$ ";
  std::cout << std::setprecision(3) << std::setw(7) << errRee[iWP] << " $\\pm$ ";
  std::cout << std::setprecision(2) << std::setw(7) << fabs(errSystRee[iWP])*Ree[iWP] << "  ";
//   std::cout << std::setprecision(2) << std::setw(7) << fabs(errSystRee[iWP])*100. << " % ";
  
  std::cout << " \\\\ " << std::endl;
  
 }
 
 
 std::cout << std::endl;
 std::cout << std::endl;
 
 
 gApplication->Terminate(0);
 
}






