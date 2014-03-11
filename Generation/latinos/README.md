Latinos instructions
=======

Create list of files

    eos ls /store/user/amassiro/WW2j/8TeV/WW_AODSIM/ | awk '{print "   @/store/user/amassiro/WW2j/8TeV/WW_AODSIM/"$1"@,"}' | tr "@" "'"

hardcoded in skim.py.

Then

    cmsRun latinosYieldSkim.py.ww2j.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2jnlo_100k.root   correctMetPhi=False   doNoFilter=True


    cmsRun step3.py print inputFiles=file:/tmp/amassiro/latinosYieldSkim_MC_ww2jnlo_100k.root  label=ww2j id=1234 scale=1 outputFile=latinosStep3_ww2j.root  doNoFilter=True  &> tmp.txt


    python ucsd2latino.py latinosStep3_ww2j.root

