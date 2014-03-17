#
# do-DY.sh
#

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


for ((i=1; i<5; i++)) do  echo "root -l  test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\\\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\\\",$i,5,\\"\\"\)" ; done
for ((i=1; i<5; i++)) do  root -l  test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\",$i,5,\"\"\) ; done



more test/WW2jewk/DYRinout/result-SF-ee-shape.txt
more test/WW2jewk/DYRinout/result-SF-mumu-shape.txt

more test/WW2jewk/DYRinout/result-SF-MC-ee-shape.txt
more test/WW2jewk/DYRinout/result-SF-MC-mumu-shape.txt


####################
#### @ WW level ####

for ((i=6; i<7; i++)) do  echo "root -l  test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\\\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\\\",$i,5,\\"-shape\\"\)" ; done
for ((i=6; i<7; i++)) do  root -l  test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\",$i,5,\"-shape\"\) ; done

for ((i=6; i<7; i++)) do  echo "root -l  test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\\\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\\\",$i,5,\\"-shape-WW\\"\)" ; done
for ((i=6; i<7; i++)) do  root -l  test/WW2jewk/DYRinout/GetDY-Result-forDataCard.cxx\(\"out_DYRinout_Latinos_2jet_WW2jewk_20Nov2000-ForResult.root\",$i,5,\"-shape-WW\"\) ; done


##################################################
##################################################

more test/WW2jewk/DYRinout/result-SF-mumu-shape-WW.txt
more test/WW2jewk/DYRinout/result-SF-ee-shape-WW.txt

more test/WW2jewk/DYRinout/result-SF-MC-mumu-shape-WW.txt
more test/WW2jewk/DYRinout/result-SF-MC-ee-shape-WW.txt

