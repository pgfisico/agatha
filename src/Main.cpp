// TODO doc

#include <RobotBase.h>

#include "Agatha.h"

START_ROBOT_CLASS(agatha::Agatha)

// TODO
/*
 * The next step is probably to refactor controls
 * We want controls to support filtering and custom curves.
 * We need to figure out how to push the controls into the subsystem default command
 * -- will there be a command factory??
 * -- will there be a common base class so each subsystem auto hooks into robot, robot state, controls, etc???
 * -- where do we put the state-based guardds/limits????
 * -----do they go in the actual subsystem
 * -----do they belong exclusively in the command???
 * -----consider amount of passoing/dereferencing
 * -----consider impact on control loop frequency...
 * ---------are loops always active or do they suspend once hitting a setpoint (e.g. forklift droop...)
 */
