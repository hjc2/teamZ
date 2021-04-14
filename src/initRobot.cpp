#include "main.h"
#include "../include/285Z/initRobot.h"

int frontLeftMotorPort = 2;
int frontRightMotorPort = -3;
int backLeftMotorPort = 4;
int backRightMotorPort = -5;

int leftIntakePort = 9;
int rightIntakePort = 8; //6
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

okapi::MotorGroup driveL({frontLeftMotorPort, backLeftMotorPort,});
okapi::MotorGroup driveR({frontRightMotorPort, backRightMotorPort});

okapi::ControllerButton cycleButton = okapi::ControllerDigital::L1;
okapi::ControllerButton ejectButton = okapi::ControllerDigital::R1;
okapi::ControllerButton reverseButton = okapi::ControllerDigital::Y;
okapi::ControllerButton lineButton = okapi::ControllerDigital::R2;
okapi::ControllerButton noIntakeButton = okapi::ControllerDigital::L2;

pros::ADIAnalogIn lineSensorOne ('A');
pros::ADIAnalogIn lineSensorTwo ('C');

pros::ADIDigitalIn autoSelectorLeft ('E');
pros::ADIDigitalIn autoSelectorRight ('D');

//IMU CODE
const std::uint8_t imuPort = 20;
pros::Imu imuSensor(imuPort);
