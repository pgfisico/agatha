#include "Subsystems/Drivetrain.h"

constexpr static double inpertick = 0.052;

namespace agatha
{

Drivetrain::Drivetrain(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
        std::unique_ptr<frc::SpeedController> frontLeftMotor, std::unique_ptr<frc::SpeedController> frontRightMotor,
        std::unique_ptr<frc::SpeedController> rearLeftMotor, std::unique_ptr<frc::SpeedController> rearRightMotor,
        std::unique_ptr<frc::Encoder> leftEncoder, std::unique_ptr<frc::Encoder> rightEncoder) :
        frc::Subsystem("Drivetrain"), controls(controls), robotState(robotState),
                frontLeftMotor(std::move(frontLeftMotor)), frontRightMotor(std::move(frontRightMotor)),
                rearLeftMotor(std::move(rearLeftMotor)), rearRightMotor(std::move(rearRightMotor)),
                leftMotors(new frc::SpeedControllerGroup(*frontLeftMotor, *rearLeftMotor)),
                rightMotors(new frc::SpeedControllerGroup(*frontRightMotor, *rearRightMotor)),
                leftEncoder(std::move(leftEncoder)), rightEncoder(std::move(rightEncoder))
{
    // TODO nav
    //, navSensor{frc::SerialPort::Port:: kUSB1}

    // TODO...
    /*rightCIMs.SetInverted(true);
     leftCIMs.SetInverted(true);
     leftencoder.SetDistancePerPulse(inpertick);
     rightencoder.SetDistancePerPulse(inpertick);*/
}

void Drivetrain::InitDefaultCommand()
{
    // TODO
    //SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::ArcadeDrive(double leftAxis, double rightAxis)
{
    (void) leftAxis;
    (void) rightAxis;
    //robotDrive.ArcadeDrive(leftAxis, rightAxis);
}

void Drivetrain::Stop()
{
    //robotDrive.StopMotor();
}

void Drivetrain::ResetDistance()
{
    leftEncoder->Reset();
    rightEncoder->Reset();
}

double Drivetrain::GetDistance()
{
    return (leftEncoder->GetDistance() + rightEncoder->GetDistance()) / 2;
}
float Drivetrain::GetHeading()
{
    //return navSensor.GetFusedHeading();
    return 1;
}
}
