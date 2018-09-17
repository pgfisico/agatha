#include <Commands/ReleaseCube.h>

#include <Subsystems/Claw.h>

namespace agatha
{

ReleaseCube::ReleaseCube(std::shared_ptr<Claw> claw) :
        frc::Command("ReleaseCube"), claw(claw)
{
    Requires(claw.get());
}

void ReleaseCube::Execute()
{
    claw->Release();
}

bool ReleaseCube::IsFinished()
{
    // This command is scheduled while a JoystickButton is held
    // It should always be running to avoid spurious End() calls
    return false;
}

void ReleaseCube::End()
{
    claw->Stop();
}

void ReleaseCube::Interrupted()
{
    End();
}

}
