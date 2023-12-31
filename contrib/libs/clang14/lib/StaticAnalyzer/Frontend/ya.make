# Generated by devtools/yamaker.

LIBRARY()

LICENSE(Apache-2.0 WITH LLVM-exception)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/clang14
    contrib/libs/clang14/include
    contrib/libs/clang14/lib/AST
    contrib/libs/clang14/lib/ASTMatchers
    contrib/libs/clang14/lib/Analysis
    contrib/libs/clang14/lib/Basic
    contrib/libs/clang14/lib/CrossTU
    contrib/libs/clang14/lib/Frontend
    contrib/libs/clang14/lib/Lex
    contrib/libs/clang14/lib/StaticAnalyzer/Checkers
    contrib/libs/clang14/lib/StaticAnalyzer/Core
    contrib/libs/llvm14
    contrib/libs/llvm14/lib/Support
)

ADDINCL(
    contrib/libs/clang14/lib/StaticAnalyzer/Frontend
)

NO_COMPILER_WARNINGS()

NO_UTIL()

SRCS(
    AnalysisConsumer.cpp
    AnalyzerHelpFlags.cpp
    CheckerRegistry.cpp
    CreateCheckerManager.cpp
    FrontendActions.cpp
    ModelConsumer.cpp
    ModelInjector.cpp
)

END()
