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

extern pros::ADIAnalogIn lineSensorOne;
extern pros::ADIAnalogIn lineSensorTwo;
extern pros::ADIAnalogIn lineSensorThree;


//auto chassis intialization
extern std::shared_ptr<okapi::ChassisController> chassis;
extern std::shared_ptr<okapi::ChassisController> chassisStrafe;

extern std::shared_ptr<okapi::AsyncMotionProfileController> tankProfile;
extern std::shared_ptr<okapi::AsyncMotionProfileController> xDriveProfile;



extern pros::ADIDigitalIn colorSelector;

extern pros::Imu imuSensor;
