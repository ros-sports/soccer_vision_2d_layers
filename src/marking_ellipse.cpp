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
  QImage & layer,
  const soccer_vision_msgs::msg::MarkingEllipse & msg)
{
  QPainter painter(&layer);

  QPen pen(QColor(255, 255, 0, 100));
  pen.setWidth(3);
  pen.setCapStyle(Qt::RoundCap);
  painter.setPen(pen);

  // Draw Bounding Box and Confidence
  painter.save();
  painter.translate(msg.bb.center.x, msg.bb.center.y);
  painter.drawRect(-msg.bb.size_x / 2, -msg.bb.size_y / 2, msg.bb.size_x, msg.bb.size_y);
  // Annotate Confidence if known
  painter.translate(-msg.bb.size_x / 2, -msg.bb.size_y / 2);
  if (msg.confidence != msg.CONFIDENCE_UNKNOWN) {
    confidence::overlay(painter, msg.confidence);
  }
  painter.restore();

  // Draw center
  painter.drawPoint(msg.center.x, msg.center.y);
}

}  // namespace soccer_vision_msgs_layers

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  soccer_vision_msgs_layers::MarkingEllipse,
  rqt_image_overlay_layer::PluginInterface)