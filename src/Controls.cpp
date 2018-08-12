#include "Controls.h"

#include <utility>

typedef frc::GenericHID::JoystickHand Hand;

namespace agatha
{

// TODO might the controls ever want to control robot state -- e.g. does controls represent teleop AND auto???, rumble feedback???
// probably want to be a robot state listener??
Controls::Controls(std::unique_ptr<frc::XboxController> xboxController) :
        xboxController(std::move(xboxController))
{
    // Intentionally empty
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

// TODO button scheduling
/*
 constexpr static int Bbutton = 2;
 constexpr static int Abutton = 1;

 Controls::Controls()
 {
 JoystickButton* GrabButton = new JoystickButton(&controller, Bbutton);
 GrabButton->WhileHeld(new GrabCube());

 JoystickButton* ReleaseButton = new JoystickButton(&controller, Abutton);
 ReleaseButton->WhileHeld(new ReleaseCube());
 }*/

}
