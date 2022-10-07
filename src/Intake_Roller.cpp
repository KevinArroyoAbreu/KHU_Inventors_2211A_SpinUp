//*****************************************************************
// Intake&Roller.cpp
//-----------------------------------------------------------------
/*This file contains Intake&Roller control functions.*/
//*****************************************************************

//Include all header files
#include "main.h"
//___________________________________________________\\

//Functions
void intakeV(int velocity){
 def::Intake.moveVelocity(velocity);
}
void intakeStop(){
  def::Intake.moveVelocity(0);
}
void shoot(){
 def::indexerLever.set_value(false);
 pros::delay(150);
 def::Roller_Indexer.moveVelocity(200);
}
void scoreRollerAuton(){
 def::Roller_Indexer.moveVelocity(200);
 pros::delay(500);
 def::Roller_Indexer.moveVelocity(0);
}
void rollerStop(){
  def::Roller_Indexer.moveVelocity(0);
}
void rollerV(int velocity){
  def::Roller_Indexer.moveVelocity(velocity);
}
