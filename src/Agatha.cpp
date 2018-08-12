#include "Agatha.h"

#include <utility>

#include <Commands/Scheduler.h>

#include "RobotBuilder.h"

namespace agatha
{

void Agatha::RobotInit()
{
    RobotBuilder robotBuilder;
    robotBuilder.build();

    // TODO we don't actually use all these items
    controls = robotBuilder.getControls();
    robotState = robotBuilder.getRobotState();

    claw = robotBuilder.getClaw();
    drivetrain = robotBuilder.getDrivetrain();
    forklift = robotBuilder.getForklift();

    controls->registerButtons(claw);
}

void Agatha::RobotPeriodic()
{
    // TODO what is this good for....maybe event bus/pose/state/update???
}

void Agatha::DisabledInit()
{
    // Intentionally empty
}

void Agatha::DisabledPeriodic()
{
    frc::Scheduler::GetInstance()->Run();
}

void Agatha::AutonomousInit()
{
    // Intentionally empty
}

void Agatha::AutonomousPeriodic()
{
    frc::Scheduler::GetInstance()->Run();
}

void Agatha::TeleopInit()
{
    // Intentionally empty
}

void Agatha::TeleopPeriodic()
{
    frc::Scheduler::GetInstance()->Run();
}

void Agatha::TestInit()
{
    // Intentionally empty
}

void Agatha::TestPeriodic()
{
    // Intentionally empty
    // TODO should we run the scheduler or maybe not to support test mode...
}

}
