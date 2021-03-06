import FWCore.ParameterSet.Config as cms
import WWAnalysis.Misc.VarParsing as opts
options = opts.VarParsing('analysis')

#-------------------------------------------------------------------------------
# some basic cleanup
del options._register['filePrepend']
del options._register['totalSections']
del options._register['section']
del options._register['secondaryOutputFile']
del options._singletons['filePrepend']
del options._singletons['totalSections']
del options._singletons['section']
del options._singletons['secondaryOutputFile']
del options._register['secondaryInputFiles']
del options._lists['secondaryInputFiles']
#-------------------------------------------------------------------------------

options.register ( 'summary',
                  True,
                  opts.VarParsing.multiplicity.singleton,
                  opts.VarParsing.varType.bool,
                  'Print run summary')

options.register ('reportEvery',
                  1000,
                  opts.VarParsing.multiplicity.singleton, # singleton or list
                  opts.VarParsing.varType.int,          # string, int, or float
                  'Report every events')

options.register ('eventsToProcess',
                  '',
                  opts.VarParsing.multiplicity.list,
                  opts.VarParsing.varType.string,
                  'Events to process')

options.register ('skipEvents',
                  0, # default value
                  opts.VarParsing.multiplicity.singleton, # singleton or list
                  opts.VarParsing.varType.int,          # string, int, or float
                  'Number of events to skip')

options.register ('isMC',
                  False, # default value
                  opts.VarParsing.multiplicity.singleton,
                  opts.VarParsing.varType.bool,
                  'Run in MonteCarlo mode')

options.register ('globalTag',
                  'START52_V9',
                  opts.VarParsing.multiplicity.singleton,
                  opts.VarParsing.varType.string,
                  'GlobalTag')

options.register ('doPF2PATAlso',
                  False, # default value
                  opts.VarParsing.multiplicity.singleton,
                  opts.VarParsing.varType.bool,
                  'Add pf2PAT leptons')

options.register ('doFakeRates',
                 'None', # default value
                 opts.VarParsing.multiplicity.singleton,
                 opts.VarParsing.varType.string,
                 'Turn on Fake Rates mode (can be None, \'only\', \'also\'')

options.register ('doTauEmbed',
                 False, # default value
                 opts.VarParsing.multiplicity.singleton,
                 opts.VarParsing.varType.bool,
                 'Turn on DY embedding mode (can be \'True\' or \'False\'')

options.register ('correctMetPhi',
                 False, # default value
                 opts.VarParsing.multiplicity.singleton,
                 opts.VarParsing.varType.bool,
                 'Turn on MET phi corrections (can be \'True\' or \'False\'')

options.register ('doSusy',
                  False,                                    # default value
                  opts.VarParsing.multiplicity.singleton,   # singleton or list
                  opts.VarParsing.varType.bool,
                  'Turn on Susy MC dumper (can be \'True\' or \'False\'')

options.register ('doNoFilter',
                  False,                                    # default value
                  opts.VarParsing.multiplicity.singleton,   # singleton or list
                  opts.VarParsing.varType.bool,
                  'Turn on no filter requirement, not even requiring 2 leptons! Needed for unfolding at GEN (can be \'True\' or \'False\'')

options.register ('doFatJet',
                  False,                                    # default value
                  opts.VarParsing.multiplicity.singleton,   # singleton or list
                  opts.VarParsing.varType.bool,
                  'Turn on Fat (can be \'True\' or \'False\'')

#-------------------------------------------------------------------------------
# defaults
options.outputFile = 'latinosYieldSkim.root'
options.maxEvents  = -1 #all events
#-------------------------------------------------------------------------------

options.parseArguments()

#   _____  __  __ __  __ ______     
#  |  __ \|  \/  |  \/  |  ____|    
#  | |__) | \  / | \  / | |__   ___ 
#  |  _  /| |\/| | |\/| |  __| / __|
#  | | \ \| |  | | |  | | |____\__ \
#  |_|  \_\_|  |_|_|  |_|______|___/
#                                   

isMC             = options.isMC
doPF2PATAlso     = options.doPF2PATAlso
doFakeRates      = options.doFakeRates
doTauEmbed       = options.doTauEmbed
inputFiles       = options.inputFiles
outputFile       = options.outputFile
skipEvents       = options.skipEvents
maxEvents        = options.maxEvents
summary          = options.summary
eventsToProcess  = options.eventsToProcess
reportEvery      = options.reportEvery
globalTag        = options.globalTag + "::All"
isVV             = False
doBorisGenFilter = False
correctMetPhi    = options.correctMetPhi
doSusy           = options.doSusy
doNoFilter       = options.doNoFilter
doFatJet         = options.doFatJet


labelJetRho = "RECO"
if doSusy :
    labelJetRho = "HLT"

# CMSSW Regular Stuff
process = cms.Process("Yield")

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.GeometryDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load('Configuration.EventContent.EventContent_cff')

#Options
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(summary))
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32 (maxEvents) )
if eventsToProcess:
    process.source.eventsToProcess = cms.untracked.VEventRange (eventsToProcess)

#Message Logger Stuff
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.destinations = ['cout', 'cerr']
process.MessageLogger.cerr.FwkReport.reportEvery = reportEvery
process.MessageLogger.suppressWarning = cms.untracked.vstring('patTrigger')

process.GlobalTag.globaltag = globalTag
if not isMC:
         process.GlobalTag.toGet = cms.VPSet(
         cms.PSet(record = cms.string("BTagTrackProbability2DRcd"),
         tag = cms.string("TrackProbabilityCalibration_2D_2012DataTOT_v1_offline"),
         connect = cms.untracked.string("frontier://FrontierPrep/CMS_COND_BTAU")),
         cms.PSet(record = cms.string("BTagTrackProbability3DRcd"),
         tag = cms.string("TrackProbabilityCalibration_3D_2012DataTOT_v1_offline"),
         connect = cms.untracked.string("frontier://FrontierPrep/CMS_COND_BTAU"))
         )



