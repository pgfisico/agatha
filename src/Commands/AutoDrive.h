#pragma once

#include <Commands/Command.h>

namespace ophelia
{
class AutoDrive : public frc::Command
{
    public:
        AutoDrive(double distress);
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();

    private:
        double distress;

};

}
