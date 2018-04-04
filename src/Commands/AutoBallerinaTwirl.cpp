#include "AutoBallerinaTwirl.h"
#include <Subsystems/DriveTrain.h>
#include "Robot.h"

AutoBallerinaTwirl::AutoBallerinaTwirl(double angle) : Twirl(angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
    Requires(&Robot::drivetrain);

    isClockwise = angle > 0;
}

// Called just before this Command runs the first time
void AutoBallerinaTwirl::Initialize() {
//positive angle's are clockwise and negative angles are counterclockwises because judy said so

    double StartingAngle=Robot::drivetrain.GetHeading();

    if (isClockwise){
        EndingAngle=StartingAngle+Twirl;

        if (EndingAngle > 360) {
            EndingAngle = EndingAngle - 360;

        }
    }
    else {

        EndingAngle= StartingAngle - Twirl;
        if(EndingAngle < 0){
            EndingAngle = EndingAngle + 360;
        }
    }
}

// Called repeatedly when this Command is scheduled to run
void AutoBallerinaTwirl::Execute() {

    Robot::drivetrain.ArcadeDrive(0, 0.3141459265);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoBallerinaTwirl::IsFinished() {
	return false;
	bool
}

// Called once after isFinished returns true
void AutoBallerinaTwirl::End() {

    Robot::drivetrain.Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoBallerinaTwirl::Interrupted() {

    Robot::drivetrain.Stop();

}
