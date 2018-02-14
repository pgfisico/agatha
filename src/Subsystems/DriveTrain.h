#pragma once

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <VictorSP.h>
#include <SpeedControllerGroup.h>
#include "RobotMap.h"

namespace frc {
class Joystick;
}  // namespace frc

/**
 * The DriveTrain subsystem controls the robot's chassis and reads in
 * information about it's speed and position.
 */
class DriveTrain : public frc::Subsystem {
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

private:
	// Subsystem devices
	frc::VictorSP frontLeftCIM{FRONT_LEFT};
	frc::VictorSP rearLeftCIM{REAR_LEFT};
	frc::SpeedControllerGroup leftCIMs{frontLeftCIM, rearLeftCIM};

	frc::VictorSP frontRightCIM{FRONT_RIGHT};
	frc::VictorSP rearRightCIM{REAR_RIGHT};
	frc::SpeedControllerGroup rightCIMs{frontRightCIM, rearRightCIM};

	frc::DifferentialDrive robotDrive{leftCIMs, rightCIMs};
};




