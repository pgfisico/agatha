#pragma once

#include <memory>

#include <XboxController.h>

namespace agatha
{

class Controls
{
    public:
        Controls(std::unique_ptr<frc::XboxController> xboxController);

    private:
        std::unique_ptr<frc::XboxController> xboxController;
};

}
