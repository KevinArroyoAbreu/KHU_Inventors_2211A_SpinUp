//*****************************************************************
// Drivetrain.cpp
//-----------------------------------------------------------------
/*This file contains functions that control Drivetrain movements*/
//*****************************************************************
#include "main.h"

///////////////////////////////
    void turnRight(int speed)
    {
      //LEFT
     pros::c::motor_move(11, speed);
     pros::c::motor_move(12, - speed);
      //RIGHT
     pros::c::motor_move(13,   speed);
     pros::c::motor_move(14, - speed);

    }
    void driveStop()
    {
      //LEFT
     pros::c::motor_move(11, MOTOR_BRAKE_BRAKE);
     pros::c::motor_move(12, MOTOR_BRAKE_BRAKE);
      //RIGHT
     pros::c::motor_move(13, MOTOR_BRAKE_BRAKE);
     pros::c::motor_move(14, MOTOR_BRAKE_BRAKE);
    }

    // turn controller gains
    float turnkP = 0.0020;
    float turnkI = 0.0020;
    float turnkD = 0.00004;

    int desireValue;//DEGREES

    int error;
    int prevError = 0;
    int derivative;
    int totalError = 0;
    int turnDifference;

    bool enableTurnPID = true;

    int turnPID(){

      while(enableTurnPID){
        int heading = def::inertial.get_heading();

        totalError = error;

        //Potential
        error = heading - desireValue;

        //Derivative
        derivative = error - prevError;

        //Integral
        totalError += error;

        double power = error * turnkP + derivative * turnkD + totalError * turnkI;

        //LEFT
        pros::c::motor_move(11, power);
        pros::c::motor_move(12, - power);
        //RIGHT
        pros::c::motor_move(13, power);
        pros::c::motor_move(14, - power);


      }
    }





void turnInertial (int deg, int speed){
  def::inertial.tare_heading();
  pros::delay(2000);
   while(def::inertial.get_heading() <= deg){
     turnRight(speed);


   }
   driveStop();
}
