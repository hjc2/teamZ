#include "main.h"
#include "../include/285Z/initRobot.h"
#pragma once
int frontLeftMotorPort = 2;
int frontRightMotorPort = -3;
int backLeftMotorPort = 4;
int backRightMotorPort = -5;
int leftIntakePort = 8;
int rightIntakePort = 9;
int ejectorPort = 11;
int cyclerPort = 1;
//  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)   .withMotors(2, -3, -5, 4)

//pros::Motor driveMotorA(portA);
//pros::Motor driveMotorB(portB);
//pros::Motor driveMotorC(portC);
//pros::Motor driveMotorD(portD);
pros::Motor intakeLeft(leftIntakePort);
pros::Motor intakeRight(rightIntakePort);

pros::Motor ejectorMotorMotor(ejectorPort);
pros::Motor cyclerMotorMotor(cyclerPort);

pros::Motor *rightIntake = &intakeRight;
pros::Motor *leftIntake = &intakeLeft;

pros::Motor *ejectorMotor = &ejectorMotorMotor;
pros::Motor *cyclerMotor = &cyclerMotorMotor;

okapi::ControllerButton intakeButton = okapi::ControllerDigital::R2;  //INTAKE BUTTON
okapi::ControllerButton outtakeButton = okapi::ControllerDigital::R1;  //OUTTAKE BUTTON
okapi::ControllerButton incycleButton = okapi::ControllerDigital::L2;
okapi::ControllerButton outcycleButton = okapi::ControllerDigital::L1;

//THE ACTUALLY USED BUTTONS
okapi::ControllerButton cycleButton = okapi::ControllerDigital::R2;
okapi::ControllerButton ejectButton = okapi::ControllerDigital::R1;
okapi::ControllerButton reverseButton = okapi::ControllerDigital::L1;
okapi::ControllerButton pushButton = okapi::ControllerDigital::L2;

pros::ADIAnalogIn lineSensorOne ('A');
