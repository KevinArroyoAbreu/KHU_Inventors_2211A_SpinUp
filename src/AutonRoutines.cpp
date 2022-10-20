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
//#1: rollerAuton ->
/*-------------------------------------------------------------------------*/
void rollerAuton(){
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
//#2: nonRollerAuton ->
/*-------------------------------------------------------------------------*/
void nonRollerAuton(){
  drive->moveDistanceAsync(32_in);
  intakeV(600);
  pros::delay(1200);
  intakeStop();
  drive->waitUntilSettled();
  drive->turnAngleAsync(40_deg);
  flySpinToV(600);
  drive->waitUntilSettled();
  pros::delay(1500);
  shoot();
  pros::delay(5000);
  flyStop();
  rollerStop();
  drive->turnAngle(-90_deg);
  drive->moveDistanceAsync(-52_in);
  intakeV(600);
  drive->waitUntilSettled();
  drive->turnAngle(55_deg);
  drive->moveDistance(-4_in);
  scoreRollerAuton();
  drive->moveDistance(2_in);




}

/*-------------------------------------------------------------------------*/
//#3: fullWPAuton ->
/*-------------------------------------------------------------------------*/
void fullWpAuton(){
  drive->moveDistance(-1_in);
  scoreRollerAuton();
  drive->moveDistance(6_in);
  drive->turnAngle(50.5_deg);
  drive->moveDistance(135_in);
  drive->turnAngle(-140_deg);
  drive->moveDistance(-8_in);
  scoreRollerAuton();
  drive->moveDistance(2_in);

}

/*-------------------------------------------------------------------------*/
//#4: progSkills --> Programming Skills Routine
/*-------------------------------------------------------------------------*/
void  progSkills(){
  rollerV(200);//Score Roller 1
  drive->moveDistance(-1_in);
  pros::delay(200);
  stopWColor();
  //-------------------------
  drive->turnAngle(-40_deg);
  drive->moveDistance(22_in);
  drive->turnAngle(130_deg);
  rollerV(200);  //Score Roller 2
  drive->moveDistance(-7_in);
  pros::delay(200);
  stopWColor();
  //------------------------
  drive->moveDistance(15_in);
  drive->turnAngle(-80_deg);
  drive->moveDistance(-6_in);
  drive->turnAngle(45_deg);
  //------------------------
  deployExpansion();


}
