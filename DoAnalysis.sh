##################
# Shape analysis #
##################


rm -r output_Latinos_tree_2012_2orMoreJet2012
mkdir output_Latinos_tree_2012_2orMoreJet2012
ls output_Latinos_tree_2012/ |  awk '{print "./bin/FilterCut.exe output_Latinos_tree_2012/"$1" output_Latinos_tree_2012_2orMoreJet2012/"$1" 012Jet2012"}' 
ls output_Latinos_tree_2012/ |  awk '{print "./bin/FilterCut.exe output_Latinos_tree_2012/"$1" output_Latinos_tree_2012_2orMoreJet2012/"$1" 012Jet2012"}'   &> skim2j.sh
chmod +x skim2j.sh
./skim2j.sh




# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# ~~~~    Shape analysis  DYee and DYmumu  ~~~~
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# now estimation of number of events
./bin/MCDATAComparisonPLOTTool_ManyWP.exe test/WW2jewk/DYRinout/testMCDATAComparisonPLOTTool_DYRinout_AllHiggsMassPoints.cfg

rm test/WW2jewk/DYRinout/result-value.txt
rm test/WW2jewk/DYRinout/result-value-ee.txt
rm test/WW2jewk/DYRinout/result-value-mumu.txt
rm test/WW2jewk/DYRinout/result-syst.txt
rm test/WW2jewk/DYRinout/result-syst-ee.txt
rm test/WW2jewk/DYRinout/result-syst-mumu.txt
rm test/WW2jewk/DYRinout/result-syst-stat.txt
rm test/WW2jewk/DYRinout/result-syst-stat-ee.txt
rm test/WW2jewk/DYRinout/result-syst-stat-mumu.txt
rm test/WW2jewk/DYRinout/result-syst-stat-MC.txt
rm test/WW2jewk/DYRinout/result-syst-stat-MC-ee.txt
rm test/WW2jewk/DYRinout/result-syst-stat-MC-mumu.txt
rm test/WW2jewk/DYRinout/result-syst-method.txt
rm test/WW2jewk/DYRinout/result-syst-method-ee.txt
rm test/WW2jewk/DYRinout/result-syst-method-mumu.txt
rm test/WW2jewk/DYRinout/result-syst-method-MC.txt
rm test/WW2jewk/DYRinout/result-syst-method-MC-ee.txt
rm test/WW2jewk/DYRinout/result-syst-method-MC-mumu.txt
rm test/WW2jewk/DYRinout/result-SF.txt
rm test/WW2jewk/DYRinout/result-SF-ee.txt
rm test/WW2jewk/DYRinout/result-SF-mumu.txt
rm test/WW2jewk/DYRinout/result-SF-MC.txt
rm test/WW2jewk/DYRinout/result-SF-MC-ee.txt
rm test/WW2jewk/DYRinout/result-SF-MC-mumu.txt
rm test/WW2jewk/DYRinout/result-R.txt

echo DY     > test/WW2jewk/DYRinout/result-value.txt
echo DYee   > test/WW2jewk/DYRinout/result-value-ee.txt
echo DYmumu > test/WW2jewk/DYRinout/result-value-mumu.txt
echo DY     > test/WW2jewk/DYRinout/result-syst.txt
echo DYee   > test/WW2jewk/DYRinout/result-syst-ee.txt
echo DYmumu > test/WW2jewk/DYRinout/result-syst-mumu.txt
echo DY     > test/WW2jewk/DYRinout/result-syst-stat.txt
echo DYee   > test/WW2jewk/DYRinout/result-syst-stat-ee.txt
echo DYmumu > test/WW2jewk/DYRinout/result-syst-stat-mumu.txt
echo DY     > test/WW2jewk/DYRinout/result-syst-stat-MC.txt
echo DYee   > test/WW2jewk/DYRinout/result-syst-stat-MC-ee.txt
echo DYmumu > test/WW2jewk/DYRinout/result-syst-stat-MC-mumu.txt
echo DY     > test/WW2jewk/DYRinout/result-syst-method.txt
echo DYee   > test/WW2jewk/DYRinout/result-syst-method-ee.txt
echo DYmumu > test/WW2jewk/DYRinout/result-syst-method-mumu.txt
echo DY     > test/WW2jewk/DYRinout/result-syst-method-MC.txt
echo DYee   > test/WW2jewk/DYRinout/result-syst-method-MC-ee.txt
echo DYmumu > test/WW2jewk/DYRinout/result-syst-method-MC-mumu.txt
echo DY     > test/WW2jewk/DYRinout/result-SF.txt
echo DY     > test/WW2jewk/DYRinout/result-SF-ee.txt
echo DY     > test/WW2jewk/DYRinout/result-SF-mumu.txt
echo DY     > test/WW2jewk/DYRinout/result-SF-MC.txt
echo DY     > test/WW2jewk/DYRinout/result-SF-MC-ee.txt
echo DY     > test/WW2jewk/DYRinout/result-SF-MC-mumu.txt
echo DY     > test/WW2jewk/DYRinout/result-R.txt


