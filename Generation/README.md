Generation with POWHEG WW+2jets EWK NLO
=======

Instructions from:

    http://powhegbox.mib.infn.it/

Process:

    VBF_Wp_Wm


# Install

* // cd CMSSW_6_2_0/src/    ---> don't do it!
* cd CMSSW_5_3_9/src/
* cmsenv
* cd ../../
* cd POWHEG-BOX/VBF_Wp_Wm
* make -j 4


since I cannot use the cmssw ones
use local lhapdf installed on cmsneu

    export PATH=/home/amassiro/Generation/MINLO/install-fastjet-3.0.6/bin/:$PATH
    export PATH=/home/amassiro/Generation/lhapdf/install-lhapdf-5.9.1/bin/:$PATH
    export LD_LIBRARY_PATH=/home/amassiro/Generation/MINLO/install-fastjet-3.0.6/lib/:$LD_LIBRARY_PATH
    export LD_LIBRARY_PATH=/home/amassiro/Generation/lhapdf/install-lhapdf-5.9.1/lib/:$LD_LIBRARY_PATH
    export LHAPATH=/home/amassiro/Generation/lhapdf/install-lhapdf-5.9.1/share/lhapdf/PDFsets


# Generation

follow instructions in manual.pdf (4 steps)

# Cross section

    cat pwg-3-0002-stat.dat  | grep Total
    cat pwg-3-0001-stat.dat  | grep Total


# Result

    pwgevents-0001.lhe
    pwgevents-0002.lhe

merged together in:

    pwgevents.lhe

Only em events are produced: now shuffle!

from

   e+m-

to

   em
   ee
   et
   mm
   me
   mt
   tm
   te
   tt


awk '/\ \ 25\ \ /&&v++%2{sub(/\ \ 25\ \ \ \ 1/, "\ \ 35\ \ \ \ 1")}{print}' $NAMEFILELHE > /tmp/$TESTFOLDER/$NAMELHEMODIFIED




Now hadronize & more 10k events in CMS









