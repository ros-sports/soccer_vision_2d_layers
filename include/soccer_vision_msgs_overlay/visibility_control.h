// Copyright 2021 Kenji Brameld
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SOCCER_VISION_MSGS_OVERLAY__VISIBILITY_CONTROL_H_
#define SOCCER_VISION_MSGS_OVERLAY__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SOCCER_VISION_MSGS_OVERLAY_EXPORT __attribute__ ((dllexport))
    #define SOCCER_VISION_MSGS_OVERLAY_IMPORT __attribute__ ((dllimport))
  #else
    #define SOCCER_VISION_MSGS_OVERLAY_EXPORT __declspec(dllexport)
    #define SOCCER_VISION_MSGS_OVERLAY_IMPORT __declspec(dllimport)
  #endif
  #ifdef SOCCER_VISION_MSGS_OVERLAY_BUILDING_LIBRARY
    #define SOCCER_VISION_MSGS_OVERLAY_PUBLIC SOCCER_VISION_MSGS_OVERLAY_EXPORT
  #else
    #define SOCCER_VISION_MSGS_OVERLAY_PUBLIC SOCCER_VISION_MSGS_OVERLAY_IMPORT
  #endif
  #define SOCCER_VISION_MSGS_OVERLAY_PUBLIC_TYPE SOCCER_VISION_MSGS_OVERLAY_PUBLIC
  #define SOCCER_VISION_MSGS_OVERLAY_LOCAL
#else
  #define SOCCER_VISION_MSGS_OVERLAY_EXPORT __attribute__ ((visibility("default")))
  #define SOCCER_VISION_MSGS_OVERLAY_IMPORT
  #if __GNUC__ >= 4
    #define SOCCER_VISION_MSGS_OVERLAY_PUBLIC __attribute__ ((visibility("default")))
    #define SOCCER_VISION_MSGS_OVERLAY_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SOCCER_VISION_MSGS_OVERLAY_PUBLIC
    #define SOCCER_VISION_MSGS_OVERLAY_LOCAL
  #endif
  #define SOCCER_VISION_MSGS_OVERLAY_PUBLIC_TYPE
#endif

#endif  // SOCCER_VISION_MSGS_OVERLAY__VISIBILITY_CONTROL_H_
