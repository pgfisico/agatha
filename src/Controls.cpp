#include "Controls.h"

#include <utility>

namespace ophelia
{


// TODO redo...
constexpr static int Bbutton = 2;
constexpr static int Abutton = 1;


// TODO overhaul all!!!
/*Controls::Controls()
{
    // TODO Process operator interface input here.
    JoystickButton* GrabButton = new JoystickButton(&controller, Bbutton);
    GrabButton->WhileHeld(new GrabCube());

    JoystickButton* ReleaseButton = new JoystickButton(&controller, Abutton);
    ReleaseButton->WhileHeld(new ReleaseCube());
}*/


// TODO might the controls ever want to control robot state -- e.g. does controls represent teleop AND auto???, rumble feedback???
Controls::Controls(std::unique_ptr<frc::XboxController> xboxController) : xboxController(std::move(xboxController))
{
    // Intentionally empty
}

}
