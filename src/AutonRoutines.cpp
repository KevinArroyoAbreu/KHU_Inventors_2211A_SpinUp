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
  //Turn Roller
  drive->moveDistance(-1_in);
  scoreRollerAuton();
  //Approach Shooting Pos. #1
  drive->moveDistance(2_in);
  flySpinToV(510);
  turn->turnAngle(50_deg);
  drive->moveDistance(20_in);
  //Align and Shoot Preloads
  turn->turnAngle(-65_deg);
  shoot();
  pros::delay(500);
  rollerStop();
  flySpinToV(540);
  pros::delay(1000);
  rollerV(200);
  pros::delay(2000);
  //Prepare & approach shooting Pos. #2
  flySpinToV(420);
  rollerV(-200);
  intakeV(600);
  turn->turnAngle(75_deg);
  //Intake discs
  drive->moveDistance(30_in);
  //Align and shoot
  turn->turnAngle(-95_deg);
  shoot();
  pros::delay(5000);
  //All subsystems shut down
  flyStop();
  rollerStop();
  intakeStop();
}

/*-------------------------------------------------------------------------*/
//#2: nonRollerAuton ->
/*-------------------------------------------------------------------------*/
void nonRollerAuton(){
  //Intake 1 disc and align with goal
 flySpinToV(460);
 intakeV(600);
 rollerV(-200);
 drive->moveDistance(32_in);
 turn->turnAngle(36_deg);
 drive->moveDistance(6_in);
 intakeV(-600);
 shoot();
 pros::delay(3000);
 flyStop();
 rollerStop();
 turn->turnAngle(-92_deg);
 drive->moveDistanceAsync(-52_in);
 intakeV(600);
 drive->waitUntilSettled();
 turn->turnAngle(55_deg);
 drive->moveDistance(-6_in);
 scoreRollerAuton();
 drive->moveDistance(3_in);
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
  turn->turnAngle(-145_deg);
  flySpinToV(450);
  drive->moveDistance(-140_in);
  //Turn towards roller 2 and turn it
  turn->turnAngle(50.5_deg);
  drive->moveDistance(-6_in);
  scoreRollerAuton();
  drive->moveDistance(2_in);

}

/*-------------------------------------------------------------------------*/
//#4: progSkills --> Programming Skills Routine (USE ONLY 1 PRELOAD!!!!!) to prevent jamming
/*-------------------------------------------------------------------------*/
void  progSkills(){
  rollerV(-200);//Score Roller 1
  skills->moveDistance(-3_in);
  pros::delay(0);
  rollerStop();
  skills->moveDistance(3_in);
  //-------------------------
  intakeV(600);
  rollerV(-200);
  turn->turnAngle(-40_deg);
  skills->moveDistance(22_in);
  turn->turnAngle(135_deg);
  rollerV(-200);  //Score Roller 2
  skills->moveDistance(-12_in);
  pros::delay(0);
  rollerStop();
  //------------------------
  skills->moveDistance(8_in);
  turn->turnAngle(-95_deg);
  flySpinToV(360); //normal shooting
  skills->moveDistance(32_in);
  turn->turnAngle(10_deg);
  shoot();  //Score 2 discs( 1 preload + 1 intaked)
  pros::delay(4000);
  turn->turnAngle(80_deg);
  flyStop();
  //------------------------
  //intake 1 disc on path
  intakeV(600);
  rollerV(-200);
  skills->moveDistance(20_in);
  //Align with discs
  turn->turnAngle(-45_deg);
  //Intake 2 discs
  skills->moveDistance(35_in);
  // Align with blue goal
  turn->turnAngle(-90_deg);
  flySpinToV(380);
  intakeV(-600);//prevent jamming
  pros::delay(500);
  shoot();//shoot 2-3 intaked discs
  pros::delay(2000);
  //--------------------------
  //Approach 2nd roller pair
  skills->moveDistance(-7_in);
  turn->turnAngle(-98_deg);
  flyStop();
  skills->moveDistance(-65_in);
  //align with 3rd roller and score it
  turn->turnAngle(-45_deg);
  rollerV(-200);
  skills->moveDistance(-14_in);
  rollerStop();
  skills->moveDistance(3_in);
  //-------------------------
  intakeV(600);
  rollerV(-200);
  turn->turnAngle(-40_deg);
  skills->moveDistance(22_in);
  turn->turnAngle(125_deg);
  rollerV(-200);  //Score Roller 4
  skills->moveDistance(-14_in);
  pros::delay(0);
  rollerStop();
  //Approach expanding location
  skills->moveDistance(20_in);
  turn->turnAngle(-48_deg);
  //expand
  deployExpansion();

  ////END-OF-ROUTINE////
  //__________________//
  //Expected Results: //
  // --4x Rollers     //
  // -- 6x High Discs  //
  // -- ~26 tiles     //
  //__________________//
  // TOTAL: ~100pts   //
  //////////////////////
}
