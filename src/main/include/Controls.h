#pragma once

#include <memory>

#include <XboxController.h>

namespace agatha
{

class Claw;

class Controls
{
    public:
        Controls(std::unique_ptr<frc::XboxController> xboxController);
        // TODO delete other ctor??

        void registerButtons(std::shared_ptr<Claw> claw);

        // TODO param names, doc...
        void getDriveControl(double& straight, double& turn);
        double getForkliftSpeed();

    private:
        std::unique_ptr<frc::XboxController> xboxController;
};

}
