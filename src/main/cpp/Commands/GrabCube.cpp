#include <Commands/GrabCube.h>

#include <Subsystems/Claw.h>

namespace agatha
{

GrabCube::GrabCube(std::shared_ptr<Claw> claw) :
        frc::Command("GrabCube"), claw(claw)
{
    Requires(claw.get());
}

void GrabCube::Execute()
{
    claw->Grab();
}

bool GrabCube::IsFinished()
{
    // This command is scheduled while a JoystickButton is held
    // It should always be running to avoid spurious End() calls
    return false;
}

void GrabCube::End()
{
    claw->Stop();
}

void GrabCube::Interrupted()
{
    End();
}

}
