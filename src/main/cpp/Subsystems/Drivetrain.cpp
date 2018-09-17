#include <Subsystems/Drivetrain.h>

#include <Commands/TeleopDrive.h>

namespace agatha
{

static const char* SUBSYSTEM_NAME = "Drivetrain";

// TOOD
static constexpr double inpertick = 0.052;

Drivetrain::Drivetrain(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
        std::unique_ptr<frc::PWMSpeedController> frontLeftMotor,
        std::unique_ptr<frc::PWMSpeedController> frontRightMotor,
        std::unique_ptr<frc::PWMSpeedController> rearLeftMotor, std::unique_ptr<frc::PWMSpeedController> rearRightMotor,
        std::unique_ptr<frc::Encoder> leftEncoder, std::unique_ptr<frc::Encoder> rightEncoder) :
        frc::Subsystem(SUBSYSTEM_NAME), controls(controls), robotState(robotState),
                frontLeftMotor(std::move(frontLeftMotor)), frontRightMotor(std::move(frontRightMotor)),
                rearLeftMotor(std::move(rearLeftMotor)), rearRightMotor(std::move(rearRightMotor)),
                leftMotors(new frc::SpeedControllerGroup(*frontLeftMotor, *rearLeftMotor)),
                rightMotors(new frc::SpeedControllerGroup(*frontRightMotor, *rearRightMotor)),
                leftEncoder(std::move(leftEncoder)), rightEncoder(std::move(rightEncoder))
{
    // TODO should this be in inti list? - also add () for clarity or leave to prcedence??
    differentialDrive.reset(new frc::DifferentialDrive(*this->leftMotors, *this->rightMotors));

    configureSendables();

    // TODO nav
    //, navSensor{frc::SerialPort::Port:: kUSB1}

    // TODO...
    /*rightCIMs.SetInverted(true);
     leftCIMs.SetInverted(true);
     leftencoder.SetDistancePerPulse(inpertick);
     rightencoder.SetDistancePerPulse(inpertick);*/
}

void Drivetrain::configureSendables()
{
    // TODO should we be using AddChild??? These are already registerd as SendableBase -- do we nedd to refresh NT??
    frontLeftMotor->SetName(SUBSYSTEM_NAME, "FrontLeftMotor");
    frontRightMotor->SetName(SUBSYSTEM_NAME, "FrontRightMotor");
    rearLeftMotor->SetName(SUBSYSTEM_NAME, "RearLeftMotor");
    rearRightMotor->SetName(SUBSYSTEM_NAME, "RearRightMotor");

    leftMotors->SetName(SUBSYSTEM_NAME, "LeftMotorGroup");
    rightMotors->SetName(SUBSYSTEM_NAME, "RightMotorGroup");

    leftEncoder->SetName(SUBSYSTEM_NAME, "LeftEncoder");
    rightEncoder->SetName(SUBSYSTEM_NAME, "RightEncoder");

    differentialDrive->SetName(SUBSYSTEM_NAME, "DifferentialDrive");
}

void Drivetrain::InitDefaultCommand()
{
    // TODO should we keep a ref to this?? - if we use unique_ptr we probably need a custom deleter to unsched
    auto cmd = new TeleopDrive(controls, shared_from_this());
    SetDefaultCommand(cmd);
}

void Drivetrain::ArcadeDrive(double leftAxis, double rightAxis)
{
    // TODO this also applies a deadband by default....
    differentialDrive->ArcadeDrive(leftAxis, rightAxis, false);
}

void Drivetrain::Stop()
{
    differentialDrive->StopMotor();
}

void Drivetrain::ResetDistance()
{
    // TODO reconsider robot state -- resets should probably be avoided??
    leftEncoder->Reset();
    rightEncoder->Reset();
}

double Drivetrain::GetDistance()
{
    // TODO reconsider robot state -- resets should probably be avoided??
    return (leftEncoder->GetDistance() + rightEncoder->GetDistance()) / 2;
}
float Drivetrain::GetHeading()
{
    //return navSensor.GetFusedHeading();
    return 0;
}

}
