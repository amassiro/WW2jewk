
cd /home/amassiro/Latinos/CMSSW_5_3_11_patch6/src/HWWAnalysis/ShapeAnalysis/
eval `scramv1 runtime -sh`
source test/env.sh
cd -


cd WW2jewkSFcutTCHE21
bash doIt.sh
cd ..
rm WW2jewkSFcutTCHE21.tgz
pack.py -p WW2jewkSFcutTCHE21

cd WW2jewkSFcutTCHE05
bash doIt.sh
cd ..
rm WW2jewkSFcutTCHE05.tgz
pack.py -p WW2jewkSFcutTCHE05

cd WW2jewkDFshapeTCHE21
bash doIt.sh
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-signalInjection.root --injectionSignal
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-data.root
cd ..
rm WW2jewkDFshapeTCHE21.tgz
pack.py -p WW2jewkDFshapeTCHE21

cd WW2jewkDFshapeTCHE05
bash doIt.sh
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-signalInjection.root --injectionSignal
mkAutopsy.py datacards/hww-19.36fb.mH125.of_2j_shape.txt   --dump=postFit/WWewk-error-data.root
cd ..
rm WW2jewkDFshapeTCHE05.tgz
pack.py -p WW2jewkDFshapeTCHE05

cd WW2jewkDFcutTCHE05
bash doIt.sh
cd ..
rm WW2jewkDFcutTCHE05.tgz
pack.py -p WW2jewkDFcutTCHE05

cd WW2jewkDFcutTCHE21
bash doIt.sh
cd ..
rm WW2jewkDFcutTCHE21.tgz
pack.py -p WW2jewkDFcutTCHE21

