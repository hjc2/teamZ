#pragma once
#include "main.h"
//ALL NAMES ARE PLACEHOLDERS TIL BOT DESIGN IS DECIDED

//MOTORS
extern int portA;
extern int portB;
extern int portC;
extern int portD;

extern int intakeLeftPort;
extern int intakeRight;
extern int beltPort;
extern int fwPort;

extern pros::Motor driveMotorA;
extern pros::Motor driveMotorB;
extern pros::Motor driveMotorC;
extern pros::Motor driveMotorD;

extern pros::Motor leftIntakeMotor;
extern pros::Motor rightIntakeMotor;
extern pros::Motor beltMotor;
extern pros::Motor fwMotor;

//CONTROLLER
extern okapi::Controller controller;
