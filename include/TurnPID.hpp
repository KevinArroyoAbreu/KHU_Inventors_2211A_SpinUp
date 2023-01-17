//*****************************************************************
// Drivetrain.cpp
//-----------------------------------------------------------------
/*This file contains functions that control Drivetrain movements*/
//*****************************************************************
#include "main.h"

extern std::shared_ptr<ChassisController> pid;
void turnRight(int speed);
void driveStop();

void turnInertial (int deg, int Speed);




    // turn controller gains
    extern float turnkP;
    extern float turnkI;
    extern float turnkD;

    extern int desireValue;//DEGREES
    extern int desiredTunerValue;

    extern int error;
    extern int prevError;
    extern int derivative;
    extern int totalError;
    extern int turnDifference;

    extern bool enableTurnPID;

    extern int turnPID();
