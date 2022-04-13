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
#include "soccer_vision_2d_layers/obstacle.hpp"
#include "confidence.hpp"

namespace soccer_vision_2d_layers
{

void Obstacle::overlay(
  QPainter & painter,
  const soccer_vision_2d_msgs::msg::Obstacle & msg)
{
  boundingBox2DLayer.overlay(painter, msg.bb);

  // Annotate Confidence if known
  if (msg.confidence.confidence != msg.confidence.CONFIDENCE_UNKNOWN) {
    painter.save();
    painter.translate(
<<<<<<< HEAD
      msg.bb.center.x - msg.bb.size_x / 2,
      msg.bb.center.y - msg.bb.size_y / 2);
    confidence::overlay(painter, msg.confidence);
=======
      msg.bb.center.position.x - msg.bb.size_x / 2,
      msg.bb.center.position.y - msg.bb.size_y / 2);
    confidence::overlay(painter, msg.confidence.confidence);
>>>>>>> 223c0f0 (adapt to changes from https://github.com/ros-sports/soccer_interfaces/pull/22)
    painter.restore();
  }
}

}  // namespace soccer_vision_2d_layers

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  soccer_vision_2d_layers::Obstacle,
  rqt_image_overlay_layer::PluginInterface)