myfilelist=cms.untracked.vstring()
myfilelist.extend(
  [
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_1.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_10.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_100.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_101.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_102.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_103.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_104.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_105.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_106.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_107.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_108.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_109.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_11.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_110.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_111.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_112.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_113.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_114.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_115.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_116.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_117.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_118.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_119.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_12.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_120.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_121.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_122.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_123.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_125.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_126.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_127.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_128.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_129.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_13.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_130.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_131.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_132.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_133.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_134.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_135.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_136.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_137.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_138.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_139.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_14.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_140.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_141.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_142.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_143.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_144.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_145.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_146.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_147.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_148.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_149.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_15.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_150.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_151.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_152.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_153.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_154.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_155.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_156.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_157.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_158.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_159.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_16.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_160.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_161.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_162.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_163.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_164.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_165.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_167.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_168.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_169.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_17.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_170.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_171.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_172.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_173.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_174.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_175.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_176.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_177.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_178.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_179.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_18.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_180.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_181.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_182.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_183.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_184.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_185.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_186.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_187.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_188.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_189.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_19.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_190.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_191.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_192.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_193.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_194.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_195.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_196.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_197.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_198.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_199.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_2.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_20.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_200.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_201.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_202.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_203.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_204.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_205.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_206.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_207.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_208.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_209.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_21.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_210.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_211.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_212.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_213.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_214.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_215.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_216.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_217.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_218.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_219.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_22.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_220.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_221.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_222.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_223.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_224.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_225.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_226.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_227.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_228.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_229.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_23.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_230.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_231.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_232.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_233.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_234.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_235.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_236.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_237.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_238.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_239.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_24.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_240.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_241.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_242.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_243.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_244.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_245.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_246.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_247.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_248.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_249.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_25.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_250.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_251.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_252.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_253.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_254.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_255.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_256.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_257.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_258.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_259.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_26.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_260.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_261.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_262.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_263.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_264.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_265.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_266.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_267.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_268.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_269.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_27.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_270.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_271.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_272.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_273.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_274.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_275.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_276.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_277.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_278.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_279.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_28.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_280.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_281.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_282.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_283.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_284.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_285.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_286.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_287.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_288.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_289.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_29.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_290.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_291.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_292.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_293.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_294.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_295.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_297.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_298.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_299.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_3.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_30.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_300.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_301.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_302.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_303.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_304.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_305.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_306.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_307.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_308.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_309.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_31.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_310.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_311.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_312.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_313.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_314.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_315.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_316.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_317.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_318.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_319.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_32.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_320.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_321.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_322.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_323.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_324.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_325.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_326.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_327.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_328.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_329.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_33.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_330.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_331.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_332.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_333.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_334.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_335.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_336.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_338.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_339.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_34.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_340.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_341.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_342.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_343.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_344.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_345.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_346.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_347.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_348.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_349.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_35.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_350.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_351.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_352.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_353.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_354.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_355.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_356.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_357.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_358.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_359.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_36.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_360.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_361.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_362.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_363.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_364.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_365.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_366.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_367.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_368.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_369.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_37.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_370.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_371.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_372.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_373.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_374.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_375.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_376.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_377.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_378.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_379.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_38.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_380.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_381.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_382.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_383.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_384.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_385.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_386.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_387.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_388.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_389.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_39.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_390.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_391.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_4.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_40.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_41.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_42.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_43.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_44.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_45.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_46.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_47.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_48.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_49.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_5.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_50.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_51.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_52.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_53.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_55.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_56.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_57.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_58.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_6.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_60.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_61.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_62.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_63.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_64.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_65.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_66.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_67.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_68.root',
   #'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_69.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_7.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_70.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_71.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_72.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_73.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_74.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_75.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_76.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_77.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_78.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_79.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_8.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_80.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_81.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_82.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_83.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_84.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_85.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_86.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_87.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_88.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_89.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_9.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_90.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_91.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_92.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_93.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_94.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_95.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_96.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_97.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_98.root',
   'file:/media/VERBATIMASSIRONI/vbs/s/WW_AODSIM_99.root'

   ])

process.source = cms.Source('PoolSource',fileNames=myfilelist, skipEvents=cms.untracked.uint32( skipEvents ) )
#process.source = cms.Source('PoolSource',fileNames=cms.untracked.vstring( inputFiles ), skipEvents=cms.untracked.uint32( skipEvents ) )
process.out    = cms.OutputModule("PoolOutputModule", outputCommands =  cms.untracked.vstring(), fileName = cms.untracked.string( outputFile ) )

# Gives us preFakeFilter and preYieldFilter
from WWAnalysis.SkimStep.preFilterPaths_cff import addPreFilters
addPreFilters(process,isMC,doBorisGenFilter,isVV)

# pat sequence
process.load("PhysicsTools.PatAlgos.patSequences_cff")

### this is necessary to avoid the conflict between PAT and RECO configurations
### see: https://hypernews.cern.ch/HyperNews/CMS/get/JetMET/1357.html
process.kt6PFJets.doRhoFastjet = True
process.kt6PFJets.doAreaFastjet = True
process.kt6PFJets.voronoiRfact = 0.9
process.kt6PFJets.Rho_EtaMax   = cms.double( 4.4)
###


from PhysicsTools.PatAlgos.tools.coreTools import *
from PhysicsTools.PatAlgos.tools.jetTools import *
from PhysicsTools.PatAlgos.tools.helpers import *
from PhysicsTools.PatAlgos.tools.tauTools import *
from PhysicsTools.PatAlgos.tools.trigTools import *

# Trigger filter
from WWAnalysis.SkimStep.triggerInformation_cff import addTriggerPaths
jetTrigMatches = addTriggerPaths(process)

process.preLeptonSequence = cms.Sequence()

process.load('WWAnalysis.SkimStep.vertexFiltering_cff')
process.preLeptonSequence += process.firstVertexIsGood
process.preLeptonSequence += process.goodPrimaryVertices




# Rho calculations
from WWAnalysis.SkimStep.rhoCalculations_cff import addRhoVariables

addRhoVariables(process,process.preLeptonSequence)
# added them above, so can remove them here
process.pfPileUp.PFCandidates = "particleFlow"
# this breaks the pfIso
# process.pfPileUp.checkClosestZVertex = cms.bool(False)
process.pfNoPileUp.bottomCollection = "particleFlow"
#process.patDefaultSequence.remove( process.pfPileUp )    # ---> why was it removed???
#process.patDefaultSequence.remove( process.pfNoPileUp )  # ---> why was it removed???

# fix for MC 512patch1 vs 522 production (begin)
process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
# process.prePatSequence += process.PFTau ---> see process.PFTau
# fix for MC 512patch1 vs 522 production (end)


# electron ID stuff
from WWAnalysis.SkimStep.electronIDs_cff import addElectronIDs
eidModules = addElectronIDs(process,process.preLeptonSequence)

# generator stuff
from WWAnalysis.SkimStep.generatorInformation_cff import addGeneratorInfo
if isMC: 
     addGeneratorInfo(process,process.preLeptonSequence)

     if doSusy :
         from WWAnalysis.SkimStep.generatorInformationSUSY_cff import additionalselect
         process.prunedGen.select.extend (additionalselect)

#print process.prunedGen.select

#  ______ _           _                     _____      _   _      
# |  ____| |         | |                   |  __ \    | | | |     
# | |__  | | ___  ___| |_ _ __ ___  _ __   | |__) |_ _| |_| |__   
# |  __| | |/ _ \/ __| __| '__/ _ \| '_ \  |  ___/ _` | __| '_ \  
# | |____| |  __/ (__| |_| | | (_) | | | | | |  | (_| | |_| | | | 
# |______|_|\___|\___|\__|_|  \___/|_| |_| |_|   \__,_|\__|_| |_| 
#                                                                 

process.patElectrons.embedPFCandidate = False
process.patElectrons.embedSuperCluster = True
process.patElectrons.embedTrack = True
process.patElectrons.addElectronID = True
process.electronMatch.matched = "prunedGen"

