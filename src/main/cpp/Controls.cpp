#include <Controls.h>

#include <utility>

#include <Buttons/JoystickButton.h>

#include <Commands/GrabCube.h>
#include <Commands/ReleaseCube.h>

using Hand = frc::GenericHID::JoystickHand;

namespace agatha
{

enum XboxControllerButton
    : int
    {
        A = 1,
    B = 2,
    X = 3,
    Y = 4,
    LEFT_BUMPER = 5,
    RIGHT_BUMPER = 6,
    BACK = 7,
    START = 8,
    LEFT_STICK = 9,
    RIGHT_STICK = 10
};

// TODO might the controls ever want to control robot state -- e.g. does controls represent teleop AND auto???, rumble feedback???
// probably want to be a robot state listener??
Controls::Controls(std::unique_ptr<frc::XboxController> xboxController) :
        xboxController(std::move(xboxController))
{
    // Intentionally empty
}

void Controls::registerButtons(std::shared_ptr<Claw> claw)
{
    // TODO keep refs or leak?? custom deleters needed?? does destoying cause unschedule??
    auto grabCubeButton = new JoystickButton(xboxController.get(), XboxControllerButton::B);
    grabCubeButton->WhileHeld(new GrabCube(claw));

    auto releaseCubeButton = new JoystickButton(xboxController.get(), XboxControllerButton::A);
    releaseCubeButton->WhileHeld(new ReleaseCube(claw));
}

void Controls::getDriveControl(double& straight, double& turn)
{
    straight = xboxController->GetY(Hand::kLeftHand);
    // TODO can we do the -1 better - i.e. invert filter??
    turn = -1 * xboxController->GetX(Hand::kRightHand);

    // TODO turbo should be factored in as a curve
    /*bool turbo = joystick.GetBumper(JoystickHand::kLeftHand);

     if (!turbo)
     {
     straight = std::pow(straight, 3) * 0.5;
     turn = std::pow(turn, 3) * 0.5;
     }*/
}

double Controls::getForkliftSpeed()
{
    return xboxController->GetTriggerAxis(Hand::kRightHand);
}

}
