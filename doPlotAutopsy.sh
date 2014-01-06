
cd /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/HWWAnalysis/ShapeAnalysis/
eval `scramv1 runtime -sh`
source test/env.sh
cd -

cd WW2jewkDFshapeTCHE21
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-signalInjection.root --injectionSignal
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-data.root
cd ..

cd WW2jewkDFshapeTCHE05
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-signalInjection.root --injectionSignal
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-data.root
cd ..

cd WW2jewkDFcutTCHE05
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-signalInjection.root --injectionSignal
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-data.root
cd ..

cd WW2jewkDFcutTCHE21
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-signalInjection.root --injectionSignal
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-data.root
cd ..