process.patElectrons.userData.userFloats.src = cms.VInputTag(
    cms.InputTag("eleSmurfPF03"),
    cms.InputTag("eleSmurfPF04"),
    cms.InputTag("electronPFIsoChHad03"),
    cms.InputTag("electronPFIsoNHad03"),
    cms.InputTag("electronPFIsoPhoton03"),
    cms.InputTag("electronPFIsoChHad04"),
    cms.InputTag("electronPFIsoNHad04"),
    cms.InputTag("electronPFIsoPhoton04"),
    cms.InputTag("convValueMapProd","dist"),
    cms.InputTag("convValueMapProd","dcot"),
    cms.InputTag("convValueMapProd","passVtxConvert"),
    cms.InputTag("rhoEl"),
    cms.InputTag("rhoElNoPU"),
)


process.patElectrons.isolationValues = cms.PSet(
#     pfNeutralHadrons = cms.InputTag("isoValElectronWithNeutralIso"),
#     pfChargedHadrons = cms.InputTag("isoValElectronWithChargedIso"),
#     pfPhotons = cms.InputTag("isoValElectronWithPhotonIso")
)


#Set the Pat Electrons to use the eID
for module in eidModules:
    setattr(process.patElectrons.electronIDSources,module.label(),cms.InputTag(module.label()))

process.load("WWAnalysis.Tools.convValueMapProd_cfi")
process.convValueMapProd.conversionLabel = "allConversions"
process.load("WWAnalysis.Tools.electronPFIsoMapProd_cfi")
process.eleSmurfPF03 = process.electronPFIsoMapProd.clone()
process.eleSmurfPF03.deltaR = 0.3
process.eleSmurfPF04 = process.electronPFIsoMapProd.clone()
process.eleSmurfPF04.deltaR = 0.4
process.load("WWAnalysis.Tools.electronEGammaPFIsoProd_cfi")
process.preElectronSequence = cms.Sequence(process.convValueMapProd + process.eleSmurfPF03 + process.eleSmurfPF04 + process.pfEGammaIsolationSingleType)

#  __  __                     _____      _   _
# |  \/  |                   |  __ \    | | | |
# | \  / |_   _  ___  _ __   | |__) |_ _| |_| |__
# | |\/| | | | |/ _ \| '_ \  |  ___/ _` | __| '_ \
# | |  | | |_| | (_) | | | | | |  | (_| | |_| | | |
# |_|  |_|\__,_|\___/|_| |_| |_|   \__,_|\__|_| |_|
#


process.patMuons.embedPFCandidate = False
process.patMuons.embedTrack = True
process.patMuons.userData.userFloats.src = cms.VInputTag(
    cms.InputTag("muSmurfPF"),
    cms.InputTag("rhoMu"),
     cms.InputTag("rhoMuNoPU"),
)
process.patMuons.isolationValues = cms.PSet()
process.muonMatch.matched = "prunedGen"
process.load("WWAnalysis.Tools.muonPFIsoMapProd_cfi")
process.muSmurfPF = process.muonPFIsoMapProd.clone()
process.preMuonSequence = cms.Sequence(process.muSmurfPF)

#  _   _                             _     _   _____  ______ ___  _____     _______ 
# | \ | |                   /\      | |   | | |  __ \|  ____|__ \|  __ \ /\|__   __|
# |  \| | _____      __    /  \   __| | __| | | |__) | |__     ) | |__) /  \  | |   
# | . ` |/ _ \ \ /\ / /   / /\ \ / _` |/ _` | |  ___/|  __|   / /|  ___/ /\ \ | |   
# | |\  | (_) \ V  V /   / ____ \ (_| | (_| | | |    | |     / /_| |  / ____ \| |   
# |_| \_|\___/ \_/\_/   /_/    \_\__,_|\__,_| |_|    |_|    |____|_| /_/    \_\_|   
                                                                                     
def addFastJetCorrection(process,label,seq="patDefaultSequence",thisRho="kt6PFJets"):
    corrFact = getattr(process,"patJetCorrFactors"+label)
    setattr(process,"patJetCorrFactorsFastJet"+label,corrFact.clone())
    getattr(process,"patJetCorrFactorsFastJet"+label).levels[0] = 'L1FastJet'
    getattr(process,"patJetCorrFactorsFastJet"+label).rho = cms.InputTag(thisRho,"rho",labelJetRho)
    getattr(process,"patJetCorrFactorsFastJet"+label).useRho = cms.bool(True)
    getattr(process,seq).replace(
        getattr(process,"patJetCorrFactors"+label),
        getattr(process,"patJetCorrFactors"+label) +
        getattr(process,"patJetCorrFactorsFastJet"+label)
    )
    getattr(process,"patJets"+label).jetCorrFactorsSource = cms.VInputTag(
        cms.InputTag("patJetCorrFactorsFastJet"+label) ,
        cms.InputTag("patJetCorrFactors"+label) 
    )

from PhysicsTools.PatAlgos.tools.pfTools import *

