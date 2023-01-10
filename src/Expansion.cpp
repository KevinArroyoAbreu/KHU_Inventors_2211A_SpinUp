//*****************************************************************
// Expansion.cpp
//-----------------------------------------------------------------
/*This file contains Expansion Mechanism control functions.*/
//*****************************************************************

//Include all header files
#include "main.h"
//___________________________________________________\\

//Functions
void deployExpansion(){
  def::expansion.set_value(true);
  pros::delay(500);
  def::expansionSides.set_value(true);
}
