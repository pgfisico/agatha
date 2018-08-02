#pragma once

#include <memory>

#include <XboxController.h>

namespace ophelia
{

class Controls
{
    public:
        Controls(std::unique_ptr<frc::XboxController> xboxController);

    private:
        std::unique_ptr<frc::XboxController> xboxController;
};

}
