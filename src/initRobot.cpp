#include "main.h"
#include "../include/285Z/initRobot.h"

int portA = 0;
int portB = 1;
int portC = 2;
int portD = 3;

int intakeLeftPort = 4;
int intakeRight = 5;
int beltPort = 6;
int fwPort = 7;

pros::Motor driveMotorA(portA);
pros::Motor driveMotorB(portB);
pros::Motor driveMotorC(portC);
pros::Motor driveMotorD(portD);

pros::Motor leftIntakeMotor(intakeLeftPort);
pros::Motor rightIntakeMotor(intakeRight);
pros::Motor beltMotor(beltPort);
pros::Motor fwMotor(fwPort);

okapi::Controller controller;
