#pragma once

// TODO also consider "wiring"
namespace ophelia
{

class PwmPins
{
    public:
        static constexpr int DRIVETRAIN_FRONT_LEFT = 1;
        static constexpr int DRIVETRAIN_FRONT_RIGHT = 3;

        static constexpr int DRIVETRAIN_REAR_LEFT = 2;
        static constexpr int DRIVETRAIN_REAR_RIGHT = 4;

        static constexpr int CLAW_LEFT = 5;
        static constexpr int CLAW_RIGHT = 6;

        static constexpr int WINCH = 6;

        // TODO priv delete ctors...
};

class DioPins
{
    public:
        static constexpr int DRIVETRAIN_LEFT_ENCODER_A = 1;
        static constexpr int DRIVETRAIN_LEFT_ENCODER_B = 2;

        static constexpr int DRIVETRAIN_RIGHT_ENCODER_A = 3;
        static constexpr int DRIVETRAIN_RIGHT_ENCODER_B = 4;

        static constexpr int FORKLIFT_LIMIT_SWITCHES = 0;
};

}
