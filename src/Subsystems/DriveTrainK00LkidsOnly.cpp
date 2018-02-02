#include "DriveTrainK00LkidsOnly.h"
#include "../RobotMap.h"

DriveTrainK00LkidsOnly::DriveTrainK00LkidsOnly() : frc::Subsystem("ExampleSubsystem") {



Motor1 =	 new frc::Talon(1);
Motor2 = new frc::Talon(2);
Motor3 = new frc::Talon(3);
Motor4 = new frc::Talon(4);



}

void DriveTrainK00LkidsOnly::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
