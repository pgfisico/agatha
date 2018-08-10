#include "Claw.h"

namespace agatha
{

static const char* SUBSYSTEM_NAME = "Claw";

// TODO wrap in namespace -- add to a config???
constexpr static double SPEED = 0.5;

Claw::Claw(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
        std::unique_ptr<frc::PWMSpeedController> leftMotor, std::unique_ptr<frc::PWMSpeedController> rightMotor) :
        frc::Subsystem(SUBSYSTEM_NAME), controls(controls), robotState(robotState),
                clawMotors(new frc::SpeedControllerGroup(*leftMotor, *rightMotor))
{
    configureSendables();
}

void Claw::configureSendables()
{
    leftMotor->SetName(SUBSYSTEM_NAME, "LeftMotor");
    rightMotor->SetName(SUBSYSTEM_NAME, "RightMotor");

    clawMotors->SetName(SUBSYSTEM_NAME, "ClawMotorGroup");
}

void Claw::InitDefaultCommand()
{
    // TODO
}

void Claw::grab()
{
    clawMotors->Set(SPEED);
}
void Claw::release()
{
    clawMotors->Set(-SPEED);
}

}