if doPF2PATAlso:
    usePF2PAT(process,runPF2PAT=True, jetAlgo="AK5", runOnMC=isMC, postfix="PFlow") 


    ##################################
    #  MVA eID
    ##################################
    process.load('EGamma.EGammaAnalysisTools.electronIdMVAProducer_cfi')
    process.eidMVASequence = cms.Sequence(  process.mvaTrigV0 )#+ process.mvaNonTrigV0 )
    #Electron ID
    process.patElectronsPFlow.electronIDSources.mvaTrigV0    = cms.InputTag("mvaTrigV0")
    #process.patElectronsPFlow.electronIDSources.mvaNonTrigV0 = cms.InputTag("mvaNonTrigV0")

    #pfLeptons Only
    process.pfLeptonsOnly=cms.Sequence(process.pfParticleSelectionSequencePFlow+process.pfPhotonSequencePFlow+process.pfMuonSequencePFlow+process.pfNoMuonPFlow+process.pfElectronSequencePFlow+process.eidMVASequence+process.patElectronsPFlow+process.patMuonsPFlow)
    #to use default sequence instead
    process.pfAllMuonsPFlow.src=cms.InputTag("pfNoPileUp")
    process.pfNoMuonPFlow.bottomCollection = cms.InputTag("pfNoPileUp")
    #add deltaBeta corr.
    process.pfIsolatedElectronsPFlow.doDeltaBetaCorrection = True
    process.pfIsolatedMuonsPFlow.doDeltaBetaCorrection = True

    ####################################
    #  changes for iso and deltaR
    ####################################
    #muons # special recipe 
    process.pfIsolatedMuonsPFlow.isolationValueMapsCharged = cms.VInputTag( cms.InputTag( 'muPFIsoValueCharged03PFlow' ) )
    process.pfIsolatedMuonsPFlow.isolationValueMapsNeutral = cms.VInputTag( cms.InputTag( 'muPFIsoValueNeutral03PFlow' ), cms.InputTag( 'muPFIsoValueGamma03PFlow' ) )
    process.pfIsolatedMuonsPFlow.deltaBetaIsolationValueMap = cms.InputTag( 'muPFIsoValuePU03PFlow' )
    process.patMuonsPFlow.isolationValues.pfNeutralHadrons = cms.InputTag( 'muPFIsoValueNeutral03PFlow' )
    process.patMuonsPFlow.isolationValues.pfPhotons = cms.InputTag( 'muPFIsoValueGamma03PFlow' )
    process.patMuonsPFlow.isolationValues.pfChargedHadrons = cms.InputTag( 'muPFIsoValueCharged03PFlow' )
    process.patMuonsPFlow.isolationValues.pfPUChargedHadrons = cms.InputTag( 'muPFIsoValuePU03PFlow' )
    process.patMuonsPFlow.isolationValues.pfChargedAll = cms.InputTag("muPFIsoValueChargedAll03PFlow")
    #all pfMuons considered as isolated
    process.pfIsolatedMuonsPFlow.combinedIsolationCut = cms.double(9999.)
    process.pfIsolatedMuonsPFlow.isolationCut = cms.double(9999.)
    #electrons
    process.pfIsolatedElectronsPFlow.isolationValueMapsCharged = cms.VInputTag( cms.InputTag( 'elPFIsoValueCharged03PFIdPFlow' ) )
    process.pfIsolatedElectronsPFlow.isolationValueMapsNeutral = cms.VInputTag( cms.InputTag( 'elPFIsoValueNeutral03PFIdPFlow' ), cms.InputTag( 'elPFIsoValueGamma03PFIdPFlow' ) )
    process.pfIsolatedElectronsPFlow.deltaBetaIsolationValueMap = cms.InputTag( 'elPFIsoValuePU03PFIdPFlow' )
    process.patElectronsPFlow.isolationValues.pfNeutralHadrons = cms.InputTag( 'elPFIsoValueNeutral03PFIdPFlow' )
    process.patElectronsPFlow.isolationValues.pfPhotons = cms.InputTag( 'elPFIsoValueGamma03PFIdPFlow' )
    process.patElectronsPFlow.isolationValues.pfChargedHadrons = cms.InputTag( 'elPFIsoValueCharged03PFIdPFlow' )
    process.patElectronsPFlow.isolationValues.pfPUChargedHadrons = cms.InputTag( 'elPFIsoValuePU03PFIdPFlow' )
    process.patElectronsPFlow.isolationValues.pfChargedAll = cms.InputTag("elPFIsoValueChargedAll03PFIdPFlow")
    #all pfElectrons considered as isolated
    process.pfIsolatedElectronsPFlow.combinedIsolationCut = cms.double(9999.)
    process.pfIsolatedElectronsPFlow.isolationCut = cms.double(9999.)

    if not isMC:
        process.pfJetMETcorr.jetCorrLabel = cms.string("ak5PFL1FastL2L3Residual")
        removeMCMatchingPF2PAT( process, postfix="PFlow" )
        removeMCMatching( process)

else:
    if not isMC:
        removeMCMatching(process)




#      _      _      _____                                      
#     | |    | |    / ____|                                     
#     | | ___| |_  | (___   ___  __ _ _   _  ___ _ __   ___ ___ 
# _   | |/ _ \ __|  \___ \ / _ \/ _` | | | |/ _ \ '_ \ / __/ _ \
#| |__| |  __/ |_   ____) |  __/ (_| | |_| |  __/ | | | (_|  __/
# \____/ \___|\__| |_____/ \___|\__, |\__,_|\___|_| |_|\___\___|
#                                  | |                          
#                                  |_|                          

def addMETCorrections(process, isMC, correctMetPhi ):

    if not isMC:
         process.pfJetMETcorr.jetCorrLabel = cms.string("ak5PFL1FastL2L3Residual")

    # for type 1/0
    process.load("JetMETCorrections.Type1MET.pfMETCorrectionType0_cfi")
    process.pfType1CorrectedMet.applyType0Corrections = cms.bool(False)
    process.pfType1CorrectedMet.srcType1Corrections = cms.VInputTag(
        cms.InputTag('pfMETcorrType0'),
        cms.InputTag('pfJetMETcorr', 'type1')
    )

    process.patMETCorrections.replace(process.producePFMETCorrections,process.type0PFMEtCorrection+process.producePFMETCorrections)
#     process.patMETCorrections.insert(0,process.type0PFMEtCorrection)
#     process.makePatMETs.insert(0,process.type0PFMEtCorrection)

    #for met xy shift
    if correctMetPhi:
        process.load("JetMETCorrections.Type1MET.pfMETsysShiftCorrections_cfi")

        # use for 2012 Data
        if not isMC:
            process.pfMEtSysShiftCorr.parameter = process.pfMEtSysShiftCorrParameters_2012runAvsNvtx_data

        # use for Spring'12 MC
        if isMC:
            process.pfMEtSysShiftCorr.parameter = process.pfMEtSysShiftCorrParameters_2012runAvsNvtx_mc

        process.patDefaultSequence.replace(process.type0PFMEtCorrection,process.type0PFMEtCorrection+process.pfMEtSysShiftCorrSequence)

        process.pfType1CorrectedMet.srcType1Corrections = cms.VInputTag(
            cms.InputTag('pfMETcorrType0'),
            cms.InputTag('pfJetMETcorr', 'type1') ,
            cms.InputTag('pfMEtSysShiftCorr'),
        )


if isMC:
    myCorrLabels = cms.vstring('L1Offset', 'L2Relative', 'L3Absolute')
else:
    myCorrLabels = cms.vstring('L1Offset', 'L2Relative', 'L3Absolute', 'L2L3Residual')

emptyCorrLabels = cms.vstring('L1Offset')


addJetCollection(
    process,
    cms.InputTag("ak5PFJetsNoPU"),
    algoLabel        = "NoPU",
    typeLabel        = "",
    doJTA            = True,
    doBTagging       = True,
    jetCorrLabel     = ('AK5PF',myCorrLabels),
    doL1Cleaning     = False,
    doL1Counters     = True,
    doType1MET       = True,
    genJetCollection = cms.InputTag("ak5GenJets"),
    doJetID          = True,
    jetIdLabel       = 'ak5',
)


#all the other jets:
switchJetCollection(
    process,
    cms.InputTag('ak5PFJets'),
    doJTA            = True,
    doBTagging       = True,
    jetCorrLabel     = ('AK5PF',myCorrLabels),
    doType1MET       = True,
    genJetCollection = cms.InputTag("ak5GenJets"),
    doJetID          = True
)




