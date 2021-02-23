#include "main.h"

extern int frontLeftMotorPort;
extern int frontRightMotorPort;
extern int backLeftMotorPort;
extern int backRightMotorPort;
extern int leftIntakePort;
extern int rightIntakePort;
extern int portG;
extern int portH;

extern pros::Motor intakeLeft;
extern pros::Motor intakeRight;
extern pros::Motor driveMotorG;
extern pros::Motor driveMotorH;

extern pros::Motor *rightIntake;
extern pros::Motor *leftIntake;
extern pros::Motor *ejectorMotor;
extern pros::Motor *cyclerMotor;

extern okapi::ControllerButton cycleButton;
extern okapi::ControllerButton ejectButton;
extern okapi::ControllerButton reverseButton;
extern okapi::ControllerButton lineButton;
extern okapi::ControllerButton noIntakeButton;


extern pros::ADIAnalogIn lineSensorOne; //TOP LINE SENSOR ('A')
extern pros::ADIAnalogIn lineSensorTwo; //MIDDLE LINE SENSOR ('C')
extern pros::ADIAnalogIn lineSensorThree; //BOTTOM LINE SENSOR ('D')

extern pros::ADIAnalogIn autoSelector;

extern pros::ADIDigitalIn colorSelector;
//extern pros::Imu imuSensor;
//
//
