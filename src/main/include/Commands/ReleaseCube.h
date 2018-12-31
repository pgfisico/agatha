#pragma once

#include <memory>

#include <Commands/Command.h>

namespace agatha
{

class Claw;

class ReleaseCube : public frc::Command
{
    public:
        ReleaseCube(std::shared_ptr<Claw> claw);
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;

    private:
        std::shared_ptr<Claw> claw;
};

}