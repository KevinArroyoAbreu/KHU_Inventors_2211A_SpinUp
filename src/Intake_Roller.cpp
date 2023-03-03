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
 def::Roller_Indexer.moveVelocity(200);
}
void intakeStop(){
  def::Intake.moveVelocity(0);
}
void shoot(){
 def::Roller_Indexer.moveVelocity(-200);
}
void angleDown(){
 def::angleChanger.set_value(false);
}
void angleUp(){
 def::angleChanger.set_value(true);
}
void scoreRollerAuton(){
 def::Roller_Indexer.moveVelocity(-200);
 pros::delay(400);
 def::Roller_Indexer.moveVelocity(0);
}
void rollerStop(){
  def::Roller_Indexer.moveVelocity(0);
}
void rollerV(int velocity){
  def::Roller_Indexer.moveVelocity(velocity);
}
void stopWColor(){
  if(22 <= def::optical.get_hue() >= 1 || 340 <= def::optical.get_hue() <= 359.5 ){
    pros::delay(800);
    def::Roller_Indexer.moveVelocity(0);
   }
}
