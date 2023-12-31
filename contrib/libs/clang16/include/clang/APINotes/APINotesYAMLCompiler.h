#pragma once

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

//===-- APINotesYAMLCompiler.h - API Notes YAML Format Reader ---*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_APINOTES_APINOTESYAMLCOMPILER_H
#define LLVM_CLANG_APINOTES_APINOTESYAMLCOMPILER_H

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/raw_ostream.h"

namespace clang {
namespace api_notes {
/// Parses the APINotes YAML content and writes the representation back to the
/// specified stream.  This provides a means of testing the YAML processing of
/// the APINotes format.
bool parseAndDumpAPINotes(llvm::StringRef YI, llvm::raw_ostream &OS);
} // namespace api_notes
} // namespace clang

#endif

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
