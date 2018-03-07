#include "Forklift.h"
#include "RobotMap.h"

Forklift::Forklift() :
        Subsystem("ExampleSubsystem"), WinchMotor(WINCH_MOTOR), LimitSwitches(LIMIT_SWITCHES)
{

}

void Forklift::InitDefaultCommand()
{
    // Set the default command for a subsystem here
    // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Forklift::ForkliftUp(){

}
void Forklift::ForkliftUp(double WinchSpeed){
WinchMotor.Set(WinchSpeed);
}

void Forklift::ForkliftDown(){
}

void Forklift::ForkliftDown(double WinchSpeed){
    (void) WinchSpeed;
}
