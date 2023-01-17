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
   void turnLeft(int speed)
   {
     //LEFT
    pros::c::motor_move(11,-speed);
    pros::c::motor_move(12, speed);
     //RIGHT
    pros::c::motor_move(13, -speed);
    pros::c::motor_move(14,  speed);

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
    float turnkP = 0.8;
    float turnkI = 0.2;
    float turnkD = 0.04;

    double error;
    int prevError = 0;
    int derivative;
    int totalError = 0;
    int turnDifference;


    void turnPID(int desireValue, int direction){//degrees
      bool turning = true;

      while(turning){

        double  heading = def::inertial.get_heading();


        pros::screen::print(TEXT_MEDIUM, 3, "Heading: %f", heading);
        totalError = error;

        //Potential
        if(direction == 0){ // for left turns
          error = abs( (360 - desireValue) - heading );
        }
        else if(direction == 1){ // for right turns
          error =  desireValue - heading;
        }

        pros::screen::print(TEXT_MEDIUM, 4, "Error: %f", error);
        //Derivative
        derivative = error - prevError;

        //Integral
        totalError += error;

        double power = error * turnkP + derivative * turnkD + totalError * turnkI;
        if(direction == 0){ // for left turns
          turnLeft(power);
        }
        else if(direction == 1){ // for right turns
          turnRight(power);
        }


        pros::screen::print(TEXT_MEDIUM, 5, "Power: %f", power);
        if(power <= 10){
          turning = false;
        }
        pros::delay(20);
      }
      driveStop();
    }

  void rotate( int degrees, int speed){
    //define our direction, basado a donde vas
    int direction = abs(degrees) / degrees;
    // Resetiar el Gyro
    def::inertial.set_heading(0); // Aqui cambiarlo a inertial si sale un error
    // Gira a la direcion
    turnRight(speed);

        while(fabs(def::inertial.get_heading())< abs(degrees * 10)-50){// esta function es para que el valor lo cambie al correcto porque esta en 350
        pros::delay(10);
        }
    // que descanse el inertial
    if(fabs(def::inertial.get_heading())> abs(degrees * 10)){

       turnRight(50);//corrective driving

        while(fabs(def::inertial.get_heading()> abs(degrees * 10))){// esta function es para que el valor lo cambie al correcto porque esta en 350
        pros::delay(10);
        }
    }
    else if (fabs(def::inertial.get_heading())> abs(degrees * 10)){

        turnLeft(50);// corrective driving

        while(fabs(def::inertial.get_heading()> abs(degrees * 10))){// esta function es para que el valor lo cambie al correcto porque esta en 350
        pros::delay(10);
        }
      }
      driveStop();
  }




void turnInertialL (int deg, int speed){
  setDriveBrake();
   while(def::inertial.get_heading() >= ( (360-deg) + 20 ) ){//20 degree threshold
     turnLeft(speed);
     pros::screen::print(TEXT_LARGE, 3, "Inertial: %f", def::inertial.get_heading());
     pros::delay(20);
   }
   driveStop();
 }
 void turnInertialR (int deg, int speed){
   setDriveBrake();
    while(def::inertial.get_heading() <= (deg - 10) ){//10 degree threshold
      turnRight(speed);
      pros::screen::print(TEXT_LARGE, 3, "Inertial: %f", def::inertial.get_heading());
      pros::delay(20);
    }
    driveStop();
  }
