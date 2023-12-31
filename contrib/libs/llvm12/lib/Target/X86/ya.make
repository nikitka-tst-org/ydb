# Generated by devtools/yamaker.

LIBRARY()

LICENSE(
    Apache-2.0 WITH LLVM-exception AND
    NCSA
)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm12
    contrib/libs/llvm12/include
    contrib/libs/llvm12/lib/Analysis
    contrib/libs/llvm12/lib/CodeGen
    contrib/libs/llvm12/lib/CodeGen/AsmPrinter
    contrib/libs/llvm12/lib/CodeGen/GlobalISel
    contrib/libs/llvm12/lib/CodeGen/SelectionDAG
    contrib/libs/llvm12/lib/IR
    contrib/libs/llvm12/lib/MC
    contrib/libs/llvm12/lib/ProfileData
    contrib/libs/llvm12/lib/Support
    contrib/libs/llvm12/lib/Target
    contrib/libs/llvm12/lib/Target/X86/MCTargetDesc
    contrib/libs/llvm12/lib/Target/X86/TargetInfo
    contrib/libs/llvm12/lib/Transforms/CFGuard
)

ADDINCL(
    ${ARCADIA_BUILD_ROOT}/contrib/libs/llvm12/lib/Target/X86
    contrib/libs/llvm12/lib/Target/X86
)

NO_CLANG_COVERAGE()

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    X86AsmPrinter.cpp
    X86AvoidStoreForwardingBlocks.cpp
    X86AvoidTrailingCall.cpp
    X86CallFrameOptimization.cpp
    X86CallLowering.cpp
    X86CallingConv.cpp
    X86CmovConversion.cpp
    X86DiscriminateMemOps.cpp
    X86DomainReassignment.cpp
    X86EvexToVex.cpp
    X86ExpandPseudo.cpp
    X86FastISel.cpp
    X86FixupBWInsts.cpp
    X86FixupLEAs.cpp
    X86FixupSetCC.cpp
    X86FlagsCopyLowering.cpp
    X86FloatingPoint.cpp
    X86FrameLowering.cpp
    X86ISelDAGToDAG.cpp
    X86ISelLowering.cpp
    X86IndirectBranchTracking.cpp
    X86IndirectThunks.cpp
    X86InsertPrefetch.cpp
    X86InsertWait.cpp
    X86InstCombineIntrinsic.cpp
    X86InstrFMA3Info.cpp
    X86InstrFoldTables.cpp
    X86InstrInfo.cpp
    X86InstructionSelector.cpp
    X86InterleavedAccess.cpp
    X86LegalizerInfo.cpp
    X86LoadValueInjectionLoadHardening.cpp
    X86LoadValueInjectionRetHardening.cpp
    X86LowerAMXType.cpp
    X86MCInstLower.cpp
    X86MachineFunctionInfo.cpp
    X86MacroFusion.cpp
    X86OptimizeLEAs.cpp
    X86PadShortFunction.cpp
    X86PartialReduction.cpp
    X86PreTileConfig.cpp
    X86RegisterBankInfo.cpp
    X86RegisterInfo.cpp
    X86SelectionDAGInfo.cpp
    X86ShuffleDecodeConstantPool.cpp
    X86SpeculativeExecutionSideEffectSuppression.cpp
    X86SpeculativeLoadHardening.cpp
    X86Subtarget.cpp
    X86TargetMachine.cpp
    X86TargetObjectFile.cpp
    X86TargetTransformInfo.cpp
    X86TileConfig.cpp
    X86VZeroUpper.cpp
    X86WinAllocaExpander.cpp
    X86WinEHState.cpp
)

END()
