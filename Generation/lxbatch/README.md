lxbatch
=======

where:

    /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/lxbatch/


Pre-preparation

    cat eos/cms/store/group/phys_higgs/cmshww/astepenn/work/tau_*/*.tar &> /tmp/amassiro/Anton_unweighted_events.lhe


Preparation
=======

change weight format to support old cmssw releases

    sed 's/<wgt/#wgt/' </tmp/amassiro/Anton_unweighted_events.lhe | sed 's/<rwgt/#rwgt/'   | sed 's|</rwgt|#/rwgt|'    | sed 's|</wgt>||'   >/tmp/amassiro/Anton_unweighted_events_weight.lhe

    sed 's/<wgt/#wgt/' </tmp/amassiro/Jasper_unweighted_events.lhe | sed 's/<rwgt/#rwgt/'   | sed 's|</rwgt|#/rwgt|'    | sed 's|</wgt>||'   >/tmp/amassiro/Jasper_unweighted_events_weight.lhe

    sed 's/<wgt/#wgt/' </data/amassiro/CMSSWLHE/WW2jetsMadgraph_aQGC/Jasper_unweighted_events.lhe | sed 's/<rwgt/#rwgt/'   | sed 's|</rwgt|#/rwgt|'    | sed 's|</wgt>||'   > /data/amassiro/CMSSWLHE/WW2jetsMadgraph_aQGC/Jasper_unweighted_events_weight.lhe


    (auto)
    if needed ->
        ls -d eos/cms/store/group/phys_higgs/cmshww/astepenn/work/*/ | tr "/" " " | awk '{print "cp eos/cms/store/group/phys_higgs/cmshww/astepenn/work/"$9"/unweighted_events.lhe.tar /tmp/amassiro/unweighted_events.lhe.tar."$9".lhe"}' 
        ls -d eos/cms/store/group/phys_higgs/cmshww/astepenn/work/tau_*/ | tr "/" " " | awk '{print "cp eos/cms/store/group/phys_higgs/cmshww/astepenn/work/"$9"/unweighted_events.lhe.tar /tmp/amassiro/unweighted_events.lhe.tar."$9".lhe"}'  

    ls /tmp/amassiro/*.lhe | awk '{print "sed @s/<wgt/#wgt/@ <   "$1" | sed @s/<rwgt/#rwgt/@   | sed @s|</rwgt|#/rwgt|@    | sed @s|</wgt>||@   > "$1".correct.lhe" }' | tr "@" "'"

    ls /tmp/amassiro/*correct.lhe  | awk '{print "tail -n +715 "$1" | head -n -1 > "$1".new.lhe"}'
    if needed ->
        ls /tmp/amassiro/*correct.lhe  | awk '{print "tail -n +854 "$1" | head -n -1 > "$1".new.lhe"}'
        ls /tmp/amassiro/*correct.lhe  | awk '{print "tail -n +855 "$1" | head -n -1 > "$1".new.lhe"}'

    cat /tmp/amassiro/*correct.lhe.new.lhe > /tmp/amassiro/joined_temp.lhe

    cat head.txt /tmp/amassiro/joined_temp.lhe tail.txt > /tmp/amassiro/joined.lhe
    if needed ->
        cat head.S.txt /tmp/amassiro/joined_temp.lhe tail.S.txt > /tmp/amassiro/joined.lhe

from LHE to CMSSW

    cmsDriver.py step1 --filein file:/tmp/amassiro/Anton_unweighted_events_weight.lhe  --fileout file:/tmp/amassiro/Anton_unweighted_events.root --mc --eventcontent LHE --datatier GEN --conditions START53_V7C::All --step NONE --python_filename test.py   -n -1

    cmsDriver.py step1 --filein file:/data/amassiro/CMSSWLHE/WW2jetsMadgraph_aQGC/Jasper_unweighted_events_weight.lhe  --fileout file:/data/amassiro/CMSSWLHE/WW2jetsMadgraph_aQGC/Jasper_unweighted_events.root --mc --eventcontent LHE --datatier GEN --conditions START53_V7C::All --step NONE --python_filename test.py   -n -1

    cmsDriver.py step1 --filein file:/data/amassiro/CMSSWLHE/WW2jetsMadgraph_aQGC/Anton_unweighted_events_weight.lhe  --fileout file:/data/amassiro/CMSSWLHE/WW2jetsMadgraph_aQGC/Anton_unweighted_events.root --mc --eventcontent LHE --datatier GEN --conditions START53_V7C::All --step NONE --python_filename test.py   -n -1

    cmsDriver.py step1 --filein file:/tmp/amassiro/Jasper_unweighted_events_weight.lhe  --fileout file:/tmp/amassiro/Jasper_unweighted_events.root --mc --eventcontent LHE --datatier GEN --conditions START53_V7C::All --step NONE --python_filename test.py    -n -1

    ls /tmp/amassiro/VBS_LS01*correct.lhe > tmp.txt
    modify by hand up to a .py file list of files
    cmsDriver.py step1 --filein tmp.txt  --fileout file:/tmp/amassiro/VBS_LS01.root --mc --eventcontent LHE --datatier GEN --conditions START53_V7C::All --step NONE --python_filename test.py    -n -1

    cmsDriver.py step1 --filein file:/tmp/amassiro/joined.lhe  --fileout file:/tmp/amassiro/VBS_LS01.root --mc --eventcontent LHE --datatier GEN --conditions START53_V7C::All --step NONE --python_filename VBS_LS01.py    -n -1

    cmsDriver.py step1 --filein file:/tmp/amassiro/joined.lhe  --fileout file:/tmp/amassiro/VBS_LT01.root --mc --eventcontent LHE --datatier GEN --conditions START53_V7C::All --step NONE --python_filename VBS_LT01.py    -n -1

    HEPMCinput = /afs/cern.ch/user/a/amassiro/work/public/WW2j/ww2j_LO_mg_Jasper.root
    HEPMCinput = /afs/cern.ch/user/a/amassiro/work/public/WW2j/ww2j_LO_mg_Anton.root



Decay & hadronize: GEN-SIM step lxbatch
=======


1. Prepare the jobs to launch on lxbatch:

        perl launchJobs_lxbatch_GEN-SIM.pl params_lxbatch_GEN-SIM_hww.CFG
        perl launchJobs_lxbatch_GEN-SIM.pl params_lxbatch_GEN-SIM_aQGC.CFG

    params_lxbatch_GEN-SIM.CFG has the following input parameters:

   - BASEDir: complete path of this lxbatch directory, eg:

                /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/lxbatch/

   - JOBCfgTemplate: cfg file to run with cmsRun, USE THE TEMPLATE:

                GENSIM_VBF_Wp_Wm_powheg_lnulnu_withTau_8TeV_template.py

   - HEPMinput: hepmc root files complete path, PUT IT IN A public OR /tmp/, eg:

                /afs/cern.ch/user/a/amassiro/work/public/WW2j/ww2j_NLO_powheg.root

   - OUTPUTSAVEPath: directory where to save the output files (also a eos directory), eg:

                /store/user/amassiro/WW2j/8TeV/WW/

   - OUTPUTFILEName: name of a single job output root file, eg:

                WW_GEN-SIM

   - EVENTSNumber: total number of events to analyze

   - EVENTSPerjob: number of events per job

   - EXEName: name of the executable in the JOB directory.

   - QUEUE: name of the queue where launch the jobs to, eg: 1nd

1. Launch the jobs (file lancia.sh automatically created):

        sh lancia.sh
        sh lanciaGENSIM.sh


Decay & hadronize: DIGI step lxbatch
=======

1. Prepare the jobs to launch on lxbatch:

        perl launchJobs_lxbatch_DIGI.pl params_lxbatch_DIGI_hww.CFG
        perl launchJobs_lxbatch_DIGI.pl params_lxbatch_DIGI_aQGC.CFG

    params_lxbatch_GEN-SIM.CFG has the following input parameters:

   - BASEDir: complete path of this lxbatch directory, eg:

                /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/lxbatch/

   - JOBCfgTemplate: path of the cfg file to run with cmsRun, USE THE TEMPLATE:

                DIGI_template_cfg.py

   - LISTOFSamples: txt file of the list of directories that contain the GEN-SIM root files, eg of path into the txt (in the format using options from previous step "OUTPUTSAVEPath", with the last folder split) :

                /store/user/amassiro/WW2j/8TeV    WW


     where the directory path and the directory have to be separated by a spacetab

   - OUTPUTSAVEPath: directory where to save the output files (also a eos directory), eg:

                /store/user/amassiro/WW2j/8TeV/WW_DIGI/

   - OUTPUTFILEName: name of a single job output root file, eg:

                WW_DIGI

   - EXEName: name of the executable in the JOB directory.

   - JOBModulo: numeber of split lhe read per job. 


2. Launch the jobs:

        sh lancia.sh


Decay & hadronize: AODSIM step lxbatch
=======

1. Prepare the jobs to launch on lxbatch:

        perl launchJobs_lxbatch_AODSIM.pl params_lxbatch_AODSIM_hww.CFG
        perl launchJobs_lxbatch_AODSIM.pl params_lxbatch_AODSIM_aQGC.CFG

   params_lxbatch_AODSIM.CFG has the following input parameters:

   - BASEDir: complete path of this lxbatch directory, eg:

                /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/lxbatch/

   - JOBCfgTemplate: path of the cfg file to run with cmsRun, USE THE TEMPLATE:

                AODSIM_template_cfg.py

   - LISTOFSamples: txt file of the list of directories that contain the DIGI root files, eg of path into the txt:

                /store/user/amassiro/WW2j/8TeV     WW_DIGI

     where the directory path and the directory have to be separated by a spacetab

   - OUTPUTSAVEPath: directory where to save the output files (also a eos directory), eg:

                /store/user/amassiro/WW2j/8TeV/WW_AODSIM/

   - OUTPUTFILEName: name of a single job output root file, eg:

                WW_AODSIM

   - EXEName: name of the executable in the JOB directory.

   - JOBModulo: numeber of split lhe read per job. 


2. Launch the jobs:

        sh lancia.sh


