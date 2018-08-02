#pragma once

#include <Commands/Command.h>

namespace ophelia
{

class ReleaseCube : public frc::Command
{
    public:
        ReleaseCube();
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
};

}
