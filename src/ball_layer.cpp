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
#include "soccer_vision_msgs_layers/ball_layer.hpp"

namespace soccer_vision_msgs_layers
{

void BallLayer::overlay(
  QImage & layer,
  const soccer_vision_msgs::msg::Ball & msg)
{
  QPainter painter(&layer);
  painter.translate(msg.center.x, msg.center.y);

  painter.save();
  QPen pen(Qt::black);
  pen.setCapStyle(Qt::RoundCap);
  pen.setWidth(20);
  painter.setPen(pen);
  painter.drawPoint(0, 0);
  painter.restore();

  painter.save();
  painter.translate(-30, -20);
  QString str = "(%1, %2)";
  painter.drawText(0, 0, str.arg(msg.center.x).arg(msg.center.y));
  painter.restore();
}

}  // namespace soccer_vision_msgs_layers

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  soccer_vision_msgs_layers::BallLayer,
  rqt_image_overlay_layer::PluginInterface)
