~~~~~~~~~~~~~~~~~~~~~~
~~~~ MVA Variable ~~~~
~~~~~~~~~~~~~~~~~~~~~~

MVA for discrimination background vs signal

-> for different mass bins
-> trees (and variables) are a sub-set of the variables used for "MassLike" variable

///==== Latino tree ====

1) filter standard trees (go up to WW level)  -> use "output_Latinos_tree_2012_2orMoreJet2012" or "output_Latinos_tree_2012_234jet"

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

2) Train mva

   rm -r output_Latinos_tree_2012_2orMoreJet2012_MVA
   cp -r output_Latinos_tree_2012_2orMoreJet2012 output_Latinos_tree_2012_2orMoreJet2012_MVA
   ./bin/MVATrainingWW2jewk.exe test/WW2jewk/MVAWW2jewk/cfg/WWewk.cfg 
 
and test

   r00t test/TMVAGui.C\(\"outMVA_WWewk.root\"\)
   r00t test/TMVAGui.C\(\"outMVA_WWewk_improved.root\"\)

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

3) Add mva value to ntuples (local ... and latinos @cmsneu)

   rm -r output_Latinos_tree_2012_2orMoreJet2012_MVA_added
   mkdir output_Latinos_tree_2012_2orMoreJet2012_MVA_added
   ./bin/MVAAddVariableWW2jewk.exe test/WW2jewk/MVAWW2jewk/cfg-add/WW2jewk.cfg 

   rm -r output_Latinos_tree_2012_2orMoreJet2012_DY_MVA
   cp -r output_Latinos_tree_2012_2jet_DY output_Latinos_tree_2012_2orMoreJet2012_DY_MVA
   rm -r output_Latinos_tree_2012_2orMoreJet2012_DY_MVA_added
   mkdir output_Latinos_tree_2012_2orMoreJet2012_DY_MVA_added
   ./bin/MVAAddVariableWW2jewk.exe test/WW2jewk/MVAWW2jewk/cfg-add/WW2jewk-DY.cfg 

   bash test/WW2jewk/DYRinout/dody.sh
   bash test/WW2jewk/ttbar/dottbarshape.sh
   bash test/WW2jewk/ttbar/dottbar.sh
   
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

4) Draw distributions

  ./bin/MCDATAComparisonPLOTTool.exe test/WW2jewk/Plot/testMCDATAComparisonPLOTTool_MVA.cfg
  r00t AMPlotMacroCreator_Moriond.cxx

  
 




on CMSNEU
====



Filter
====

How to filter folders with a TFormula string

    ls --color=none /home/amassiro/Latinos/Shape/tree_skim_all/ | awk '{print "gardener.py  filter -f \"njet>=2 && pfmet>20\"   -r  -F  /home/amassiro/Latinos/Shape/tree_skim_all/"$1"  /data/amassiro/LatinosTrees/tree_skim_all_2j/"$1   }'

    
WW+2j new variable
====

new variables


    ls --color=none /data/amassiro/LatinosTrees/tree_skim_all_2j/ | awk '{print "gardener.py  ww2jVar -r  -F  /data/amassiro/LatinosTrees/tree_skim_all_2j/"$1"  /data/amassiro/LatinosTrees/tree_skim_all_2j_mva/"$1   }'



WW+2j mva addition
====

mva addition

    ls --color=none /data/amassiro/LatinosTrees/tree_skim_all_2j_mva/ | awk '{print "gardener.py  wwewkMVAVar -r  -F  /data/amassiro/LatinosTrees/tree_skim_all_2j_mva/"$1"  /data/amassiro/LatinosTrees/tree_skim_all_2j_mva_new/"$1   }'



































