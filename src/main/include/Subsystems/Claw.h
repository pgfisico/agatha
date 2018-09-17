#pragma once

#include <memory>

#include <Commands/Subsystem.h>
// TODO should we fwd declare frc claswses??
#include <PWMSpeedController.h>
#include <SpeedControllerGroup.h>

namespace agatha
{

class Controls;
class RobotState;

class Claw : public frc::Subsystem, public std::enable_shared_from_this<Claw>
{
    public:
        Claw(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
                std::unique_ptr<frc::PWMSpeedController> leftMotor, std::unique_ptr<frc::PWMSpeedController> rightMotor);

        void Grab();
        void Release();
        void Stop();

    private:
        std::shared_ptr<Controls> controls;
        std::shared_ptr<RobotState> robotState;

        std::unique_ptr<frc::PWMSpeedController> leftMotor;
        std::unique_ptr<frc::PWMSpeedController> rightMotor;

        std::unique_ptr<frc::SpeedControllerGroup> clawMotors;

        void configureSendables();
};

}
