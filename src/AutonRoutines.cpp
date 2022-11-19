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
//  drive->turnAngle(50_deg);
//  intakeV(-600);
//  drive->moveDistance(33_in);
/*  flySpinToV(600);
  drive->turnAngle(-70_deg);
  pros::delay(2000);
  shoot();
  pros::delay(4000);
  flyStop();
  rollerStop();
  intakeStop(); */


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
  drive->turnAngle(40_deg);
  /*flySpinToV(570);*/
  drive->moveDistance(6_in);
  pros::delay(1500);
  /*shoot();*/
  pros::delay(4000);
  flyStop();
  rollerStop();
  liftLever();
  drive->turnAngle(-90_deg);
  drive->moveDistanceAsync(-52_in);
  intakeV(600);
  drive->waitUntilSettled();
  drive->turnAngle(55_deg);
  drive->moveDistance(-8_in);
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
  drive->turnAngle(-141_deg);
  flySpinToV(450);
  drive->moveDistance(-66_in);
  //Turn towards goal and shoot
  drive->turnAngle(100_deg);
  shoot();
  pros::delay(2000);
  //Approach second roller
  drive->turnAngle(-95_deg);
  drive->moveDistance(-74_in);
  //Turn towards roller 2 and turn it
  drive->turnAngle(50.5_deg);
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
