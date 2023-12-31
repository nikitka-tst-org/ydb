# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm12
    contrib/libs/llvm12/lib/IR
    contrib/libs/llvm12/lib/Object
    contrib/libs/llvm12/lib/ProfileData
    contrib/libs/llvm12/lib/Support
)

ADDINCL(
    contrib/libs/llvm12/lib/ProfileData/Coverage
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    CoverageMapping.cpp
    CoverageMappingReader.cpp
    CoverageMappingWriter.cpp
)

END()
