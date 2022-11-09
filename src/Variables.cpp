//*****************************************************************
// Variables.cpp
//-----------------------------------------------------------------
/*This file contains global variables*/
//*****************************************************************

//Include all header files
#include "main.h"
//_________________________________________________________________
//Drivetrain Movements (Op Control) (p. 24 subsystem#5)
int fwdJoystick = pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y);
int turnJoystick = pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_X);
//b(x) = x^2
float fwdMovementFunct = fwdJoystick^3;
float turnMovementFunct = turnJoystick^3;

//PID
// distance controller gains
float dkP = 0.0025;
float dkI = 0.0000;
float dkD = 0.00004;
// turn controller gains
float tkP = 0.0035;
float tkI = 0.00;
float tkD = 0.00009;
// angle controller gains
float akP = 0.00;
float akI = 0.00;
float akD = 0.00;
