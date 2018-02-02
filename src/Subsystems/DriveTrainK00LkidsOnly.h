#ifndef DriveTrainK00LkidsOnly_H
#define DriveTrainK00LkidsOnly_H

#include <Commands/Subsystem.h>
#include <Talon.h>
#include <memory>


class DriveTrainK00LkidsOnly : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	frc::Talon *Motor1;
	frc::Talon *Motor2;
	frc::Talon *Motor3;
	frc::Talon *Motor4;
	std::shared_ptr<frc::Talon> LeftfrontMotorEMMA;
	std::shared_ptr<frc::Talon> LeftbackMotorJUDY;
	std::shared_ptr<frc::Talon> RightfrontMotorPAOLO;
	std::shared_ptr<frc::Talon> RightbackMotorTOMOE;
	//code for future use
	//RobotDrive *drive;
	//drive = new RobotDrive(0,1,2,3) //4 motor drive
	//drive = new RobotDrive(0,1) //2 motor drive

public:
	DriveTrainK00LkidsOnly();
	void InitDefaultCommand();
};

#endif  // DriveTrainK00LkidsOnly_H
