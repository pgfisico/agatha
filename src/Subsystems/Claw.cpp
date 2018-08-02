#include "Claw.h"

// TODO wrap in namespace -- add to a config???
constexpr static double SPEED = 0.5;

namespace agatha
{

Claw::Claw(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
        std::unique_ptr<frc::SpeedController> leftMotor, std::unique_ptr<frc::SpeedController> rightMotor) :
        frc::Subsystem("Claw"), controls(controls), robotState(robotState),
                clawMotors(new frc::SpeedControllerGroup(*leftMotor, *rightMotor))
{
    // Intentionally empty
}

void Claw::InitDefaultCommand()
{
    // TODO
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Claw::grab()
{
    clawMotors->Set(SPEED);
}
void Claw::release()
{
    clawMotors->Set(-SPEED);
}

}
