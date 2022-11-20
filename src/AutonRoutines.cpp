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
  drive->turnAngle(90_deg);
//  intakeV(-600);
//  drive->moveDistance(33_in);
  flySpinToV(300);
//  drive->turnAngle(-70_deg);
  pros::delay(2000);
  shoot();
//  pros::delay(4000);
//  flyStop();
//  rollerStop();
//  intakeStop(); */


}

/*-------------------------------------------------------------------------*/
//#2: nonRollerAuton ->
/*-------------------------------------------------------------------------*/
void nonRollerAuton(){
  flySpinToV(300);
  pros::delay(2000);
  shoot();
  pros::delay(4000);
  flyStop();
  rollerStop();
  liftLever();
  drive->moveDistance(-25_in);
  drive->turnAngle(95_deg);
  drive->moveDistance(-5_in);
  scoreRollerAuton();
  drive->moveDistance(2_in);




}

/*-------------------------------------------------------------------------*/
//#3: fullWPAuton ->
/*-------------------------------------------------------------------------*/
void fullWpAuton(){
  //Score Roller 1
  drive->moveDistance(-1_in);
  scoreRollerAuton();
  drive->moveDistance(4_in);
  //Approach shooting distance
  drive->turnAngle(-145_deg);
  flySpinToV(450);
  drive->moveDistance(-140_in);
  //Turn towards roller 2 and turn it
  drive->turnAngle(50.5_deg);
  drive->moveDistance(-6_in);
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
  drive->turnAngle(30_deg);
  //drive->moveDistance(10_in);
//  drive->turnAngle(90_deg);
  //rollerV(200);  //Score Roller 2
//  drive->moveDistance(-4_in);
//  pros::delay(200);
//  stopWColor();
  //------------------------
//  drive->moveDistance(15_in);
//  drive->turnAngle(-80_deg);
//  drive->moveDistance(-6_in);
//  drive->turnAngle(45_deg);
  //------------------------
  deployExpansion();
}
