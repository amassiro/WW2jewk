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
