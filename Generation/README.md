Generation with POWHEG WW+2jets EWK NLO
=======

Instructions from:

    http://powhegbox.mib.infn.it/

Process:

    VBF_Wp_Wm

where:

    /home/amassiro/Generation/MINLO/POWHEG-BOX/VBF_Wp_Wm

# Install

    // cd CMSSW_6_2_0/src/    ---> don't do it!
    cd CMSSW_5_3_9/src/
    cmsenv
    cd ../../
    cd POWHEG-BOX/VBF_Wp_Wm
    make -j 4


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


    btilde Total (pos.-|neg.|):  2.467605012301833E-003  +-  8.273806561210325E-005
    this is only (-11,24)(-14,13) -> e+ mu-
    then: em, ee, et, mm, me, mt, tm, te, tt  -> x9
    cross section = 2.467605012301833E-003 * 9 = 2.22084451107164987e-02 pb



# Result

    pwgevents-0001.lhe
    pwgevents-0002.lhe

merged together in:

    cat pwgevents-0001.lhe | grep -v "/LesHouchesEvents" > tmp.lhe
    cat tmp.lhe pwgevents-0002.lhe  > pwgevents.lhe

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


    cp pwgevents.lhe /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/
    c++ -o Transform.exe `root-config --glibs --cflags` -lm Transform.cpp
    ./Transform.exe  pwgevents.lhe pwgevents-shuffled.lhe

    NB: it helps in cleaning the lhe file as well!
        removal of unused comments and headers


# hadronization and CMSSW

where:

    /afs/cern.ch/user/a/amassiro/work/Generation/CMSSW_5_3_14_patch2/src/WW2jewk/Generation/

look at lxbatch folder

First create edm root version:

    cmsDriver.py MCDBtoEDM --conditions START53_V19::All -s NONE --eventcontent RAWSIM --datatier GEN --filein file:pwgevents-shuffled.lhe      --fileout ww2j_NLO_powheg.root  -n -1