for ((i=1; i<2; i++)) do  echo "r00t test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\\\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\\\",$i,2,\\"\\"\)" ; done
for ((i=1; i<2; i++)) do  r00t test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\",$i,2,\"\"\) ; done



more test/WW2jewk/DYRinout/result-SF-ee-shape.txt
more test/WW2jewk/DYRinout/result-SF-mumu-shape.txt

more test/WW2jewk/DYRinout/result-SF-MC-ee-shape.txt
more test/WW2jewk/DYRinout/result-SF-MC-mumu-shape.txt


####################
#### @ WW level ####

for ((i=3; i<4; i++)) do  echo "r00t test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\\\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\\\",$i,2,\\"-shape\\"\)" ; done
for ((i=3; i<4; i++)) do  r00t test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\",$i,2,\"-shape\"\) ; done

for ((i=3; i<4; i++)) do  echo "r00t test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\\\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\\\",$i,2,\\"-shape-WW\\"\)" ; done
for ((i=3; i<4; i++)) do  r00t test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\",$i,2,\"-shape-WW\"\) ; done


##################################################
##################################################

more test/WW2jewk/DYRinout/result-SF-mumu-shape-WW.txt
more test/WW2jewk/DYRinout/result-SF-ee-shape-WW.txt

more test/WW2jewk/DYRinout/result-SF-MC-mumu-shape-WW.txt
more test/WW2jewk/DYRinout/result-SF-MC-ee-shape-WW.txt



# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# ~~~~    Shape analysis  ttbar  ~~~~
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# ---- cut based analysis

