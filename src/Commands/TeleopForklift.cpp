#include "TeleopForklift.h"

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
    // TODO fill??
    // maybe this should be empty since there is no stop??
    // although we do need to deassert the subsys....
}

void TeleopForklift::Interrupted()
{
    End();
}

}
