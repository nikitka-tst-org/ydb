/*
 *
 * Copyright 2016 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GRPC_INTERNAL_COMPILER_PHP_GENERATOR_HELPERS_H
#define GRPC_INTERNAL_COMPILER_PHP_GENERATOR_HELPERS_H

#include <algorithm>

#include "src/compiler/config.h"
#include "src/compiler/generator_helpers.h"

namespace grpc_php_generator {

inline TString GetPHPServiceClassname(
    const grpc::protobuf::ServiceDescriptor* service,
    const TString& class_suffix, bool is_server) {
  return service->name() +
         (class_suffix == "" ? (is_server ? "" : "Client") : class_suffix) +
         (is_server ? "Stub" : "");
}

// ReplaceAll replaces all instances of search with replace in s.
inline TString ReplaceAll(TString s, const TString& search,
                              const TString& replace) {
  size_t pos = 0;
  while ((pos = s.find(search, pos)) != TString::npos) {
    s.replace(pos, search.length(), replace);
    pos += replace.length();
  }
  return s;
}

inline TString GetPHPServiceFilename(
    const grpc::protobuf::FileDescriptor* file,
    const grpc::protobuf::ServiceDescriptor* service,
    const TString& class_suffix, bool is_server) {
  std::ostringstream oss;
  if (file->options().has_php_namespace()) {
    oss << ReplaceAll(file->options().php_namespace(), "\\", "/");
  } else {
    std::vector<TString> tokens =
        grpc_generator::tokenize(file->package(), ".");
    for (unsigned int i = 0; i < tokens.size(); i++) {
      oss << (i == 0 ? "" : "/")
          << grpc_generator::CapitalizeFirstLetter(tokens[i]);
    }
  }
  return oss.str() + "/" +
         GetPHPServiceClassname(service, class_suffix, is_server) + ".php";
}

// Get leading or trailing comments in a string. Comment lines start with "// ".
// Leading detached comments are put in front of leading comments.
template <typename DescriptorType>
inline TString GetPHPComments(const DescriptorType* desc,
                                  TString prefix) {
  return ReplaceAll(grpc_generator::GetPrefixedComments(desc, true, prefix),
                    "*/", "&#42;/");
}

}  // namespace grpc_php_generator

#endif  // GRPC_INTERNAL_COMPILER_PHP_GENERATOR_HELPERS_H
