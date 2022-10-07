//*****************************************************************
// Drivetrain.cpp
//-----------------------------------------------------------------
/*This file contains functions that control Drivetrain movements*/
//*****************************************************************
#include "main.h"

///////////////////////////////


/*-----------------------------------------------------------------*/
//Chassis Controller builder: PID controller
/*-----------------------------------------------------------------*/
std::shared_ptr<ChassisController> drive =
ChassisControllerBuilder()
  .withMotors({11,-12},{-13,14} )
  // Blue gearset, 2.75" inch wheel diameter,  inch wheel track; 36/60 transmission
  .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{2.75_in, 11_in}, imev5BlueTPR})
  .withGains(
    {dkP, dkI, dkD}, // distance controller gains
    {tkP, tkI, tkD}, // turn controller gains
    {akP, akI, akD}
  )
  .withMaxVelocity(400)
  .withOdometry()
  .buildOdometry();


/*-----------------------------------------------------------------*/
//Functions:
/*-----------------------------------------------------------------*/
//Set brake mode to coast
void setDriveCoast(){
  pros::c::motor_set_brake_mode(11, MOTOR_BRAKE_COAST);
  pros::c::motor_set_brake_mode(12, MOTOR_BRAKE_COAST);
  pros::c::motor_set_brake_mode(13, MOTOR_BRAKE_COAST);
  pros::c::motor_set_brake_mode(14, MOTOR_BRAKE_COAST);
}
