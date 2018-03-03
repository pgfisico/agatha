/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Controls.h>
#include <WPILib.h>
#include "Commands/GrabCube.h"
#include"Commands/ReleaseCube.h"

frc::XboxController Controls::controller(0);
constexpr static int Bbutton = 2;
constexpr static int Xbutton = 3;
Controls::Controls()
{
    // Process operator interface input here.
    JoystickButton* GrabButton = new JoystickButton(&controller, Bbutton);
    GrabButton->WhileHeld(new GrabCube());

    JoystickButton* ReleaseButton = new JoystickButton(&controller, Xbutton);
    ReleaseButton->WhileHeld(new ReleaseCube());
}
