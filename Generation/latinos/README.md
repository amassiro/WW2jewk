Latinos instructions
=======

Create list of files

    eos ls /store/user/amassiro/WW2j/8TeV/WW_AODSIM/ | awk '{print "   @/store/user/amassiro/WW2j/8TeV/WW_AODSIM/"$1"@,"}' | tr "@" "'"

hardcoded in skim.py.

Then

    cmsRun latinosYieldSkim.py.ww2j.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2jnlo_100k.root   correctMetPhi=False   doNoFilter=True


    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2jnlo_100k.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j.root  doNoFilter=True  &> tmp.txt


    python ucsd2latino.py latinosStep3_ww2j.root



change baseW

    cross section = 2.467605012301833E-003 * 9 = 2.22084451107164987e-02 pb
    total events processed (looking at root file, since it has no events rejected): 24206
    baseW = 2.22084451107164987e-02 / 24206 * 1000. = 9.17476869813951086e-04


    cd /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/HWWAnalysis/ShapeAnalysis/
    eval `scramv1 runtime -sh`
    source test/env.sh
    cd -

    gardener.py  adder -v 'baseW/F=9.17476869813951086e-04'     latinolatinosStep3_ww2j.root     latinolatinosStep3_ww2j_new.root
    mv latinolatinosStep3_ww2j_new.root latinolatinosStep3_ww2j.root


