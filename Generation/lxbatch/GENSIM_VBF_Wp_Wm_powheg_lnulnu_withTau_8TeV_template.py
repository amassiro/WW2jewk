# Auto generated configuration file
# using:
# Revision: 1.381.2.20
# Source: /local/reps/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v
# with command line options: Configuration/GenProduction/python/EightTeV/POWHEG_PYTHIA6_Tauola_H_WW_lnulnu_withTau_8TeV_cff.py --filein file:/tmp/amassiro/prova.root --fileout /tmp/amassiro/provaGENSIM.root --mc --eventcontent RAWSIM --datatier GEN-SIM --conditions START53_V7C::All --beamspot Realistic8TeVCollision --step GEN,SIM
import FWCore.ParameterSet.Config as cms


from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
# add a list of strings for events to process
options.parseArguments()



process = cms.Process('SIM')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.GeometrySimDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedRealistic8TeVCollision_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.SimIdeal_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(NUMBEREVENTS)
)

# Input source
process.source = cms.Source("PoolSource",
    secondaryFileNames = cms.untracked.vstring(),
    firstEvent = cms.untracked.uint32(FIRSTEVENT),
    fileNames = cms.untracked.vstring (options.inputFiles),
)


process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.381.2.20 $'),
    annotation = cms.untracked.string('Configuration/GenProduction/python/EightTeV/POWHEG_PYTHIA6_Tauola_H_WW_lnulnu_withTau_8TeV_cff.py nevts:1'),
    name = cms.untracked.string('PyReleaseValidation')
)


# Output definition

process.RAWSIMoutput = cms.OutputModule("PoolOutputModule",
    splitLevel = cms.untracked.int32(0),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    fileName = cms.untracked.string (options.outputFile),
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('GEN-SIM')
    ),
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    )
)

# Additional output definition

# Other statements
process.genstepfilter.triggerConditions=cms.vstring("generation_step")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'START53_V7C::All', '')

process.generator = cms.EDFilter(
    "Pythia6HadronizerFilter",
    pythiaPylistVerbosity = cms.untracked.int32(1),
    filterEfficiency = cms.untracked.double(1.0),
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    comEnergy = cms.double(8000.0),
    maxEventsToPrint = cms.untracked.int32(0),
    ExternalDecays = cms.PSet(
        Tauola = cms.untracked.PSet(
            UseTauolaPolarization = cms.bool(True),
            InputCards = cms.PSet(
                mdtau = cms.int32(0),
                pjak2 = cms.int32(0),
                pjak1 = cms.int32(0)
            )
        ),
        parameterSets = cms.vstring('Tauola')
    ),
    PythiaParameters = cms.PSet(
        pythiaUESettings = cms.vstring(
            'MSTU(21)=1 ! Check on possible errors during program execution',
            'MSTJ(22)=2 ! Decay those unstable particles',
            'PARJ(71)=10 . ! for which ctau 10 mm',
            'MSTP(33)=0 ! no K factors in hard cross sections',
            'MSTP(2)=1 ! which order running alphaS',
            'MSTP(51)=10042 ! structure function chosen (external PDF CTEQ6L1)',
            'MSTP(52)=2 ! work with LHAPDF',
            'PARP(82)=1.921 ! pt cutoff for multiparton interactions',
            'PARP(89)=1800. ! sqrts for which PARP82 is set',
            'PARP(90)=0.227 ! Multiple interactions: rescaling power',
            'MSTP(95)=6 ! CR (color reconnection parameters)',
            'PARP(77)=1.016 ! CR',
            'PARP(78)=0.538 ! CR',
            'PARP(80)=0.1 ! Prob. colored parton from BBR',
            'PARP(83)=0.356 ! Multiple interactions: matter distribution parameter',
            'PARP(84)=0.651 ! Multiple interactions: matter distribution parameter',
            'PARP(62)=1.025 ! ISR cutoff',
            'MSTP(91)=1 ! Gaussian primordial kT',
            'PARP(93)=10.0 ! primordial kT-max',
            'MSTP(81)=21 ! multiple parton interactions 1 is Pythia default',
            'MSTP(82)=4 ! Defines the multi-parton model'),
        processParameters = cms.vstring(
            'MSEL=0 ! User defined processes',
            'PMAS(5,1)=4.75 ! b quark mass',
            'PMAS(6,1)=172.5 ! t quark mass',
            
            'MDME(210,1)=0 ! Higgs decay into dd',
            'MDME(211,1)=0 ! Higgs decay into uu',
            'MDME(212,1)=0 ! Higgs decay into ss',
            'MDME(213,1)=0 ! Higgs decay into cc',
            'MDME(214,1)=0 ! Higgs decay into bb',
            'MDME(215,1)=0 ! Higgs decay into tt',
            'MDME(216,1)=0 ! Higgs decay into bbbar prime',
            'MDME(217,1)=0 ! Higgs decay into ttbar prime',
            'MDME(218,1)=0 ! Higgs decay into e e',
            'MDME(219,1)=0 ! Higgs decay into mu mu',
            'MDME(220,1)=0 ! Higgs decay into tau tau',
            'MDME(221,1)=0 ! Higgs decay into tau tau prime',
            'MDME(222,1)=0 ! Higgs decay into g g',
            'MDME(223,1)=0 ! Higgs decay into gam gam',
            'MDME(224,1)=0 ! Higgs decay into gam Z',
            'MDME(225,1)=0 ! Higgs decay into Z Z',
            'MDME(226,1)=1 ! Higgs decay into W W',
            
            'MDME(190,1)=0 ! W decay into dbar u',
            'MDME(191,1)=0 ! W decay into dbar c',
            'MDME(192,1)=0 ! W decay into dbar t',
            'MDME(194,1)=0 ! W decay into sbar u',
            'MDME(195,1)=0 ! W decay into sbar c',
            'MDME(196,1)=0 ! W decay into sbar t',
            'MDME(198,1)=0 ! W decay into bbar u',
            'MDME(199,1)=0 ! W decay into bbar c',
            'MDME(200,1)=0 ! W decay into bbar t',
            'MDME(206,1)=1 ! W decay into e+ nu_e',
            'MDME(207,1)=1 ! W decay into mu+ nu_mu',
            'MDME(208,1)=1 ! W decay into tau+ nu_tau'
            ),
        parameterSets = cms.vstring(
            'pythiaUESettings',
            'processParameters'
            )
        )
    )


# Path and EndPath definitions
process.generation_step = cms.Path(process.pgen)
process.simulation_step = cms.Path(process.psim)
process.genfiltersummary_step = cms.EndPath(process.genFilterSummary)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RAWSIMoutput_step = cms.EndPath(process.RAWSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.generation_step,process.genfiltersummary_step,process.simulation_step,process.endjob_step,process.RAWSIMoutput_step)
# filter all path with the production filter sequence
for path in process.paths:
    getattr(process,path)._seq = process.generator * getattr(process,path)._seq

