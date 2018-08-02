#include "Forklift.h"

#include <utility>

// TODO
//#include "Commands/Leviosa.h"

namespace agatha
{

Forklift::Forklift(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
        std::unique_ptr<frc::SpeedController> winchMotor, std::unique_ptr<frc::DigitalInput> limitSwitches) :
        frc::Subsystem("Forklift"), controls(controls), robotState(robotState), winchMotor(std::move(winchMotor)),
                limitSwitches(std::move(limitSwitches))
{
    // Intentionally empty
}

void Forklift::InitDefaultCommand()
{
    //SetDefaultCommand(new Leviosa());
}

void Forklift::ForkliftUp()
{
    ForkliftUp(0.824);
}

void Forklift::ForkliftUp(double WinchSpeed)
{
    if (WinchSpeed < 0)
    {
        return;
    }

    if (limitSwitches->Get())
    {
        winchMotor->Set(0);
    }
    else
    {
        winchMotor->Set(WinchSpeed);
    }
}

void Forklift::ForkliftDown()
{
    ForkliftDown(0.824);
}

void Forklift::ForkliftDown(double WinchSpeed)
{
    if (WinchSpeed < 0)
    {
        return;
    }

    if (limitSwitches->Get())
    {
        winchMotor->Set(0);
    }
    else
    {
        winchMotor->Set(-1 * WinchSpeed);
    }
}

}
