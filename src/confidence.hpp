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

#ifndef CONFIDENCE_HPP_
#define CONFIDENCE_HPP_

#include "soccer_vision_msgs_layers/visibility_control.h"

namespace soccer_vision_msgs_layers
{
namespace confidence
{

void overlay(
  QPainter & painter,
  float confidence);

}  // namespace confidence
}  // namespace soccer_vision_msgs_layers

#endif  // CONFIDENCE_HPP_
