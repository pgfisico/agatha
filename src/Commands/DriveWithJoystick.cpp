#include "DriveWithJoystick.h"

// TODO below
#include <Controls.h>
#include <Subsystems/DriveTrain.h>
#include <Xboxcontroller.h>

typedef frc::GenericHID::JoystickHand JoystickHand;

namespace agatha
{

DriveWithJoystick::DriveWithJoystick()
{
    // TODO inject subsystem
    //Requires(&Ophelia::drivetrain);
}

void DriveWithJoystick::Execute()
{
    // TODO inject controls
    //auto &joystick = Controls::controller;
    /*    double straight = joystick.GetY(JoystickHand::kLeftHand);
     double turn = -1 * joystick.GetX(JoystickHand::kRightHand);
     bool turbo = joystick.GetBumper(JoystickHand::kLeftHand);

     if (!turbo)
     {
     straight = std::pow(straight, 3) * 0.5;
     turn = std::pow(turn, 3) * 0.5;
     }*/

    // TODO inject subsystem
    //Ophelia::drivetrain.ArcadeDrive(straight, turn);
}

bool DriveWithJoystick::IsFinished()
{
    return false;
}

void DriveWithJoystick::End()
{
    // TODO inject subsystem
    //Ophelia::drivetrain.Stop();
}

}
