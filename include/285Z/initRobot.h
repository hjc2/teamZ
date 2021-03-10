#pragma once
#include "main.h"

extern int frontLeftMotorPort;
extern int frontRightMotorPort;
extern int backLeftMotorPort;
extern int backRightMotorPort;
extern int leftIntakePort;
extern int rightIntakePort;
extern int ejectorPort;
extern int cyclerPort;

extern pros::Motor intakeLeft;
extern pros::Motor intakeRight;

extern pros::Motor *rightIntake;
extern pros::Motor *leftIntake;
extern pros::Motor *ejectorMotor;
extern pros::Motor *cyclerMotor;

extern okapi::MotorGroup driveL;
extern okapi::MotorGroup driveR;

extern okapi::ControllerButton cycleButton;
extern okapi::ControllerButton ejectButton;
extern okapi::ControllerButton reverseButton;
extern okapi::ControllerButton lineButton;
extern okapi::ControllerButton noIntakeButton;

extern pros::ADIAnalogIn lineSensorOne; //TOP LINE SENSOR ('A')
extern pros::ADIAnalogIn lineSensorTwo; //MIDDLE LINE SENSOR ('C')
extern pros::ADIAnalogIn lineSensorThree; //BOTTOM LINE SENSOR ('D')


//auto chassis intialization
extern std::shared_ptr<okapi::ChassisController> chassis;
extern std::shared_ptr<okapi::ChassisController> chassisStrafe;

extern std::shared_ptr<okapi::AsyncMotionProfileController> tankProfile;
extern std::shared_ptr<okapi::AsyncMotionProfileController> xDriveProfile;


extern pros::ADIAnalogIn autoSelector;

extern pros::ADIDigitalIn colorSelector;

extern pros::Imu imuSensor;
