#pragma once

#include <memory>

#include <Commands/Subsystem.h>
#include <DigitalInput.h>
#include <PWMSpeedController.h>

#include "../Controls.h"
#include "../RobotState.h"

namespace agatha
{

class Forklift : public frc::Subsystem, public std::enable_shared_from_this<Forklift>
{
    public:
        Forklift(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
                std::unique_ptr<frc::PWMSpeedController> winchMotor, std::unique_ptr<frc::DigitalInput> limitSwitches);

        void InitDefaultCommand() override;

        void ForkliftUp(double WinchSpeed);
        void Stop();

    private:
        std::shared_ptr<Controls> controls;
        std::shared_ptr<RobotState> robotState;

        std::unique_ptr<frc::PWMSpeedController> winchMotor;
        std::unique_ptr<frc::DigitalInput> limitSwitches;

        void configureSendables();
};

}
