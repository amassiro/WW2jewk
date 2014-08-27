#include <iostream>
#include <fstream>

void AMPlotMacroCreator_Moriond() {
 
//  TString fileVar = Form("var19Nov.txt");
//  TString date    = Form("19Nov_WWewk_Moriond_forAN");
//  TString file    = Form("out_test_Latinos_19Nov2013_2300_RunABCD-WWewk.root");

//  //---- MVA ----
//  TString fileVar = Form("var20Nov.txt");
//  TString date    = Form("20Nov_WWewk_Moriond_forAN");
//  TString file    = Form("out_test_Latinos_20Nov2013_2300_RunABCD-WWewk.root");

 //  //---- MVA inputs ----
//  TString fileVar = Form("var20Feb.txt");
//  TString date    = Form("20Feb_WWewk_Moriond_forAN");
//  TString file    = Form("out_test_Latinos_22Feb2014_1200_RunABCD-WWewk.root");
 
 //  //---- MVA inputs ----
 TString fileVar = Form("var25Jul.txt");
 TString date    = Form("25Jul_WWewk_Moriond_forAN");
 TString file    = Form("out_test_Latinos_25Jul2014_1200_RunABCD-WWewk.root");
 
 
 

 //  //---- mjj/detajj optimization inputs ----
//  TString fileVar = Form("var28Feb.txt");
//  TString date    = Form("20Feb_WWewk_Moriond_forAN");
//  TString file    = Form("out_test_Latinos_28Feb2014_2300_RunABCD-WWewk.root");
 


 
 //---- test new variables ----
//  TString fileVar = Form("var26Dec.txt");
//  TString date    = Form("16Dec_WWewk_Moriond_forAN");
// // //  TString file    = Form("out_test_Latinos_16Dec2013_2300_RunABCD-WWewk.root"); --> test new kinematic variables to suppress top
//  TString file    = Form("out_test_Latinos_17Dec2013_2300_RunABCD-WWewk.root");
 
 TString hmass   = Form("125");
 TString lumi    = Form("19.468");

//  for (int iCut = 0; iCut < 9; iCut++) {
  for (int iCut = 0; iCut < 3*2; iCut++) {
//    for (int iCut = 0; iCut < 3; iCut++) {
    
//  for (int iCut = 0; iCut < (3+1)*3; iCut++) {
     
  TString CommandToExec = Form("rm -r %s_%d",date.Data(),iCut);
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("mkdir %s_%d",date.Data(),iCut);
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("cp index.php %s_%d",date.Data(),iCut);
  gSystem->Exec(CommandToExec);  
  
  
  
  //---- red file "var" ----
  std::vector<std::string> vVar_simple;
  std::vector<std::string> vVar;
  std::vector<int>         vVar_num;
  std::vector<int>         vBlindBinSx;
  std::vector<int>         vBlindBinDx;
  std::vector<double>      vCutValueSx;
  std::vector<double>      vCutValueDx;
  std::ifstream indata;
  
  indata.open(fileVar.Data());
  if(!indata) {
   std::cerr << "Error: file " << fileVar.Data() << " could not be opened" << std::endl;
   return 1;
  }
  
  std::string variable_simple;
  std::string variable;
  int variable_num;
  int blind_num_sx;
  int blind_num_dx;
  double cut_value_sx;
  double cut_value_dx;
  std::string buffer;
  
  while ( !indata.eof() ) { // keep reading until end-of-file
  getline(indata,buffer);
  if (buffer != "" && buffer.at(0) != '#' ){ ///---> save from empty line at the end!
   std::stringstream line( buffer );      
   line >> variable_simple; 
   line >> variable; 
   line >> variable_num; 
   line >> blind_num_sx;
   line >> blind_num_dx;
   line >> cut_value_sx;
   line >> cut_value_dx;
   vVar_simple.push_back(variable_simple);
   vVar.push_back(variable);
   vVar_num.push_back(variable_num);
   vBlindBinSx.push_back(blind_num_sx);
   vBlindBinDx.push_back(blind_num_dx);
   vCutValueSx.push_back(cut_value_sx);
   vCutValueDx.push_back(cut_value_dx);
  }
  }
  indata.close();
  
  
  std::cout << std::endl;
  
  for (int iVar=0; iVar<vVar_simple.size(); iVar++) {
   TString name = Form ("Plot-AM-%s-%s-%d-auto.C",vVar_simple.at(iVar).c_str(), date.Data(), iCut);
   ofstream myfile;
   myfile.open (name.Data());
   
   myfile << "#include \"TString.h\"" << std::endl;
   myfile << "#include \"TH1F.h\"" << std::endl;
   myfile << "#include \"TSystem.h\"" << std::endl;
   myfile << "#include \"TInterpreter.h\"" << std::endl;
   myfile << "#include \"TFile.h\"" << std::endl;
   myfile << std::endl;
   myfile << "  #include \"PlotVHqqHggH.C\"" << std::endl;
   myfile << std::endl;
   myfile << std::endl;
   myfile << "void Plot_AM_" << vVar_simple.at(iVar).c_str() << "_" << date.Data() << "_" << iCut << "_auto() {" << std::endl;
   myfile << " TString cutNameBefore = Form(\"Data/\");" << std::endl;
   myfile << std::endl;
   myfile << " //                            cut_variable " << std::endl;
   myfile << " TString cutNameAfter  = Form(\"_" << iCut << "_" << vVar_num.at(iVar) << "_Tot_temp\");" << std::endl;
   myfile << std::endl;  
   myfile << " gROOT->LoadMacro(\"PlotVHqqHggH.C+\");" << std::endl;   
   myfile << " gInterpreter->ExecuteMacro(\"LatinoStyle2.C\");" << std::endl;
   myfile << std::endl;  
   myfile << " TCanvas* c1 = new TCanvas(\"" <<  vVar_simple.at(iVar).c_str() << "\",\"" <<  vVar_simple.at(iVar).c_str() << "\",500,600);" << std::endl;
   myfile << " TFile* f = new TFile(\"~/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/" << file.Data() << "\");" << std::endl;
   myfile << std::endl;  
   myfile << std::endl;  
   myfile << " PlotVHqqHggH* hs = new PlotVHqqHggH();" << std::endl;
   myfile << std::endl;
   myfile << " hs->setLumi(" << lumi.Data() << ");" << std::endl;
   myfile << " hs->setLabel(\""<<  vVar.at(iVar).c_str() <<"\");" << std::endl;
   myfile << " hs->addLabel(\"    #sqrt{s} = 8 TeV\");" << std::endl;
   myfile << std::endl;
   myfile << " TString name;" << std::endl;
   myfile << std::endl;
   myfile << " std::vector<int> vectColourBkg;        " << std::endl;
   myfile << " std::vector<double> vectSystBkg;       " << std::endl;
   myfile << " std::vector<double> vectScaleBkg;      " << std::endl;
   myfile << " std::vector<std::string> vectNameBkg;  " << std::endl;
   myfile << " std::vector<double> vectNormalizationBkg; " << std::endl;
   myfile << " std::vector<TH1F*> vectTHBkg;          " << std::endl;
   myfile << std::endl;
   myfile << " std::vector<int> vectColourSig;      " << std::endl;
   myfile << " std::vector<double> vectSystSig;       " << std::endl;
   myfile << " std::vector<double> vectScaleSig;      " << std::endl;
   myfile << " std::vector<std::string> vectNameSig;  " << std::endl;
   myfile << " std::vector<double> vectNormalizationSig; " << std::endl;
   myfile << " std::vector<TH1F*> vectTHSig;          " << std::endl;
   
   myfile << std::endl;
   myfile << " ///==== signal (begin) ====" << std::endl;
   myfile << std::endl;
 
   myfile << " name = Form(\"%sWW2j%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHSig.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameSig.push_back (\"WWewk\");" << std::endl;
   myfile << " vectColourSig.push_back(633);" << std::endl;
   myfile << " vectScaleSig.push_back(1.0000);" << std::endl;
   myfile << " vectNormalizationSig.push_back(1.0000);" << std::endl;
       
   myfile << std::endl;
   myfile << " ///==== signal (end)  ====" << std::endl;
   myfile << std::endl;
   myfile << " name = Form(\"%sDATA%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " hs->setDataHist ((TH1F*)f->Get(name));" << std::endl;
   myfile << std::endl;
   myfile << std::endl;
   myfile << std::endl;
   myfile << " hs->setBlindBinSx("<< vBlindBinSx.at(iVar) << ");" << std::endl;
   myfile << " hs->setBlindBinDx("<< vBlindBinDx.at(iVar) << ");" << std::endl;
   myfile << std::endl;
   myfile << " hs->setCutSx("<< vCutValueSx.at(iVar) << ",\">\");" << std::endl;
   myfile << " hs->setCutDx("<< vCutValueDx.at(iVar) << ",\"<\");" << std::endl;
   myfile << std::endl;  
   myfile << std::endl;
   myfile << " ///==== background (begin)  ====" << std::endl;
   
   
   myfile << " name = Form(\"%sggH-"<< hmass.Data() <<"%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"H m_{H}="<< hmass.Data() <<"\");" << std::endl;
   myfile << " vectColourBkg.push_back(6);" << std::endl;
   myfile << " vectSystBkg.push_back(0.20);" << std::endl;
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   myfile << " vectNormalizationBkg.push_back(0.719);" << std::endl;

   myfile << std::endl;
   myfile << " name = Form(\"%sqqH-"<< hmass.Data() <<"%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"H m_{H}="<< hmass.Data() <<"\");" << std::endl;
   myfile << " vectColourBkg.push_back(6);" << std::endl;
   myfile << " vectSystBkg.push_back(0.20);" << std::endl;
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   myfile << " vectNormalizationBkg.push_back(0.719);" << std::endl;
   
   myfile << std::endl;
   myfile << " name = Form(\"%sWH-"<< hmass.Data() <<"%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"H m_{H}="<< hmass.Data() <<"\");" << std::endl;
   //    myfile << " vectNameBkg.push_back (\"WH m_{H}="<< hmass.Data() <<"\");" << std::endl;
   myfile << " vectColourBkg.push_back(6);" << std::endl;
   myfile << " vectSystBkg.push_back(0.20);" << std::endl;
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   myfile << " vectNormalizationBkg.push_back(0.018);" << std::endl;
   
   myfile << std::endl;
   myfile << " name = Form(\"%sZH-"<< hmass.Data() <<"%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"H m_{H}="<< hmass.Data() <<"\");" << std::endl;
   //    myfile << " vectNameBkg.push_back (\"ZH m_{H}="<< hmass.Data() <<"\");" << std::endl;
   myfile << " vectColourBkg.push_back(6);" << std::endl;
   myfile << " vectSystBkg.push_back(0.20);" << std::endl;
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   myfile << " vectNormalizationBkg.push_back(0.018);" << std::endl;
   

   myfile << std::endl;
   myfile << " name = Form(\"%sVV%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"WZ/ZZ\");" << std::endl;
   myfile << " vectColourBkg.push_back(858);" << std::endl;
   myfile << " vectSystBkg.push_back(0.00);" << std::endl;
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   myfile << " vectNormalizationBkg.push_back(0.281);" << std::endl;
   
   myfile << std::endl;
   myfile << " name = Form(\"%sWJets%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"W+jets\");" << std::endl;
   myfile << " vectColourBkg.push_back(921);" << std::endl;
   myfile << " vectSystBkg.push_back(0.36);" << std::endl;
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   myfile << " vectNormalizationBkg.push_back(0.667);" << std::endl;
   myfile << std::endl;
   
   myfile << std::endl;
   myfile << " name = Form(\"%sVg%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"V+#gamma/V+#gamma*\");" << std::endl;
   myfile << " vectColourBkg.push_back(617);" << std::endl;
   myfile << " vectSystBkg.push_back(0.20);" << std::endl;
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   myfile << " vectNormalizationBkg.push_back(0.667);" << std::endl;
   myfile << std::endl;
   
   myfile << " name = Form(\"%sTop%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"top\");" << std::endl;
   myfile << " vectColourBkg.push_back(400);" << std::endl;
   myfile << " vectSystBkg.push_back(0.20);" << std::endl;
   myfile << " vectScaleBkg.push_back(1.0500);" << std::endl; // Scale factor from Data driven estimation
   myfile << " vectNormalizationBkg.push_back(5.654);" << std::endl;

//    myfile << " name = Form(\"%sTopPt0%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
//    myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
//    myfile << " vectNameBkg.push_back (\"top 30<pt<50\");" << std::endl;
//    myfile << " vectColourBkg.push_back(400+1);" << std::endl;
//    myfile << " vectSystBkg.push_back(0.20);" << std::endl;
//    myfile << " vectScaleBkg.push_back(1.0500);" << std::endl; // Scale factor from Data driven estimation
//    myfile << " vectNormalizationBkg.push_back(5.654);" << std::endl;
//    
//    myfile << " name = Form(\"%sTopPt1%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
//    myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
//    myfile << " vectNameBkg.push_back (\"top 50<pt<70\");" << std::endl;
//    myfile << " vectColourBkg.push_back(400+2);" << std::endl;
//    myfile << " vectSystBkg.push_back(0.20);" << std::endl;
//    myfile << " vectScaleBkg.push_back(1.0500);" << std::endl; // Scale factor from Data driven estimation
//    myfile << " vectNormalizationBkg.push_back(5.654);" << std::endl;
//    
//    myfile << " name = Form(\"%sTopPt2%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
//    myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
//    myfile << " vectNameBkg.push_back (\"top pt>70\");" << std::endl;
//    myfile << " vectColourBkg.push_back(400+3);" << std::endl;
//    myfile << " vectSystBkg.push_back(0.20);" << std::endl;
//    myfile << " vectScaleBkg.push_back(1.0500);" << std::endl; // Scale factor from Data driven estimation
//    myfile << " vectNormalizationBkg.push_back(5.654);" << std::endl;
   
   
   myfile << " name = Form(\"%sDYee%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"DY+jets\");" << std::endl;
   myfile << " vectColourBkg.push_back(418);" << std::endl;
   myfile << " vectSystBkg.push_back(0.11);" << std::endl; // +50%
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   myfile << std::endl;
   
   myfile << " name = Form(\"%sDYmumu%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"DY+jets\");" << std::endl;
   myfile << " vectColourBkg.push_back(418);" << std::endl;
   myfile << " vectSystBkg.push_back(0.11);" << std::endl; // +50%
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   myfile << std::endl;
   
   myfile << " name = Form(\"%sDYtautau%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"DY+jets\");" << std::endl;
   myfile << " vectColourBkg.push_back(418);" << std::endl;
   myfile << " vectSystBkg.push_back(0.00);" << std::endl; // +50%
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   //    myfile << " vectScaleBkg.push_back(1.472*0.9);" << std::endl;
   myfile << std::endl;
   
     
   
   myfile << " name = Form(\"%sWW%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"WW\");" << std::endl;
   myfile << " vectColourBkg.push_back(851);" << std::endl;
   myfile << " vectSystBkg.push_back(0.20);" << std::endl; 
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   myfile << " vectNormalizationBkg.push_back(2.256);" << std::endl;
   
   myfile << std::endl;
   myfile << " name = Form(\"%sVVV%s\",cutNameBefore.Data(),cutNameAfter.Data());" << std::endl;
   myfile << " vectTHBkg.push_back ( (TH1F*) f->Get(name) );" << std::endl;
   myfile << " vectNameBkg.push_back (\"VVV\");" << std::endl;
   myfile << " vectColourBkg.push_back(852);" << std::endl;
   myfile << " vectSystBkg.push_back(0.00);" << std::endl;
   myfile << " vectScaleBkg.push_back(1.0000);" << std::endl;
   myfile << " vectNormalizationBkg.push_back(0.667);" << std::endl;
   myfile << std::endl;
   
   
   myfile << std::endl;
   myfile << std::endl;
   myfile << std::endl;
   
   
   myfile << std::endl;
   myfile << " ///==== background (end)  ====" << std::endl;
   myfile << std::endl;
   myfile << std::endl;
   myfile << " hs->set_addSignal(1); // 1 = stack signal, 0 = no stack signal" << std::endl;
   myfile << std::endl;
   myfile << std::endl;
   myfile << " hs->set_vectTHBkg     (vectTHBkg);      " << std::endl; 
   myfile << " hs->set_vectNameBkg   (vectNameBkg);    " << std::endl;
   myfile << " hs->set_vectColourBkg (vectColourBkg);  " << std::endl;
   myfile << " hs->set_vectSystBkg   (vectSystBkg);    " << std::endl;
//    myfile << " hs->set_vectScaleBkg  (vectScaleBkg);   " << std::endl;
   myfile << " //  hs->set_vectScaleBkg  (vectScaleBkg);   " << std::endl;
   
   myfile << std::endl;  
   myfile << " hs->set_vectTHSig     (vectTHSig);      " << std::endl;
   myfile << " hs->set_vectNameSig   (vectNameSig);    " << std::endl;
   myfile << " hs->set_vectColourSig (vectColourSig);  " << std::endl;
   myfile << " //  hs->set_vectScaleSig  (vectScaleSig);   " << std::endl;
   myfile << " //  hs->set_vectSystSig   (vectSystSig);" << std::endl;
   myfile << std::endl;
   myfile << " hs->prepare();" << std::endl;
   myfile << " hs->mergeSamples(); //---- merge trees with the same name! ---- to be called after 'prepare' !" << std::endl;
   
   myfile << std::endl;
   myfile << std::endl;
   myfile << " hs->set_addSignalOnBackground(1); // 1 = signal over background , 0 = signal on its own" << std::endl;
   myfile << std::endl;
   myfile << " ///==== draw ====" << std::endl;
   myfile << std::endl;   
//    myfile << " hs->addLabel(\""<< date.Data() <<"\");" << std::endl; // ---- add folder name on plot! to combine later!
   myfile << std::endl;
   myfile << std::endl;
   myfile << " hs->Draw(c1,1,true);" << std::endl;
   myfile << std::endl;
   myfile << " c1->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << ".pdf\");" << std::endl;
   myfile << " c1->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << ".png\");" << std::endl;
   //   myfile << " c1->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << ".gif\");" << std::endl;
   myfile << std::endl;
   
//    myfile << " TCanvas* c2 = new TCanvas(\"" <<  vVar_simple.at(iVar).c_str() << "_norm\",\"" <<  vVar_simple.at(iVar).c_str() << "_norm\",500,600);" << std::endl;
//    myfile << " hs->DrawNormalized(c2,1);" << std::endl;
//    myfile << " c2->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_norm.pdf\");" << std::endl;
//    myfile << " c2->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_norm.png\");" << std::endl;   
   
   
   
   
   
   
//    myfile << " c1->SetLogy();" << std::endl;
//    myfile << " hs->Draw(c1,1,true);" << std::endl;
//    myfile << " c1->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_logy.pdf\");" << std::endl;
//    myfile << " c1->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_logy.png\");" << std::endl;
   //   myfile << " c1->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_logy.gif\");" << std::endl;
   
   //   myfile << " TCanvas* c2 = new TCanvas(\"" <<  vVar_simple.at(iVar).c_str() << "_image\",\"" <<  vVar_simple.at(iVar).c_str() << "_image\",600,600);" << std::endl;
   //   myfile << " c2->SetLogy(0);" << std::endl;
   //   myfile << " hs->Draw(c2,1,false);" << std::endl;
   //   myfile << " c2->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_plot.pdf\");" << std::endl;
   //   myfile << " c2->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_plot.png\");" << std::endl;
   //   myfile << " c2->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_plot.gif\");" << std::endl;
   
   //   myfile << " c2->SetLogy();" << std::endl;
   //   myfile << " hs->Draw(c2,1,false);" << std::endl;
   //   myfile << " c2->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_plot_logy.pdf\");" << std::endl;
   //   myfile << " c2->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_plot_logy.png\");" << std::endl;
   //   myfile << " c2->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_plot_logy.gif\");" << std::endl;
   
   
   
//    myfile << " c2->SetLogy();" << std::endl;
//    myfile << " hs->DrawNormalized(c2,1);" << std::endl;
//    myfile << " c2->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_logy_norm.pdf\");" << std::endl;
//    myfile << " c2->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_logy_norm.png\");" << std::endl;   
   
   
   
 
   
   myfile << " TCanvas* c3 = new TCanvas(\"" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_right\",\"" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_right\",400,400);" << std::endl;
   myfile << " TCanvas* c4 = new TCanvas(\"" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_SoB_right\",\"" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_SoB_right\",400,400);" << std::endl;
   myfile << " hs->DrawIntegralRight(c3);" << std::endl;
   myfile << " c3->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_right.pdf\");" << std::endl;
   myfile << " c3->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_right.png\");" << std::endl;
   myfile << " c3->SetGrid();" << std::endl;
   myfile << std::endl;
   
   myfile << " hs->DrawIntegralRightSoB(c4);" << std::endl;
   myfile << " c4->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_SoB_right.pdf\");" << std::endl;
   myfile << " c4->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_SoB_right.png\");" << std::endl;
   myfile << std::endl;
//    
//    myfile << " TCanvas* c5 = new TCanvas(\"" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_left\",\"" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_left\",400,400);" << std::endl;
//    myfile << " hs->DrawIntegralLeft(c5);" << std::endl;
//    myfile << " c5->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_left.pdf\");" << std::endl;
//    myfile << " c5->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_left.png\");" << std::endl;
//    myfile << std::endl;
   
//    myfile << " TCanvas* c6 = new TCanvas(\"" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_SoB_left\",\"" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_SoB_left\",400,400);" << std::endl;
//    myfile << " hs->DrawIntegralLeftSoB(c6);" << std::endl;
//    myfile << " c6->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_SoB_left.pdf\");" << std::endl;
//    myfile << " c6->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_cut_opt_SoB_left.png\");" << std::endl;
//    myfile << std::endl;

   
   myfile << " TCanvas* c7 = new TCanvas(\"" <<  vVar_simple.at(iVar).c_str() << "_norm_bkg\",\"" <<  vVar_simple.at(iVar).c_str() << "_norm_bkg\",400,400);" << std::endl;
   myfile << " hs->DrawNormalizedBkgSummed(c7);" << std::endl;
   myfile << " c7->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_norm_bkg.pdf\");" << std::endl;
   myfile << " c7->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_norm_bkg.png\");" << std::endl;

//    
//    myfile << " TCanvas* c8 = new TCanvas(\"" <<  vVar_simple.at(iVar).c_str() << "_sob_bkg\",\"" <<  vVar_simple.at(iVar).c_str() << "_sob_bkg\",400,400);" << std::endl;
//    myfile << " hs->DrawNormalizedSoBBkgSummed(c8);" << std::endl;
//    myfile << " c8->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_sob_bkg.pdf\");" << std::endl;
//    myfile << " c8->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_sob_bkg.png\");" << std::endl;
//    
//    myfile << " TCanvas* c9 = new TCanvas(\"" <<  vVar_simple.at(iVar).c_str() << "_s2ob_bkg\",\"" <<  vVar_simple.at(iVar).c_str() << "_s2ob_bkg\",400,400);" << std::endl;
//    myfile << " hs->DrawNormalizedS2oBBkgSummed(c9);" << std::endl;
//    myfile << " c9->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_s2ob_bkg.pdf\");" << std::endl;
//    myfile << " c9->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_s2ob_bkg.png\");" << std::endl;
//    
//    myfile << " TCanvas* c10 = new TCanvas(\"" <<  vVar_simple.at(iVar).c_str() << "_s2ob_bkg\",\"" <<  vVar_simple.at(iVar).c_str() << "_sosqrtb_bkg\",400,400);" << std::endl;
//    myfile << " hs->DrawNormalizedSosqrtBBkgSummed(c10);" << std::endl;
//    myfile << " c10->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_sosqrtb_bkg.pdf\");" << std::endl;
//    myfile << " c10->Print(\"" << date.Data() << "_" << iCut << "/" <<  vVar_simple.at(iVar).c_str() << "_sosrqtb_bkg.png\");" << std::endl;
   
   myfile << "}" << std::endl;
   myfile << std::endl;
   myfile << std::endl;
   
   
   myfile.close(); 
   
   CommandToExec = Form("root -l -q -b %s+",name.Data());
//    gSystem->Exec(CommandToExec);  
   
  }
  
  
  
  for (int iVar=0; iVar<vVar_simple.size(); iVar++) {
   TString name = Form ("Plot-AM-%s-%s-%d-auto.C",vVar_simple.at(iVar).c_str(), date.Data(), iCut);
   std::cout << "r00t " << name.Data() << "+" << std::endl;
  }
  
  std::cout << std::endl;
  std::cout << std::endl;
  
  std::cout << "scp -r " << date.Data() << "_" << iCut << "/ amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/www/HWW/Plot/HCP2012/plot/06Oct2012/" << std::endl;
  
  std::cout << std::endl;
  std::cout << std::endl;
  
 }
 
 gApplication->Terminate(0);
 
}









