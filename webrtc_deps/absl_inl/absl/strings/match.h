//
// Copyright 2017 The Abseil Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// -----------------------------------------------------------------------------
// File: match.h
// -----------------------------------------------------------------------------
//
// This file contains simple utilities for performing string matching checks.
// All of these function parameters are specified as `absl::string_view`,
// meaning that these functions can accept `std::string`, `absl::string_view` or
// NUL-terminated C-style strings.
//
// Examples:
//   std::string s = "foo";
//   absl::string_view sv = "f";
//   assert(absl::StrContains(s, sv));
//
// Note: The order of parameters in these functions is designed to mimic the
// order an equivalent member function would exhibit;
// e.g. `s.Contains(x)` ==> `absl::StrContains(s, x).
#ifndef ABSL_STRINGS_MATCH_H_
#define ABSL_STRINGS_MATCH_H_

#include <cstring>

#include "absl/strings/string_view.h"
#include "absl/strings/ascii.h"

namespace absl {
ABSL_NAMESPACE_BEGIN

// StrContains()
//
// Returns whether a given string `haystack` contains the substring `needle`.
inline bool StrContains(absl::string_view haystack, absl::string_view needle) {
  return haystack.find(needle, 0) != haystack.npos;
}

// StartsWith()
//
// Returns whether a given string `text` begins with `prefix`.
inline bool StartsWith(absl::string_view text, absl::string_view prefix) {
  return prefix.empty() ||
         (text.size() >= prefix.size() &&
          memcmp(text.data(), prefix.data(), prefix.size()) == 0);
}

// EndsWith()
//
// Returns whether a given string `text` ends with `suffix`.
inline bool EndsWith(absl::string_view text, absl::string_view suffix) {
  return suffix.empty() ||
         (text.size() >= suffix.size() &&
          memcmp(text.data() + (text.size() - suffix.size()), suffix.data(),
                 suffix.size()) == 0);
}

inline int memcasecmp(const char* s1, const char* s2, size_t len) {
  const unsigned char* us1 = reinterpret_cast<const unsigned char*>(s1);
  const unsigned char* us2 = reinterpret_cast<const unsigned char*>(s2);

  for (size_t i = 0; i < len; i++) {
    const int diff =
        int{static_cast<unsigned char>(absl::ascii_tolower(us1[i]))} -
        int{static_cast<unsigned char>(absl::ascii_tolower(us2[i]))};
    if (diff != 0) return diff;
  }
  return 0;
}

// EqualsIgnoreCase()
//
// Returns whether given ASCII strings `piece1` and `piece2` are equal, ignoring
// case in the comparison.
inline bool EqualsIgnoreCase(absl::string_view piece1, absl::string_view piece2) {
  return (piece1.size() == piece2.size() &&
          0 == memcasecmp(piece1.data(), piece2.data(),
                          piece1.size()));
  // memcasecmp uses absl::ascii_tolower().
}

// StartsWithIgnoreCase()
//
// Returns whether a given ASCII string `text` starts with `prefix`,
// ignoring case in the comparison.
inline bool StartsWithIgnoreCase(absl::string_view text, absl::string_view prefix) {
  return (text.size() >= prefix.size()) &&
         EqualsIgnoreCase(text.substr(0, prefix.size()), prefix);
}

// EndsWithIgnoreCase()
//
// Returns whether a given ASCII string `text` ends with `suffix`, ignoring
// case in the comparison.
inline bool EndsWithIgnoreCase(absl::string_view text, absl::string_view suffix) {
  return (text.size() >= suffix.size()) &&
         EqualsIgnoreCase(text.substr(text.size() - suffix.size()), suffix);
}

ABSL_NAMESPACE_END
}  // namespace absl

#endif  // ABSL_STRINGS_MATCH_H_
