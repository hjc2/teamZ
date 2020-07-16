#pragma once
#include "main.h"
//ALL NAMES ARE PLACEHOLDERS TIL BOT DESIGN IS DECIDED

//MOTORS
extern int driveMotorTopLeftPort;
extern int driveMotorTopRightPort;
extern int driveMotorBackLeftPort;
extern int driveMotorBackRightPort;

extern int intakeLeftPort;
extern int intakeRight;
extern int beltPort;
extern int fwPort;

extern pros::Motor driveMotorTopLeft;
extern pros::Motor driveMotorTopRight;
extern pros::Motor driveMotorBackLeft;
extern pros::Motor driveMotorBackRight;

extern pros::Motor leftIntakeMotor;
extern pros::Motor rightIntakeMotor;
extern pros::Motor beltMotor;
extern pros::Motor fwMotor;

//CONTROLLER
extern okapi::Controller controller;
