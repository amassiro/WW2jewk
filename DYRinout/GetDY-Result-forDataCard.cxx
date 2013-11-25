#include <iomanip>


void GetDY_Result_forDataCard(TString nameInFileRoot, int WorkingPoint = 1, int WorkingPointForK = 19, std::string endName = ""){
 
//  int masses[1000] = {110, 115, 120, 130, 140, 150, 160, 170, 180, 190, 200, 250, 300, 350, 400, 450, 500, 550, 600};
 int masses[1000] = {110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 170, 180, 190, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
 
 std::cout << " ~~~~~~~~~~~~~ " << std::endl;
 std::cout << " nameInFileRoot   = " << nameInFileRoot.Data() << std::endl;
 std::cout << " WorkingPoint     = " << WorkingPoint          << std::endl;
 std::cout << " WorkingPointForK = " << WorkingPointForK      << std::endl;
 std::cout << " ~~~~~~~~~~~~~ " << std::endl;
 
 ///---- for shapeanalysis datacard (begin) ----
//  double B_mm;
//  double Rinout_mm;
//  double errRelativeRinout_mm;
//  double B_ee;
//  double Rinout_ee;
//  double errRelativeRinout_ee;
//  double B_ll;
//  double Rinout_ll;
//  double errRelativeRinout_ll;
// 
//  double Bprime_mm;
//  double Rprimeinout_mm;
//  double errRelativeRprimeinout_mm;
//  double Bprime_ee;
//  double Rprimeinout_ee;
//  double errRelativeRprimeinout_ee;
//  double Bprime_ll;
//  double Rprimeinout_ll;
//  double errRelativeRprimeinout_ll;
 ///---- for shapeanalysis datacard (end) ----
 
TFile* fileIn = new TFile(nameInFileRoot);
 
 double Nee_ZVsub_Result;
 double Nmumu_ZVsub_Result;
 double errNee_ZVsub_Result;
 double errNmumu_ZVsub_Result;
 
 double Nee_Result;
 double Nmumu_Result;
 double errNee_Result;
 double errNmumu_Result;
 
 
 
 double Nee_CR_A;
 double Nee_CR_B;
 double Nee_SR_A;
 double Nee_SR_B;
 
 double Nmumu_CR_A;
 double Nmumu_CR_B;
 double Nmumu_SR_A;
 double Nmumu_SR_B;
 
 double Nemu_CR_A;
 double Nemu_CR_B;
 double Nemu_SR_A;
 double Nemu_SR_B;
 
 double Nmue_CR_A;
 double Nmue_CR_B;
 double Nmue_SR_A;
 double Nmue_SR_B;
 
 
 double errNee_CR_A;
 double errNee_CR_B;
 double errNee_SR_A;
 double errNee_SR_B;
 
 double errNmumu_CR_A;
 double errNmumu_CR_B;
 double errNmumu_SR_A;
 double errNmumu_SR_B;
 
 double errNemu_CR_A;
 double errNemu_CR_B;
 double errNemu_SR_A;
 double errNemu_SR_B;
 
 double errNmue_CR_A;
 double errNmue_CR_B;
 double errNmue_SR_A;
 double errNmue_SR_B;
 
 
 
 
 double Nee_CR_RHP_A;
 double Nee_CR_RHP_B;
 double Nee_SR_RHP_A;
 double Nee_SR_RHP_B;
 
 double Nmumu_CR_RHP_A;
 double Nmumu_CR_RHP_B;
 double Nmumu_SR_RHP_A;
 double Nmumu_SR_RHP_B;
 
 double Nemu_CR_RHP_A;
 double Nemu_CR_RHP_B;
 double Nemu_SR_RHP_A;
 double Nemu_SR_RHP_B;
 
 double Nmue_CR_RHP_A;
 double Nmue_CR_RHP_B;
 double Nmue_SR_RHP_A;
 double Nmue_SR_RHP_B;
 
 
 double errNee_CR_RHP_A;
 double errNee_CR_RHP_B;
 double errNee_SR_RHP_A;
 double errNee_SR_RHP_B;
 
 double errNmumu_CR_RHP_A;
 double errNmumu_CR_RHP_B;
 double errNmumu_SR_RHP_A;
 double errNmumu_SR_RHP_B;
 
 double errNemu_CR_RHP_A;
 double errNemu_CR_RHP_B;
 double errNemu_SR_RHP_A;
 double errNemu_SR_RHP_B;
 
 double errNmue_CR_RHP_A;
 double errNmue_CR_RHP_B;
 double errNmue_SR_RHP_A;
 double errNmue_SR_RHP_B;
 
 double Nee_SR_A_DYee;
 double Nee_SR_B_DYee;
 double Nee_CR_A_DYee;
 double Nee_CR_B_DYee;
 
 double Nmumu_SR_A_DYmumu;
 double Nmumu_SR_B_DYmumu;
 double Nmumu_CR_A_DYmumu;
 double Nmumu_CR_B_DYmumu;
 
 double errNee_SR_A_DYee;
 double errNee_SR_B_DYee;
 double errNee_CR_A_DYee;
 double errNee_CR_B_DYee;
 
 double errNmumu_SR_A_DYmumu;
 double errNmumu_SR_B_DYmumu;
 double errNmumu_CR_A_DYmumu;
 double errNmumu_CR_B_DYmumu;
 
 
 
 
 
 double Nee_SR_A_DYtautau;
 double Nmumu_SR_A_DYtautau;
 double Nemu_SR_A_DYtautau;
 
 double errNee_SR_A_DYtautau;
 double errNmumu_SR_A_DYtautau;
 double errNemu_SR_A_DYtautau;
 
 
 
 
 double Nee_CR_A_ZV;
 double Nmumu_CR_A_ZV;
 double Nemu_CR_A_ZV;
 double Nmue_CR_A_ZV;
 double Nee_CR_B_ZV;
 double Nmumu_CR_B_ZV;
 double Nemu_CR_B_ZV;
 double Nmue_CR_B_ZV;
 
 double errNee_CR_A_ZV;
 double errNmumu_CR_A_ZV;
 double errNemu_CR_A_ZV;
 double errNmue_CR_A_ZV;
 double errNee_CR_B_ZV;
 double errNmumu_CR_B_ZV;
 double errNemu_CR_B_ZV;
 double errNmue_CR_B_ZV;
 
 double Nee_SR_B_ZV;
 double Nmumu_SR_B_ZV;
 double Nemu_SR_B_ZV;
 double Nmue_SR_B_ZV;
 
 double errNee_SR_B_ZV;
 double errNmumu_SR_B_ZV;
 double errNemu_SR_B_ZV;
 double errNmue_SR_B_ZV;
 
 
 
 
 
 double Nee_CR_RHP_A_ZV;
 double Nmumu_CR_RHP_A_ZV;
 double Nemu_CR_RHP_A_ZV;
 double Nmue_CR_RHP_A_ZV;
 double Nee_CR_RHP_B_ZV;
 double Nmumu_CR_RHP_B_ZV;
 double Nemu_CR_RHP_B_ZV;
 double Nmue_CR_RHP_B_ZV;
 
 double errNee_CR_RHP_A_ZV;
 double errNmumu_CR_RHP_A_ZV;
 double errNemu_CR_RHP_A_ZV;
 double errNmue_CR_RHP_A_ZV;
 double errNee_CR_RHP_B_ZV;
 double errNmumu_CR_RHP_B_ZV;
 double errNemu_CR_RHP_B_ZV;
 double errNmue_CR_RHP_B_ZV;
 
 double Nee_SR_RHP_B_ZV;
 double Nmumu_SR_RHP_B_ZV;
 double Nemu_SR_RHP_B_ZV;
 double Nmue_SR_RHP_B_ZV;
 
 double errNee_SR_RHP_B_ZV;
 double errNmumu_SR_RHP_B_ZV;
 double errNemu_SR_RHP_B_ZV;
 double errNmue_SR_RHP_B_ZV;
 
 
 ///---- for k ----
 double kB_em;
 double err_kB_em;
 double kB_me;
 double err_kB_me;
 
 double kA_em;
 double err_kA_em;
 double kA_me;
 double err_kA_me;
 
 
 double DATA_NeeA_forK;
 double DATA_NeeB_forK;
 double DATA_NmumuA_forK;
 double DATA_NmumuB_forK;
 
 double DATA_errNeeA_forK;
 double DATA_errNeeB_forK;
 double DATA_errNmumuA_forK;
 double DATA_errNmumuB_forK;
 
 
 ///=====================
 
 TString nameHistoInRootFile;
 TH1F* h; 
 
 ///==== MC ==== 
 
 nameHistoInRootFile = Form("Data/DYtautau_%d_0_Tot_temp",2+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_A_DYtautau    = h->GetBinContent(2);
 errNee_SR_A_DYtautau = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYtautau_%d_1_Tot_temp",2+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_A_DYtautau     = h->GetBinContent(2);
 errNmumu_SR_A_DYtautau  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYtautau_%d_2_Tot_temp",2+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_A_DYtautau      = h->GetBinContent(2);
 errNemu_SR_A_DYtautau   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYtautau_%d_3_Tot_temp",2+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_A_DYtautau      += h->GetBinContent(2);
 errNemu_SR_A_DYtautau   = sqrt (errNemu_SR_A_DYtautau*errNemu_SR_A_DYtautau + h->GetBinError(2) * h->GetBinError(2)); 
 
 
 
 nameHistoInRootFile = Form("Data/ZV_%d_0_Tot_temp",0+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_A_ZV    = h->GetBinContent(2);
 errNee_CR_A_ZV = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_1_Tot_temp",0+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_A_ZV     = h->GetBinContent(2);
 errNmumu_CR_A_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_2_Tot_temp",0+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_CR_A_ZV     = h->GetBinContent(2);
 errNemu_CR_A_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_3_Tot_temp",0+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_CR_A_ZV     = h->GetBinContent(2);
 errNmue_CR_A_ZV  = h->GetBinError(2);
 
 
 nameHistoInRootFile = Form("Data/ZV_%d_0_Tot_temp",1+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_B_ZV    = h->GetBinContent(2);
 errNee_CR_B_ZV = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_1_Tot_temp",1+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_B_ZV     = h->GetBinContent(2);
 errNmumu_CR_B_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_2_Tot_temp",1+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_CR_B_ZV     = h->GetBinContent(2);
 errNemu_CR_B_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_3_Tot_temp",1+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_CR_B_ZV     = h->GetBinContent(2);
 errNmue_CR_B_ZV  = h->GetBinError(2);
 
 
 nameHistoInRootFile = Form("Data/ZV_%d_0_Tot_temp",3+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_B_ZV    = h->GetBinContent(2);
 errNee_SR_B_ZV = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_1_Tot_temp",3+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_B_ZV     = h->GetBinContent(2);
 errNmumu_SR_B_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_2_Tot_temp",3+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_B_ZV     = h->GetBinContent(2);
 errNemu_SR_B_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_3_Tot_temp",3+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_SR_B_ZV     = h->GetBinContent(2);
 errNmue_SR_B_ZV  = h->GetBinError(2);
 
 
 
 
 
 //~~~ DYee ~~~
 
 nameHistoInRootFile = Form("Data/DYee_%d_0_Tot_temp",0+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_A_DYee    = h->GetBinContent(2);
 errNee_CR_A_DYee = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYee_%d_0_Tot_temp",1+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_B_DYee    = h->GetBinContent(2);
 errNee_CR_B_DYee = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYee_%d_0_Tot_temp",3+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_B_DYee    = h->GetBinContent(2);
 errNee_SR_B_DYee = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYee_%d_0_Tot_temp",2+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_A_DYee    = h->GetBinContent(2);
 errNee_SR_A_DYee = h->GetBinError(2);
 
  
 
 
 //~~~ DYmumu ~~~
 
 nameHistoInRootFile = Form("Data/DYmumu_%d_1_Tot_temp",0+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_A_DYmumu     = h->GetBinContent(2);
 errNmumu_CR_A_DYmumu  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYmumu_%d_1_Tot_temp",1+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_B_DYmumu     = h->GetBinContent(2);
 errNmumu_CR_B_DYmumu  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYmumu_%d_1_Tot_temp",3+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_B_DYmumu     = h->GetBinContent(2);
 errNmumu_SR_B_DYmumu  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DYmumu_%d_1_Tot_temp",2+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_A_DYmumu     = h->GetBinContent(2);
 errNmumu_SR_A_DYmumu  = h->GetBinError(2);
 
 
 
 
 ///==== DATA ====
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",0+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_A    = h->GetBinContent(2);
 errNee_CR_A = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",0+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_A     = h->GetBinContent(2);
 errNmumu_CR_A  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",0+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_CR_A      = h->GetBinContent(2);
 errNemu_CR_A   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",0+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_CR_A      = h->GetBinContent(2);
 errNmue_CR_A   = h->GetBinError(2); 
 
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",1+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_B    = h->GetBinContent(2);
 errNee_CR_B = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",1+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_B     = h->GetBinContent(2);
 errNmumu_CR_B  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",1+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_CR_B      = h->GetBinContent(2);
 errNemu_CR_B   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",1+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_CR_B      = h->GetBinContent(2);
 errNmue_CR_B   = h->GetBinError(2); 
 
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",2+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_A    = h->GetBinContent(2);
 errNee_SR_A = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",2+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_A     = h->GetBinContent(2);
 errNmumu_SR_A  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",2+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_A      = h->GetBinContent(2);
 errNemu_SR_A   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",2+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_SR_A      = h->GetBinContent(2);
 errNmue_SR_A   = h->GetBinError(2); 
 
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",3+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_B    = h->GetBinContent(2);
 errNee_SR_B = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",3+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_B     = h->GetBinContent(2);
 errNmumu_SR_B  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",3+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_B      = h->GetBinContent(2);
 errNemu_SR_B   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",3+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_SR_B      = h->GetBinContent(2);
 errNmue_SR_B   = h->GetBinError(2); 
 
 
 
 
 
 
 
 ///---- for calculation of systematics due to R constance -> RHP = R-Hypothesis ----
 
 
 
 nameHistoInRootFile = Form("Data/ZV_%d_0_Tot_temp",0+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_RHP_A_ZV    = h->GetBinContent(2);
 errNee_CR_RHP_A_ZV = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_1_Tot_temp",0+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_RHP_A_ZV     = h->GetBinContent(2);
 errNmumu_CR_RHP_A_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_2_Tot_temp",0+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_CR_RHP_A_ZV     = h->GetBinContent(2);
 errNemu_CR_RHP_A_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_3_Tot_temp",0+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_CR_RHP_A_ZV     = h->GetBinContent(2);
 errNmue_CR_RHP_A_ZV  = h->GetBinError(2);
 
 
 nameHistoInRootFile = Form("Data/ZV_%d_0_Tot_temp",1+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_RHP_B_ZV    = h->GetBinContent(2);
 errNee_CR_RHP_B_ZV = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_1_Tot_temp",1+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_RHP_B_ZV     = h->GetBinContent(2);
 errNmumu_CR_RHP_B_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_2_Tot_temp",1+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_CR_RHP_B_ZV     = h->GetBinContent(2);
 errNemu_CR_RHP_B_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_3_Tot_temp",1+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_CR_RHP_B_ZV     = h->GetBinContent(2);
 errNmue_CR_RHP_B_ZV  = h->GetBinError(2);
 
 
 nameHistoInRootFile = Form("Data/ZV_%d_0_Tot_temp",3+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_RHP_B_ZV    = h->GetBinContent(2);
 errNee_SR_RHP_B_ZV = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_1_Tot_temp",3+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_RHP_B_ZV     = h->GetBinContent(2);
 errNmumu_SR_RHP_B_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_2_Tot_temp",3+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_RHP_B_ZV     = h->GetBinContent(2);
 errNemu_SR_RHP_B_ZV  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/ZV_%d_3_Tot_temp",3+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_SR_RHP_B_ZV     = h->GetBinContent(2);
 errNmue_SR_RHP_B_ZV  = h->GetBinError(2);
 
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",0+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_RHP_A    = h->GetBinContent(2);
 errNee_CR_RHP_A = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",0+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_RHP_A     = h->GetBinContent(2);
 errNmumu_CR_RHP_A  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",0+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_CR_RHP_A      = h->GetBinContent(2);
 errNemu_CR_RHP_A   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",0+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_CR_RHP_A      = h->GetBinContent(2);
 errNmue_CR_RHP_A   = h->GetBinError(2); 
 
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",1+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_CR_RHP_B    = h->GetBinContent(2);
 errNee_CR_RHP_B = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",1+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_CR_RHP_B     = h->GetBinContent(2);
 errNmumu_CR_RHP_B  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",1+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_CR_RHP_B      = h->GetBinContent(2);
 errNemu_CR_RHP_B   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",1+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_CR_RHP_B      = h->GetBinContent(2);
 errNmue_CR_RHP_B   = h->GetBinError(2); 
 
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",2+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_RHP_A    = h->GetBinContent(2);
 errNee_SR_RHP_A = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",2+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_RHP_A     = h->GetBinContent(2);
 errNmumu_SR_RHP_A  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",2+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_RHP_A      = h->GetBinContent(2);
 errNemu_SR_RHP_A   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",2+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_SR_RHP_A      = h->GetBinContent(2);
 errNmue_SR_RHP_A   = h->GetBinError(2); 
 
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",3+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nee_SR_RHP_B    = h->GetBinContent(2);
 errNee_SR_RHP_B = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",3+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmumu_SR_RHP_B     = h->GetBinContent(2);
 errNmumu_SR_RHP_B  = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_2_Tot_temp",3+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nemu_SR_RHP_B      = h->GetBinContent(2);
 errNemu_SR_RHP_B   = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_3_Tot_temp",3+4+(WorkingPoint-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 Nmue_SR_RHP_B      = h->GetBinContent(2);
 errNmue_SR_RHP_B   = h->GetBinError(2); 
 
 
 
 
 
 
 
 
 
 
 
 
 //---- for k calculation ----
 
 
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",0+(WorkingPointForK-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 DATA_NeeA_forK    = h->GetBinContent(2);
 DATA_errNeeA_forK = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",0+(WorkingPointForK-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 DATA_NmumuA_forK     = h->GetBinContent(2);
 DATA_errNmumuA_forK  = h->GetBinError(2);
 
 
 nameHistoInRootFile = Form("Data/DATA_%d_0_Tot_temp",1+(WorkingPointForK-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 DATA_NeeB_forK    = h->GetBinContent(2);
 DATA_errNeeB_forK = h->GetBinError(2);
 
 nameHistoInRootFile = Form("Data/DATA_%d_1_Tot_temp",1+(WorkingPointForK-1)*8);
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 DATA_NmumuB_forK     = h->GetBinContent(2);
 DATA_errNmumuB_forK  = h->GetBinError(2);
 
 
 
 
 
 
 
 ///==== calculate result ====
 
 
 ///==== calculate result with ZV subtraction ====
 
//  Bprime_ee = Nee_SR_B;
//  Bprime_mm = Nmumu_SR_B;
//  Bprime_ll = Nee_SR_B + Nmumu_SR_B;
 
 
 std::cout << " >>> input BEFORE ZV subtraction <<< " << std::endl;
 std::cout << " Nee_SR_B   = " << Nee_SR_B   << " +/- " << errNee_SR_B   << std::endl;
 std::cout << " Nmumu_SR_B = " << Nmumu_SR_B << " +/- " << errNmumu_SR_B << std::endl;
 std::cout << " Nemu_SR_B  = " << Nemu_SR_B  << " +/- " << errNemu_SR_B  << std::endl;
 std::cout << " Nmue_SR_B  = " << Nmue_SR_B  << " +/- " << errNmue_SR_B  << std::endl;
 
 std::cout << " Nee_CR_B   = " << Nee_CR_B   << " +/- " << errNee_CR_B   << std::endl;
 std::cout << " Nmumu_CR_B = " << Nmumu_CR_B << " +/- " << errNmumu_CR_B << std::endl;
 std::cout << " Nemu_CR_B  = " << Nemu_CR_B  << " +/- " << errNemu_CR_B  << std::endl;
 std::cout << " Nmue_CR_B  = " << Nmue_CR_B  << " +/- " << errNmue_CR_B  << std::endl;
 
 std::cout << " Nee_CR_A   = " << Nee_CR_A   << " +/- " << errNee_CR_A   << std::endl;
 std::cout << " Nmumu_CR_A = " << Nmumu_CR_A << " +/- " << errNmumu_CR_A << std::endl;
 std::cout << " Nemu_CR_A  = " << Nemu_CR_A  << " +/- " << errNemu_CR_A  << std::endl;
 std::cout << " Nmue_CR_A  = " << Nmue_CR_A  << " +/- " << errNmue_CR_A  << std::endl;
 
 
 Nee_CR_B    = Nee_CR_B   - Nee_CR_B_ZV;
 Nmumu_CR_B  = Nmumu_CR_B - Nmumu_CR_B_ZV;
 Nemu_CR_B   = Nemu_CR_B  - Nemu_CR_B_ZV;
 Nmue_CR_B   = Nmue_CR_B  - Nmue_CR_B_ZV;
 
 Nee_CR_A    = Nee_CR_A   - Nee_CR_A_ZV;
 Nmumu_CR_A  = Nmumu_CR_A - Nmumu_CR_A_ZV;
 Nemu_CR_A   = Nemu_CR_A  - Nemu_CR_A_ZV;
 Nmue_CR_A   = Nmue_CR_A  - Nmue_CR_A_ZV;
 
 Nee_SR_B    = Nee_SR_B   - Nee_SR_B_ZV;
 Nmumu_SR_B  = Nmumu_SR_B - Nmumu_SR_B_ZV;
 Nemu_SR_B   = Nemu_SR_B  - Nemu_SR_B_ZV;
 Nmue_SR_B   = Nmue_SR_B  - Nmue_SR_B_ZV;
 
 std::cout << " >>> input Corrected by ZV subtraction <<< " << std::endl;
 std::cout << " Nee_SR_B   = " << Nee_SR_B   << " +/- " << errNee_SR_B   << std::endl;
 std::cout << " Nmumu_SR_B = " << Nmumu_SR_B << " +/- " << errNmumu_SR_B << std::endl;
 std::cout << " Nemu_SR_B  = " << Nemu_SR_B  << " +/- " << errNemu_SR_B  << std::endl;
 std::cout << " Nmue_SR_B  = " << Nmue_SR_B  << " +/- " << errNmue_SR_B  << std::endl;
 
 std::cout << " Nee_CR_B   = " << Nee_CR_B   << " +/- " << errNee_CR_B   << std::endl;
 std::cout << " Nmumu_CR_B = " << Nmumu_CR_B << " +/- " << errNmumu_CR_B << std::endl;
 std::cout << " Nemu_CR_B  = " << Nemu_CR_B  << " +/- " << errNemu_CR_B  << std::endl;
 std::cout << " Nmue_CR_B  = " << Nmue_CR_B  << " +/- " << errNmue_CR_B  << std::endl;
 
 std::cout << " Nee_CR_A   = " << Nee_CR_A   << " +/- " << errNee_CR_A   << std::endl;
 std::cout << " Nmumu_CR_A = " << Nmumu_CR_A << " +/- " << errNmumu_CR_A << std::endl;
 std::cout << " Nemu_CR_A  = " << Nemu_CR_A  << " +/- " << errNemu_CR_A  << std::endl;
 std::cout << " Nmue_CR_A  = " << Nmue_CR_A  << " +/- " << errNmue_CR_A  << std::endl;
 
 //  test for ICHEP only -> low stat!!!
//  if (Nee_CR_B<=0)   { Nee_CR_B = 0.5; errNee_CR_B = 0.5; }
//  if (Nmumu_CR_B<=0) { Nmumu_CR_B = 0.5; errNmumu_CR_B = 0.5; }
 if (Nee_CR_B<0)   Nee_CR_B = 0;
 if (Nmumu_CR_B<0) Nmumu_CR_B = 0;
 if (Nemu_CR_B<0)  Nemu_CR_B = 0;
 if (Nmue_CR_B<0)  Nmue_CR_B = 0;
 
 if (Nee_CR_A<0)   Nee_CR_A = 0;
 if (Nmumu_CR_A<0) Nmumu_CR_A = 0;
 if (Nemu_CR_A<0)  Nemu_CR_A = 0;
 if (Nmue_CR_A<0)  Nmue_CR_A = 0;
 
//  test for ICHEP only -> low stat!!!
//  if (Nee_CR_A<=0)   { Nee_CR_A = 0.5; errNee_CR_A = 0.5; }
//  if (Nmumu_CR_A<=0) { Nmumu_CR_A = 0.5; errNmumu_CR_A = 0.5; }
//  if (Nemu_CR_A<=0)  Nemu_CR_A = 0;
//  if (Nmue_CR_A<=0)  Nmue_CR_A = 0;
 
 //  test for ICHEP only -> low stat!!!
//  if (Nee_SR_B<=0)   { Nee_SR_B = 0.5; errNee_SR_B = 0.5; }
//  if (Nmumu_SR_B<=0) { Nmumu_SR_B = 0.5; errNmumu_SR_B = 0.5; }
 if (Nee_SR_B<0)   Nee_SR_B = 0;
 if (Nmumu_SR_B<0) Nmumu_SR_B = 0;
 if (Nemu_SR_B<0)  Nemu_SR_B = 0;
 if (Nmue_SR_B<0)  Nmue_SR_B = 0;
 
 
 
 
 
 ///===========================================
 
 std::cout << " --- " << std::endl;
 std::cout << " DATA_NeeB_forK   = " << DATA_NeeB_forK   << std::endl;
 std::cout << " DATA_NmumuB_forK = " << DATA_NmumuB_forK << std::endl;
 std::cout << " DATA_NeeA_forK   = " << DATA_NeeA_forK   << std::endl;
 std::cout << " DATA_NmumuA_forK = " << DATA_NmumuA_forK << std::endl;
 std::cout << " --- " << std::endl;
 
 kB_em = sqrt (DATA_NeeB_forK / DATA_NmumuB_forK) ;
 err_kB_em = kB_em * 1. / 2. * sqrt(DATA_errNeeB_forK * DATA_errNeeB_forK * 1./(2. * DATA_NeeB_forK)/(2. * DATA_NeeB_forK) + DATA_errNmumuB_forK * DATA_errNmumuB_forK * 1./(2. * DATA_NmumuB_forK)/(2. * DATA_NmumuB_forK)) ;
 
 kB_me = 1. / kB_em ;
 err_kB_me = err_kB_em / kB_em / kB_em ;
 
 kA_em = sqrt (DATA_NeeA_forK / DATA_NmumuA_forK) ;
 err_kA_em = kA_em * 1. / 2. * sqrt(DATA_errNeeA_forK * DATA_errNeeA_forK * 1./(2. * DATA_NeeA_forK)/(2. * DATA_NeeA_forK) + DATA_errNmumuA_forK * DATA_errNmumuA_forK * 1./(2. * DATA_NmumuA_forK)/(2. * DATA_NmumuA_forK)) ;
 
 kA_me = 1. / kA_em ;
 err_kA_me = err_kA_em / kA_em / kA_em ;
 
 
 
 //  double k_eu = sqrt (Nee_CR_B / Nmumu_CR_B) ;
 //  double err_k_eu = sqrt (  0.25 * errNee_CR_B * errNee_CR_B / (Nee_CR_B * Nmumu_CR_B) +  0.25 * errNmumu_CR_B * errNmumu_CR_B * Nee_CR_B / (Nmumu_CR_B * Nmumu_CR_B)  ) ;
 
 double SR_B_ee = (Nee_SR_B - 0.5 * kB_em * (Nemu_SR_B + Nmue_SR_B)) ;
 double CR_A_ee = (Nee_CR_A - 0.5 * kA_em * (Nemu_CR_A + Nmue_CR_A)) ;
 double CR_B_ee = (Nee_CR_B - 0.5 * kB_em * (Nemu_CR_B + Nmue_CR_B)) ;
  
 if (SR_B_ee<0)   SR_B_ee = 0;
 if (CR_A_ee<0)   CR_A_ee = 0;
 if (CR_B_ee<0)   CR_B_ee = 0;
 
 double DY_ee_fromDATA_SR_B = SR_B_ee;
 
 Nee_Result = -1;
 if (CR_B_ee != 0) Nee_Result = SR_B_ee * CR_A_ee / CR_B_ee ;
 
 std::cout << " kB_em = " << kB_em << std::endl;
 std::cout << " kA_em = " << kA_em << std::endl;
 std::cout << " CR_A_ee = " << CR_A_ee << " = ( " << Nee_CR_A << " - 0.5 * " << kA_em << " * ( " << Nemu_CR_A << " + " << Nmue_CR_A << "))"  << std::endl;
 std::cout << " Nee_Result = " <<  Nee_Result << " = " <<  SR_B_ee << " * " << CR_A_ee << " / " << CR_B_ee << std::endl;
 
 double Esq_SR_B_ee = (errNee_SR_B * errNee_SR_B + 0.25 * err_kB_em * (Nemu_SR_B + Nmue_SR_B) * err_kB_em * (Nemu_SR_B + Nmue_SR_B) + 0.25 * kB_em * (errNemu_SR_B + errNmue_SR_B) * kB_em * (errNemu_SR_B + errNmue_SR_B)) ;
 double Esq_CR_A_ee = (errNee_CR_A * errNee_CR_A + 0.25 * err_kA_em * (Nemu_CR_A + Nmue_CR_A) * err_kA_em * (Nemu_CR_A + Nmue_CR_A) + 0.25 * kA_em * (errNemu_CR_A + errNmue_CR_A) * kA_em * (errNemu_CR_A + errNmue_CR_A)) ;
 double Esq_CR_B_ee = (errNee_CR_A * errNee_CR_B + 0.25 * err_kB_em * (Nemu_CR_B + Nmue_CR_B) * err_kB_em * (Nemu_CR_B + Nmue_CR_B) + 0.25 * kB_em * (errNemu_CR_B + errNmue_CR_B) * kB_em * (errNemu_CR_B + errNmue_CR_B)) ;
 
 errNee_Result = -1;
 if (CR_B_ee != 0) errNee_Result = sqrt (Esq_SR_B_ee * CR_A_ee/CR_B_ee*CR_A_ee/CR_B_ee + Esq_CR_A_ee * SR_B_ee/CR_B_ee*SR_B_ee/CR_B_ee + Esq_CR_B_ee * SR_B_ee*CR_A_ee/(CR_B_ee*CR_B_ee)*SR_B_ee*CR_A_ee/(CR_B_ee*CR_B_ee) ) ;
 
 
 ///---- no R error propagation : + 20% at the end added
 double Ree = CR_A_ee / CR_B_ee;
 double errRee = 0;
 if (CR_B_ee != 0) errRee = sqrt (Esq_CR_A_ee / CR_B_ee / CR_B_ee + Esq_CR_B_ee * CR_A_ee / (CR_B_ee * CR_B_ee) * CR_A_ee / (CR_B_ee * CR_B_ee)) ;
 
 
//  ///---- for shapeanalysis (begin) ----
//  B_ee = SR_B_ee;
//  Rinout_ee = CR_A_ee / CR_B_ee;
//  errRelativeRinout_ee = sqrt(Esq_CR_A_ee/CR_B_ee/CR_B_ee + Esq_CR_B_ee*CR_A_ee/CR_B_ee/CR_B_ee*CR_A_ee/CR_B_ee/CR_B_ee) / Rinout_ee ;
//  ///---- for shapeanalysis (end) ---- 
 
 
 
 double SR_B_mumu = (Nmumu_SR_B - 0.5 * kB_me * (Nemu_SR_B + Nmue_SR_B)) ;
 double CR_A_mumu = (Nmumu_CR_A - 0.5 * kA_me * (Nemu_CR_A + Nmue_CR_A)) ;
 double CR_B_mumu = (Nmumu_CR_B - 0.5 * kB_me * (Nemu_CR_B + Nmue_CR_B)) ;
 
 if (SR_B_mumu<0)   SR_B_mumu = 0;
 if (CR_A_mumu<0)   CR_A_mumu = 0;
 if (CR_B_mumu<0)   CR_B_mumu = 0;
 
 //  test for ICHEP only -> low stat!!!
//  if (SR_B_mumu<=0)   { SR_B_mumu = 0.5;}
//  if (CR_A_mumu<=0)   { CR_A_mumu = 0.5;}
//  if (CR_B_mumu<=0)   { CR_B_mumu = 0.5;}
 
 
 double DY_mumu_fromDATA_SR_B = SR_B_mumu;
 
 Nmumu_Result = -1;
 if (CR_B_mumu != 0) Nmumu_Result = SR_B_mumu * CR_A_mumu / CR_B_mumu ;
 
 std::cout << " kB_em = " << kB_em << std::endl;
 std::cout << " kA_em = " << kA_em << std::endl;
 std::cout << " CR_A_mumu = " << CR_A_mumu << " = ( " << Nmumu_CR_A << " - 0.5 * " << kA_em << " * ( " << Nemu_CR_A << " + " << Nmue_CR_A << "))"  << std::endl;
 std::cout << " Nmumu_Result = " <<  Nmumu_Result << " = " <<  SR_B_mumu << " * " << CR_A_mumu << " / " << CR_B_mumu << std::endl;
 
 double Esq_SR_B_mumu = (errNmumu_SR_B * errNmumu_SR_B + 0.25 * err_kB_me * (Nemu_SR_B + Nmue_SR_B) * err_kB_me * (Nemu_SR_B + Nmue_SR_B) + 0.25 * kB_me * (errNemu_SR_B + errNmue_SR_B) * kB_me * (errNemu_SR_B + errNmue_SR_B)) ;
 double Esq_CR_A_mumu = (errNmumu_CR_A * errNmumu_CR_A + 0.25 * err_kA_me * (Nemu_CR_A + Nmue_CR_A) * err_kA_me * (Nemu_CR_A + Nmue_CR_A) + 0.25 * kA_me * (errNemu_CR_A + errNmue_CR_A) * kA_me * (errNemu_CR_A + errNmue_CR_A)) ;
 double Esq_CR_B_mumu = (errNmumu_CR_A * errNmumu_CR_B + 0.25 * err_kB_me * (Nemu_CR_B + Nmue_CR_B) * err_kB_me * (Nemu_CR_B + Nmue_CR_B) + 0.25 * kB_me * (errNemu_CR_B + errNmue_CR_B) * kB_me * (errNemu_CR_B + errNmue_CR_B)) ;
 
 errNmumu_Result = -1;
 if (CR_B_mumu != 0) errNmumu_Result = sqrt (Esq_SR_B_mumu * CR_A_mumu/CR_B_mumu * CR_A_mumu/CR_B_mumu + Esq_CR_A_mumu * SR_B_mumu/CR_B_mumu*SR_B_mumu/CR_B_mumu + Esq_CR_B_mumu * SR_B_mumu*CR_A_mumu/(CR_B_mumu*CR_B_mumu)*SR_B_mumu*CR_A_mumu/(CR_B_mumu*CR_B_mumu) ) ;
 
 ///---- no R error propagation : + 20% at the end added
//  errNmumu_Result = -1;
//  if (CR_B_mumu != 0) errNmumu_Result = sqrt (Esq_SR_B_mumu * CR_A_mumu/CR_B_mumu*CR_A_mumu/CR_B_mumu ) ;
 
 double Rmumu = CR_A_mumu / CR_B_mumu;
 double errRmumu = 0;
 if (CR_B_mumu != 0) errRmumu = sqrt (Esq_CR_A_mumu / CR_B_mumu / CR_B_mumu + Esq_CR_B_mumu * CR_A_mumu / (CR_B_mumu * CR_B_mumu) * CR_A_mumu / (CR_B_mumu * CR_B_mumu)) ;
 
 
 double NmumuUnderPeak = (Nmumu_SR_B - 0.5 * kB_me * (Nemu_SR_B + Nmue_SR_B));
 double errNmumuUnderPeak = sqrt(Esq_SR_B_mumu);
 
 
//  ///---- for shapeanalysis (begin) ----
//  B_mm = SR_B_mumu;
//  Rinout_mm = CR_A_mumu / CR_B_mumu;
//  errRelativeRinout_mm = sqrt(Esq_CR_A_mumu/CR_B_mumu/CR_B_mumu + Esq_CR_B_mumu*CR_A_mumu/CR_B_mumu/CR_B_mumu*CR_A_mumu/CR_B_mumu/CR_B_mumu) / Rinout_mm;
//  ///---- for shapeanalysis (end) ---- 
 
 ///===========================================
 
 
 
 
 
 
 std::cout << " ****************************** " << std::endl;
 std::cout << std::endl;
 std::cout << " >>> input <<< " << std::endl;
 std::cout << " Nee_SR_B_ZV   = " << Nee_SR_B_ZV   << " +/- " << errNee_SR_B_ZV   << std::endl;
 std::cout << " Nmumu_SR_B_ZV = " << Nmumu_SR_B_ZV << " +/- " << errNmumu_SR_B_ZV << std::endl;
 std::cout << " Nemu_SR_B_ZV  = " << Nemu_SR_B_ZV  << " +/- " << errNemu_SR_B_ZV  << std::endl;
 std::cout << " Nmue_SR_B_ZV  = " << Nmue_SR_B_ZV  << " +/- " << errNmue_SR_B_ZV  << std::endl;
 
 std::cout << " Nee_CR_B_ZV   = " << Nee_CR_B_ZV   << " +/- " << errNee_CR_B_ZV   << std::endl;
 std::cout << " Nmumu_CR_B_ZV = " << Nmumu_CR_B_ZV << " +/- " << errNmumu_CR_B_ZV << std::endl;
 std::cout << " Nemu_CR_B_ZV  = " << Nemu_CR_B_ZV  << " +/- " << errNemu_CR_B_ZV  << std::endl;
 std::cout << " Nmue_CR_B_ZV  = " << Nmue_CR_B_ZV  << " +/- " << errNmue_CR_B_ZV  << std::endl;
 
 std::cout << " Nee_CR_A_ZV   = " << Nee_CR_A_ZV   << " +/- " << errNee_CR_A_ZV   << std::endl;
 std::cout << " Nmumu_CR_A_ZV = " << Nmumu_CR_A_ZV << " +/- " << errNmumu_CR_A_ZV << std::endl;
 std::cout << " Nemu_CR_A_ZV  = " << Nemu_CR_A_ZV  << " +/- " << errNemu_CR_A_ZV  << std::endl;
 std::cout << " Nmue_CR_A_ZV  = " << Nmue_CR_A_ZV  << " +/- " << errNmue_CR_A_ZV  << std::endl;
 
 std::cout << " >>> result <<< " << std::endl;
 std::cout << " Nee   = " << Nee_Result   << " +/- " << errNee_Result   ;
 std::cout << " ==> " << (Nee_Result==0 ?   0 : errNee_Result   / Nee_Result   ) << " == datacard ==> " << 1 + (Nee_Result==0 ?   0 : errNee_Result   / Nee_Result   ) << std::endl;
 std::cout << " Nmumu = " << Nmumu_Result << " +/- " << errNmumu_Result ;
 std::cout << " ==> " << (Nmumu_Result==0 ? 0 : errNmumu_Result / Nmumu_Result ) << " == datacard ==> " << 1 + (Nmumu_Result==0 ? 0 : errNmumu_Result / Nmumu_Result ) << std::endl;
 std::cout << " >>> total <<< " << std::endl;
 std::cout << " N     = " << Nmumu_Result + Nee_Result << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) << " ==> " << ((Nmumu_Result + Nee_Result)==0 ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << " == datacard ==> " << 1 + ((Nmumu_Result + Nee_Result)==0 ? 0 : sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result) ) << std::endl; 
 std::cout << std::endl;
 std::cout << " WorkingPoint = " << WorkingPoint << std::endl;
 
 std::cout << " ****************************** " << std::endl;
 std::cout << std::endl;
 
 
 
 
 
 ///---- variation of R between SR and CR ----
 
 ///==== calculate result with ZV subtraction ====
 Nee_CR_RHP_B    = Nee_CR_RHP_B   - Nee_CR_RHP_B_ZV;
 Nmumu_CR_RHP_B  = Nmumu_CR_RHP_B - Nmumu_CR_RHP_B_ZV;
 Nemu_CR_RHP_B   = Nemu_CR_RHP_B  - Nemu_CR_RHP_B_ZV;
 Nmue_CR_RHP_B   = Nmue_CR_RHP_B  - Nmue_CR_RHP_B_ZV;
 
 Nee_CR_RHP_A    = Nee_CR_RHP_A   - Nee_CR_RHP_A_ZV;
 Nmumu_CR_RHP_A  = Nmumu_CR_RHP_A - Nmumu_CR_RHP_A_ZV;
 Nemu_CR_RHP_A   = Nemu_CR_RHP_A  - Nemu_CR_RHP_A_ZV;
 Nmue_CR_RHP_A   = Nmue_CR_RHP_A  - Nmue_CR_RHP_A_ZV;
 
 Nee_SR_RHP_B    = Nee_SR_RHP_B   - Nee_SR_RHP_B_ZV;
 Nmumu_SR_RHP_B  = Nmumu_SR_RHP_B - Nmumu_SR_RHP_B_ZV;
 Nemu_SR_RHP_B   = Nemu_SR_RHP_B  - Nemu_SR_RHP_B_ZV;
 Nmue_SR_RHP_B   = Nmue_SR_RHP_B  - Nmue_SR_RHP_B_ZV;
 
 std::cout << " >>> input Corrected by ZV subtraction <<< " << std::endl;
 std::cout << " Nee_SR_RHP_B   = " << Nee_SR_RHP_B   << " +/- " << errNee_SR_RHP_B   << std::endl;
 std::cout << " Nmumu_SR_RHP_B = " << Nmumu_SR_RHP_B << " +/- " << errNmumu_SR_RHP_B << std::endl;
 std::cout << " Nemu_SR_RHP_B  = " << Nemu_SR_RHP_B  << " +/- " << errNemu_SR_RHP_B  << std::endl;
 std::cout << " Nmue_SR_RHP_B  = " << Nmue_SR_RHP_B  << " +/- " << errNmue_SR_RHP_B  << std::endl;
 
 std::cout << " Nee_CR_RHP_B   = " << Nee_CR_RHP_B   << " +/- " << errNee_CR_RHP_B   << std::endl;
 std::cout << " Nmumu_CR_RHP_B = " << Nmumu_CR_RHP_B << " +/- " << errNmumu_CR_RHP_B << std::endl;
 std::cout << " Nemu_CR_RHP_B  = " << Nemu_CR_RHP_B  << " +/- " << errNemu_CR_RHP_B  << std::endl;
 std::cout << " Nmue_CR_RHP_B  = " << Nmue_CR_RHP_B  << " +/- " << errNmue_CR_RHP_B  << std::endl;
 
 std::cout << " Nee_CR_RHP_A   = " << Nee_CR_RHP_A   << " +/- " << errNee_CR_RHP_A   << std::endl;
 std::cout << " Nmumu_CR_RHP_A = " << Nmumu_CR_RHP_A << " +/- " << errNmumu_CR_RHP_A << std::endl;
 std::cout << " Nemu_CR_RHP_A  = " << Nemu_CR_RHP_A  << " +/- " << errNemu_CR_RHP_A  << std::endl;
 std::cout << " Nmue_CR_RHP_A  = " << Nmue_CR_RHP_A  << " +/- " << errNmue_CR_RHP_A  << std::endl;
 
 if (Nee_CR_RHP_B<0)   Nee_CR_RHP_B = 0;
 if (Nmumu_CR_RHP_B<0) Nmumu_CR_RHP_B = 0;
 if (Nemu_CR_RHP_B<0)  Nemu_CR_RHP_B = 0;
 if (Nmue_CR_RHP_B<0)  Nmue_CR_RHP_B = 0;
 
 if (Nee_CR_RHP_A<0)   Nee_CR_RHP_A = 0;
 if (Nmumu_CR_RHP_A<0) Nmumu_CR_RHP_A = 0;
 if (Nemu_CR_RHP_A<0)  Nemu_CR_RHP_A = 0;
 if (Nmue_CR_RHP_A<0)  Nmue_CR_RHP_A = 0;
 
 if (Nee_SR_RHP_B<0)   Nee_SR_RHP_B = 0;
 if (Nmumu_SR_RHP_B<0) Nmumu_SR_RHP_B = 0;
 if (Nemu_SR_RHP_B<0)  Nemu_SR_RHP_B = 0;
 if (Nmue_SR_RHP_B<0)  Nmue_SR_RHP_B = 0;
 
 
 
 double P4_ee;
 double P4_mumu;
 
 SR_B_ee = (Nee_SR_RHP_B - 0.5 * kB_em * (Nemu_SR_RHP_B + Nmue_SR_RHP_B)) ;
 CR_A_ee = (Nee_SR_RHP_A - 0.5 * kA_em * (Nemu_SR_RHP_A + Nmue_SR_RHP_A)) ;
 CR_B_ee = (Nee_CR_RHP_B - 0.5 * kB_em * (Nemu_CR_RHP_B + Nmue_CR_RHP_B)) ;
 P4_ee = (Nee_CR_RHP_A - 0.5 * kA_em * (Nemu_CR_RHP_A + Nmue_CR_RHP_A)) ;
 
 double ee_R_variation = (SR_B_ee!=0 && CR_A_ee!=0 && CR_B_ee!=0 && P4_ee!=0) ? ( CR_A_ee / SR_B_ee - P4_ee / CR_B_ee )  /  (CR_A_ee / SR_B_ee + P4_ee / CR_B_ee) * 2 : 0;
 //  double ee_R_variation = (SR_B_ee!=0 && CR_A_ee!=0 && CR_B_ee!=0) ? ( CR_A_ee / SR_B_ee - P4_ee / CR_B_ee )  /  (CR_A_ee / SR_B_ee + P4_ee / CR_B_ee) * 2 : 0;
 //  double ee_R_variation = (SR_B_ee!=0 && CR_A_ee!=0 && CR_B_ee!=0) ? ( CR_A_ee / SR_B_ee - P4_ee / CR_B_ee )  /  (CR_A_ee / SR_B_ee) : 0;
 //  double ee_R_variation = (SR_B_ee!=0 && CR_A_ee!=0 && CR_B_ee!=0 && P4_ee!=0) ? ( CR_A_ee / SR_B_ee - P4_ee / CR_B_ee )  /  (P4_ee / CR_B_ee) : 0;
 
 SR_B_mumu = (Nmumu_SR_RHP_B - 0.5 * kB_me * (Nemu_SR_RHP_B + Nmue_SR_RHP_B)) ;
 CR_A_mumu = (Nmumu_SR_RHP_A - 0.5 * kA_me * (Nemu_SR_RHP_A + Nmue_SR_RHP_A)) ;
 CR_B_mumu = (Nmumu_CR_RHP_B - 0.5 * kB_me * (Nemu_CR_RHP_B + Nmue_CR_RHP_B)) ;
 P4_mumu = (Nmumu_CR_RHP_A - 0.5 * kA_me * (Nemu_CR_RHP_A + Nmue_CR_RHP_A)) ;
 
 double mumu_R_variation = (SR_B_mumu!=0 && CR_A_mumu!=0 && CR_B_mumu!=0 && P4_mumu!=0) ? ( CR_A_mumu / SR_B_mumu - P4_mumu / CR_B_mumu )  /  ( CR_A_mumu / SR_B_mumu + P4_mumu / CR_B_mumu) * 2 : 0;
 //  double mumu_R_variation = (SR_B_mumu!=0 && CR_A_mumu!=0 && CR_B_mumu!=0) ? ( CR_A_mumu / SR_B_mumu - P4_mumu / CR_B_mumu )  /  ( CR_A_mumu / SR_B_mumu + P4_mumu / CR_B_mumu) * 2 : 0;
 //  double mumu_R_variation = (SR_B_mumu!=0 && CR_A_mumu!=0 && CR_B_mumu!=0) ? ( CR_A_mumu / SR_B_mumu - P4_mumu / CR_B_mumu )  /  (CR_A_mumu / SR_B_mumu) : 0;
 //  double mumu_R_variation = (SR_B_mumu!=0 && CR_A_mumu!=0 && CR_B_mumu!=0 && P4_mumu!=0) ? ( CR_A_mumu / SR_B_mumu - P4_mumu / CR_B_mumu )  /  (P4_mumu / CR_B_mumu) : 0;
 
 
 ///---- half the error! ----
//  ee_R_variation   /= 2.;
//  mumu_R_variation /= 2.;
 
 
 std::cout << " **************************************************** " << std::endl;
 std::cout << " ee_R_variation   = " << ee_R_variation*100   << " % " << std::endl;
 std::cout << " mumu_R_variation = " << mumu_R_variation*100 << " % " << std::endl;
 std::cout << " **************************************************** " << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 
//  ///---- for shapeanalysis (begin) ----
//  errRelativeRinout_mm = sqrt( errRelativeRinout_mm*errRelativeRinout_mm + mumu_R_variation*mumu_R_variation );
//  errRelativeRinout_ee = sqrt( errRelativeRinout_ee*errRelativeRinout_ee + ee_R_variation*ee_R_variation     );
//  
//  B_ll = B_mm + B_ee;
//  Rinout_ll = 0.5 * (Rinout_ee + Rinout_mm);
//  errRelativeRinout_ll = 0.5 * sqrt(errRelativeRinout_mm*Rinout_mm*errRelativeRinout_mm*Rinout_mm + errRelativeRinout_ee*Rinout_ee*errRelativeRinout_ee*Rinout_ee) / Rinout_ll;
// 
//  Rprimeinout_ll = (Nmumu_Result + Nee_Result) / Bprime_ll ;
//  errRelativeRprimeinout_ll = errRelativeRinout_ll * Rinout_ll / Rprimeinout_ll;
//  Rprimeinout_ee = Nee_Result / Bprime_ee ;
//  errRelativeRprimeinout_ee = errRelativeRinout_ee * Rinout_ee / Rprimeinout_ee;
//  Rprimeinout_mm = Nmumu_Result / Bprime_mm ;
//  errRelativeRprimeinout_mm = errRelativeRinout_mm * Rinout_mm / Rprimeinout_mm; 
//  ///---- for shapeanalysis (end) ---- 
 
 double totalSyst = 0;
 
 TString nameFile;
 
 std::ofstream myfileValue_ee; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-value-ee%s.txt",endName.c_str());
 myfileValue_ee.open (nameFile.Data(),std::fstream::app);
 myfileValue_ee << Nee_Result << std::endl;
 myfileValue_ee.close();
 
 std::ofstream myfileValue_mumu; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-value-mumu%s.txt",endName.c_str());
 myfileValue_mumu.open (nameFile.Data(),std::fstream::app);
 myfileValue_mumu << Nmumu_Result << std::endl;
 myfileValue_mumu.close();
 
 nameFile = Form ("test/WW2jewk/DYRinout/result-value%s.txt",endName.c_str());
 std::ofstream myfileValue; 
 myfileValue.open (nameFile.Data(),std::fstream::app);
 myfileValue << (Nmumu_Result + Nee_Result) << std::endl;
 myfileValue.close();
 
 
 
 
 double meanRsyst = 0;
 if (ee_R_variation != 0 && mumu_R_variation != 0) meanRsyst = (ee_R_variation+mumu_R_variation)/2.;
 else if (ee_R_variation != 0)   meanRsyst = ee_R_variation;
 else if (mumu_R_variation != 0) meanRsyst = mumu_R_variation;
 
 double statErr = 0;
 if ((Nmumu_Result + Nee_Result) != 0) statErr = sqrt(errNmumu_Result*errNmumu_Result  +  errNee_Result*errNee_Result) / (Nmumu_Result + Nee_Result);
 
 
 if (Nmumu_Result != 0) totalSyst = sqrt(totalSyst*totalSyst + errNmumu_Result/Nmumu_Result*errNmumu_Result/Nmumu_Result);
 if (Nee_Result != 0)   totalSyst = sqrt(totalSyst*totalSyst + errNee_Result/Nee_Result*errNee_Result/Nee_Result);
 totalSyst = sqrt(totalSyst*totalSyst + mumu_R_variation*mumu_R_variation);
 totalSyst = sqrt(totalSyst*totalSyst + ee_R_variation*ee_R_variation);
 
 ///---- total systematics: Rvariation, statistics in CR-B, R measurement ----
 
 std::ofstream myfileSyst; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst%s.txt",endName.c_str());
 myfileSyst.open (nameFile.Data(),std::fstream::app);
 myfileSyst << (1 + totalSyst) << std::endl;
 
 myfileSyst.close();
 
 
 
 
 
 
 std::ofstream myfileSystStat_ee; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-stat-ee%s.txt",endName.c_str());
 myfileSystStat_ee.open (nameFile.Data(),std::fstream::app);
 if ((Nee_SR_B + Nee_SR_B_ZV) != 0)  myfileSystStat_ee << (Nee_Result) / (Nee_SR_B + Nee_SR_B_ZV) << std::endl; 
 else  myfileSystStat_ee << -1 << std::endl; 
 myfileSystStat_ee.close();
 
 std::ofstream myfileSystStat_mumu;
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-stat-mumu%s.txt",endName.c_str());
 myfileSystStat_mumu.open (nameFile.Data(),std::fstream::app);
 if ((Nmumu_SR_B + Nmumu_SR_B_ZV) != 0) myfileSystStat_mumu << (Nmumu_Result) / (Nmumu_SR_B + Nmumu_SR_B_ZV) << std::endl; 
 else myfileSystStat_mumu << -1 << std::endl; 
 myfileSystStat_mumu.close();
 
 
 
 std::ofstream myfileSystStat; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-stat%s.txt",endName.c_str());
 myfileSystStat.open (nameFile.Data(),std::fstream::app);
 //---- alpha factor : A/B, a sort of "effective R" ----
 //---- re-add the ZV contribution ... for correctness alpha * N = expected rate
 if ((Nmumu_Result + Nee_Result) / (Nmumu_SR_B + Nee_SR_B + Nmumu_SR_B_ZV + Nee_SR_B_ZV) != 0) myfileSystStat << (Nmumu_Result + Nee_Result) / (Nmumu_SR_B + Nee_SR_B + Nmumu_SR_B_ZV + Nee_SR_B_ZV) << std::endl;
 else myfileSystStat << -1 << std::endl; 
 myfileSystStat.close();
 
 
 
 
 
 
 
 std::ofstream myfileSystMethod_ee; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-method-ee%s.txt",endName.c_str());
 myfileSystMethod_ee.open (nameFile.Data(),std::fstream::app);
 double systMethod_ee = 0;
 if (Ree != 0) systMethod_ee = errRee/Ree;
 systMethod_ee = sqrt(systMethod_ee*systMethod_ee + ee_R_variation*ee_R_variation);
 myfileSystMethod_ee << (1. + systMethod_ee) << std::endl;
 myfileSystMethod_ee.close();
 
 std::ofstream myfileSystMethod_mumu; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-method-mumu%s.txt",endName.c_str());
 myfileSystMethod_mumu.open (nameFile.Data(),std::fstream::app);
 double systMethod_mumu = 0;
 if (Rmumu != 0) systMethod_mumu = errRmumu/Rmumu;
 systMethod_mumu = sqrt(systMethod_mumu*systMethod_mumu + mumu_R_variation*mumu_R_variation);
 myfileSystMethod_mumu << (1. + systMethod_mumu) << std::endl;
 myfileSystMethod_mumu.close();
 
 std::ofstream myfileSystMethod; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-method%s.txt",endName.c_str());
 myfileSystMethod.open (nameFile.Data(),std::fstream::app);
 double systMethod = 0;
 if (Rmumu!=0 && Ree!=0) systMethod = 0.5 * sqrt(errRmumu/Rmumu*errRmumu/Rmumu + errRee/Ree*errRee/Ree);
 systMethod = sqrt(systMethod*systMethod + meanRsyst*meanRsyst);
 myfileSystMethod << (1. + systMethod) << std::endl;
 myfileSystMethod.close();
 
 
 
 
 std::ofstream myfileSyst_ee; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-ee%s.txt",endName.c_str());
 myfileSyst_ee.open (nameFile.Data(),std::fstream::app);
 if (Nee_Result != 0) myfileSyst_ee << (1 + sqrt(   errNee_Result/Nee_Result*errNee_Result/Nee_Result + ee_R_variation*ee_R_variation   )) << std::endl;
 else myfileSyst_ee << -1 << std::endl;
 myfileSyst_ee.close();
 
 std::ofstream myfileSyst_mumu; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-mumu%s.txt",endName.c_str());
 myfileSyst_mumu.open (nameFile.Data(),std::fstream::app);
 if (Nmumu_Result != 0) myfileSyst_mumu << (1 + sqrt(   errNmumu_Result/Nmumu_Result*errNmumu_Result/Nmumu_Result + mumu_R_variation*mumu_R_variation   )) << std::endl;
 else myfileSyst_mumu << -1 << std::endl;
 myfileSyst_mumu.close();
 
 
 
 
 
 
 double SF;
 double errSF;
 
 if ((Nee_SR_A_DYee+Nmumu_SR_A_DYmumu) != 0) {
  SF = (Nmumu_Result+Nee_Result) / (Nee_SR_A_DYee+Nmumu_SR_A_DYmumu);
  errSF = sqrt( (errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) / (Nee_SR_A_DYee+Nmumu_SR_A_DYmumu) / (Nee_SR_A_DYee+Nmumu_SR_A_DYmumu) +  meanRsyst*meanRsyst*SF*SF );
 }
 else {
  SF = -1;
  errSF = -1;
 }
 
 std::ofstream myfileScaleFactor; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-SF%s.txt",endName.c_str());
 myfileScaleFactor.open (nameFile.Data(),std::fstream::app);
 myfileScaleFactor << SF << " +/- " << errSF << std::endl;
 myfileScaleFactor.close();
 
 std::cout << " ********************** " << std::endl;
 std::cout << " SF = " << SF << " = (" << (Nmumu_Result+Nee_Result);
 std::cout << " +/- " << sqrt(errNmumu_Result*errNmumu_Result+errNee_Result*errNee_Result) << " ) ";
 std::cout << " / ( " << (Nee_SR_A_DYee+Nmumu_SR_A_DYmumu) ;
 std::cout << " +/- " << sqrt(errNee_SR_A_DYee*errNee_SR_A_DYee+errNmumu_SR_A_DYmumu*errNmumu_SR_A_DYmumu) << " ) " << std::endl;
 std::cout << " ********************** " << std::endl;
 

 //---- ee ----
 double SF_ee;
 double errSF_ee;
 if ((Nee_SR_A_DYee) != 0) {
  SF_ee = (Nee_Result) / (Nee_SR_A_DYee);
  errSF_ee = sqrt( (errNee_Result) / (Nee_SR_A_DYee) * (errNee_Result) / (Nee_SR_A_DYee) + ee_R_variation*ee_R_variation*SF_ee*SF_ee );
 }
 else {
  SF_ee = -1;
  errSF_ee = -1;
 }
 
 std::ofstream myfileScaleFactor_ee; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-SF-ee%s.txt",endName.c_str());
 myfileScaleFactor_ee.open (nameFile.Data(),std::fstream::app);
 myfileScaleFactor_ee << SF_ee << " +/- " << errSF_ee << std::endl;
 myfileScaleFactor_ee.close();
 
 std::cout << " ********************** " << std::endl;
 std::cout << " SF_ee = " << SF_ee << " = (" << (Nee_Result);
 std::cout << " +/- " << errNee_Result << " ) ";
 std::cout << " / ( " << Nee_SR_A_DYee ;
 std::cout << " +/- " << errNee_SR_A_DYee << " ) " << std::endl;
 std::cout << " ********************** " << std::endl;

 //---- mumu ----
 double SF_mumu;
 double errSF_mumu;
 if ((Nmumu_SR_A_DYmumu) != 0) {
  SF_mumu = (Nmumu_Result) / (Nmumu_SR_A_DYmumu);
  errSF_mumu = sqrt( (errNmumu_Result) / (Nmumu_SR_A_DYmumu) * (errNmumu_Result) / (Nmumu_SR_A_DYmumu) + mumu_R_variation*mumu_R_variation*SF_mumu*SF_mumu );
 }
 else {
  SF_mumu = -1;
  errSF_mumu = -1;
 }
 
 std::ofstream myfileScaleFactor_mumu; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-SF-mumu%s.txt",endName.c_str());
 myfileScaleFactor_mumu.open (nameFile.Data(),std::fstream::app);
 myfileScaleFactor_mumu << SF_mumu << " +/- " << errSF_mumu << std::endl;
 myfileScaleFactor_mumu.close();
 
 std::cout << " ********************** " << std::endl;
 std::cout << " SF_mumu = " << SF_mumu << " = (" << (Nmumu_Result);
 std::cout << " +/- " << errNmumu_Result << " ) ";
 std::cout << " / ( " << Nmumu_SR_A_DYmumu ;
 std::cout << " +/- " << errNmumu_SR_A_DYmumu << " ) " << std::endl;
 std::cout << " ********************** " << std::endl;
 
 
 
 
 
 std::ofstream myfileR; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-R%s.txt",endName.c_str());
 myfileR.open (nameFile.Data(),std::fstream::app);
 myfileR << Rmumu << "  " ;
 myfileR << errRmumu << " " ;
 myfileR << mumu_R_variation << " " ;
 myfileR << "      " ;
 myfileR << Ree << " " ;
 myfileR << errRee << " " ;
 myfileR << ee_R_variation << " " ;
 myfileR << std::endl;
 myfileR.close();
 

 
 
 
 
 
 
 ///---- smurf method: 
 ///         -> using R evolution from MC
 ///         -> R variation from MC as error
 ///----
 
 std::cout << " ~~~~~~~~~~~ " << std::endl;
 
 double ReeMC;
 double errReeMC;
 double ReeMC_CR;
 double errReeMC_CR;
 double ReeMC_SR;
 double errReeMC_SR;
 
 std::cout << "Nee_CR_A_DYee = " << errNee_CR_A_DYee << " +/- " << errNee_CR_A_DYee << std::endl;
 std::cout << "Nee_CR_B_DYee = " << errNee_CR_B_DYee << " +/- " << errNee_CR_B_DYee << std::endl;
 
 std::cout << "Nee_SR_A_DYee = " << errNee_SR_A_DYee << " +/- " << errNee_SR_A_DYee << std::endl;
 std::cout << "Nee_SR_B_DYee = " << errNee_SR_B_DYee << " +/- " << errNee_SR_B_DYee << std::endl;
 
 ReeMC_CR    = (Nee_CR_B_DYee != 0) ? Nee_CR_A_DYee / Nee_CR_B_DYee : 0;
 if (Nee_CR_B_DYee != 0) errReeMC_CR = sqrt ( (errNee_CR_A_DYee / Nee_CR_B_DYee * errNee_CR_A_DYee / Nee_CR_B_DYee) + (Nee_CR_A_DYee / Nee_CR_B_DYee / Nee_CR_B_DYee * errNee_CR_B_DYee * Nee_CR_A_DYee / Nee_CR_B_DYee / Nee_CR_B_DYee * errNee_CR_B_DYee));
 else errReeMC_CR = 0;
  
 ReeMC_SR    = (Nee_SR_B_DYee != 0) ? Nee_SR_A_DYee / Nee_SR_B_DYee : 0;
 if (Nee_SR_B_DYee != 0) errReeMC_SR = sqrt ( (errNee_SR_A_DYee / Nee_SR_B_DYee * errNee_SR_A_DYee / Nee_SR_B_DYee) + (Nee_SR_A_DYee / Nee_SR_B_DYee / Nee_SR_B_DYee * errNee_SR_B_DYee * Nee_SR_A_DYee / Nee_SR_B_DYee / Nee_SR_B_DYee * errNee_SR_B_DYee));
 else errReeMC_SR = 0;
  
 if ((ReeMC_SR + ReeMC_CR) != 0)  errReeMC = fabs(ReeMC_SR - ReeMC_CR) / (ReeMC_SR + ReeMC_CR) * 2. ;
 else  errReeMC = errRee; // --- > errRee  !?!?!?
 if (ReeMC_CR != 0) ReeMC = Ree * ReeMC_SR / ReeMC_CR;
 else  ReeMC = Ree;
 
 std::cout << "ReeMC SR = " << ReeMC_SR << std::endl;
 std::cout << "ReeMC CR = " << ReeMC_CR << std::endl; 
 std::cout << "errReeMC = " << errReeMC << std::endl; 
 std::cout << "ReeMC    = " << ReeMC    << std::endl; 
 
 
 std::cout << "errRee   = " << errRee   << std::endl; 
 std::cout << "Ree      = " <<    Ree   << std::endl; 
 
 
 std::cout << " ~~~~~~~~~~~ " << std::endl;
 
 std::ofstream myfileSystMethod_ee_MC; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-method-MC-ee%s.txt",endName.c_str());
 myfileSystMethod_ee_MC.open (nameFile.Data(),std::fstream::app);
 systMethod_ee = 0;
 if (Ree != 0) systMethod_ee = errRee/Ree;
 systMethod_ee = sqrt(systMethod_ee*systMethod_ee + errReeMC*errReeMC);
 myfileSystMethod_ee_MC << (1. + systMethod_ee) << std::endl;
 myfileSystMethod_ee_MC.close();
 
 
 
 std::cout << " ~~~~~~~~~~~ " << std::endl;
 
 
 double RmumuMC;
 double errRmumuMC;
 double RmumuMC_CR;
 double errRmumuMC_CR;
 double RmumuMC_SR;
 double errRmumuMC_SR;
 
 std::cout << "Nmumu_CR_A_DYmumu = " << errNmumu_CR_A_DYmumu << " +/- " << errNmumu_CR_A_DYmumu << std::endl;
 std::cout << "Nmumu_CR_B_DYmumu = " << errNmumu_CR_B_DYmumu << " +/- " << errNmumu_CR_B_DYmumu << std::endl;
 
 std::cout << "Nmumu_SR_A_DYmumu = " << errNmumu_SR_A_DYmumu << " +/- " << errNmumu_SR_A_DYmumu << std::endl;
 std::cout << "Nmumu_SR_B_DYmumu = " << errNmumu_SR_B_DYmumu << " +/- " << errNmumu_SR_B_DYmumu << std::endl;
 
 RmumuMC_CR    = (Nmumu_CR_B_DYmumu != 0) ? Nmumu_CR_A_DYmumu / Nmumu_CR_B_DYmumu : 0;
 if (Nmumu_CR_B_DYmumu != 0) errRmumuMC_CR = sqrt ( (errNmumu_CR_A_DYmumu / Nmumu_CR_B_DYmumu * errNmumu_CR_A_DYmumu / Nmumu_CR_B_DYmumu) + (Nmumu_CR_A_DYmumu / Nmumu_CR_B_DYmumu / Nmumu_CR_B_DYmumu * errNmumu_CR_B_DYmumu * Nmumu_CR_A_DYmumu / Nmumu_CR_B_DYmumu / Nmumu_CR_B_DYmumu * errNmumu_CR_B_DYmumu));
 else errRmumuMC_CR = 0;
 
 RmumuMC_SR    = (Nmumu_SR_B_DYmumu != 0) ? Nmumu_SR_A_DYmumu / Nmumu_SR_B_DYmumu : 0;
 if (Nmumu_SR_B_DYmumu != 0) errRmumuMC_SR = sqrt ( (errNmumu_SR_A_DYmumu / Nmumu_SR_B_DYmumu * errNmumu_SR_A_DYmumu / Nmumu_SR_B_DYmumu) + (Nmumu_SR_A_DYmumu / Nmumu_SR_B_DYmumu / Nmumu_SR_B_DYmumu * errNmumu_SR_B_DYmumu * Nmumu_SR_A_DYmumu / Nmumu_SR_B_DYmumu / Nmumu_SR_B_DYmumu * errNmumu_SR_B_DYmumu));
 else errRmumuMC_SR = 0;
 
 
 
 if ((RmumuMC_SR + RmumuMC_CR) != 0)  errRmumuMC = fabs(RmumuMC_SR - RmumuMC_CR) / (RmumuMC_SR + RmumuMC_CR) * 2. ;
 else  errRmumuMC = errRmumu; // --- > errRmumu  !?!?!?
 if (RmumuMC_CR != 0) RmumuMC = Rmumu * RmumuMC_SR / RmumuMC_CR;
 else  RmumuMC = Rmumu;
 
 std::cout << "RmumuMC SR = " << RmumuMC_SR << std::endl;
 std::cout << "RmumuMC CR = " << RmumuMC_CR << std::endl; 
 std::cout << "errRmumuMC = " << errRmumuMC << std::endl; 
 std::cout << "RmumuMC    = " << RmumuMC    << std::endl; 
 
 
 std::ofstream myfileSystMethod_mumu_MC; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-method-MC-mumu%s.txt",endName.c_str());
 myfileSystMethod_mumu_MC.open (nameFile.Data(),std::fstream::app);
 systMethod_mumu = 0;
 if (Rmumu != 0) systMethod_mumu = errRmumu/Rmumu;
 systMethod_mumu = sqrt(systMethod_mumu*systMethod_mumu + errRmumuMC*errRmumuMC);
 myfileSystMethod_mumu_MC << (1. + systMethod_mumu) << std::endl;
 myfileSystMethod_mumu_MC.close();
 
 
 
 
 
 
 std::ofstream myfileSystMethod_MC; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-method-MC%s.txt",endName.c_str());
 myfileSystMethod_MC.open (nameFile.Data(),std::fstream::app);
 systMethod = 0;
 if (Rmumu!=0 && Ree!=0) systMethod = 0.5 * sqrt(errRmumu/Rmumu*errRmumu/Rmumu + errRee/Ree*errRee/Ree);
 systMethod = sqrt(systMethod*systMethod + errRmumuMC*errRmumuMC + errReeMC*errReeMC);
 myfileSystMethod_MC << (1. + systMethod) << std::endl;
 myfileSystMethod_MC.close();
 
 
 
 
 
 std::cout << " ~~~~~~~~~~~ " << std::endl;
 
 //---- new evaluation using MC scaling
 Nee_Result = DY_ee_fromDATA_SR_B * ReeMC;
 
 std::ofstream myfileSystStat_ee_MC; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-stat-MC-ee%s.txt",endName.c_str());
 myfileSystStat_ee_MC.open (nameFile.Data(),std::fstream::app);
 if ((Nee_SR_B + Nee_SR_B_ZV) != 0)  myfileSystStat_ee_MC << (Nee_Result) / (Nee_SR_B + Nee_SR_B_ZV) << std::endl; 
 else  myfileSystStat_ee_MC << -1 << std::endl; 
 myfileSystStat_ee_MC.close();

 
 //---- new evaluation using MC scaling
 Nmumu_Result = DY_mumu_fromDATA_SR_B * RmumuMC;
 
 std::ofstream myfileSystStat_mumu_MC;
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-stat-MC-mumu%s.txt",endName.c_str());
 myfileSystStat_mumu_MC.open (nameFile.Data(),std::fstream::app);
 if ((Nmumu_SR_B + Nmumu_SR_B_ZV) != 0) myfileSystStat_mumu_MC << (Nmumu_Result) / (Nmumu_SR_B + Nmumu_SR_B_ZV) << std::endl; 
 else myfileSystStat_mumu_MC << -1 << std::endl; 
 myfileSystStat_mumu_MC.close();
 
 
 
 std::ofstream myfileSystStat_MC; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-syst-stat-MC%s.txt",endName.c_str());
 myfileSystStat_MC.open (nameFile.Data(),std::fstream::app);
 //---- alpha factor : A/B, a sort of "effective R" ----
 //---- re-add the ZV contribution ... for correctness alpha * N = expected rate
 if ((Nmumu_Result + Nee_Result) / (Nmumu_SR_B + Nee_SR_B + Nmumu_SR_B_ZV + Nee_SR_B_ZV) != 0) myfileSystStat_MC << (Nmumu_Result + Nee_Result) / (Nmumu_SR_B + Nee_SR_B + Nmumu_SR_B_ZV + Nee_SR_B_ZV) << std::endl;
 else myfileSystStat_MC << -1 << std::endl; 
 myfileSystStat_MC.close();
 
 
 if ((Nee_SR_A_DYee+Nmumu_SR_A_DYmumu) != 0) {
  SF = (Nmumu_Result+Nee_Result) / (Nee_SR_A_DYee+Nmumu_SR_A_DYmumu);
  errSF = SF * sqrt(systMethod_mumu*Nmumu_Result*systMethod_mumu*Nmumu_Result + systMethod_ee*Nee_Result*systMethod_ee*Nee_Result) / (Nmumu_Result+Nee_Result);
 }
 else {
  SF = -1;
  errSF = -1;
 }
 
 std::ofstream myfileScaleFactor_MC; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-SF-MC%s.txt",endName.c_str());
 myfileScaleFactor_MC.open (nameFile.Data(),std::fstream::app);
 myfileScaleFactor_MC << SF << " +/- " << errSF << std::endl;
 myfileScaleFactor_MC.close();
 
 //---- ee ----
 if ((Nee_SR_A_DYee) != 0) {
  SF_ee = (Nee_Result) / (Nee_SR_A_DYee);
  errSF_ee = SF_ee * systMethod_ee;
 }
 else {
  SF_ee = -1;
  errSF_ee = -1;
 }
 
 std::ofstream myfileScaleFactor_ee_MC; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-SF-MC-ee%s.txt",endName.c_str());
 myfileScaleFactor_ee_MC.open (nameFile.Data(),std::fstream::app);
 myfileScaleFactor_ee_MC << SF_ee << " +/- " << errSF_ee << std::endl;
 myfileScaleFactor_ee_MC.close();
 
 std::cout << " ********************** " << std::endl;
 std::cout << " (MC) SF_ee = " << SF_ee << " = (" << (Nee_Result);
 std::cout << " +/- " << errNee_Result << " ) ";
 std::cout << " / ( " << Nee_SR_A_DYee ;
 std::cout << " +/- " << errNee_SR_A_DYee << " ) " << std::endl;
 std::cout << " ********************** " << std::endl;
 
 //---- mumu ----
 if ((Nmumu_SR_A_DYmumu) != 0) {
  SF_mumu = (Nmumu_Result) / (Nmumu_SR_A_DYmumu);
  errSF_mumu = SF_mumu * systMethod_mumu;
 }
 else {
  SF_mumu = -1;
  errSF_mumu = -1;
 }
 
 std::ofstream myfileScaleFactor_mumu_MC; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-SF-MC-mumu%s.txt",endName.c_str());
 myfileScaleFactor_mumu_MC.open (nameFile.Data(),std::fstream::app);
 myfileScaleFactor_mumu_MC << SF_mumu << " +/- " << errSF_mumu << std::endl;
 myfileScaleFactor_mumu_MC.close();
 
 
 std::cout << " ********************** " << std::endl;
 std::cout << " (MC) SF_mumu = " << SF_mumu << " = (" << (Nmumu_Result);
 std::cout << " +/- " << errNmumu_Result << " ) ";
 std::cout << " / ( " << Nmumu_SR_A_DYmumu ;
 std::cout << " +/- " << errNmumu_SR_A_DYmumu << " ) " << std::endl;
 std::cout << " ********************** " << std::endl;
 
 
 
 
 
 
 std::ofstream myfileRMC; 
 nameFile = Form ("test/WW2jewk/DYRinout/result-MC-R%s.txt",endName.c_str());
 myfileRMC.open (nameFile.Data(),std::fstream::app);
 myfileRMC << RmumuMC_CR << "  " ;
 myfileRMC << errRmumuMC_SR << " " ;
 myfileRMC << errRmumuMC << " " ;
 myfileRMC << "      " ;
 myfileRMC << ReeMC_CR << " " ;
 myfileRMC << errReeMC_SR << " " ;
 myfileRMC << errReeMC << " " ;
 myfileRMC << std::endl;
 myfileRMC.close();
 
 
 
 
 
 
 
 
 
 
 gApplication->Terminate(0);
 
}






