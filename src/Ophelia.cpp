#include "Ophelia.h"

#include <utility>

#include <Commands/Scheduler.h>

#include "RobotBuilder.h"

namespace ophelia
{

void Ophelia::RobotInit()
{
    RobotBuilder robotBuilder;
    robotBuilder.build();

    // TODO we don't actually use all these items
    controls = robotBuilder.getControls();
    robotState = robotBuilder.getRobotState();

    claw = robotBuilder.getClaw();
    drivetrain = robotBuilder.getDrivetrain();
    forklift = robotBuilder.getForklift();
}

void Ophelia::RobotPeriodic()
{
    // TODO what is this good for....maybe event bus/pose/state/update???
}

void Ophelia::DisabledInit()
{
    // Intentionally empty
}

void Ophelia::DisabledPeriodic()
{
    // TODO??? is this right??? - does it run command s only if set as run in disabled???
    frc::Scheduler::GetInstance()->Run();
}

void Ophelia::AutonomousInit()
{
    // Intentionally empty
}

void Ophelia::AutonomousPeriodic()
{
    frc::Scheduler::GetInstance()->Run();
}

void Ophelia::TeleopInit()
{
    // Intentionally empty
}

void Ophelia::TeleopPeriodic()
{
    frc::Scheduler::GetInstance()->Run();
}

void Ophelia::TestInit()
{
    // Intentionally empty
}

void Ophelia::TestPeriodic()
{
    // Intentionally empty
    // TODO should we run the scheduler or maybe not to support test mode...
}

}
