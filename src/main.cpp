#include "main.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/functions.h"
using namespace okapi; //DONT TOUCH THIS

const int BRAKE = 0;
const int FORWARD = 1;
const int REVERSE = 2;
const int EJECT = 3;
const int LINE = 4;

const double Deadzone = 0.1;

int toggleCycle = 0;
int toggleLine = 0;

void on_center_button() { }

void initialize() {
}

void disabled() {} //LEAVE THIS EMPTY

void competition_initialize() {}

//xArcade(myStrafe, myForward, mySpin)

void autonomous() {}

void opcontrol() {
  lineSensorOne.calibrate();
  //pros::delay(1000);
	//DO NOT TOUCH THIS CODE
    auto chassis = ChassisControllerBuilder()
	.withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
	.withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
	.build();

    auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());
    Controller controller(ControllerId::master);

    while (true) {
      xModel->xArcade(
  			controller.getAnalog(ControllerAnalog::rightX), //side to side
      	controller.getAnalog(ControllerAnalog::rightY), //front back
      	controller.getAnalog(ControllerAnalog::leftX), //spin
        Deadzone
		  );
      evaluateDriver();
      std::cout << "raw value: " << lineSensorOne.get_value() << "\n";
      std::cout << "calibrated: " << lineSensorOne.get_value_calibrated() << "\n";
      std::cout << "actual cycler velocity: " << cyclerMotor -> get_actual_velocity() << "\n";
      std::cout << "actual ejector velocity: " << ejectorMotor -> get_actual_velocity() << "\n";
      std::cout << "actual left intake velocity: " << leftIntake -> get_actual_velocity() << "\n";
      std::cout << "actual right intake velocity: " << rightIntake -> get_actual_velocity() << "\n";
      std::cout << "actual cycler voltage: " << cyclerMotor -> get_voltage() << "\n";
      std::cout << "actual ejector voltage: " << ejectorMotor -> get_voltage() << "\n";
      std::cout << "actual left intake voltage: " << leftIntake -> get_voltage() << "\n";
      std::cout << "actual right intake voltage: " << rightIntake -> get_voltage() << "\n";
    pros::delay(20);
	}
}
