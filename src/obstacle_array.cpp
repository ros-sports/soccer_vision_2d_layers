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
#include "soccer_vision_msgs_layers/obstacle_array.hpp"

namespace soccer_vision_msgs_layers
{

void ObstacleArray::overlay(
  QPainter & painter,
  const soccer_vision_msgs::msg::ObstacleArray & msg)
{
  for (auto & obstacle : msg.obstacles) {
    obstacleLayer.overlay(painter, obstacle);
  }
}

}  // namespace soccer_vision_msgs_layers

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  soccer_vision_msgs_layers::ObstacleArray,
  rqt_image_overlay_layer::PluginInterface)
