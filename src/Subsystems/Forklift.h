#pragma once

#include <memory>

#include <Commands/Subsystem.h>
#include <DigitalInput.h>
#include <SpeedController.h>

#include "../Controls.h"
#include "../RobotState.h"

namespace agatha
{

class Forklift : public frc::Subsystem
{
    public:
        Forklift(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
                std::unique_ptr<frc::SpeedController> winchMotor, std::unique_ptr<frc::DigitalInput> limitSwitches);

        // TODO fixup...
        void InitDefaultCommand() override;
        void ForkliftUp();
        void ForkliftUp(double WinchSpeed);
        void ForkliftDown();
        void ForkliftDown(double WinchSpeed);

    private:
        std::shared_ptr<Controls> controls;
        std::shared_ptr<RobotState> robotState;

        std::unique_ptr<frc::SpeedController> winchMotor;
        // TODO move documentation
        //The limit switches are plugged in to the NC2 and COM if you are confused asked Judy @ 587 429 2424
        std::unique_ptr<frc::DigitalInput> limitSwitches;
};

}
