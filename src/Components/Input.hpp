#pragma once
#include <esp32-hal-gpio.h>


class Input
{
    //methods
    public:

    /*
        @brief
        Returns true if the button is pressed (assuming a PULL-UP button)
    */
    bool GetButton(int ButtonName);


    //member variables
};