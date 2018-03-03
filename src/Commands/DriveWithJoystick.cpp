/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Controls.h>
#include "DriveWithJoystick.h"
#include <Subsystems/DriveTrain.h>
#include "../Robot.h"
#include <Xboxcontroller.h>

typedef frc::GenericHID::JoystickHand JoystickHand;

DriveWithJoystick::DriveWithJoystick()
{
    Requires(&Robot::drivetrain);
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute()
{
    auto &joystick = Controls::controller;
    double straight = joystick.GetY(JoystickHand::kLeftHand);
    double turn = -1 * joystick.GetX(JoystickHand::kRightHand);

    Robot::drivetrain.ArcadeDrive(straight, turn);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End()
{
    Robot::drivetrain.Stop();
}
