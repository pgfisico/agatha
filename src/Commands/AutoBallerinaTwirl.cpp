#include "AutoBallerinaTwirl.h"

// TODO below
#include <Subsystems/DriveTrain.h>

namespace agatha
{

AutoBallerinaTwirl::AutoBallerinaTwirl(double angle) :
        Twirl(angle)
{
    // TODO inject subsystem
    //Requires(&Ophelia::drivetrain);

    isClockwise = angle > 0;
}

void AutoBallerinaTwirl::Initialize()
{
//positive angle's are clockwise and negative angles are counterclockwises because judy said so

    // TODO inject subsystem
    // double StartingAngle = Ophelia::drivetrain.GetHeading();
    double StartingAngle = 0;

    if (isClockwise)
    {
        EndingAngle = StartingAngle + Twirl;

        if (EndingAngle > 360)
        {
            EndingAngle = EndingAngle - 360;

        }
    }
    else
    {

        EndingAngle = StartingAngle - Twirl;
        if (EndingAngle < 0)
        {
            EndingAngle = EndingAngle + 360;
        }
    }
}

void AutoBallerinaTwirl::Execute()
{
    // TODO inject subsystem
    //Ophelia::drivetrain.ArcadeDrive(0, 0.3141459265);
}

bool AutoBallerinaTwirl::IsFinished()
{
    return false;
}

void AutoBallerinaTwirl::End()
{
    // TODO inject subsystem
    //Ophelia::drivetrain.Stop();

}

void AutoBallerinaTwirl::Interrupted()
{
    // TODO inject subsystem
    //Ophelia::drivetrain.Stop();

}

}
