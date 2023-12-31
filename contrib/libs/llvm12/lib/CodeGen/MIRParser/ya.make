# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm12
    contrib/libs/llvm12/include
    contrib/libs/llvm12/lib/AsmParser
    contrib/libs/llvm12/lib/BinaryFormat
    contrib/libs/llvm12/lib/CodeGen
    contrib/libs/llvm12/lib/IR
    contrib/libs/llvm12/lib/MC
    contrib/libs/llvm12/lib/Support
    contrib/libs/llvm12/lib/Target
)

ADDINCL(
    contrib/libs/llvm12/lib/CodeGen/MIRParser
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    MILexer.cpp
    MIParser.cpp
    MIRParser.cpp
)

END()
