//*****************************************************************
// Drivetrain.cpp
//-----------------------------------------------------------------
/*This file contains functions that control Drivetrain movements*/
//*****************************************************************
#include "main.h"

extern std::shared_ptr<ChassisController> pid;
void turnRight(int speed);
void turnLeft(int speed);
void driveStop();

void turnInertialL(int deg, int Speed);
void turnInertialR(int deg, int Speed);
void rotate( int degrees, int speed);



    // turn controller gains
    extern float turnkP;
    extern float turnkI;
    extern float turnkD;


    extern double error;
    extern int prevError;
    extern int derivative;
    extern int totalError;
    extern int turnDifference;

    void turnPID(int DesireValue, int direction);
