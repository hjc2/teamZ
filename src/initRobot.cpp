#include "main.h"
#include "../include/285Z/initRobot.h"

int driveMotorTopLeftPort = 0;
int driveMotorTopRightPort = 1;
int driveMotorBackLeftPort = 2;
int driveMotorBackRightPort = 3;

int intakeLeftPort = 4;
int intakeRight = 5;
int beltPort = 6;
int fwPort = 7;

pros::Motor driveMotorTopLeft(driveMotorTopLeftPort);
pros::Motor driveMotorTopRight(driveMotorTopRightPort);

pros::Motor driveMotorBackLeft(driveMotorBackLeftPort);
pros::Motor driveMotorBackRight(driveMotorBackRightPort);

pros::Motor leftIntakeMotor(intakeLeftPort);
pros::Motor rightIntakeMotor(intakeRight);
pros::Motor beltMotor(beltPort);
pros::Motor fwMotor(fwPort);

okapi::Controller controller;
