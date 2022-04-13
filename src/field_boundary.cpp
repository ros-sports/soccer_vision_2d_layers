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
#include "soccer_vision_2d_layers/field_boundary.hpp"
#include "confidence.hpp"

namespace soccer_vision_2d_layers
{

void FieldBoundary::overlay(
  QPainter & painter,
  const soccer_vision_2d_msgs::msg::FieldBoundary & msg)
{
  QPen pen = painter.pen();
  pen.setWidth(2);
  pen.setCapStyle(Qt::RoundCap);
  painter.setPen(pen);

  if (msg.points.size() >= 2) {
    for (unsigned i = 0; i < msg.points.size() - 1; ++i) {
      auto & head = msg.points.at(i);
      auto & tail = msg.points.at(i + 1);
      painter.drawLine(head.x, head.y, tail.x, tail.y);
    }
  }
}

}  // namespace soccer_vision_2d_layers

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  soccer_vision_2d_layers::FieldBoundary,
  rqt_image_overlay_layer::PluginInterface)
