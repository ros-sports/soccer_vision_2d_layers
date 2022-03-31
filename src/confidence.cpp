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
#include "confidence.hpp"

namespace soccer_vision_msgs_layers
{
namespace confidence
{

void overlay(
  QPainter & painter,
  float confidence)
{
  painter.save();

  QString str = QString{"%1%"}.arg(confidence * 100);  // Convert to %
  QFontMetrics fm(painter.font());
  int pixelsWide = fm.horizontalAdvance(str);

  painter.fillRect(0, -fm.height(), pixelsWide, fm.height(), painter.pen().color());

  // Invert pen color
  QPen pen = painter.pen();
  QColor color = pen.color();
  color.setRed(255 - color.red());
  color.setGreen(255 - color.green());
  color.setBlue(255 - color.blue());
  pen.setColor(color);
  painter.setPen(pen);

  painter.drawText(0, -fm.descent(), str);

  painter.restore();
}

}  // namespace confidence
}  // namespace soccer_vision_msgs_layers