rm test/WW2jewk/ttbar/result-eff-cut-of.txt
for ((i=0; i<1; i++)) do root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard.cxx\($i,\"of\"\,\"cut\",true\)  ; done
rm TopCard_2j-cut-of_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-cut-of-0.txt >>  TopCard_2j-cut-of_new.txt  ; done
rm TopCard_2j-cut-of-ScaleFactor_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-SF-cut-of-0.txt >>  TopCard_2j-cut-of-ScaleFactor_new.txt  ; done

rm test/WW2jewk/ttbar/result-eff-cut-sf.txt
for ((i=0; i<1; i++)) do root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard.cxx\($i,\"sf\"\,\"cut\",true\)  ; done 
rm TopCard_2j-cut-sf_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-cut-sf-0.txt >>  TopCard_2j-cut-sf_new.txt  ; done
rm TopCard_2j-cut-sf-ScaleFactor_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-SF-cut-sf-0.txt >>  TopCard_2j-cut-sf-ScaleFactor_new.txt  ; done

rm test/WW2jewk/ttbar/result-eff-cut-sfof.txt
for ((i=0; i<1; i++)) do root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard.cxx\($i,\"sfof\"\,\"cut\",true\)  ; done
rm TopCard_2j-cut-sfof_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-cut-sfof-0.txt >>  TopCard_2j-cut-sfof_new.txt  ; done
rm TopCard_2j-cut-sfof-ScaleFactor_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-SF-cut-sfof-0.txt >>  TopCard_2j-cut-sfof-ScaleFactor_new.txt  ; done





# ---- shape analysis

rm test/WW2jewk/ttbar/result-eff-shape-of.txt
for ((i=0; i<1; i++)) do root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard.cxx\($i,\"of\"\,\"shape\",true\)  ; done
rm TopCard_2j-shape-of_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-shape-of-0.txt >>  TopCard_2j-shape-of_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-shape-of_new.txt\",4\)
rm TopCard_2j-shape-of-ScaleFactor_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-SF-shape-of-0.txt >>  TopCard_2j-shape-of-ScaleFactor_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-shape-of-ScaleFactor_new.txt\",4\)














# prepare data driven #
r00t test/createDDAnalysisWW2jewk.cxx\(\"-shape\"\)
r00t test/createDDAnalysisWW2jewk.cxx


bash test/WW2jewk/ttbar/dottbarshape.sh
bash test/WW2jewk/ttbar/dottbar.sh





























#---- pt dependence and 2 regions in tche ----


# ---- cut based analysis
# GetTop_Macro_forDataCard_Complete(int iWP, std::string suffix = "of", std::string whatAnalysis = "cut", bool doEnrichToGetEvents = false, int binCutPt = 0, int binTCHE = 0

# pt 0 thce 0

rm test/WW2jewk/ttbar/result-eff-cut-of-pt-0-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,0,0\)
rm TopCard_2j-cut-of_new-pt-0-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-of-pt-0-tche-0-0.txt >>  TopCard_2j-cut-of-pt-0-tche-0_new.txt
rm TopCard_2j-cut-of-pt-0-tche-0-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-of-pt-0-tche-0-0.txt >>  TopCard_2j-cut-of-pt-0-tche-0-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-0-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,0,0\)
rm TopCard_2j-cut-sf_new-pt-0-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-sf-pt-0-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-0-tche-0_new.txt
rm TopCard_2j-cut-sf-pt-0-tche-0-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-0-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-0-tche-0-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-0-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,0,0\)
rm TopCard_2j-cut-sfof_new-pt-0-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-sfof-pt-0-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-0-tche-0_new.txt
rm TopCard_2j-cut-sfof-pt-0-tche-0-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-0-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-0-tche-0-ScaleFactor_new.txt


# pt 0 thce 1

rm test/WW2jewk/ttbar/result-eff-cut-of-pt-0-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,0,1\)
rm TopCard_2j-cut-of_new-pt-0-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-of-pt-0-tche-1-0.txt >>  TopCard_2j-cut-of-pt-0-tche-1_new.txt
rm TopCard_2j-cut-of-pt-0-tche-1-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-of-pt-0-tche-1-0.txt >>  TopCard_2j-cut-of-pt-0-tche-1-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-0-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,0,1\)
rm TopCard_2j-cut-sf_new-pt-0-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-sf-pt-0-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-0-tche-1_new.txt
rm TopCard_2j-cut-sf-pt-0-tche-1-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-0-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-0-tche-1-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-0-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,0,1\)
rm TopCard_2j-cut-sfof_new-pt-0-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-sfof-pt-0-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-0-tche-1_new.txt
rm TopCard_2j-cut-sfof-pt-0-tche-1-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-0-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-0-tche-1-ScaleFactor_new.txt



# pt 1 thce 0

rm test/WW2jewk/ttbar/result-eff-cut-of-pt-1-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,1,0\)
rm TopCard_2j-cut-of_new-pt-1-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-of-pt-1-tche-0-0.txt >>  TopCard_2j-cut-of-pt-1-tche-0_new.txt
rm TopCard_2j-cut-of-pt-1-tche-0-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-of-pt-1-tche-0-0.txt >>  TopCard_2j-cut-of-pt-1-tche-0-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-1-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,1,0\)
rm TopCard_2j-cut-sf_new-pt-1-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-sf-pt-1-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-1-tche-0_new.txt
rm TopCard_2j-cut-sf-pt-1-tche-0-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-1-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-1-tche-0-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-1-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,1,0\)
rm TopCard_2j-cut-sfof_new-pt-1-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-sfof-pt-1-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-1-tche-0_new.txt
rm TopCard_2j-cut-sfof-pt-1-tche-0-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-1-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-1-tche-0-ScaleFactor_new.txt


