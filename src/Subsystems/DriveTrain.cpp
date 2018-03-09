#include "Subsystems/DriveTrain.h"

#include "Commands/DriveWithJoystick.h"
#include "RobotMap.h"

constexpr static double inpertick = 0.052;

DriveTrain::DriveTrain() :
        frc::Subsystem("ExampleSubsystem"), frontLeftCIM { FRONT_LEFT }, rearLeftCIM { REAR_LEFT }, leftCIMs {
                frontLeftCIM, rearLeftCIM }, frontRightCIM { FRONT_RIGHT }, rearRightCIM { REAR_RIGHT }, rightCIMs {
                frontRightCIM, rearRightCIM }, leftencoder { leftencoderA, leftencoderB }, rightencoder { rightencoderA,
                rightencoderB }, robotDrive { leftCIMs, rightCIMs }
{
    rightCIMs.SetInverted(true);
    leftCIMs.SetInverted(true);
    leftencoder.SetDistancePerPulse(inpertick);
    rightencoder.SetDistancePerPulse(inpertick);
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

void DriveTrain::ResetDistance()
{
    leftencoder.Reset();
    rightencoder.Reset();
}

double DriveTrain::GetDistance()
{
    return (leftencoder.GetDistance() + rightencoder.GetDistance()) / 2;
}
