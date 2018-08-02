#include "ReleaseCube.h"

// TODO below

namespace agatha
{

ReleaseCube::ReleaseCube()
{
    // TODO inject subsystem
    //Requires(&Ophelia::claw);
}

void ReleaseCube::Initialize()
{
    // TODO drop??
}

void ReleaseCube::Execute()
{
    // TODO inject subsystem
    //Ophelia::claw.release();
}

bool ReleaseCube::IsFinished()
{
    return false;
}

void ReleaseCube::End()
{
    // TODO fill??
}

void ReleaseCube::Interrupted()
{
    // TODO fill??
}

}
