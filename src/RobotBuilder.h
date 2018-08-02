#pragma once

#include <memory>

#include "Subsystems/Claw.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Forklift.h"
#include "Controls.h"
#include "RobotState.h"

namespace ophelia
{

class RobotBuilder
{
        // TODO delete extra ctors...??
    public:
        // TODO noexcept???
        void build();

        std::shared_ptr<Controls> getControls();
        std::shared_ptr<RobotState> getRobotState();

        std::shared_ptr<Claw> getClaw();
        std::shared_ptr<Drivetrain> getDrivetrain();
        std::shared_ptr<Forklift> getForklift();

    private:
        std::shared_ptr<Controls> controls;
        std::shared_ptr<RobotState> robotState;

        std::shared_ptr<Claw> claw;
        std::shared_ptr<Drivetrain> drivetrain;
        std::shared_ptr<Forklift> forklift;

        void buildControls();
        void buildRobotState();

        void buildClaw();
        void buildDrivetrain();
        void buildForklift();
};

}
