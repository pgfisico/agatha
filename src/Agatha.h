#pragma once

#include <memory>

#include <TimedRobot.h>

#include "Subsystems/Claw.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Forklift.h"
#include "Controls.h"
#include "RobotState.h"

namespace agatha
{

class Agatha : public frc::TimedRobot
{
    public:
        void RobotInit() override;
        void RobotPeriodic() override;

        void DisabledInit() override;
        void DisabledPeriodic() override;

        void AutonomousInit() override;
        void AutonomousPeriodic() override;

        void TeleopInit() override;
        void TeleopPeriodic() override;

        void TestInit() override;
        void TestPeriodic() override;

    private:
        std::shared_ptr<Controls> controls;
        std::shared_ptr<RobotState> robotState;

        std::shared_ptr<Drivetrain> drivetrain;
        std::shared_ptr<Forklift> forklift;
        std::shared_ptr<Claw> claw;
};

}
