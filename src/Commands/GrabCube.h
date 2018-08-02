#pragma once

#include <Commands/Command.h>

namespace agatha
{
class GrabCube : public frc::Command
{
    public:
        GrabCube();
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
};

}