if doFatJet :

    # for FatJets #

    from RecoJets.JetProducers.ca4PFJets_cfi import ca4PFJets

    process.ca8PFJetsPFlow = ca4PFJets.clone(
        rParam = cms.double(0.8),
        src = cms.InputTag('pfNoPileUp'),
        doAreaFastjet = cms.bool(True),
        doRhoFastjet = cms.bool(True),
        Rho_EtaMax = cms.double(4.4),  ## sure?
        Ghost_EtaMax = cms.double(5.0)  ## sure?
      )

    addJetCollection(
        process,
        cms.InputTag('ca8PFJetsPFlow'), # Jet collection; must be already in the event when patLayer0 sequence is executed
        algoLabel     = "CA8",
        typeLabel     = "PF",
        doJTA         = True, # Run Jet-Track association & JetCharge
        doBTagging    = True, # Run b-tagging
        #jetCorrLabel  = ('AK7PF',myCorrLabels),
        jetCorrLabel  = ('AK7PF',emptyCorrLabels), # ---> no jet corrections
        doType1MET    = True,
        doL1Cleaning  = False,
        doL1Counters  = False,
        #genJetCollection = cms.InputTag("ca8GenJetsNoNu"),
        doJetID       = False
        )

    process.pfInputsCA8 = cms.EDProducer(
          "CandViewNtpProducer",
          src = cms.InputTag('selectedPatJetsCA8PF', 'pfCandidates'),
          lazyParser = cms.untracked.bool(True),
          eventInfo = cms.untracked.bool(False),
          variables = cms.VPSet(
              cms.PSet(
                  tag = cms.untracked.string("px"),
                  quantity = cms.untracked.string("px")
                  ),
              cms.PSet(
                  tag = cms.untracked.string("py"),
                  quantity = cms.untracked.string("py")
                  ),
              cms.PSet(
                  tag = cms.untracked.string("pz"),
                  quantity = cms.untracked.string("pz")
                  ),
              cms.PSet(
                  tag = cms.untracked.string("energy"),
                  quantity = cms.untracked.string("energy")
                  ),
              cms.PSet(
                  tag = cms.untracked.string("pdgId"),
                  quantity = cms.untracked.string("pdgId")
                  )
              )
      )

    # add to the sequence
    process.preLeptonSequence.replace( process.pfNoPileUp, process.pfNoPileUp*process.ca8PFJetsPFlow )
    process.patDefaultSequence.replace (process.selectedPatJetsCA8PF, process.selectedPatJetsCA8PF*process.pfInputsCA8)






#### MET corrections ####

addMETCorrections(process, isMC, correctMetPhi)


# add TCVHE
#### experimental configuration from Andrea Rizzi
process.trackCounting3D1st = cms.ESProducer("TrackCountingESProducer",
    impactParameterType = cms.int32(0), ## 0 = 3D, 1 = 2D

    maximumDistanceToJetAxis = cms.double(0.07),
    deltaR = cms.double(-1.0), ## use cut from JTA

    maximumDecayLength = cms.double(5.0),
    nthTrack = cms.int32(1),
    trackQualityClass = cms.string("any")
)
process.trackCountingVeryHighEffBJetTagsAOD = process.trackCountingHighEffBJetTagsAOD.clone( jetTagComputer = 'trackCounting3D1st' )
process.patDefaultSequence.replace(
    process.trackCountingHighEffBJetTagsAOD,
    process.trackCountingHighEffBJetTagsAOD +
    process.trackCountingVeryHighEffBJetTagsAOD
)
process.patJets.discriminatorSources.append(cms.InputTag("trackCountingVeryHighEffBJetTagsAOD"))

# Need to comment out for MVAMet
# Only keep 'em above 7 GeV as the f'in Smurfs
process.selectedPatJets.cut = "correctedJet('Uncorrected').pt > 7"


# add TCVHE
process.trackCountingVeryHighEffBJetTagsNoPU = process.trackCountingHighEffBJetTagsNoPU.clone( jetTagComputer = 'trackCounting3D1st' )
process.patDefaultSequence.replace(
    process.trackCountingHighEffBJetTagsNoPU,
    process.trackCountingHighEffBJetTagsNoPU +
    process.trackCountingVeryHighEffBJetTagsNoPU
)
process.patJetsNoPU.discriminatorSources.append(cms.InputTag("trackCountingVeryHighEffBJetTagsNoPU"))

# Some stuff to save space
process.patJets.embedCaloTowers = False
process.patJetsNoPU.embedCaloTowers = False
process.patJets.addTagInfos = False
process.patJetsNoPU.addTagInfos = False
process.patJets.embedPFCandidates = False
process.patJetsNoPU.embedPFCandidates = False
process.patJets.addAssociatedTracks = False
process.patJetsNoPU.addAssociatedTracks = False

# process.patJets.embedPFCandidates = cms.bool(True)
# process.patJetsNoPU.embedPFCandidates = cms.bool(True)

# Not set up correctly by PAT:
process.cleanPatJetsNoPU = process.cleanPatJets.clone( src = cms.InputTag("selectedPatJetsNoPU") )
process.patDefaultSequence.replace(
    process.cleanPatJets,
    process.cleanPatJets +
    process.cleanPatJetsNoPU 
)

for X in jetTrigMatches:
    oldmatch = getattr(process,X)
    newmatch = oldmatch.clone( src = cms.InputTag("cleanPatJetsNoPU") )
    setattr(process, X+'NoPU', newmatch)
    process.patDefaultSequence.replace(oldmatch, oldmatch+newmatch)

process.cleanPatJetsTriggerMatchNoPU = process.cleanPatJetsTriggerMatch.clone( matches = [X+"NoPU" for X in jetTrigMatches], src = cms.InputTag("cleanPatJetsNoPU") )
process.patDefaultSequence.replace(
    process.cleanPatJetsTriggerMatch,
    process.cleanPatJetsTriggerMatch +
    process.cleanPatJetsTriggerMatchNoPU
)


# Phil Jet ID:
from CMGTools.External.puJetIDAlgo_cff import PhilV1

process.JetIDcleanPatJetsTriggerMatch = cms.EDProducer('PileupJetIdProducer',
             produceJetIds = cms.bool(True),
             jetids = cms.InputTag(""),
                         runMvas = cms.bool(True),
                         jets = cms.InputTag("cleanPatJetsTriggerMatch"),
                         vertexes = cms.InputTag("goodPrimaryVertices"),
                         algos = cms.VPSet(PhilV1),
)
process.JetIDcleanPatJetsTriggerMatchNoPU = process.JetIDcleanPatJetsTriggerMatch.clone( jets ="cleanPatJetsTriggerMatchNoPU" )


process.boostedPatJetsTriggerMatch = cms.EDProducer("PatJetBooster",
    jetTag = cms.InputTag("cleanPatJetsTriggerMatch"),
    vertexTag = cms.InputTag("goodPrimaryVertices"),
    storeJetId = cms.untracked.bool(True),  
    jetIdTag   = cms.InputTag("JetIDcleanPatJetsTriggerMatch:philv1Id"),
    jetMvaTag  = cms.InputTag("JetIDcleanPatJetsTriggerMatch:philv1Discriminant")
)
process.boostedPatJetsTriggerMatchNoPU = process.boostedPatJetsTriggerMatch.clone( 
    jetTag    = "cleanPatJetsTriggerMatchNoPU" ,
    jetIdTag  = "JetIDcleanPatJetsTriggerMatchNoPU:philv1Id" ,
    jetMvaTag = "JetIDcleanPatJetsTriggerMatchNoPU:philv1Discriminant"
) 

process.slimPatJetsTriggerMatch = cms.EDProducer("PATJetSlimmer",
    src = cms.InputTag("boostedPatJetsTriggerMatch"),
    clearJetVars = cms.bool(True),
    clearDaughters = cms.bool(True),
    #clearJetVars = cms.bool(False),   # it was True
    #clearDaughters = cms.bool(False), # it was True
    dropSpecific = cms.bool(False),
)
process.slimPatJetsTriggerMatchNoPU = process.slimPatJetsTriggerMatch.clone( src = "boostedPatJetsTriggerMatchNoPU" ) 

