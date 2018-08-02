#include "GrabCube.h"

// TODO below
#include <Ophelia.h>

namespace ophelia
{

GrabCube::GrabCube()
{
    // TODO inject subsystem
    //Requires(&Ophelia::claw);
}

void GrabCube::Initialize()
{
    // TODO drop?
}

void GrabCube::Execute()
{
    // TODO inject subsystem
    //Ophelia::claw.grab();
}

bool GrabCube::IsFinished()
{
    return false;
}

void GrabCube::End()
{
    // TODO fill??
}

void GrabCube::Interrupted()
{
    // TODO fill?
}

}
