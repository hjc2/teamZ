#include "main.h"
#include "../include/285Z/initRobot.h"
#pragma  once
int frontLeftMotorPort = 2;
int frontRightMotorPort = -3;
int backLeftMotorPort = 4;
int backRightMotorPort = -5;
int leftIntakePort = 8;
int rightIntakePort = -9;
int portG = 6;
int portH = 7;
//  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)   .withMotors(2, -3, -5, 4)

//pros::Motor driveMotorA(portA);
//pros::Motor driveMotorB(portB);
//pros::Motor driveMotorC(portC);
//pros::Motor driveMotorD(portD);
pros::Motor intakeLeft(leftIntakePort);
pros::Motor intakeRight(rightIntakePort);
pros::Motor driveMotorG(portG);
pros::Motor driveMotorH(portH);

pros::Motor *rightIntake = &intakeLeft;
pros::Motor *leftIntake = &intakeRight;

okapi::ControllerButton intakeButton = okapi::ControllerDigital::R2;  //INTAKE BUTTON
okapi::ControllerButton outtakeButton = okapi::ControllerDigital::R1;  //OUTTAKE BUTTON
