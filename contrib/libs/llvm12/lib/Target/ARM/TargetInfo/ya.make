# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm12
    contrib/libs/llvm12/lib/Support
)

ADDINCL(
    contrib/libs/llvm12/lib/Target/ARM
    contrib/libs/llvm12/lib/Target/ARM/TargetInfo
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    ARMTargetInfo.cpp
)

END()
