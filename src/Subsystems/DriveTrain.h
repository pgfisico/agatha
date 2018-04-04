#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
//#include <AHRS.h>
#pragma GCC diagnostic pop

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <VictorSP.h>
#include <SpeedControllerGroup.h>
#include "RobotMap.h"
#include <Encoder.h>

namespace frc
{
class Joystick;
}  // namespace frc

/**
 * The DriveTrain subsystem controls the robot's chassis and reads in
 * information about it's speed and position.
 */
class DriveTrain : public frc::Subsystem
{
    public:
        DriveTrain();

        /**
         * When other commands aren't using the drivetrain, allow tank drive
         * with
         * the joystick.
         */
        void InitDefaultCommand();

        /**
         * @param leftAxis Left sides value
         * @param rightAxis Right sides value
         */
        void ArcadeDrive(double leftAxis, double rightAxis);

        /**
         * Stop the drivetrain from moving.
         */
        void Stop();
        void ResetDistance();
        double GetDistance();
        float GetHeading();
    private:
        // Subsystem devices
        frc::VictorSP frontLeftCIM;
        frc::VictorSP rearLeftCIM;
        frc::SpeedControllerGroup leftCIMs;

        frc::VictorSP frontRightCIM;
        frc::VictorSP rearRightCIM;
        frc::SpeedControllerGroup rightCIMs;
        frc::Encoder leftencoder;
        frc::Encoder rightencoder;
        frc::DifferentialDrive robotDrive;

      //  AHRS navSensor;
};

