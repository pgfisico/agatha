#include "Subsystems/DriveTrain.h"

#include "Commands/DriveWithJoystick.h"
#include "RobotMap.h"

DriveTrain::DriveTrain() :
        frc::Subsystem("ExampleSubsystem")
{
    rightCIMs.SetInverted(true);
    leftCIMs.SetInverted(true);
}

void DriveTrain::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    SetDefaultCommand(new DriveWithJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::ArcadeDrive(double leftAxis, double rightAxis)
{
    robotDrive.ArcadeDrive(leftAxis, rightAxis);
}

void DriveTrain::Stop()
{
    robotDrive.StopMotor();
}
