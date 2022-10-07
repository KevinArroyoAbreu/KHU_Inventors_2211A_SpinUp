//*****************************************************************
// Definitions.hpp
//-----------------------------------------------------------------
/*This file contains Robot Configuration.
 Here we define the motors, sensors, actuators, and controllers used.*/
//*****************************************************************

#pragma once

//Include all header files
#include "main.h"
//___________________________________________________\\

namespace def
{
  /* ----------------------------------------------------------- */
  /* Devices */
  /* ----------------------------------------------------------- */

  /* -------------------------- Motors ------------------------- */
 //Drivetrain
 extern Motor driveFL;
 extern Motor driveFR;
 extern Motor driveRL;
 extern Motor driveRR;
  //Shooter
  extern MotorGroup Flywheel;
  //Intake&Roller
  extern Motor Intake;
  extern Motor Roller_Indexer;

  //*------------------------Pneumatics----------------------*//
  //Pneumatics (Expansion)
  //Reservoir: Top
  extern pros::ADIDigitalOut expansion;


  //Pneumatics (Indexer)
  //Reservoir: Bottom
  extern pros::ADIDigitalOut indexerLever;

  //*------------------------Sensors----------------------*//
  //Senses robot movements; accerelometer + gyroscope
  extern pros::Imu inertial;
  //Optical Sensor (on Roller Spinner)
  extern pros::Optical optical;
  //*------------------------Controller----------------------*//
  extern pros::Controller controller;


}