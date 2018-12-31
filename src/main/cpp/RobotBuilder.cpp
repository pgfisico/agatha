#include "RobotBuilder.h"

#include <utility>

#include <DigitalInput.h>
#include <Encoder.h>
#include <Spark.h>
#include <Talon.h>
#include <VictorSP.h>
#include <XboxController.h>

#include <Subsystems/Claw.h>
#include <Subsystems/Drivetrain.h>
#include <Subsystems/Forklift.h>
#include <Controls.h>
#include <RobotState.h>
#include <Wiring.h>

namespace agatha
{

// TODO consider double build protection??
void RobotBuilder::build()
{
    buildControls();
    buildRobotState();

    buildClaw();
    buildDrivetrain();
    buildForklift();
}

std::shared_ptr<Controls> RobotBuilder::getControls()
{
    return controls;
}

std::shared_ptr<RobotState> RobotBuilder::getRobotState()
{
    return robotState;
}

std::shared_ptr<Claw> RobotBuilder::getClaw()
{
    return claw;
}

std::shared_ptr<Drivetrain> RobotBuilder::getDrivetrain()
{
    return drivetrain;
}

std::shared_ptr<Forklift> RobotBuilder::getForklift()
{
    return forklift;
}

void RobotBuilder::buildControls()
{
    std::unique_ptr<XboxController> xboxController = std::make_unique<XboxController>(wiring::controller::XBOX_CONTROLLER_PORT);

    controls = std::make_shared<Controls>(std::move(xboxController));
}

void RobotBuilder::buildRobotState()
{
    robotState = std::make_shared<RobotState>();
}

void RobotBuilder::buildClaw()
{
    std::unique_ptr<frc::PWMSpeedController> leftMotor = std::make_unique<frc::Talon>(wiring::pwm::CLAW_LEFT);
    std::unique_ptr<frc::PWMSpeedController> rightMotor = std::make_unique<frc::Talon>(wiring::pwm::CLAW_RIGHT);

    claw = std::make_shared<Claw>(controls, robotState, std::move(leftMotor), std::move(rightMotor));
}

void RobotBuilder::buildDrivetrain()
{
    std::unique_ptr<frc::PWMSpeedController> frontLeftMotor = std::make_unique<frc::VictorSP>(wiring::pwm::DRIVETRAIN_FRONT_LEFT);
    std::unique_ptr<frc::PWMSpeedController> frontRightMotor = std::make_unique<frc::VictorSP>(wiring::pwm::DRIVETRAIN_FRONT_RIGHT);
    std::unique_ptr<frc::PWMSpeedController> rearLeftMotor = std::make_unique<frc::VictorSP>(wiring::pwm::DRIVETRAIN_REAR_LEFT);
    std::unique_ptr<frc::PWMSpeedController> rearRightMotor = std::make_unique<frc::VictorSP>(wiring::pwm::DRIVETRAIN_REAR_RIGHT);
    std::unique_ptr<frc::Encoder> leftEncoder = std::make_unique<frc::Encoder>(wiring::dio::DRIVETRAIN_LEFT_ENCODER_A, wiring::dio::DRIVETRAIN_LEFT_ENCODER_B);
    std::unique_ptr<frc::Encoder> rightEncoder = std::make_unique<frc::Encoder>(wiring::dio::DRIVETRAIN_RIGHT_ENCODER_A, wiring::dio::DRIVETRAIN_RIGHT_ENCODER_B);

    drivetrain = std::make_shared<Drivetrain>(
                    controls, robotState, std::move(frontLeftMotor), std::move(frontRightMotor),
                    std::move(rearLeftMotor), std::move(rearRightMotor), std::move(leftEncoder),
                    std::move(rightEncoder));
}

void RobotBuilder::buildForklift()
{
    std::unique_ptr<frc::PWMSpeedController> winchMotor = std::make_unique<frc::Spark>(wiring::pwm::WINCH);
    std::unique_ptr<frc::DigitalInput> limitSwitches = std::make_unique<frc::DigitalInput>(wiring::dio::FORKLIFT_LIMIT_SWITCHES);

    forklift = std::make_shared<Forklift>(controls, robotState, std::move(winchMotor), std::move(limitSwitches));
}

}
