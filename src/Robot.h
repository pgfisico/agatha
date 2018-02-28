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

class Robot : public frc::TimedRobot
{
    public:
        static DriveTrain drivetrain;

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
};

#endif /* SRC_ROBOT_H_ */
