//*****************************************************************
// Auton-Op.cpp
//-----------------------------------------------------------------
/*This file contains Autonomous and Operator Control tasks.*/
//*****************************************************************


//Include all header files
#include "main.h"
//___________________________________________________\\




void runAuton(){
  /*------------------------------------------*/
  //SELECTED AUTON ROUTINE:
  /*------------------------------------------*/
  //  rollerAuton();
  //  nonRollerAuton();
  //  fullWpAuton();
    progSkills();
}


void runOp(){
  //set brake mode to coast
  setDriveCoast();
  while (true) {

/*------------------------------------------*/
    //Drivetrain movement; Operator Control:
/*------------------------------------------*/

//Control Drivetrain with left joystick (drive) and right joystick(turn)
//--DRIVETRAIN CONTROL FUNCTIONS
//Drivetrain Movements (Op Control) (p. 24 subsystem#5)
int fwdJoystick = pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y);
int turnJoystick = pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_X);
//b(x) = x^2
int fwdMovementFunct = fwdJoystick^2;
int turnMovementFunct = turnJoystick/1.25;
///////////////////////////////////////////////////////////////////////////

    //LEFT
   pros::c::motor_move(11, fwdMovementFunct + turnMovementFunct);
   pros::c::motor_move(12, - fwdMovementFunct - turnMovementFunct);
    //RIGHT
   pros::c::motor_move(13, - fwdMovementFunct + turnMovementFunct);
   pros::c::motor_move(14, fwdMovementFunct - turnMovementFunct);


/*------------------------------------------*/
//Shooter; Operator Control:
/*------------------------------------------*/
if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
  flySpinToV(350);//310
}
else if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1) {
  flySpinToV(600);
}
else{
  flyStop();
}

/*------------------------------------------*/
//Intake and Roller Spinner; Operator Control:
/*------------------------------------------*/
//Intake + Shoot and Roller + Angle Changer
if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
  shoot();
}
else if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 1) {
  def::angleLever.set_value(true);
  shoot();
}
else if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) {
  intakeV(600);
  rollerV(-200);
}
else if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
  intakeV(-600);
}
else{
  intakeStop();
  def::angleLever.set_value(false);
  def::Roller_Indexer.moveVelocity(0);
  pros::c::motor_move(10, pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_Y)*(-4));
}
/*------------------------------------------*/
//Expansion; Operator Control:
/*------------------------------------------*/
if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
  deployExpansion();
  pros::delay(1000);
}



  //Refresh at a 10msec rate to prevent data loss
  pros::delay(10);
  }
}