process.patDefaultSequence += (
    ( process.JetIDcleanPatJetsTriggerMatch +
      process.JetIDcleanPatJetsTriggerMatchNoPU ) *
    ( process.boostedPatJetsTriggerMatch +
      process.boostedPatJetsTriggerMatchNoPU ) * 
    ( process.slimPatJetsTriggerMatch     +
      process.slimPatJetsTriggerMatchNoPU )
)

# Add the fast jet correction:
addFastJetCorrection(process,"")
addFastJetCorrection(process,"NoPU","patDefaultSequence","kt6PFJets")

#               _               _____      _ _           _   _                 
#    /\        | |             / ____|    | | |         | | (_)                
#   /  \  _   _| |_ _ __ ___  | |     ___ | | | ___  ___| |_ _  ___  _ __  ___ 
#  / /\ \| | | | __| '__/ _ \ | |    / _ \| | |/ _ \/ __| __| |/ _ \| '_ \/ __|
# / ____ \ |_| | |_| | |  __/ | |___| (_) | | |  __/ (__| |_| | (_) | | | \__ \
#/_/    \_\__,_|\__|_|  \___|  \_____\___/|_|_|\___|\___|\__|_|\___/|_| |_|___/
#                                                                              

process.load("WWAnalysis.Tools.vertexSumPtMapProd_cfi")


process.autreSeq = cms.Sequence( 
    process.vertexMapProd 
#     process.mergedSuperClusters
)

process.load("WWAnalysis.SkimStep.hzz4lDetectorIsolation_cff")

# make the crazy sequence
process.hzzIsoSequence = cms.Sequence(process.hzz4lDetectorIsolationSequence)


#  _____ _                              _   __  __ ______ _______ 
# / ____| |                            | | |  \/  |  ____|__   __|
#| |    | |__   __ _ _ __ __ _  ___  __| | | \  / | |__     | |   
#| |    | '_ \ / _` | '__/ _` |/ _ \/ _` | | |\/| |  __|    | |   
#| |____| | | | (_| | | | (_| |  __/ (_| | | |  | | |____   | |   
# \_____|_| |_|\__,_|_|  \__, |\___|\__,_| |_|  |_|______|  |_|   
#                         __/ |                                   
#                        |___/                                    

# Needed for MVAMet
# process.allReducedPFCands = cms.EDProducer("ReducedCandidatesProducer",
#                                            srcCands    = cms.InputTag("particleFlow",""),
#                                            srcVertices = cms.InputTag("goodPrimaryVertices"),
#                                            dz          = cms.double(999999999.),
#                                            ptThresh    = cms.double(0.0)
#                                            )


process.reducedPFCands = cms.EDProducer("ReducedCandidatesProducer",
                                        srcCands = cms.InputTag("particleFlow",""),
                                        srcVertices = cms.InputTag("goodPrimaryVertices"),
                                        dz = cms.double(0.1),
                                        ptThresh = cms.double(0.5)
                                        )

# Needed for pfIso
process.reducedPFCandsPfNoPU = cms.EDProducer("ReducedCandidatesProducer",
                                              srcCands = cms.InputTag("pfNoPileUp",""),
                                              srcVertices = cms.InputTag("goodPrimaryVertices"),
                                              dz = cms.double(999999999.),
                                              ptThresh = cms.double(0.0)
                                              )


process.load("WWAnalysis.Tools.interestingVertexRefProducer_cfi")
process.load("WWAnalysis.Tools.chargedMetProducer_cfi")

process.patMuonsWithTriggerNoSA = cms.EDFilter("PATMuonRefSelector",
    cut = cms.string("type!=8"),
    src = cms.InputTag("boostedMuons"),
    filter = cms.bool(False)
)

process.lepsForMET = cms.EDProducer("CandViewMerger",
    src = cms.VInputTag(cms.InputTag("patMuonsWithTriggerNoSA"), cms.InputTag("boostedElectrons"))
)


process.lowPtLeps = cms.EDFilter("CandViewRefSelector",
    src = cms.InputTag("lepsForMET"),
    cut = cms.string("pt>8"),
    filter = cms.bool(False),
)

process.interestingVertexRefProducer.leptonTags = [cms.InputTag("lowPtLeps")]

process.chargedMetProducer.collectionTag = "particleFlow"
process.chargedMetProducer.vertexTag = "interestingVertexRefProducer"
process.trackMetProducer = process.chargedMetProducer.clone(minNeutralPt = 99999., maxNeutralEta = 0)

process.chargedMetSeq = cms.Sequence( ( 
        process.patMuonsWithTriggerNoSA *
        process.lepsForMET * 
        process.lowPtLeps *
        process.interestingVertexRefProducer ) * 
    #process.chargedMetProducer +
    #process.trackMetProducer + 
    #process.allReducedPFCands *
    process.reducedPFCands +
    process.reducedPFCandsPfNoPU
)


# _______              
#|__   __|             
#   | | __ _ _   _ ___ 
#   | |/ _` | | | / __|
#   | | (_| | |_| \__ \
#   |_|\__,_|\__,_|___/
#                      

switchToPFTauHPS(
   process,
   pfTauLabelOld = cms.InputTag('shrinkingConePFTauProducer'),
   pfTauLabelNew = cms.InputTag('hpsPFTauProducer'),
   postfix=""
)

# process.selectedPatTaus.cut = (
#     "pt > 8"
#    "pt > 8 && " +
#    "tauID('leadingTrackFinding') > 0.2 && tauID('byLooseIsolation') > 0.2"
# )




#  _____                        _                _              
# / ____|                      | |              | |             
#| (___   ___  _ __ ___   ___  | |     ___ _ __ | |_ ___  _ __  
# \___ \ / _ \| '_ ` _ \ / _ \ | |    / _ \ '_ \| __/ _ \| '_ \ 
# ____) | (_) | | | | | |  __/ | |___|  __/ |_) | || (_) | | | |
#|_____/ \___/|_| |_| |_|\___| |______\___| .__/ \__\___/|_| |_|
#                                         | |                   
#                                         |_|                   
# ____                  _   _             
#|  _ \                | | (_)            
#| |_) | ___   ___  ___| |_ _ _ __   __ _ 
#|  _ < / _ \ / _ \/ __| __| | '_ \ / _` |
#| |_) | (_) | (_) \__ \ |_| | | | | (_| |
#|____/ \___/ \___/|___/\__|_|_| |_|\__, |
#                                    __/ |
#                                   |___/ 

# First boost to get the IP values
# Then boost to add the PF isolation and the 

# needed rho for electron BDTISO
process.rhoElFullEta    = process.rhoEl.clone(rhoTag = cms.untracked.InputTag("kt6PFJets","rho",labelJetRho))
process.patElectrons.userData.userFloats.src  += [ cms.InputTag("rhoElFullEta") ]
process.preLeptonSequence.replace(process.rhoEl, process.rhoEl + process.rhoElFullEta)
process.rhoMuFullEta    = process.rhoMu.clone(rhoTag = cms.untracked.InputTag("kt6PFJets","rho",labelJetRho))
process.patElectrons.userData.userFloats.src  += [ cms.InputTag("rhoMuFullEta") ]
process.preLeptonSequence.replace(process.rhoMu, process.rhoMu + process.rhoMuFullEta)

