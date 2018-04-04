/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "Controls.h"
#include "Leviosa.h"
#include "Robot.h"
typedef frc::GenericHID::JoystickHand JoystickHand;

Leviosa::Leviosa() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
    Requires(&Robot::forklift);
}

// Called just before this Command runs the first time
void Leviosa::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Leviosa::Execute() {
    auto &joystick = Controls::controller;
    double speed = joystick.GetTriggerAxis(JoystickHand::kRightHand);
    speed=std::pow(speed, 3)*0.5;
    double DownSpeed = joystick.GetTriggerAxis(JoystickHand::kLeftHand);
    DownSpeed=std::pow(DownSpeed, 3)*0.5;

    Robot::forklift.ForkliftUp(speed);
    Robot::forklift.ForkliftDown(DownSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool Leviosa::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Leviosa::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Leviosa::Interrupted() {

}
