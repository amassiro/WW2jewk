lxbatch
=======

Decay & hadronize: GEN-SIM step lxbatch
=======


1. Prepare the jobs to launch on lxbatch:

        perl launchJobs_lxbatch_GEN-SIM.pl params_lxbatch_GEN-SIM_hww.CFG

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


Decay & hadronize: DIGI step lxbatch
=======

1. Prepare the jobs to launch on lxbatch:

        perl launchJobs_lxbatch_DIGI.pl params_lxbatch_DIGI_hww.CFG

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


