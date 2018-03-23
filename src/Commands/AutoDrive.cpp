#include <Commands/AutoDrive.h>
#include <Subsystems/DriveTrain.h>
#include "Robot.h"

AutoDrive::AutoDrive(double distress) : distress(distress) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get()); WE have to tell it what subsystems it requires

    Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
    Robot::drivetrain.ResetDistance();

}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {

   Robot::drivetrain.ArcadeDrive(0.314159265, 0);

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	return Robot::drivetrain.GetDistance() >= distress;
}

// Called once after isFinished returns true
void AutoDrive::End() {

    Robot::drivetrain.Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {

    Robot::drivetrain.Stop();


}
