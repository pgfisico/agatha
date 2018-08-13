#include "TeleopForklift.h"

#include "Subsystems/Forklift.h"
#include "Controls.h"

namespace agatha
{

TeleopForklift::TeleopForklift(std::shared_ptr<Controls> controls, std::shared_ptr<Forklift> forklift) :
        frc::Command("TeleopForklift"), controls(controls), forklift(forklift)
{
    Requires(forklift.get());
}

void TeleopForklift::Execute()
{
    forklift->ForkliftUp(controls->getForkliftSpeed());
}

bool TeleopForklift::IsFinished()
{
    // This is a default command that responds to controller input
    // It should always be running
    return false;
}

void TeleopForklift::End()
{
    forklift->Stop();
}

void TeleopForklift::Interrupted()
{
    End();
}

}
