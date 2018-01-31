#ifndef DriveTrainK00LkidsOnly_H
#define DriveTrainK00LkidsOnly_H

#include <Commands/Subsystem.h>
#include <PWMSpeedController.h>
#include <memory>


class DriveTrainK00LkidsOnly : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<frc::PWMSpeedController>  LeftfrontMotorEMMA;
	std::shared_ptr<frc::PWMSpeedController> LeftbackMotorJUDY;
	std::shared_ptr<frc::PWMSpeedController> RightfrontMotorPAOLO;
	std::shared_ptr<frc::PWMSpeedController> RightbackMotorTOMOE;

public:
	DriveTrainK00LkidsOnly();
	void InitDefaultCommand();
};

#endif  // DriveTrainK00LkidsOnly_H