# add track IP information?
process.load("WWAnalysis.AnalysisStep.leptonBoosting_cff")
if doTauEmbed == False:
    process.preBoostedElectrons = process.boostedElectrons.clone( electronTag = cms.InputTag("cleanPatElectronsTriggerMatch") )
else :
    process.preBoostedElectrons = process.fakePreBoostedElectrons.clone (src = cms.InputTag("cleanPatElectronsTriggerMatch"))

# to correct for btag
if doTauEmbed == True :
    process.jetTracksAssociatorAtVertex.tracks = cms.InputTag("tmfTracks")


# process.preBoostedElectrons = process.boostedElectrons.clone( electronTag = cms.InputTag("cleanPatElectronsTriggerMatch") )
process.preBoostedMuons     = process.boostedMuons.clone( muonTag = cms.InputTag("cleanPatMuonsTriggerMatch") )
process.patDefaultSequence += process.preBoostedElectrons
process.patDefaultSequence += process.preBoostedMuons


# add Iso deposits 
process.load("WWAnalysis.AnalysisStep.isoAdding_cff")
process.boostedElectronsIso = process.isoAddedElectrons.clone( electronTag = "preBoostedElectrons" )
process.boostedMuonsIso = process.isoAddedMuons.clone( muonTag = "preBoostedMuons" )
# from WWAnalysis.SkimStep.hzz4lDetectorIsolation_cff import muIsoFromDepsZZ4L, eleIsoFromDepsZZ4L
# process.boostedMuonsIso.deposits     += muIsoFromDepsZZ4L
# process.boostedElectronsIso.deposits += eleIsoFromDepsZZ4L

# process.patDefaultSequence += process.hzzIsoSequence
process.patDefaultSequence += process.boostedElectronsIso
process.patDefaultSequence += process.boostedMuonsIso

# add MVA Id and MVA Iso
if doTauEmbed == True:
    process.boostedElectronsBDTID = cms.EDProducer("PatElectronUserFloatAdder",
        src = cms.InputTag("boostedElectronsIso"),
        variables = cms.PSet( 
            bdttrig = cms.string("1000"),
            bdtnontrig = cms.string("1000")
        )
    )
    process.boostedElectrons = cms.EDProducer("PatElectronUserFloatAdder",
        src = cms.InputTag("boostedElectronsBDTID"),
        variables = cms.PSet( 
            bdtisonontrig = cms.string("0")
        )
    )
else:
    process.boostedElectronsBDTID = cms.EDProducer("PatElectronBoosterBDTID", src = cms.InputTag("boostedElectronsIso"))
    process.boostedElectrons = cms.EDProducer("PatElectronBoosterBDTIso", src = cms.InputTag("boostedElectronsBDTID"), effectiveAreaTarget = cms.string("Data2011"),  rho = cms.string("rhoElFullEta"))

#process.boostedElectronsBDTID = cms.EDProducer("PatElectronBoosterBDTID", src = cms.InputTag("boostedElectronsIso"))
#process.boostedElectrons = cms.EDProducer("PatElectronBoosterBDTIso", src = cms.InputTag("boostedElectronsBDTID"), effectiveAreaTarget = cms.string("Data2011"),  rho = cms.string("rhoElFullEta"))



process.boostedMuonsBDTID = cms.EDProducer("PatMuonBoosterBDTID", 
                                           src = cms.InputTag("boostedMuonsIso"), 
                                           vertexs = cms.InputTag("goodPrimaryVertices"),
                                           pfCands = cms.InputTag("particleFlow"),
                                           rho = cms.InputTag("kt6PFJets","rho",labelJetRho),
                                           dzCut = cms.double(0.2),
                                           outputName = cms.string("bdtidnontrigDZ"))

process.boostedMuonsBDTIso = cms.EDProducer("PatMuonBoosterBDTIso", 
                                            src = cms.InputTag("boostedMuonsBDTID"),
                                            vertexs = cms.InputTag("goodPrimaryVertices"),
                                            pfCands = cms.InputTag("particleFlow"),
                                            rho = cms.InputTag("kt6PFJets","rho",labelJetRho),
                                            effectiveAreaTarget = cms.string("Fall11MC"),
                                            dzCut = cms.double(0.2),
                                            outputName = cms.string("bdtisonontrigDZ"))

process.boostedMuons = cms.EDProducer("PatMuonBoosterBDTIso", 
                                      src = cms.InputTag("boostedMuonsBDTIso"),
                                      vertexs = cms.InputTag("goodPrimaryVertices"),
                                      pfCands = cms.InputTag("pfNoPileUp"),
                                      rho = cms.InputTag("kt6PFJets","rho",labelJetRho),
                                      effectiveAreaTarget = cms.string("Fall11MC"),
                                      dzCut = cms.double(999999.),
                                      outputName = cms.string("bdtisonontrigPFNOPU"))


process.patDefaultSequence += process.boostedElectronsBDTID
process.patDefaultSequence += process.boostedElectrons
process.patDefaultSequence += process.boostedMuonsBDTID  
process.patDefaultSequence += process.boostedMuonsBDTIso  
process.patDefaultSequence += process.boostedMuons


# save pfCandidates from the jets
#process.reducedPFCandsForJet = cms.EDProducer("ReducedCandidatesForJetProducer",
                                        #srcCands = cms.InputTag("particleFlow",""),
                                        #jetTag   = cms.InputTag("ak5PFJets")
                                        #)
#process.jetPFCandidatesSeq = cms.Sequence(
     #process.reducedPFCandsForJet
#)


#   _____      _              _       _      
#  / ____|    | |            | |     | |     
# | (___   ___| |__   ___  __| |_   _| | ___ 
#  \___ \ / __| '_ \ / _ \/ _` | | | | |/ _ \
#  ____) | (__| | | |  __/ (_| | |_| | |  __/
# |_____/ \___|_| |_|\___|\__,_|\__,_|_|\___|
#                                            

