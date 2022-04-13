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

#include <QPainter>
#include "soccer_vision_2d_layers/ball_array.hpp"

namespace soccer_vision_2d_layers
{

void BallArray::overlay(
  QPainter & painter,
  const soccer_vision_2d_msgs::msg::BallArray & msg)
{
  for (auto & ball : msg.balls) {
    ballLayer.overlay(painter, ball);
  }
}

}  // namespace soccer_vision_2d_layers

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  soccer_vision_2d_layers::BallArray,
  rqt_image_overlay_layer::PluginInterface)
