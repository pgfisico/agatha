#include "TeleopDrive.h"

#include "Subsystems/Drivetrain.h"
#include "Controls.h"

namespace agatha
{

TeleopDrive::TeleopDrive(std::shared_ptr<Controls> controls, std::shared_ptr<Drivetrain> drivetrain) :
        frc::Command("TeleopDrive"), controls(controls), drivetrain(drivetrain)
{
    Requires(drivetrain.get());
}

void TeleopDrive::Execute()
{
    double straight, turn;
    controls->getDriveControl(straight, turn);

    drivetrain->ArcadeDrive(straight, turn);
}

bool TeleopDrive::IsFinished()
{
    // This is a default command that responds to controller input
    // It should always be running
    return false;
}

void TeleopDrive::End()
{
    drivetrain->Stop();
}

void TeleopDrive::Interrupted()
{
    End();
}

}
