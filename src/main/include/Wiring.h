#pragma once

namespace agatha
{
// TODO consider alternate options for this
namespace wiring
{

namespace controller
{
constexpr int XBOX_CONTROLLER_PORT = 0;
}

namespace pwm
{
constexpr int DRIVETRAIN_FRONT_LEFT = 1;
constexpr int DRIVETRAIN_FRONT_RIGHT = 3;

constexpr int DRIVETRAIN_REAR_LEFT = 2;
constexpr int DRIVETRAIN_REAR_RIGHT = 4;

constexpr int CLAW_LEFT = 5;
constexpr int CLAW_RIGHT = 6;

constexpr int WINCH = 6;
} // namespace pwm

namespace dio
{
constexpr int DRIVETRAIN_LEFT_ENCODER_A = 1;
constexpr int DRIVETRAIN_LEFT_ENCODER_B = 2;

constexpr int DRIVETRAIN_RIGHT_ENCODER_A = 3;
constexpr int DRIVETRAIN_RIGHT_ENCODER_B = 4;

constexpr int FORKLIFT_LIMIT_SWITCHES = 0;
} // namespace dio

} // namespace wiring
} // namespace agatha
