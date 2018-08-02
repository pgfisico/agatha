#pragma once

#include <Commands/Command.h>

namespace agatha
{

class AutoBallerinaTwirl : public frc::Command
{
    public:
        AutoBallerinaTwirl(double angle);
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();

    private:
        bool isClockwise;
        double EndingAngle;
        double Twirl;

};

}
