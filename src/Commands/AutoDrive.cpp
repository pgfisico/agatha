#include "AutoDrive.h"

// TODO below
#include <Ophelia.h>
#include <Subsystems/DriveTrain.h>

namespace ophelia
{
AutoDrive::AutoDrive(double distress) :
        distress(distress)
{
    // TODO inject subsystem
    //Requires(&Ophelia::drivetrain);
}

void AutoDrive::Initialize()
{
    // TODO inject subsystem
    //Ophelia::drivetrain.ResetDistance();
}

void AutoDrive::Execute()
{
    // TODO inject subsystem
    //Ophelia::drivetrain.ArcadeDrive(0.314159265, 0);
}

bool AutoDrive::IsFinished()
{
    // TODO inject subsystem
    //return Ophelia::drivetrain.GetDistance() >= distress;
    return true;
}

void AutoDrive::End()
{
    // TODO inject subsystem
    //Ophelia::drivetrain.Stop();
}

void AutoDrive::Interrupted()
{
    // TODO inject subsystem
    //Ophelia::drivetrain.Stop();

}

}
