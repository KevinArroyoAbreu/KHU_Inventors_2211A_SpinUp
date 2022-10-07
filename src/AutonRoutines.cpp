//*****************************************************************
// AutonRoutines.cpp
//-----------------------------------------------------------------
/*This file contains diff. match autonomous routines,
and programming skills*/
//*****************************************************************

//Include all header files
#include "main.h"
//___________________________________________________\\

/*-------------------------------------------------------------------------*/
//#1: closeAuton ->
/*-------------------------------------------------------------------------*/
void closeAuton(){
  drive->moveDistance(-1_in);
  scoreRollerAuton();
  drive->moveDistance(2_in);
  drive->turnAngle(50_deg);
  intakeV(-600);
  drive->moveDistance(35_in);
  flySpinToV(510);
  rollerV(-200);
  drive->turnAngle(-75_deg);
  rollerStop();
  pros::delay(2000);
  shoot();

}

/*-------------------------------------------------------------------------*/
//#2: farAuton ->
/*-------------------------------------------------------------------------*/
void farAuton(){

}

/*-------------------------------------------------------------------------*/
//#3: fullWPAuton ->
/*-------------------------------------------------------------------------*/
void fullWpAuton(){

}

/*-------------------------------------------------------------------------*/
//#4: progSkills --> Programming Skills Routine
/*-------------------------------------------------------------------------*/
void  progSkills(){

}