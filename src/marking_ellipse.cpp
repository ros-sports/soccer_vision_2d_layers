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
#include "soccer_vision_msgs_layers/marking_ellipse.hpp"
#include "confidence.hpp"

namespace soccer_vision_msgs_layers
{

void MarkingEllipse::overlay(
  QPainter & painter,
  const soccer_vision_msgs::msg::MarkingEllipse & msg)
{
  boundingBox2DLayer.overlay(painter, msg.bb);

  // Annotate Confidence if known
  if (msg.confidence != msg.CONFIDENCE_UNKNOWN) {
    painter.save();
    painter.translate(
      msg.bb.center.x - msg.bb.size_x / 2,
      msg.bb.center.y - msg.bb.size_y / 2);
    confidence::overlay(painter, msg.confidence);
    painter.restore();
  }

  // Draw center
  painter.drawPoint(msg.center.x, msg.center.y);
}

}  // namespace soccer_vision_msgs_layers

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  soccer_vision_msgs_layers::MarkingEllipse,
  rqt_image_overlay_layer::PluginInterface)
