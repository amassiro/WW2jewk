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

rm test/WW2jewk/DYRinout/result-value-shape.txt
rm test/WW2jewk/DYRinout/result-value-ee-shape.txt
rm test/WW2jewk/DYRinout/result-value-mumu-shape.txt
rm test/WW2jewk/DYRinout/result-syst-shape.txt
rm test/WW2jewk/DYRinout/result-syst-ee-shape.txt
rm test/WW2jewk/DYRinout/result-syst-mumu-shape.txt
rm test/WW2jewk/DYRinout/result-syst-stat-shape.txt
rm test/WW2jewk/DYRinout/result-syst-stat-ee-shape.txt
rm test/WW2jewk/DYRinout/result-syst-stat-mumu-shape.txt
rm test/WW2jewk/DYRinout/result-syst-stat-MC-shape.txt
rm test/WW2jewk/DYRinout/result-syst-stat-MC-ee-shape.txt
rm test/WW2jewk/DYRinout/result-syst-stat-MC-mumu-shape.txt
rm test/WW2jewk/DYRinout/result-syst-method-shape.txt
rm test/WW2jewk/DYRinout/result-syst-method-ee-shape.txt
rm test/WW2jewk/DYRinout/result-syst-method-mumu-shape.txt
rm test/WW2jewk/DYRinout/result-syst-method-MC-shape.txt
rm test/WW2jewk/DYRinout/result-syst-method-MC-ee-shape.txt
rm test/WW2jewk/DYRinout/result-syst-method-MC-mumu-shape.txt
rm test/WW2jewk/DYRinout/result-SF-shape.txt
rm test/WW2jewk/DYRinout/result-SF-ee-shape.txt
rm test/WW2jewk/DYRinout/result-SF-mumu-shape.txt
rm test/WW2jewk/DYRinout/result-SF-MC-shape.txt
rm test/WW2jewk/DYRinout/result-SF-MC-ee-shape.txt
rm test/WW2jewk/DYRinout/result-SF-MC-mumu-shape.txt
rm test/WW2jewk/DYRinout/result-R-shape.txt

echo DY     > test/WW2jewk/DYRinout/result-value-shape.txt
echo DYee   > test/WW2jewk/DYRinout/result-value-ee-shape.txt
echo DYmumu > test/WW2jewk/DYRinout/result-value-mumu-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-syst-shape.txt
echo DYee   > test/WW2jewk/DYRinout/result-syst-ee-shape.txt
echo DYmumu > test/WW2jewk/DYRinout/result-syst-mumu-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-syst-stat-shape.txt
echo DYee   > test/WW2jewk/DYRinout/result-syst-stat-ee-shape.txt
echo DYmumu > test/WW2jewk/DYRinout/result-syst-stat-mumu-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-syst-stat-MC-shape.txt
echo DYee   > test/WW2jewk/DYRinout/result-syst-stat-MC-ee-shape.txt
echo DYmumu > test/WW2jewk/DYRinout/result-syst-stat-MC-mumu-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-syst-method-shape.txt
echo DYee   > test/WW2jewk/DYRinout/result-syst-method-ee-shape.txt
echo DYmumu > test/WW2jewk/DYRinout/result-syst-method-mumu-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-syst-method-MC-shape.txt
echo DYee   > test/WW2jewk/DYRinout/result-syst-method-MC-ee-shape.txt
echo DYmumu > test/WW2jewk/DYRinout/result-syst-method-MC-mumu-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-SF-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-SF-ee-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-SF-mumu-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-SF-MC-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-SF-MC-ee-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-SF-MC-mumu-shape.txt
echo DY     > test/WW2jewk/DYRinout/result-R-shape.txt


for ((i=1; i<2; i++)) do  echo "r00t test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\\\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\\\",$i,2,\\"-shape\\"\)" ; done
for ((i=1; i<2; i++)) do  r00t test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\",$i,2,\"-shape\"\) ; done



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
r00t test/CorrectTop.cxx\(\"TopCard_2j-cut-of_new.txt\",4\)
rm TopCard_2j-cut-of-ScaleFactor_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-SF-cut-of-0.txt >>  TopCard_2j-cut-of-ScaleFactor_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-cut-of-ScaleFactor_new.txt\",4\)


rm test/WW2jewk/ttbar/result-eff-cut-sf.txt
for ((i=0; i<1; i++)) do root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard.cxx\($i,\"sf\"\,\"cut\",true\)  ; done 
rm TopCard_2j-cut-sf_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-cut-sf-0.txt >>  TopCard_2j-cut-sf_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-cut-sf_new.txt\",4\)
rm TopCard_2j-cut-sf-ScaleFactor_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-SF-cut-sf-0.txt >>  TopCard_2j-cut-sf-ScaleFactor_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-cut-sf-ScaleFactor_new.txt\",4\)

rm test/WW2jewk/ttbar/result-eff-cut-sfof.txt
for ((i=0; i<1; i++)) do root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard.cxx\($i,\"sfof\"\,\"cut\",true\)  ; done
rm TopCard_2j-cut-sfof_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-cut-sfof-0.txt >>  TopCard_2j-cut-sfof_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-cut-sfof_new.txt\",4\)
rm TopCard_2j-cut-sfof-ScaleFactor_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-SF-cut-sfof-0.txt >>  TopCard_2j-cut-sfof-ScaleFactor_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-cut-sfof-ScaleFactor_new.txt\",4\)





# ---- shape analysis

rm test/WW2jewk/ttbar/result-eff-shape-of.txt
for ((i=0; i<1; i++)) do root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard.cxx\($i,\"of\"\,\"shape\",true\)  ; done
rm TopCard_2j-shape-of_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-shape-of-0.txt >>  TopCard_2j-shape-of_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-shape-of_new.txt\",4\)
rm TopCard_2j-shape-of-ScaleFactor_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-SF-shape-of-0.txt >>  TopCard_2j-shape-of-ScaleFactor_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-shape-of-ScaleFactor_new.txt\",4\)


rm test/WW2jewk/ttbar/result-eff-shape-sf.txt
for ((i=0; i<1; i++)) do root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard.cxx\($i,\"sf\"\,\"shape\",true\)  ; done 
rm TopCard_2j-shape-sf_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-shape-sf-0.txt >>  TopCard_2j-shape-sf_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-shape-sf_new.txt\",4\)
rm TopCard_2j-shape-sf-ScaleFactor_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-SF-shape-sf-0.txt >>  TopCard_2j-shape-sf-ScaleFactor_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-shape-sf-ScaleFactor_new.txt\",4\)

rm test/WW2jewk/ttbar/result-eff-shape-sfof.txt
for ((i=0; i<1; i++)) do root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard.cxx\($i,\"sfof\"\,\"shape\",true\)  ; done
rm TopCard_2j-shape-sfof_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-shape-sfof-0.txt >>  TopCard_2j-shape-sfof_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-shape-sfof_new.txt\",4\)
rm TopCard_2j-shape-sfof-ScaleFactor_new.txt
for ((i=0; i<1; i++)) do cat test/WW2jewk/ttbar/result-SF-shape-sfof-0.txt >>  TopCard_2j-shape-sfof-ScaleFactor_new.txt  ; done
r00t test/CorrectTop.cxx\(\"TopCard_2j-shape-sfof-ScaleFactor_new.txt\",4\)















# prepare data driven #
r00t test/createDDAnalysisWW2jewk.cxx\(\"-shape\"\)

