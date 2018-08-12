#include "Forklift.h"

#include "Commands/TeleopForklift.h"

namespace agatha
{

static const char* SUBSYSTEM_NAME = "Forklift";

Forklift::Forklift(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
        std::unique_ptr<frc::PWMSpeedController> winchMotor, std::unique_ptr<frc::DigitalInput> limitSwitches) :
        frc::Subsystem(SUBSYSTEM_NAME), controls(controls), robotState(robotState), winchMotor(std::move(winchMotor)),
                limitSwitches(std::move(limitSwitches))
{
    configureSendables();
}

void Forklift::configureSendables()
{
    winchMotor->SetName(SUBSYSTEM_NAME, "WinchMotor");
    limitSwitches->SetName(SUBSYSTEM_NAME, "LimitSwitches");
}

void Forklift::InitDefaultCommand()
{
    // TODO keep ref???
    auto cmd = new TeleopForklift(controls, shared_from_this());
    SetDefaultCommand(cmd);
}

void Forklift::ForkliftUp(double WinchSpeed)
{
    if (WinchSpeed < 0)
    {
        return;
    }

    //The limit switches are plugged in to the NC2 and COM if you are confused asked Judy @ 587 429 2424
    if (limitSwitches->Get())
    {
        Stop();
    }
    else
    {
        winchMotor->Set(WinchSpeed);
    }
}

void Forklift::Stop()
{
    winchMotor->StopMotor();
}

}
