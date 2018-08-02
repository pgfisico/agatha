#pragma once

#include <memory>

// TODO should probably just forward declare.......
#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <Encoder.h>
#include <SpeedController.h>
#include <SpeedControllerGroup.h>

// TODO nav
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
//#include <AHRS.h>
#pragma GCC diagnostic pop

// TODO is there a way to avoid the ..
#include "../Controls.h"
#include "../RobotState.h"

namespace ophelia
{

// TODO consider pulling up common subsystem items - name, controls/robotState, shared_form_this, etc
class Drivetrain : public frc::Subsystem, public std::enable_shared_from_this<Drivetrain>
{
    public:
        Drivetrain(std::shared_ptr<Controls> controls, std::shared_ptr<RobotState> robotState,
                std::unique_ptr<frc::SpeedController> frontLeftMotor,
                std::unique_ptr<frc::SpeedController> frontRightMotor,
                std::unique_ptr<frc::SpeedController> rearLeftMotor,
                std::unique_ptr<frc::SpeedController> rearRightMotor, std::unique_ptr<frc::Encoder> leftEncoder,
                std::unique_ptr<frc::Encoder> rightEncoder);

        // TODO fixup...
        void InitDefaultCommand() override;
        void ArcadeDrive(double leftAxis, double rightAxis);
        void Stop();
        void ResetDistance();
        double GetDistance();
        float GetHeading();

    private:
        std::shared_ptr<Controls> controls;
        std::shared_ptr<RobotState> robotState;

        std::unique_ptr<frc::SpeedController> frontLeftMotor;
        std::unique_ptr<frc::SpeedController> frontRightMotor;

        std::unique_ptr<frc::SpeedController> rearLeftMotor;
        std::unique_ptr<frc::SpeedController> rearRightMotor;

        std::unique_ptr<frc::SpeedControllerGroup> leftMotors;
        std::unique_ptr<frc::SpeedControllerGroup> rightMotors;

        std::unique_ptr<frc::Encoder> leftEncoder;
        std::unique_ptr<frc::Encoder> rightEncoder;

        // TODO
        //frc::DifferentialDrive robotDrive;

        // TODO nav
        //  AHRS navSensor;
};

}