process.out.outputCommands =  cms.untracked.vstring(
    'drop *',
    # Leptons
    'keep *_boostedElectrons_*_*',
    'keep *_boostedMuons_*_*',
    'keep *_cleanPatTausTriggerMatch*_*_*',
    # Jets
    'keep patJets_slimPatJetsTriggerMatch_*_*',
    'keep patJets_slimPatJetsTriggerMatchPFlow_*_*',
    'keep patJets_slimPatJetsTriggerMatchNoPU_*_*',
    #'keep recoGenJets_patJets_genJets_*',
    #'keep recoGenJets_patJetsPFlow_genJets_*',
    #'keep recoGenJets_patJetsNoPU_genJets_*',
    'keep recoGenJets_selectedPatJets_genJets_*',
    'keep recoGenJets_selectedPatJetsPFlow_genJets_*',
    'keep recoGenJets_selectedPatJetsNoPU_genJets_*',
#     'keep patJets_slimPatJetsTriggerMatchCalo_*_*',
#     'keep patJets_slimPatJetsTriggerMatchJPT_*_*',
    # Tracking
    'keep *_goodPrimaryVertices_*_*',
    #'keep *_offlineBeamSpot_*_*',
    # MET
    #'keep *_tcMet_*_*',
    #'keep *_met_*_*',
    'keep *_pfMet_*_*',
    # MC
    'keep *_prunedGen_*_*',
    'keep *_genMetTrue_*_*',
    'keep GenEventInfoProduct_generator_*_*',
    'keep LHEEventProduct_source_*_*',
    'keep *_genParticles_*_*',
    # Trigger
    'keep *_TriggerResults_*_*',
    #'keep *_vertexMapProd_*_*',
    # Misc
    'keep *_addPileupInfo_*_*',
    #'keep *_chargedMetProducer_*_*',
    #'keep *_trackMetProducer_*_*',
# Needed for MVAMet
#    'keep *_allReducedPFCands_*_*',
    'keep *_reducedPFCands_*_*',
#to be checked if replaces above collection
    'keep *_reducedPFCandsPfNoPU_*_*',
# pfConstituents of the jets
    #'keep *_reducedPFCandsForJet_*_*',
    #'keep *_particleFlow_*_RECO',
#     'keep *_mergedSuperClusters_*_'+process.name_(),
    'keep *_kt6PF*_rho_'+process.name_(),
    'keep double_kt6PFJetsCentralNeutral_rho_RECO',
    # Debug info, usually commented out
    #'keep *_patTrigger_*_*',  
    #'keep *_l1extraParticles_*_*',  
#if doPF2PATAlso...
    'keep *_patMuonsPFlow_*_Yield',
    'keep *_patElectronsPFlow_*_Yield',
    'keep *_pfType1CorrectedMet_*_Yield',
 # met xy shift correction
    'keep *_pfMEtSysShiftCorr_*_Yield',
 # for FatJet
    #'keep *_pfNoPileUp_*_*',
    'keep *_pfInputsCA8_*_*',
    'keep *_selectedPatJetsCA8PF__*',
    'keep recoGenJets_ak5GenJets*NoNu_*_Yield'
)

process.prePatSequence  = cms.Sequence( process.preLeptonSequence + process.preElectronSequence + process.preMuonSequence + process.PFTau)
process.postPatSequence = cms.Sequence( process.autreSeq + process.chargedMetSeq)
#process.postPatSequence = cms.Sequence( process.autreSeq + process.chargedMetSeq + process.jetPFCandidatesSeq)


# In order to use the good primary vertices everywhere (It would be nicer to set the proper inputTags in the first place)
massSearchReplaceAnyInputTag(process.preYieldFilter,cms.InputTag("offlinePrimaryVertices"), cms.InputTag("goodPrimaryVertices"),True)
massSearchReplaceAnyInputTag(process.prePatSequence,cms.InputTag("offlinePrimaryVertices"), cms.InputTag("goodPrimaryVertices"),True)
massSearchReplaceAnyInputTag(process.patDefaultSequence,cms.InputTag("offlinePrimaryVertices"), cms.InputTag("goodPrimaryVertices"),True)
massSearchReplaceAnyInputTag(process.postPatSequence,cms.InputTag("offlinePrimaryVertices"), cms.InputTag("goodPrimaryVertices"),True)

#Vertex definition
if doPF2PATAlso:
    massSearchReplaceAnyInputTag(process.patPF2PATSequencePFlow,cms.InputTag("offlinePrimaryVertices"), cms.InputTag("goodPrimaryVertices"))
    removeMCMatching( process,['Muons','Electrons'], postfix="PFlow" )

process.firstVertexIsGood.vertices = cms.InputTag("offlinePrimaryVertices")
process.goodPrimaryVertices.src = cms.InputTag("offlinePrimaryVertices")

process.scrap      = cms.Path( process.noscraping ) 
process.outpath    = cms.EndPath(process.out)

if  doPF2PATAlso:
    process.patPath = cms.Path( process.preYieldFilter + process.prePatSequence * process.patDefaultSequence * process.pfLeptonsOnly * process.postPatSequence )
    process.fakPath = cms.Path( process.preFakeFilter + process.prePatSequence * process.patDefaultSequence * process.pfLeptonsOnly * process.postPatSequence )
    process.allPath = cms.Path(                         process.prePatSequence * process.patDefaultSequence * process.pfLeptonsOnly * process.postPatSequence )

else:
    process.patPath = cms.Path( process.preYieldFilter + process.prePatSequence * process.patDefaultSequence * process.postPatSequence)
    process.fakPath = cms.Path( process.preFakeFilter + process.prePatSequence * process.patDefaultSequence * process.postPatSequence )
    process.allPath = cms.Path(                         process.prePatSequence * process.patDefaultSequence * process.postPatSequence )

process.out.SelectEvents   = cms.untracked.PSet(SelectEvents = cms.vstring('patPath'))

# from WWAnalysis.SkimStep.skimTools import addIsolationInformation
# addIsolationInformation(process)

if doFakeRates == 'None':
    process.schedule = cms.Schedule( process.patPath, process.scrap, process.outpath)
elif doFakeRates == 'also':
    process.out.SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring( 'patPath', 'fakPath' ))
    process.countOverlaps = cms.Path(process.preYieldFilter + process.preFakeFilter)
    process.schedule = cms.Schedule( process.patPath, process.fakPath, process.countOverlaps, process.scrap, process.outpath)
elif doFakeRates == 'only':
    process.out.SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring( 'fakPath' ))
    process.schedule = cms.Schedule( process.fakPath, process.scrap, process.outpath)

if doNoFilter :
    ##Extra GenJets
    process.load('RecoJets.Configuration.RecoGenJets_cff')
    process.load('RecoJets.Configuration.GenJetParticles_cff')
    process.genParticlesForJetsNoElNoMuNoNu = process.genParticlesForJetsNoMuNoNu.clone()
    process.genParticlesForJetsNoElNoMuNoNu.ignoreParticleIDs += cms.vuint32( 11)
    process.ak5GenJetsNoElNoMuNoNu = process.ak5GenJetsNoMuNoNu.clone()
    process.ak5GenJetsNoElNoMuNoNu.src = cms.InputTag("genParticlesForJetsNoElNoMuNoNu")
    process.extraGenJets = cms.Sequence(process.genParticlesForJetsNoNu+process.ak5GenJetsNoNu+process.genParticlesForJetsNoMuNoNu+process.ak5GenJetsNoMuNoNu+process.genParticlesForJetsNoElNoMuNoNu+process.ak5GenJetsNoElNoMuNoNu)
    process.allPath += process.extraGenJets
    #No need to run patPath (with preYieldFilter)
    process.out.SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring( 'allPath' ))
    process.schedule = cms.Schedule( process.allPath, process.scrap, process.outpath)


if doTauEmbed == True:
    process.out.outputCommands.extend(
   [
       'keep *_generator_*_*' , 
       'keep *_goldenZmumuCandidatesGe2IsoMuons_*_*'
   ]
  )
