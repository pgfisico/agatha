#pragma once

#include <memory>

#include <Commands/Subsystem.h>
#include <SpeedControllerGroup.h>

#include "../Controls.h"
#include "../RobotState.h"

namespace agatha
{

class Claw : public frc::Subsystem, public std::enable_shared_from_this<Claw>
{
    public:
        Claw(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
                std::unique_ptr<frc::SpeedController> leftMotor, std::unique_ptr<frc::SpeedController> rightMotor);

        // TODO fixup...

        void InitDefaultCommand() override;
        /**
         * grabs the power cube.
         */
        void grab();
        /**
         * releases the power cube.
         */
        void release();

    private:
        std::shared_ptr<Controls> controls;
        std::shared_ptr<RobotState> robotState;

        std::unique_ptr<frc::SpeedController> leftMotor;
        std::unique_ptr<frc::SpeedController> rightMotor;

        std::unique_ptr<frc::SpeedControllerGroup> clawMotors;
};

}
