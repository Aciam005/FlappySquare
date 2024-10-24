#include "Input.hpp"

bool Input::GetButton(int ButtonName)
{
    return(digitalRead(ButtonName) == 0);
}