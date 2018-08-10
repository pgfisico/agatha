#pragma once

#include <memory>

// TODO should probably just forward declare.......
#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <Encoder.h>
#include <PWMSpeedController.h>
#include <SpeedControllerGroup.h>

// TODO nav
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
//#include <AHRS.h>
#pragma GCC diagnostic pop

// TODO is there a way to avoid the ..
#include "../Controls.h"
#include "../RobotState.h"

namespace agatha
{

// TODO consider pulling up common subsystem items - name, controls/robotState, shared_form_this, etc
class Drivetrain : public frc::Subsystem, public std::enable_shared_from_this<Drivetrain>
{
    public:
        Drivetrain(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
                std::unique_ptr<frc::PWMSpeedController> frontLeftMotor,
                std::unique_ptr<frc::PWMSpeedController> frontRightMotor,
                std::unique_ptr<frc::PWMSpeedController> rearLeftMotor,
                std::unique_ptr<frc::PWMSpeedController> rearRightMotor, std::unique_ptr<frc::Encoder> leftEncoder,
                std::unique_ptr<frc::Encoder> rightEncoder);

        // TODO fixup...
        void InitDefaultCommand() override;

        // TODO rename params
        void ArcadeDrive(double leftAxis, double rightAxis);
        // TODOnocapss??
        void Stop();
        void ResetDistance();
        double GetDistance();
        float GetHeading();

    private:
        std::shared_ptr<Controls> controls;
        std::shared_ptr<RobotState> robotState;

        std::unique_ptr<frc::PWMSpeedController> frontLeftMotor;
        std::unique_ptr<frc::PWMSpeedController> frontRightMotor;

        std::unique_ptr<frc::PWMSpeedController> rearLeftMotor;
        std::unique_ptr<frc::PWMSpeedController> rearRightMotor;

        std::unique_ptr<frc::SpeedControllerGroup> leftMotors;
        std::unique_ptr<frc::SpeedControllerGroup> rightMotors;

        std::unique_ptr<frc::Encoder> leftEncoder;
        std::unique_ptr<frc::Encoder> rightEncoder;

        std::unique_ptr<frc::DifferentialDrive> differentialDrive;

        // TODO nav
        //  AHRS navSensor;

        void configureSendables();
};

}
