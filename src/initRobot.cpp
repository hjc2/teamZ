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

pros::Motor intakeLeft(leftIntakePort, pros::E_MOTOR_GEARSET_06 );
pros::Motor intakeRight(rightIntakePort, pros::E_MOTOR_GEARSET_06 );

pros::Motor ejectorMotorMotor(ejectorPort, pros::E_MOTOR_GEARSET_06 );
pros::Motor cyclerMotorMotor(cyclerPort, pros::E_MOTOR_GEARSET_06 );

pros::Motor *rightIntake = &intakeRight;
pros::Motor *leftIntake = &intakeLeft;
pros::Motor *ejectorMotor = &ejectorMotorMotor;
pros::Motor *cyclerMotor = &cyclerMotorMotor;

okapi::ControllerButton cycleButton = okapi::ControllerDigital::L2;
okapi::ControllerButton ejectButton = okapi::ControllerDigital::R1;
okapi::ControllerButton reverseButton = okapi::ControllerDigital::L1;
okapi::ControllerButton lineButton = okapi::ControllerDigital::R2;
pros::ADIAnalogIn lineSensorOne ('A');
