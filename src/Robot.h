/*
 * Robot.h
 *
 *  Created on: Feb 6, 2018
 *      Author: judy
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_
#include <TimedRobot.h>
#include <Subsystems/DriveTrain.h>
#include <Subsystems/Claw.h>
#include "Subsystems/Forklift.h"
#include "Commands/AutoDrive.h"
#include "Commands/AutoBallerinaTwirl.h"

class Robot : public frc::TimedRobot
{
    public:
        static DriveTrain drivetrain;
        static Claw claw;
        static Forklift forklift;

        void RobotInit() override;
        void DisabledInit() override;
        void DisabledPeriodic() override;
        void AutonomousInit() override;
        void AutonomousPeriodic() override;
        void TeleopInit() override;
        void TeleopPeriodic() override;
        void TestPeriodic() override;

    private:
        frc::Command* m_autonomousCommand = nullptr;
        AutoDrive *autodriveDefault;
        AutoBallerinaTwirl *autodriveBallerina;
};

#endif /* SRC_ROBOT_H_ */
