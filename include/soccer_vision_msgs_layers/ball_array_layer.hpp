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

#ifndef SOCCER_VISION_MSGS_LAYERS__BALL_ARRAY_LAYER_HPP_
#define SOCCER_VISION_MSGS_LAYERS__BALL_ARRAY_LAYER_HPP_

#include "soccer_vision_msgs_layers/visibility_control.h"
#include "rqt_image_overlay_layer/plugin.hpp"
#include "soccer_vision_msgs/msg/ball_array.hpp"
#include "soccer_vision_msgs_layers/ball_layer.hpp"

namespace soccer_vision_msgs_layers
{

class BallArrayLayer : public rqt_image_overlay_layer::Plugin<soccer_vision_msgs::msg::BallArray>
{
protected:
  void overlay(
    QImage & layer,
    const soccer_vision_msgs::msg::BallArray & msg) override;

private:
  BallLayer ballLayer;
};

}  // namespace soccer_vision_msgs_layers

#endif  // SOCCER_VISION_MSGS_LAYERS__BALL_ARRAY_LAYER_HPP_