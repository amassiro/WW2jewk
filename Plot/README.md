
# For MVA: input variables #
====
    ./bin/MCDATAComparisonPLOTTool.exe test/WW2jewk/Plot/testPlotInputVariables.cfg
    r00t AMPlotMacroCreator_Moriond.cxx
    
     -> new variables

     



# propaganda plot for mll shape analysis
    
    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/WW2jewkDFshapeTCHE21/postFit/WWewk-error-*.root postFit-WW2jewk-21/
    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/WW2jewkDFshapeTCHE05/postFit/WWewk-error-*.root postFit-WW2jewk-05/
 
    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/WW2jewkDFshapeTopEnriched/postFit/WWewk-error-*.root postFit-WW2jewk-Top/

    r00t Plot_AM_WW2jewk_Propaganda_Moriond.C+


     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
backup
====


##########################
#### MC distributions ####


    ./bin/MCDATAComparisonPLOTTool.exe test/WW2jewk/Plot/testMCDATAComparisonPLOTTool_ForNote.cfg
    r00t AMPlotMacroCreator_Moriond.cxx


######################################################
#### cut optimization by looking at distributions ####



    rm -r output_Latinos_tree_2012_2orMoreJet2012
    mkdir output_Latinos_tree_2012_2orMoreJet2012
    ls --color=none output_Latinos_tree_2012/ | tr "@" " " |  awk '{print "./bin/FilterCut.exe output_Latinos_tree_2012/"$1" output_Latinos_tree_2012_2orMoreJet2012/"$1" 2orMoreJet2012"}'   &> skim2orMoreJet.sh
    chmod +x skim2orMoreJet.sh
    ./skim2orMoreJet.sh







#####################################
# for MVA: top enriched phase space #

     ./bin/MCDATAComparisonPLOTTool.exe test/WW2jewk/Plot/testMCDATAComparisonPLOTTool_MVA.cfg
    r00t AMPlotMacroCreator_Moriond.cxx





 
 
#########################################
# check possible mjj cut based analysis #

    ./bin/MCDATAComparisonPLOTTool.exe test/WW2jewk/Plot/testOptimization.cfg
    r00t AMPlotMacroCreator_Moriond.cxx








# create distributions

    ./bin/MCDATAComparisonPLOTTool.exe test/WW2jewk/Plot/testMCDATAComparisonPLOTTool_ForOptimization.cfg

# integrate distributions
    
    ./bin/MCDATAPlotCutOptimization.exe test/WW2jewk/Plot/CutOptimization.cfg 

# then look at the root file obtained "by hand"
    
    r00t AMPlotMacroCreator_HCP.cxx


# propaganda plot for mll shape analysis
    
    r00t Plot_AM_VH_testPropaganda_Normal.C+




#############################
#### control plot for AN ####


    ./bin/MCDATAComparisonPLOTTool.exe test/WW2jewk/Plot/testMCDATAComparisonPLOTTool_ForNote_ControlPlot.cfg

    r00t AMPlotMacroCreator_Moriond_ControlPlot.cxx

    --> also at Higgs level




#####################################
#### control plot for HWW review ####


    ./bin/MCDATAComparisonPLOTTool.exe test/WW2jewk/Plot/testMCDATAComparisonPLOTTool_ForHWWreview.cfg

    r00t AMPlotMacroCreator_Moriond.cxx














