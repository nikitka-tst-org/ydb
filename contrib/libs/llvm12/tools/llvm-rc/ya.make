# Generated by devtools/yamaker.

PROGRAM()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/llvm12
    contrib/libs/llvm12/include
    contrib/libs/llvm12/lib/Demangle
    contrib/libs/llvm12/lib/Option
    contrib/libs/llvm12/lib/Support
)

ADDINCL(
    ${ARCADIA_BUILD_ROOT}/contrib/libs/llvm12/tools/llvm-rc
    contrib/libs/llvm12/tools/llvm-rc
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    ResourceFileWriter.cpp
    ResourceScriptCppFilter.cpp
    ResourceScriptParser.cpp
    ResourceScriptStmt.cpp
    ResourceScriptToken.cpp
    llvm-rc.cpp
)

END()
