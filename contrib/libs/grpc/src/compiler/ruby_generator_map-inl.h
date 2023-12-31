/*
 *
 * Copyright 2015 gRPC authors.
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

#ifndef GRPC_INTERNAL_COMPILER_RUBY_GENERATOR_MAP_INL_H
#define GRPC_INTERNAL_COMPILER_RUBY_GENERATOR_MAP_INL_H

#include <initializer_list>
#include <iostream>
#include <map>
#include <ostream>  // NOLINT
#include <vector>

#include "src/compiler/config.h"

using std::initializer_list;
using std::map;
using std::vector;

namespace grpc_ruby_generator {

// Converts an initializer list of the form { key0, value0, key1, value1, ... }
// into a map of key* to value*. Is merely a readability helper for later code.
inline std::map<TString, TString> ListToDict(
    const initializer_list<TString>& values) {
  if (values.size() % 2 != 0) {
    std::cerr << "Not every 'key' has a value in `values`." << std::endl;
  }
  std::map<TString, TString> value_map;
  auto value_iter = values.begin();
  for (unsigned i = 0; i < values.size() / 2; ++i) {
    TString key = *value_iter;
    ++value_iter;
    TString value = *value_iter;
    value_map[key] = value;
    ++value_iter;
  }
  return value_map;
}

}  // namespace grpc_ruby_generator

#endif  // GRPC_INTERNAL_COMPILER_RUBY_GENERATOR_MAP_INL_H
