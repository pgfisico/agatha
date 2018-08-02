#include "Leviosa.h"

// TODO below
#include <Ophelia.h>
#include "Controls.h"

typedef frc::GenericHID::JoystickHand JoystickHand;

namespace ophelia
{

Leviosa::Leviosa()
{
    // TODO inject subsystem
    //Requires(&Ophelia::forklift);
}

void Leviosa::Initialize()
{
    // TODO drop??
}

void Leviosa::Execute()
{
    // TODO inject controls
    /*auto &joystick = Controls::controller;
     double speed = joystick.GetTriggerAxis(JoystickHand::kRightHand);
     speed = std::pow(speed, 3) * 0.5;
     double DownSpeed = joystick.GetTriggerAxis(JoystickHand::kLeftHand);
     DownSpeed = std::pow(DownSpeed, 3) * 0.5;*/

    // TODO inject subsystem
    //Ophelia::forklift.ForkliftUp(speed);
    //Ophelia::forklift.ForkliftDown(DownSpeed);
}

bool Leviosa::IsFinished()
{
    return false;
}

void Leviosa::End()
{
    // TODO fill??
}

void Leviosa::Interrupted()
{
    // TODO fill??
}

}
