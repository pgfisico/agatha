#pragma once

#include <memory>

#include <Commands/Command.h>

namespace agatha
{

class Controls;
class Forklift;

class TeleopForklift : public frc::Command
{
    public:
        TeleopForklift(std::shared_ptr<Controls> controls, std::shared_ptr<Forklift> forklift);
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;

    private:
        std::shared_ptr<Controls> controls;
        std::shared_ptr<Forklift> forklift;
};

}

