#pragma once

#include <Commands/Command.h>

namespace agatha
{

class DriveWithJoystick : public frc::Command
{
    public:
        DriveWithJoystick();
        void Execute() override;
        bool IsFinished() override;
        void End() override;
};

}
