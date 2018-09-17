#include "Claw.h"

namespace agatha
{

static const char* SUBSYSTEM_NAME = "Claw";

// TODO add to a config???
constexpr static double SPEED = 0.5;

Claw::Claw(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
        std::unique_ptr<frc::PWMSpeedController> leftMotor, std::unique_ptr<frc::PWMSpeedController> rightMotor) :
        frc::Subsystem(SUBSYSTEM_NAME), controls(controls), robotState(robotState), leftMotor(std::move(leftMotor)),
                rightMotor(std::move(rightMotor)), clawMotors(new frc::SpeedControllerGroup(*leftMotor, *rightMotor))
{
    configureSendables();
}

void Claw::configureSendables()
{
    leftMotor->SetName(SUBSYSTEM_NAME, "LeftMotor");
    rightMotor->SetName(SUBSYSTEM_NAME, "RightMotor");

    clawMotors->SetName(SUBSYSTEM_NAME, "ClawMotorGroup");
}

void Claw::Grab()
{
    clawMotors->Set(SPEED);
}

void Claw::Release()
{
    clawMotors->Set(-SPEED);
}

void Claw::Stop()
{
    clawMotors->StopMotor();
}

}
