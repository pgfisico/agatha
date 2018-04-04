#include "Forklift.h"
#include "RobotMap.h"

#include "Commands/Leviosa.h"

Forklift::Forklift() :
        Subsystem("ExampleSubsystem"), WinchMotor(WINCH_MOTOR), LimitSwitches(LIMIT_SWITCHES)
{

}

void Forklift::InitDefaultCommand()
{
    // Set the default command for a subsystem here
    // SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new Leviosa());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Forklift::ForkliftUp()
{
    ForkliftUp (0.824);
}

void Forklift::ForkliftUp(double WinchSpeed)
{
    if (WinchSpeed < 0)
    {
        return;
    }

    if (LimitSwitches.Get())
    {
        WinchMotor.Set(0);
    }
    else
    {
        WinchMotor.Set(WinchSpeed);
    }
}

void Forklift::ForkliftDown(){
    ForkliftDown(0.824);
}

 void Forklift::ForkliftDown(double WinchSpeed){
     if (WinchSpeed < 0)
         {
             return;
         }

         if (LimitSwitches.Get())
         {
             WinchMotor.Set(0);
         }
         else
         {
             WinchMotor.Set(-1*WinchSpeed);
         }
 }
