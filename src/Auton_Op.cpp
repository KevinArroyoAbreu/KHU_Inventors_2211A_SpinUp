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
  closeAuton();
//  farAuton();
//  fullWpAuton();
//  progSkills();
}


void runOp(){
  //set brake mode to coast
  setDriveCoast();
  while (true) {

/*------------------------------------------*/
    //Drivetrain movement; Operator Control:
/*------------------------------------------*/

//Control Drivetrain with left joystick (drive) and right joystick(turn)

    //LEFT
    pros::c::motor_move(11,
      pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y)*driveMult
      + pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_X)*turnMult);

    pros::c::motor_move(12,
      - pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y)*driveMult
      - pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_X)*turnMult);


    //RIGHT
    pros::c::motor_move(13,
    -  pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y)*driveMult
      + pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_X)*turnMult);

    pros::c::motor_move(14,
      pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y)*driveMult
      - pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_X)*turnMult);


/*------------------------------------------*/
//Shooter; Operator Control:
/*------------------------------------------*/
if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
  flySpinToV(310);
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
//Intake
if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) {
  intakeV(600);
}
else if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
  intakeV(-600);
}
else{
  intakeStop();
}
//Shoot and Roller
if (def::controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
  shoot();
}
else{
  def::indexerLever.set_value(true);
  def::Roller_Indexer.moveVelocity(0);
  pros::c::motor_move(10, pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_Y)*(-2));
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