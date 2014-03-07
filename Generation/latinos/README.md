Latinos instructions
=======

Create list of files

    eos ls /store/user/amassiro/bbH/8TeV/WW_AODSIM/ | awk '{print "   @/store/user/amassiro/bbH/8TeV/WW_AODSIM/"$1"@,"}' | tr "@" "'"

hardcoded in skim.py.

Then

    cmsRun latinosYieldSkim.py.ww2j.py    print  isMC=True globalTag=GR_R_52_V7  outputFile=/tmp/amassiro/latinosYieldSkim_MC_ww2jnlo_100k.root   correctMetPhi=False
