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
  flySpinToV(535);
  drive->turnAngle(50_deg);
  drive->moveDistance(20_in);
  //Align and Shoot Preloads
  drive->turnAngle(-64_deg);
  shoot();
  pros::delay(500);
  rollerStop();
  pros::delay(800);
  rollerV(200);
  pros::delay(2000);
  //Prepare & approach shooting Pos. #2
  flySpinToV(450);
  rollerV(-200);
  intakeV(600);
  drive->turnAngle(70_deg);
  //Intake discs
  drive->moveDistance(30_in);
  //Align and shoot
  drive->turnAngle(-90_deg);
  shoot();
  intakeV(-600);
  pros::delay(500);
  rollerStop();
  pros::delay(500);
  rollerV(200);
  pros::delay(500);
  rollerStop();
  flySpinToV(500);
  pros::delay(600);
  rollerV(200);
  pros::delay(2000);
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
flySpinToV(480);
 drive->moveDistanceAsync(32_in);
 intakeV(600);
 rollerV(-200);
 pros::delay(1200);
 drive->waitUntilSettled();
 drive->turnAngleAsync(39_deg);
 pros::delay(200);
 intakeStop();
 drive->waitUntilSettled();
 drive->moveDistance(6_in);
 shoot();
 pros::delay(800);
 rollerStop();
 intakeV(600);
 pros::delay(1500);
 rollerV(200);
 pros::delay(2000);
 flyStop();
 rollerStop();
 drive->turnAngle(-89_deg);
 drive->moveDistanceAsync(-52_in);
 intakeV(600);
 drive->waitUntilSettled();
 drive->turnAngle(55_deg);
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
//#4: progSkills --> Programming Skills Routine (USE ONLY 1 PRELOAD!!!!!) to prevent jamming
/*-------------------------------------------------------------------------*/
void  progSkills(){
  rollerV(200);//Score Roller 1
  drive->moveDistance(-2_in);
  pros::delay(300);
  stopWColor();
  //-------------------------
  intakeV(600);
  rollerV(-200);
  drive->turnAngle(-40_deg);
  drive->moveDistance(22_in);
  drive->turnAngle(135_deg);
  rollerV(200);  //Score Roller 2
  drive->moveDistance(-9_in);
  pros::delay(300);
  stopWColor();
  //------------------------
  drive->moveDistance(4_in);
  drive->turnAngle(-95_deg);
  flySpinToV(350); //normal shooting
  drive->moveDistance(32_in);
  shoot();  //Score 2 discs( 1 preload + 1 intaked)
  pros::delay(4000);
  drive->turnAngle(90_deg);
  flyStop();
  //------------------------
  //intake 2 discs on path
  intakeV(600);
  rollerV(-200);
  drive->moveDistance(70_in);
  // Align with blue goal
  flySpinToV(360);
  drive->turnAngle(45_deg);
  intakeV(-600);//prevent jamming
  pros::delay(500);
  shoot();//shoot 2-3 intaked discs
  pros::delay(2000);
  //--------------------------
  //Approach expanding location
  drive->turnAngle(-80_deg);
  drive->moveDistance(-75_in);//drive towards end location (close to start location)
  drive->turnAngle(-20_deg);//optimal expanding robot heading */
  //expand
  deployExpansion();

  ////END-OF-ROUTINE////
  //__________________//
  //Expected Results: //
  // --2x Rollers     //
  // --4-6x High Discs  //
  // -- ~20 tiles     //
  //__________________//
  // TOTAL: ~100pts   //
  //////////////////////


  //deployExpansion();
}
