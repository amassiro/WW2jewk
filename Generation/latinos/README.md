Latinos instructions
=======

Create list of files

    eos ls /store/user/amassiro/WW2j/8TeV/WW_AODSIM/ | awk '{print "   @/store/user/amassiro/WW2j/8TeV/WW_AODSIM/"$1"@,"}' | tr "@" "'"
    eos ls /eos/cms/store/user/amassiro/WW2j_aQGC/8TeV/WW_AODSIM/WW_s | awk '{print "   @/store/user/amassiro/WW2j_aQGC/8TeV/WW_AODSIM/WW_s/"$1"@,"}' | tr "@" "'"
    eos ls /eos/cms/store/user/amassiro/WW2j_aQGC/8TeV/WW_AODSIM/WW_t | awk '{print "   @/store/user/amassiro/WW2j_aQGC/8TeV/WW_AODSIM/WW_t/"$1"@,"}' | tr "@" "'"

    eos ls /eos/cms/store/group/phys_higgs/cmshww/amassiro/WW2j_aQGC/8TeV/WW_AODSIM/WW_GENSIM | awk '{print "   @/store/group/phys_higgs/cmshww/amassiro/WW2j_aQGC/8TeV/WW_AODSIM/WW_GENSIM/"$1"@,"}' | tr "@" "'"
    eos ls /eos/cms/store/group/phys_higgs/cmshww/amassiro/WW2j_aQGC/8TeV/WW_AODSIM/WW_T_GENSIM | awk '{print "   @/store/group/phys_higgs/cmshww/amassiro/WW2j_aQGC/8TeV/WW_AODSIM/WW_T_GENSIM/"$1"@,"}' | tr "@" "'"


hardcoded in skim.py.

Then:

    cd /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/SkimStep/test/

    cmsRun latinosYieldSkim.py.ww2j.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2jnlo_100k.root   correctMetPhi=False   doNoFilter=True

    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/latinosYieldSkim.py.ww2j_s.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_100k.root   correctMetPhi=False   doNoFilter=True
    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/latinosYieldSkim.py.ww2j_t.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_100k.root   correctMetPhi=False   doNoFilter=True

    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/latinosYieldSkim.py.ww2j_s.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M.root   correctMetPhi=False   doNoFilter=True      &> tmp_s.txt
    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/latinosYieldSkim.py.ww2j_t.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M.root   correctMetPhi=False   doNoFilter=True      &> tmp_t.txt



    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/subsamples/latinosYieldSkim.py.ww2j_s_0.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_0.root   correctMetPhi=False   doNoFilter=True      &> tmp_s_0.txt
    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/subsamples/latinosYieldSkim.py.ww2j_s_1.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_1.root   correctMetPhi=False   doNoFilter=True      &> tmp_s_1.txt
    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/subsamples/latinosYieldSkim.py.ww2j_s_2.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_2.root   correctMetPhi=False   doNoFilter=True      &> tmp_s_2.txt
    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/subsamples/latinosYieldSkim.py.ww2j_s_3.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_3.root   correctMetPhi=False   doNoFilter=True      &> tmp_s_3.txt
    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/subsamples/latinosYieldSkim.py.ww2j_s_4.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_4.root   correctMetPhi=False   doNoFilter=True      &> tmp_s_4.txt
    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/subsamples/latinosYieldSkim.py.ww2j_s_5.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_5.root   correctMetPhi=False   doNoFilter=True      &> tmp_s_5.txt

    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/subsamples/latinosYieldSkim.py.ww2j_t_0.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M_0.root   correctMetPhi=False   doNoFilter=True      &> tmp_t_0.txt
    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/subsamples/latinosYieldSkim.py.ww2j_t_1.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M_1.root   correctMetPhi=False   doNoFilter=True      &> tmp_t_1.txt
    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/subsamples/latinosYieldSkim.py.ww2j_t_2.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M_2.root   correctMetPhi=False   doNoFilter=True      &> tmp_t_2.txt
    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/subsamples/latinosYieldSkim.py.ww2j_t_3.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M_3.root   correctMetPhi=False   doNoFilter=True      &> tmp_t_3.txt
    cmsRun /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/subsamples/latinosYieldSkim.py.ww2j_t_4.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M_4.root   correctMetPhi=False   doNoFilter=True      &> tmp_t_4.txt





    cd /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3

    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2jnlo_100k.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j.root  doNoFilter=True  &> tmp.txt

    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_100k.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_s.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_s.txt
    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_100k.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_t.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_t.txt

    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_s_1M.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_s.txt
    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_t_1M.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_t.txt





    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_0.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_s_1M_0.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_s_0.txt
    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_1.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_s_1M_1.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_s_1.txt
    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_2.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_s_1M_2.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_s_2.txt
    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_3.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_s_1M_3.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_s_3.txt
    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_4.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_s_1M_4.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_s_4.txt
    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_s_1M_5.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_s_1M_5.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_s_5.txt

    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M_0.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_t_1M_0.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_t_0.txt
    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M_1.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_t_1M_1.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_t_1.txt
    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M_2.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_t_1M_2.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_t_2.txt
    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M_3.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_t_1M_3.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_t_3.txt
    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2j_t_1M_4.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j_t_1M_4.root  doNoFilter=True doLHE=True  typeLHEcomment=1  &> tmp_t_4.txt




    hadd latinosStep3_ww2j_t_1M_all.root latinosStep3_ww2j_t_1M_?.root
    hadd latinosStep3_ww2j_s_1M_all.root latinosStep3_ww2j_s_1M_?.root

    python ucsd2latino.py latinosStep3_ww2j_s_1M_all.root
    python ucsd2latino.py latinosStep3_ww2j_t_1M_all.root



    python ucsd2latino.py latinosStep3_ww2j.root
    python ucsd2latino.py latinosStep3_ww2j_s.root
    python ucsd2latino.py latinosStep3_ww2j_t.root

    python ucsd2latino.py latinosStep3_ww2j_s_1M.root
    python ucsd2latino.py latinosStep3_ww2j_t_1M.root



