#include "main.h"
#include "../include/285Z/initRobot.h"

int frontLeftMotorPort = 2;
int frontRightMotorPort = -3;
int backLeftMotorPort = 4;
int backRightMotorPort = -5;
int portE = 4;
int portF = 5;
int portG = 6;
int portH = 7;
//  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)   .withMotors(2, -3, -5, 4)

//pros::Motor driveMotorA(portA);
//pros::Motor driveMotorB(portB);
//pros::Motor driveMotorC(portC);
//pros::Motor driveMotorD(portD);
pros::Motor driveMotorE(portE);
pros::Motor driveMotorF(portF);
pros::Motor driveMotorG(portG);
pros::Motor driveMotorH(portH);