# pt 1 thce 1

rm test/WW2jewk/ttbar/result-eff-cut-of-pt-1-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,1,1\)
rm TopCard_2j-cut-of_new-pt-1-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-of-pt-1-tche-1-0.txt >>  TopCard_2j-cut-of-pt-1-tche-1_new.txt
rm TopCard_2j-cut-of-pt-1-tche-1-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-of-pt-1-tche-1-0.txt >>  TopCard_2j-cut-of-pt-1-tche-1-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-1-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,1,1\)
rm TopCard_2j-cut-sf_new-pt-1-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-sf-pt-1-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-1-tche-1_new.txt
rm TopCard_2j-cut-sf-pt-1-tche-1-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-1-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-1-tche-1-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-1-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,1,1\)
rm TopCard_2j-cut-sfof_new-pt-1-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-sfof-pt-1-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-1-tche-1_new.txt
rm TopCard_2j-cut-sfof-pt-1-tche-1-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-1-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-1-tche-1-ScaleFactor_new.txt



# pt 2 thce 0

rm test/WW2jewk/ttbar/result-eff-cut-of-pt-2-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,2,0\)
rm TopCard_2j-cut-of_new-pt-2-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-of-pt-2-tche-0-0.txt >>  TopCard_2j-cut-of-pt-2-tche-0_new.txt
rm TopCard_2j-cut-of-pt-2-tche-0-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-of-pt-2-tche-0-0.txt >>  TopCard_2j-cut-of-pt-2-tche-0-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-2-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,2,0\)
rm TopCard_2j-cut-sf_new-pt-2-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-sf-pt-2-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-2-tche-0_new.txt
rm TopCard_2j-cut-sf-pt-2-tche-0-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-2-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-2-tche-0-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-2-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,2,0\)
rm TopCard_2j-cut-sfof_new-pt-2-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-sfof-pt-2-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-2-tche-0_new.txt
rm TopCard_2j-cut-sfof-pt-2-tche-0-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-2-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-2-tche-0-ScaleFactor_new.txt


# pt 2 thce 1

rm test/WW2jewk/ttbar/result-eff-cut-of-pt-2-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,2,1\)
rm TopCard_2j-cut-of_new-pt-2-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-of-pt-2-tche-1-0.txt >>  TopCard_2j-cut-of-pt-2-tche-1_new.txt
rm TopCard_2j-cut-of-pt-2-tche-1-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-of-pt-2-tche-1-0.txt >>  TopCard_2j-cut-of-pt-2-tche-1-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-2-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,2,1\)
rm TopCard_2j-cut-sf_new-pt-2-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-sf-pt-2-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-2-tche-1_new.txt
rm TopCard_2j-cut-sf-pt-2-tche-1-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-2-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-2-tche-1-ScaleFactor_new.txt

rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-2-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,2,1\)
rm TopCard_2j-cut-sfof_new-pt-2-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-sfof-pt-2-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-2-tche-1_new.txt
rm TopCard_2j-cut-sfof-pt-2-tche-1-ScaleFactor_new.txt
cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-2-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-2-tche-1-ScaleFactor_new.txt







# ---- shape analysis

rm test/WW2jewk/ttbar/result-eff-shape-of.txt
for ((i=0; i<1; i++)) do root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard.cxx\($i,\"of\"\,\"shape\",true\)  ; done
rm TopCard_2j-shape-of_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-shape-of-0.txt >>  TopCard_2j-shape-of_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-shape-of_new.txt\",4\)
rm TopCard_2j-shape-of-ScaleFactor_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-SF-shape-of-0.txt >>  TopCard_2j-shape-of-ScaleFactor_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-shape-of-ScaleFactor_new.txt\",4\)











# prepare data driven #
r00t test/createDDAnalysisWW2jewkComplete.cxx\(\"-shape\"\)
r00t test/createDDAnalysisWW2jewkComplete.cxx







