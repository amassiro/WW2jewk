

cd /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/HWWAnalysis/ShapeAnalysis/
eval `scramv1 runtime -sh`
source test/env.sh
cd scripts



# triggW

./gardener.py efftfiller \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s_1M.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s_1M_1.root  \
      -f ../data/fit_results.txt
./gardener.py efftfiller \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t_1M.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t_1M_1.root  \
      -f ../data/fit_results.txt



# puW

./gardener.py  puadder \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s_1M_1.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s_1M_2.root  \
           --mc=../data/PileupMC_60bin_S10.root    \
           --data=../data/PUdata2012Final.root   \
           --HistName=pileup   \
           --branch=puW  \
           --kind=trpu

./gardener.py  puadder \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t_1M_1.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t_1M_2.root  \
           --mc=../data/PileupMC_60bin_S10.root    \
           --data=../data/PUdata2012Final.root   \
           --HistName=pileup   \
           --branch=puW  \
           --kind=trpu



# effW

./gardener.py effwfiller \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s_1M_2.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s_1M_3.root  \
        --mufile=../data/muons_scale_factors.root \
        --elfile=../data/electrons_scale_factors.root \
        --muname=muonsDATAMCratio_all \
        --elname=electronsDATAMCratio_All_selec

./gardener.py effwfiller \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t_1M_2.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t_1M_3.root  \
        --mufile=../data/muons_scale_factors.root \
        --elfile=../data/electrons_scale_factors.root \
        --muname=muonsDATAMCratio_all \
        --elname=electronsDATAMCratio_All_selec

