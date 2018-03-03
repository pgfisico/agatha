/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "GrabCube.h"
#include"Robot.h"

GrabCube::GrabCube()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    Requires(&Robot::claw);
}

// Called just before this Command runs the first time
void GrabCube::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GrabCube::Execute()
{
    Robot::claw.grab();
}

// Make this return true when this Command no longer needs to run execute()
bool GrabCube::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void GrabCube::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabCube::Interrupted()
{

}
