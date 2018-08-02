#pragma once

#include <Commands/Command.h>

namespace agatha
{

class Leviosa : public frc::Command
{
    public:
        Leviosa();
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
};

}

