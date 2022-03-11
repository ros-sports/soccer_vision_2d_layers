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
#include <cmath>
#include "soccer_vision_msgs_layers/marking_intersection.hpp"
#include "confidence.hpp"

#define RAY_LENGTH 20  // pixels

namespace soccer_vision_msgs_layers
{

void MarkingIntersection::overlay(
  QPainter & painter,
  const soccer_vision_msgs::msg::MarkingIntersection & msg)
{
  QPen pen = painter.pen();
  pen.setWidth(8);
  pen.setCapStyle(Qt::RoundCap);
  painter.setPen(pen);

  painter.translate(msg.center.x, msg.center.y);

  for (int i = 0; i < msg.num_rays; ++i) {
    double heading = msg.heading_rays.at(i);
    double x = RAY_LENGTH * cos(heading);
    double y = RAY_LENGTH * sin(heading);
    painter.drawLine(0, 0, x, y);
  }

  // Draw center
  pen.setColor(Qt::yellow);
  painter.setPen(pen);
  painter.drawPoint(0, 0);
}

}  // namespace soccer_vision_msgs_layers

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  soccer_vision_msgs_layers::MarkingIntersection,
  rqt_image_overlay_layer::PluginInterface)
