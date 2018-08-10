#pragma once

#include <memory>

// TODO fwd decl...
#include <XboxController.h>

namespace agatha
{

class Controls
{
    public:
        Controls(std::unique_ptr<frc::XboxController> xboxController);
        // TODO delete other ctor??

        // TODO param names, doc...
        void getDriveControl(double& straight, double& turn);
        double getForkliftSpeed();

    private:
        std::unique_ptr<frc::XboxController> xboxController;
};

}
