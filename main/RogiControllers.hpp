#pragma once

#include "sdkconfig.h"

#include <Arduino.h>
#include <Bluepad32.h>

class RogiControllers {
    public:
        ControllerPtr ctls[BP32_MAX_GAMEPADS];
        RogiControllers();
        void loop();
        
    private:
        void onConnectedController(ControllerPtr ctl);
        void onDisconnectedController(ControllerPtr ctl);
};