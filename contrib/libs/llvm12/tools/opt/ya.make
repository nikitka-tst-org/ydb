# Generated by devtools/yamaker.

PROGRAM()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm12
    contrib/libs/llvm12/include
    contrib/libs/llvm12/lib/Analysis
    contrib/libs/llvm12/lib/AsmParser
    contrib/libs/llvm12/lib/BinaryFormat
    contrib/libs/llvm12/lib/Bitcode/Reader
    contrib/libs/llvm12/lib/Bitcode/Writer
    contrib/libs/llvm12/lib/Bitstream/Reader
    contrib/libs/llvm12/lib/CodeGen
    contrib/libs/llvm12/lib/CodeGen/AsmPrinter
    contrib/libs/llvm12/lib/CodeGen/GlobalISel
    contrib/libs/llvm12/lib/CodeGen/SelectionDAG
    contrib/libs/llvm12/lib/DebugInfo/CodeView
    contrib/libs/llvm12/lib/DebugInfo/DWARF
    contrib/libs/llvm12/lib/Demangle
    contrib/libs/llvm12/lib/Extensions
    contrib/libs/llvm12/lib/Frontend/OpenMP
    contrib/libs/llvm12/lib/IR
    contrib/libs/llvm12/lib/IRReader
    contrib/libs/llvm12/lib/Linker
    contrib/libs/llvm12/lib/MC
    contrib/libs/llvm12/lib/MC/MCDisassembler
    contrib/libs/llvm12/lib/MC/MCParser
    contrib/libs/llvm12/lib/Object
    contrib/libs/llvm12/lib/Passes
    contrib/libs/llvm12/lib/ProfileData
    contrib/libs/llvm12/lib/Remarks
    contrib/libs/llvm12/lib/Support
    contrib/libs/llvm12/lib/Target
    contrib/libs/llvm12/lib/Target/AArch64
    contrib/libs/llvm12/lib/Target/AArch64/AsmParser
    contrib/libs/llvm12/lib/Target/AArch64/MCTargetDesc
    contrib/libs/llvm12/lib/Target/AArch64/TargetInfo
    contrib/libs/llvm12/lib/Target/AArch64/Utils
    contrib/libs/llvm12/lib/Target/ARM
    contrib/libs/llvm12/lib/Target/ARM/AsmParser
    contrib/libs/llvm12/lib/Target/ARM/MCTargetDesc
    contrib/libs/llvm12/lib/Target/ARM/TargetInfo
    contrib/libs/llvm12/lib/Target/ARM/Utils
    contrib/libs/llvm12/lib/Target/BPF
    contrib/libs/llvm12/lib/Target/BPF/AsmParser
    contrib/libs/llvm12/lib/Target/BPF/MCTargetDesc
    contrib/libs/llvm12/lib/Target/BPF/TargetInfo
    contrib/libs/llvm12/lib/Target/NVPTX
    contrib/libs/llvm12/lib/Target/NVPTX/MCTargetDesc
    contrib/libs/llvm12/lib/Target/NVPTX/TargetInfo
    contrib/libs/llvm12/lib/Target/PowerPC
    contrib/libs/llvm12/lib/Target/PowerPC/AsmParser
    contrib/libs/llvm12/lib/Target/PowerPC/MCTargetDesc
    contrib/libs/llvm12/lib/Target/PowerPC/TargetInfo
    contrib/libs/llvm12/lib/Target/X86
    contrib/libs/llvm12/lib/Target/X86/AsmParser
    contrib/libs/llvm12/lib/Target/X86/MCTargetDesc
    contrib/libs/llvm12/lib/Target/X86/TargetInfo
    contrib/libs/llvm12/lib/TextAPI/MachO
    contrib/libs/llvm12/lib/Transforms/AggressiveInstCombine
    contrib/libs/llvm12/lib/Transforms/CFGuard
    contrib/libs/llvm12/lib/Transforms/Coroutines
    contrib/libs/llvm12/lib/Transforms/HelloNew
    contrib/libs/llvm12/lib/Transforms/IPO
    contrib/libs/llvm12/lib/Transforms/InstCombine
    contrib/libs/llvm12/lib/Transforms/Instrumentation
    contrib/libs/llvm12/lib/Transforms/ObjCARC
    contrib/libs/llvm12/lib/Transforms/Scalar
    contrib/libs/llvm12/lib/Transforms/Utils
    contrib/libs/llvm12/lib/Transforms/Vectorize
    contrib/libs/llvm12/tools/polly/lib
    contrib/libs/llvm12/tools/polly/lib/External/isl
)

ADDINCL(
    contrib/libs/llvm12/tools/opt
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    AnalysisWrappers.cpp
    BreakpointPrinter.cpp
    GraphPrinters.cpp
    NewPMDriver.cpp
    PassPrinters.cpp
    PrintSCC.cpp
    opt.cpp
)

END()
