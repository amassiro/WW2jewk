
# ---- shape based analysis
# GetTop_Macro_forDataCard_Complete(int iWP, std::string suffix = "of", std::string whatAnalysis = "shape", bool doEnrichToGetEvents = false, int binCutPt = 0, int binTCHE = 0

# pt 0 thce 0

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-0-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,0,0\)
rm TopCard_2j-shape-of-pt-0-tche-0.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-0-tche-0-0.txt >>  TopCard_2j-shape-of-pt-0-tche-0.txt
rm TopCard_2j-shape-of-pt-0-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-0-tche-0-0.txt >>  TopCard_2j-shape-of-pt-0-tche-0-ScaleFactor.txt


# pt 0 thce 1

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-0-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,0,1\)
rm TopCard_2j-shape-of-pt-0-tche-1.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-0-tche-1-0.txt >>  TopCard_2j-shape-of-pt-0-tche-1.txt
rm TopCard_2j-shape-of-pt-0-tche-1-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-0-tche-1-0.txt >>  TopCard_2j-shape-of-pt-0-tche-1-ScaleFactor.txt


# pt 1 thce 0

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-1-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,1,0\)
rm TopCard_2j-shape-of-pt-1-tche-0.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-1-tche-0-0.txt >>  TopCard_2j-shape-of-pt-1-tche-0.txt
rm TopCard_2j-shape-of-pt-1-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-1-tche-0-0.txt >>  TopCard_2j-shape-of-pt-1-tche-0-ScaleFactor.txt


# pt 1 thce 1

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-1-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,1,1\)
rm TopCard_2j-shape-of-pt-1-tche-1.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-1-tche-1-0.txt >>  TopCard_2j-shape-of-pt-1-tche-1.txt
rm TopCard_2j-shape-of-pt-1-tche-1-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-1-tche-1-0.txt >>  TopCard_2j-shape-of-pt-1-tche-1-ScaleFactor.txt


# pt 2 thce 0

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-2-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,2,0\)
rm TopCard_2j-shape-of-pt-2-tche-0.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-2-tche-0-0.txt >>  TopCard_2j-shape-of-pt-2-tche-0.txt
rm TopCard_2j-shape-of-pt-2-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-2-tche-0-0.txt >>  TopCard_2j-shape-of-pt-2-tche-0-ScaleFactor.txt


# pt 2 thce 1

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-2-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,2,1\)
rm TopCard_2j-shape-of-pt-2-tche-1.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-2-tche-1-0.txt >>  TopCard_2j-shape-of-pt-2-tche-1.txt
rm TopCard_2j-shape-of-pt-2-tche-1-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-2-tche-1-0.txt >>  TopCard_2j-shape-of-pt-2-tche-1-ScaleFactor.txt






# pt 3 thce 0

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-3-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,3,0\)
rm TopCard_3j-shape-of-pt-3-tche-0.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-3-tche-0-0.txt >>  TopCard_3j-shape-of-pt-3-tche-0.txt
rm TopCard_3j-shape-of-pt-3-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-3-tche-0-0.txt >>  TopCard_3j-shape-of-pt-3-tche-0-ScaleFactor.txt


# pt 3 thce 1

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-3-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,3,1\)
rm TopCard_3j-shape-of-pt-3-tche-1.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-3-tche-1-0.txt >>  TopCard_3j-shape-of-pt-3-tche-1.txt
rm TopCard_3j-shape-of-pt-3-tche-1-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-3-tche-1-0.txt >>  TopCard_3j-shape-of-pt-3-tche-1-ScaleFactor.txt






# pt 4 thce 0

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-4-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,4,0\)
rm TopCard_4j-shape-of-pt-4-tche-0.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-4-tche-0-0.txt >>  TopCard_4j-shape-of-pt-4-tche-0.txt
rm TopCard_4j-shape-of-pt-4-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-4-tche-0-0.txt >>  TopCard_4j-shape-of-pt-4-tche-0-ScaleFactor.txt


# pt 4 thce 1

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-4-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,4,1\)
rm TopCard_4j-shape-of-pt-4-tche-1.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-4-tche-1-0.txt >>  TopCard_4j-shape-of-pt-4-tche-1.txt
rm TopCard_4j-shape-of-pt-4-tche-1-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-4-tche-1-0.txt >>  TopCard_4j-shape-of-pt-4-tche-1-ScaleFactor.txt





# pt 5 thce 0

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-5-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,5,0\)
rm TopCard_5j-shape-of-pt-5-tche-0.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-5-tche-0-0.txt >>  TopCard_5j-shape-of-pt-5-tche-0.txt
rm TopCard_5j-shape-of-pt-5-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-5-tche-0-0.txt >>  TopCard_5j-shape-of-pt-5-tche-0-ScaleFactor.txt


# pt 5 thce 1

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-5-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,5,1\)
rm TopCard_5j-shape-of-pt-5-tche-1.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-5-tche-1-0.txt >>  TopCard_5j-shape-of-pt-5-tche-1.txt
rm TopCard_5j-shape-of-pt-5-tche-1-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-5-tche-1-0.txt >>  TopCard_5j-shape-of-pt-5-tche-1-ScaleFactor.txt






# pt 6 thce 0

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-6-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,6,0\)
rm TopCard_6j-shape-of-pt-6-tche-0.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-6-tche-0-0.txt >>  TopCard_6j-shape-of-pt-6-tche-0.txt
rm TopCard_6j-shape-of-pt-6-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-6-tche-0-0.txt >>  TopCard_6j-shape-of-pt-6-tche-0-ScaleFactor.txt


# pt 6 thce 1

rm test/WW2jewk/ttbar/result-eff-shape-of-pt-6-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,6,1\)
rm TopCard_6j-shape-of-pt-6-tche-1.txt
cat test/WW2jewk/ttbar/result-shape-of-pt-6-tche-1-0.txt >>  TopCard_6j-shape-of-pt-6-tche-1.txt
rm TopCard_6j-shape-of-pt-6-tche-1-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-shape-of-pt-6-tche-1-0.txt >>  TopCard_6j-shape-of-pt-6-tche-1-ScaleFactor.txt

























# pt 3 thce 0

# rm test/WW2jewk/ttbar/result-eff-shape-of-pt-3-tche-0.txt
# root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,3,0\)
# rm TopCard_2j-shape-of-pt-3-tche-0.txt
# cat test/WW2jewk/ttbar/result-shape-of-pt-3-tche-0-0.txt >>  TopCard_2j-shape-of-pt-3-tche-0.txt
# rm TopCard_2j-shape-of-pt-3-tche-0-ScaleFactor.txt
# cat test/WW2jewk/ttbar/result-SF-shape-of-pt-3-tche-0-0.txt >>  TopCard_2j-shape-of-pt-3-tche-0-ScaleFactor.txt
# 
# 
# # pt 3 thce 1
# 
# rm test/WW2jewk/ttbar/result-eff-shape-of-pt-3-tche-1.txt
# root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,3,1\)
# rm TopCard_2j-shape-of-pt-3-tche-1.txt
# cat test/WW2jewk/ttbar/result-shape-of-pt-3-tche-1-0.txt >>  TopCard_2j-shape-of-pt-3-tche-1.txt
# rm TopCard_2j-shape-of-pt-3-tche-1-ScaleFactor.txt
# cat test/WW2jewk/ttbar/result-SF-shape-of-pt-3-tche-1-0.txt >>  TopCard_2j-shape-of-pt-3-tche-1-ScaleFactor.txt




