#pragma once

#include <memory>

#include <Commands/Command.h>

#include "Subsystems/Drivetrain.h"
#include "Controls.h"

namespace agatha
{

class TeleopDrive : public frc::Command
{
    public:
        TeleopDrive(std::shared_ptr<Controls> controls, std::shared_ptr<Drivetrain> drivetrain);
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;

    private:
        std::shared_ptr<Controls> controls;
        std::shared_ptr<Drivetrain> drivetrain;
};

}
