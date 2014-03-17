Interference WW+2jets ewk/qcd
=======

Interference between WW+2jets: ewk, qcd, ewk+qcd


Working here:

    cmsneu
    /home/amassiro/Generation/MINLO/WW2jewk/Interference/

LHE files here:

    /data/amassiro/CMSSWLHE/WW2jetsPhantom/

Dump sensitive information into a root file

    c++ -o ntupleMaker.exe `root-config --glibs --cflags` `lhapdf-config --cppflags  --ldflags` -lm ntupleMaker.cpp
    ./ntupleMaker.exe   blabla.lhe    blabla.root


Merge LHE:

    ls -d  gen_*/ --color=none | awk '{print "cd "$1"/gen2jmu-e+/; /home/amassiro/Interference/LHEActions/mergeLHEfiles  `find . -name \"phamom.dat\"`;  cd -; cd "$1"/gen2jmu-mu+/; /home/amassiro/Interference/LHEActions/mergeLHEfiles  `find . -name \"phamom.dat\"`;  cd -;"}'

Dump:

    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_ew/gen2jmu-e+/total.lhe EW_jjme.root
    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_ew/gen2jmu-mu+/total.lhe EW_jjmm.root

    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_qcd/gen2jmu-e+/total.lhe QCD_jjme.root
    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_qcd/gen2jmu-mu+/total.lhe QCD_jjmm.root

    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_ewqcd/gen2jmu-e+/total.lhe EWQCD_jjme.root
    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_ewqcd/gen2jmu-mu+/total.lhe EWQCD_jjmm.root


Get cross-section:

    cat   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_qcd/gen2jmu-e+/result | grep total 
    cat   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_qcd/gen2jmu-mu+/result | grep total 
    cat   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_ew/gen2jmu-e+/result | grep total 
    cat   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_ew/gen2jmu-mu+/result | grep total 
    cat   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_ewqcd/gen2jmu-e+/result | grep total 
    cat   /data/amassiro/CMSSWLHE/WW2jetsPhantom/gen_126_lvlv_s1_ewqcd/gen2jmu-mu+/result | grep total 

qcd

    total cross section=  0.62100954917703377       +/-  4.38916672987245599E-004
    total cross section=  0.31107029810623943       +/-  2.19922873754970909E-004

ewk

    total cross section=  2.68719361245196228E-002  +/-  1.89984045079834006E-005
    total cross section=  1.35241401169139651E-002  +/-  9.56109888684092098E-006

ew+qcd

    total cross section=  0.64303443036305363       +/-  4.54530754262088578E-004
    total cross section=  0.32257867984679178       +/-  2.28027278887301088E-004


    
Draw:

    r00t  Draw.cxx\(0,\"mWW\",100,0,2000,\"mWW\ [GeV]\"\)
    r00t  Draw.cxx\(0,\"mjj\",100,0,2000,\"mjj\ [GeV]\"\)
    r00t  Draw.cxx\(0,\"mjj\",100,0,4000,\"mjj\ [GeV]\"\)
    r00t  Draw.cxx\(0,\"mll\",100,0,200,\"mll\ [GeV]\"\)
    r00t  Draw.cxx\(0,\"jetpt1\",100,0,200\,\"jetpt1\ [GeV]\"\)
    r00t  Draw.cxx\(0,\"jetpt2\",100,0,200,\"jetpt2\ [GeV]\"\)
    r00t  Draw.cxx\(0,\"pt1\",100,0,200,\"pt1\ [GeV]\"\)
    r00t  Draw.cxx\(0,\"pt2\",100,0,200,\"pt2\ [GeV]\"\)

    
    
    
# Madgraph    
    
Generation:

    cd /home/amassiro/Generation/MG5/MG5_aMC_v2_0_0
    
    cd WW2j_QCD_DIR_LO/Events/run_02
    gunzip -d  unweighted_events.lhe.gz
    cp unweighted_events.lhe /data/amassiro/CMSSWLHE/WW2jetsMadgraph/QCD_1M.lhe
    cd -
    
    cd WW2j_EWK_DIR_LO/Events/run_02
    gunzip -d  unweighted_events.lhe.gz
    cp unweighted_events.lhe /data/amassiro/CMSSWLHE/WW2jetsMadgraph/EWK_1M.lhe
    cd -
    
    cd WW2j_EWKQCD_DIR_LO/Events/run_02
    gunzip -d  unweighted_events.lhe.gz
    cp unweighted_events.lhe /data/amassiro/CMSSWLHE/WW2jetsMadgraph/EWKQCD_1M.lhe
    cd -
    
    cmsneu
    /home/amassiro/Generation/MINLO/WW2jewk/Interference/

LHE files here:

    /data/amassiro/CMSSWLHE/WW2jetsMadgraph

Dump sensitive information into a root file

    c++ -o ntupleMaker.exe `root-config --glibs --cflags` `lhapdf-config --cppflags  --ldflags` -lm ntupleMaker.cpp
    ./ntupleMaker.exe   blabla.lhe    blabla.root

Dump:

    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsMadgraph/EWK.lhe     EWK_MG.root
    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsMadgraph/QCD.lhe     QCD_MG.root
    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsMadgraph/EWKQCD.lhe  EWKQCD_MG.root
    
    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsMadgraph/EWK_1M.lhe     EWK_MG.root
    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsMadgraph/QCD_1M.lhe     QCD_MG.root
    ./ntupleMaker.exe   /data/amassiro/CMSSWLHE/WW2jetsMadgraph/EWKQCD_1M.lhe  EWKQCD_MG.root

Cross-section:

         with 10k events                    with 1M events
    0.008021 +- 2.212e-05 pb  EWK        0.008115 +- 2.12e-06 pb
    0.1663 +- 0.0003664 pb    QCD        0.1668 +- 5.003e-05 pb
    0.1743 +- 0.0003675 pb    EWKQCD     0.1754 +- 5.231e-05 pb

    
Draw:

    r00t  DrawMG.cxx\(\"mWW\",100,0,2000,\"mWW\ [GeV]\"\)
    r00t  DrawMG.cxx\(\"mWW\",50,0,2000,\"mWW\ [GeV]\"\)
    r00t  DrawMG.cxx\(\"mjj\",300,0,6000,\"mjj\ [GeV]\"\)
    r00t  DrawMG.cxx\(\"mjj\",100,0,2000,\"mjj\ [GeV]\"\)
    r00t  DrawMG.cxx\(\"mjj\",30,0,4000,\"mjj\ [GeV]\"\)
    r00t  DrawMG.cxx\(\"mll\",100,0,200,\"mll\ [GeV]\"\)
    r00t  DrawMG.cxx\(\"mll\",100,0,2000,\"mll\ [GeV]\"\)
    r00t  DrawMG.cxx\(\"jetpt1\",100,0,200\,\"jetpt1\ [GeV]\"\)
    r00t  DrawMG.cxx\(\"jetpt1\",100,0,2000\,\"jetpt1\ [GeV]\"\)
    r00t  DrawMG.cxx\(\"jetpt2\",100,0,200,\"jetpt2\ [GeV]\"\)
    r00t  DrawMG.cxx\(\"pt1\",100,0,200,\"pt1\ [GeV]\"\)
    r00t  DrawMG.cxx\(\"pt2\",100,0,200,\"pt2\ [GeV]\"\)


    
        
    
    
    

    
    
    
    
    