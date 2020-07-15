#pragma once
#include "main.h"

//ALL NAMES ARE PLACEHOLDERS TIL BOT DESIGN IS DECIDED

//MOTOR DECLARATIONS
//drive
extern int portA;
extern int portB;
extern int portC;
extern int portD;
//functional
extern int portE;
extern int portF;
extern int portG;
extern int portH;

extern pros::Motor driveMotorA;
extern pros::Motor driveMotorB;
extern pros::Motor driveMotorC;
extern pros::Motor driveMotorD;
extern pros::Motor driveMotorE;
extern pros::Motor driveMotorF;
extern pros::Motor driveMotorG;
extern pros::Motor driveMotorH;

//CONTROLLER DECLARATIONS
extern okapi::ControllerButton aButton;
extern okapi::ControllerButton bButton;
extern okapi::ControllerButton xButton;
extern okapi::ControllerButton yButton;
extern okapi::ControllerButton upButton;
extern okapi::ControllerButton downButton;
extern okapi::ControllerButton rightButton;
extern okapi::ControllerButton leftButton;
extern okapi::ControllerButton rightTrigger;
extern okapi::ControllerButton leftTrigger;
extern okapi::ControllerButton rightBumper;
extern okapi::ControllerButton leftBumper;
