#include "RobotBuilder.h"

#include <utility>

#include <DigitalInput.h>
#include <Encoder.h>
#include <Spark.h>
#include <Talon.h>
#include <VictorSP.h>
#include <XboxController.h>

#include "Pins.h"

namespace agatha
{

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

// TODO consider double build protection??
void RobotBuilder::buildControls()
{
    // TODO pin const
    std::unique_ptr<XboxController> xboxController(new frc::XboxController(0));

    // TODO should we reset or assign??
    controls.reset(new Controls(std::move(xboxController)));
}

void RobotBuilder::buildRobotState()
{
    robotState.reset(new RobotState());
}

void RobotBuilder::buildClaw()
{
    std::unique_ptr<frc::PWMSpeedController> leftMotor(new frc::Talon(PwmPins::CLAW_LEFT));
    std::unique_ptr<frc::PWMSpeedController> rightMotor(new frc::Talon(PwmPins::CLAW_RIGHT));

    claw.reset(new Claw(controls, robotState, std::move(leftMotor), std::move(rightMotor)));
}

void RobotBuilder::buildDrivetrain()
{
    std::unique_ptr<frc::PWMSpeedController> frontLeftMotor(new frc::VictorSP(PwmPins::DRIVETRAIN_FRONT_LEFT));
    std::unique_ptr<frc::PWMSpeedController> frontRightMotor(new frc::VictorSP(PwmPins::DRIVETRAIN_FRONT_RIGHT));
    std::unique_ptr<frc::PWMSpeedController> rearLeftMotor(new frc::VictorSP(PwmPins::DRIVETRAIN_REAR_LEFT));
    std::unique_ptr<frc::PWMSpeedController> rearRightMotor(new frc::VictorSP(PwmPins::DRIVETRAIN_REAR_RIGHT));
    std::unique_ptr<frc::Encoder> leftEncoder(
            new frc::Encoder(DioPins::DRIVETRAIN_LEFT_ENCODER_A, DioPins::DRIVETRAIN_LEFT_ENCODER_B));
    std::unique_ptr<frc::Encoder> rightEncoder(
            new frc::Encoder(DioPins::DRIVETRAIN_RIGHT_ENCODER_A, DioPins::DRIVETRAIN_RIGHT_ENCODER_B));

    drivetrain.reset(
            new Drivetrain(controls, robotState, std::move(frontLeftMotor), std::move(frontRightMotor),
                    std::move(rearLeftMotor), std::move(rearRightMotor), std::move(leftEncoder),
                    std::move(rightEncoder)));
}

void RobotBuilder::buildForklift()
{
    std::unique_ptr<frc::PWMSpeedController> winchMotor(new frc::Spark(PwmPins::WINCH));
    std::unique_ptr<frc::DigitalInput> limitSwitches(new frc::DigitalInput(DioPins::FORKLIFT_LIMIT_SWITCHES));

    forklift.reset(new Forklift(controls, robotState, std::move(winchMotor), std::move(limitSwitches)));
}

}
