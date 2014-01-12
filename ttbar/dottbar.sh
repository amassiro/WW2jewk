
# ---- cut based analysis
# GetTop_Macro_forDataCard_Complete(int iWP, std::string suffix = "of", std::string whatAnalysis = "cut", bool doEnrichToGetEvents = false, int binCutPt = 0, int binTCHE = 0

# pt 0 thce 0

rm test/WW2jewk/ttbar/result-eff-cut-of-pt-0-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,4,0\)
rm TopCard_2j-cut-of-pt-0-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-of-pt-0-tche-0-0.txt >>  TopCard_2j-cut-of-pt-0-tche-0.txt
rm TopCard_2j-cut-of-pt-0-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-cut-of-pt-0-tche-0-0.txt >>  TopCard_2j-cut-of-pt-0-tche-0-ScaleFactor.txt

rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-0-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,4,0\)
rm TopCard_2j-cut-sf-pt-0-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-sf-pt-0-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-0-tche-0.txt
rm TopCard_2j-cut-sf-pt-0-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-0-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-0-tche-0-ScaleFactor.txt

rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-0-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,4,0\)
rm TopCard_2j-cut-sfof-pt-0-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-sfof-pt-0-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-0-tche-0.txt
rm TopCard_2j-cut-sfof-pt-0-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-0-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-0-tche-0-ScaleFactor.txt


# pt 0 thce 1

rm test/WW2jewk/ttbar/result-eff-cut-of-pt-0-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,4,1\)
rm TopCard_2j-cut-of-pt-0-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-of-pt-0-tche-1-0.txt >>  TopCard_2j-cut-of-pt-0-tche-1.txt
rm TopCard_2j-cut-of-pt-0-tche-1-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-cut-of-pt-0-tche-1-0.txt >>  TopCard_2j-cut-of-pt-0-tche-1-ScaleFactor.txt

rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-0-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,4,1\)
rm TopCard_2j-cut-sf-pt-0-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-sf-pt-0-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-0-tche-1.txt
rm TopCard_2j-cut-sf-pt-0-tche-1-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-0-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-0-tche-1-ScaleFactor.txt

# rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-0-tche-1.txt
# root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,4,1\)
# rm TopCard_2j-cut-sfof-pt-0-tche-1.txt
# cat test/WW2jewk/ttbar/result-cut-sfof-pt-0-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-0-tche-1.txt
# rm TopCard_2j-cut-sfof-pt-0-tche-1-ScaleFactor.txt
# cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-0-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-0-tche-1-ScaleFactor.txt



# pt 1 thce 0

rm test/WW2jewk/ttbar/result-eff-cut-of-pt-1-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,5,0\)
rm TopCard_2j-cut-of-pt-1-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-of-pt-1-tche-0-0.txt >>  TopCard_2j-cut-of-pt-1-tche-0.txt
rm TopCard_2j-cut-of-pt-1-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-cut-of-pt-1-tche-0-0.txt >>  TopCard_2j-cut-of-pt-1-tche-0-ScaleFactor.txt

rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-1-tche-0.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,5,0\)
rm TopCard_2j-cut-sf-pt-1-tche-0.txt
cat test/WW2jewk/ttbar/result-cut-sf-pt-1-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-1-tche-0.txt
rm TopCard_2j-cut-sf-pt-1-tche-0-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-1-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-1-tche-0-ScaleFactor.txt

# rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-1-tche-0.txt
# root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,5,0\)
# rm TopCard_2j-cut-sfof-pt-1-tche-0.txt
# cat test/WW2jewk/ttbar/result-cut-sfof-pt-1-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-1-tche-0.txt
# rm TopCard_2j-cut-sfof-pt-1-tche-0-ScaleFactor.txt
# cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-1-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-1-tche-0-ScaleFactor.txt


# pt 1 thce 1

rm test/WW2jewk/ttbar/result-eff-cut-of-pt-1-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,5,1\)
rm TopCard_2j-cut-of-pt-1-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-of-pt-1-tche-1-0.txt >>  TopCard_2j-cut-of-pt-1-tche-1.txt
rm TopCard_2j-cut-of-pt-1-tche-1-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-cut-of-pt-1-tche-1-0.txt >>  TopCard_2j-cut-of-pt-1-tche-1-ScaleFactor.txt

rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-1-tche-1.txt
root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,5,1\)
rm TopCard_2j-cut-sf-pt-1-tche-1.txt
cat test/WW2jewk/ttbar/result-cut-sf-pt-1-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-1-tche-1.txt
rm TopCard_2j-cut-sf-pt-1-tche-1-ScaleFactor.txt
cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-1-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-1-tche-1-ScaleFactor.txt

# rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-1-tche-1.txt
# root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,5,1\)
# rm TopCard_2j-cut-sfof-pt-1-tche-1.txt
# cat test/WW2jewk/ttbar/result-cut-sfof-pt-1-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-1-tche-1.txt
# rm TopCard_2j-cut-sfof-pt-1-tche-1-ScaleFactor.txt
# cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-1-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-1-tche-1-ScaleFactor.txt



# pt 2 thce 0

# rm test/WW2jewk/ttbar/result-eff-cut-of-pt-2-tche-0.txt
# root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,2,0\)
# rm TopCard_2j-cut-of-pt-2-tche-0.txt
# cat test/WW2jewk/ttbar/result-cut-of-pt-2-tche-0-0.txt >>  TopCard_2j-cut-of-pt-2-tche-0.txt
# rm TopCard_2j-cut-of-pt-2-tche-0-ScaleFactor.txt
# cat test/WW2jewk/ttbar/result-SF-cut-of-pt-2-tche-0-0.txt >>  TopCard_2j-cut-of-pt-2-tche-0-ScaleFactor.txt
# 
# rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-2-tche-0.txt
# root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,2,0\)
# rm TopCard_2j-cut-sf-pt-2-tche-0.txt
# cat test/WW2jewk/ttbar/result-cut-sf-pt-2-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-2-tche-0.txt
# rm TopCard_2j-cut-sf-pt-2-tche-0-ScaleFactor.txt
# cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-2-tche-0-0.txt >>  TopCard_2j-cut-sf-pt-2-tche-0-ScaleFactor.txt
# 
# rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-2-tche-0.txt
# root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,2,0\)
# rm TopCard_2j-cut-sfof-pt-2-tche-0.txt
# cat test/WW2jewk/ttbar/result-cut-sfof-pt-2-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-2-tche-0.txt
# rm TopCard_2j-cut-sfof-pt-2-tche-0-ScaleFactor.txt
# cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-2-tche-0-0.txt >>  TopCard_2j-cut-sfof-pt-2-tche-0-ScaleFactor.txt


# pt 2 thce 1

# rm test/WW2jewk/ttbar/result-eff-cut-of-pt-2-tche-1.txt
# root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"cut\",true,2,1\)
# rm TopCard_2j-cut-of-pt-2-tche-1.txt
# cat test/WW2jewk/ttbar/result-cut-of-pt-2-tche-1-0.txt >>  TopCard_2j-cut-of-pt-2-tche-1.txt
# rm TopCard_2j-cut-of-pt-2-tche-1-ScaleFactor.txt
# cat test/WW2jewk/ttbar/result-SF-cut-of-pt-2-tche-1-0.txt >>  TopCard_2j-cut-of-pt-2-tche-1-ScaleFactor.txt
# 
# rm test/WW2jewk/ttbar/result-eff-cut-sf-pt-2-tche-1.txt
# root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sf\"\,\"cut\",true,2,1\)
# rm TopCard_2j-cut-sf-pt-2-tche-1.txt
# cat test/WW2jewk/ttbar/result-cut-sf-pt-2-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-2-tche-1.txt
# rm TopCard_2j-cut-sf-pt-2-tche-1-ScaleFactor.txt
# cat test/WW2jewk/ttbar/result-SF-cut-sf-pt-2-tche-1-0.txt >>  TopCard_2j-cut-sf-pt-2-tche-1-ScaleFactor.txt
# 
# rm test/WW2jewk/ttbar/result-eff-cut-sfof-pt-2-tche-1.txt
# root -l test/WW2jewk/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"sfof\"\,\"cut\",true,2,1\)
# rm TopCard_2j-cut-sfof-pt-2-tche-1.txt
# cat test/WW2jewk/ttbar/result-cut-sfof-pt-2-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-2-tche-1.txt
# rm TopCard_2j-cut-sfof-pt-2-tche-1-ScaleFactor.txt
# cat test/WW2jewk/ttbar/result-SF-cut-sfof-pt-2-tche-1-0.txt >>  TopCard_2j-cut-sfof-pt-2-tche-1-ScaleFactor.txt












