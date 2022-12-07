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
 def::Roller_Indexer.moveVelocity(200);
}
void liftLever(){
 def::angleLever.set_value(false);
}
void scoreRollerAuton(){
 def::Roller_Indexer.moveVelocity(200);
 pros::delay(350);
 def::Roller_Indexer.moveVelocity(0);
}
void rollerStop(){
  def::Roller_Indexer.moveVelocity(0);
}
void rollerV(int velocity){
  def::Roller_Indexer.moveVelocity(velocity);
}
void stopWColor(){
  if(22 <= def::optical.get_hue() >= 0.01 || 340 <= def::optical.get_hue() <= 359.99 ){
    pros::delay(0);
    def::Roller_Indexer.moveVelocity(0);
   }
}