Change baseW:

    cross section = 2.467605012301833E-003 * 9 = 2.22084451107164987e-02 pb
    total events processed (looking at root file, since it has no events rejected): 24206
    baseW = 2.22084451107164987e-02 / 24206 * 1000. = 9.17476869813951086e-04


    cd /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/HWWAnalysis/ShapeAnalysis/
    eval `scramv1 runtime -sh`
    source test/env.sh
    cd -

    gardener.py  adder -v 'baseW/F=9.17476869813951086e-04'     latinolatinosStep3_ww2j.root     latinolatinosStep3_ww2j_new.root
    mv latinolatinosStep3_ww2j_new.root latinolatinosStep3_ww2j.root


    1M events:

    cross section = 2.467605012301833E-003 * 9 = 2.22084451107164987e-02 pb
    s: total events processed (looking at root file, since it has no events rejected): 64953
    s: baseW = 2.22084451107164987e-02 / 64953 * 1000. = 3.41915617611449811e-04 

    t: total events processed (looking at root file, since it has no events rejected): 64992
    t: baseW = 2.22084451107164987e-02 / 64992 * 1000. = 3.41710442988621649e-04 

    cd /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/HWWAnalysis/ShapeAnalysis/
    eval `scramv1 runtime -sh`
    source test/env.sh
    cd -

    gardener.py  adder -v 'baseW/F=3.41915617611449811e-04'     latinolatinosStep3_ww2j_s_1M.root     latinolatinosStep3_ww2j_s_1M_new.root
    mv latinolatinosStep3_ww2j_s_1M_new.root   latinolatinosStep3_ww2j_s_1M.root

    gardener.py  adder -v 'baseW/F=3.41710442988621649e-04'     latinolatinosStep3_ww2j_t_1M.root     latinolatinosStep3_ww2j_t_1M_new.root
    mv latinolatinosStep3_ww2j_t_1M_new.root   latinolatinosStep3_ww2j_t_1M.root



Add variables
====

Automatic script:

    sh addVariables.sh
    sh /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/latinos/addVariables.sh


triggW

    ./gardener.py efftfiller \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s_1.root  \
      -f ../data/fit_results.txt
    ./gardener.py efftfiller \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t_1.root  \
      -f ../data/fit_results.txt

puW

    ./gardener.py  puadder \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s_1.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s_2.root  \
           --mc=../data/PileupMC_60bin_S10.root    \
           --data=../data/PUdata2012Final.root   \
           --HistName=pileup   \
           --branch=puW  \
           --kind=trpu

    ./gardener.py  puadder \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t_1.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t_2.root  \
           --mc=../data/PileupMC_60bin_S10.root    \
           --data=../data/PUdata2012Final.root   \
           --HistName=pileup   \
           --branch=puW  \
           --kind=trpu

effW

    ./gardener.py effwfiller \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s_2.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_s_3.root  \
        --mufile=../data/muons_scale_factors.root \
        --elfile=../data/electrons_scale_factors.root \
        --muname=muonsDATAMCratio_all \
        --elname=electronsDATAMCratio_All_selec

    ./gardener.py effwfiller \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t_2.root  \
      /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/WWAnalysis/AnalysisStep/test/step3/latinolatinosStep3_ww2j_t_3.root  \
        --mufile=../data/muons_scale_factors.root \
        --elfile=../data/electrons_scale_factors.root \
        --muname=muonsDATAMCratio_all \
        --elname=electronsDATAMCratio_All_selec




