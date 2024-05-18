#include "sdkconfig.h"

#include <Arduino.h>
#include <Bluepad32.h>
#include "RogiControllers.hpp"
#include "RogiLinkFlex/UartLink.hpp"

const uint8_t ROGICTLS_FRAME_ID = 0x16;

// UART通信クラス
UartLink uart(Serial2); 

// コントローラ管理クラス
RogiControllers controllers;

// Publisherクラス(コントローラのボタン情報を送信する)
UartLinkPublisher<
    uint8_t, // controller_id
    int32_t, // axisX
    int32_t, // axisY
    int32_t, // axisRX
    int32_t, // axisRY
    uint16_t, // buttons
    uint16_t  // misc_buttons
> publisher(uart, ROGICTLS_FRAME_ID);

void setup() {
    Serial.begin(115200);
    Serial2.begin(115200);
}

void loop() {
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        ControllerPtr ctl = controllers.ctls[i];
        if (ctl == nullptr) {
            continue;
        }

        publisher.publish(
            i,
            ctl->axisX(),
            ctl->axisY(),
            ctl->axisRX(),
            ctl->axisRY(),
            ctl->buttons(),
            ctl->miscButtons()
        );
    }
}
