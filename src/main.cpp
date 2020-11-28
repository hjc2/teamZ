#include "main.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/functions.h"
using namespace okapi; //DONT TOUCH THIS

const int BRAKE = 0;
const int FORWARD = 1;
const int REVERSE = 2;
const int EJECT = 3;
const int LINE = 4;

const int NO_AUTO = 0;
const int RED_HOMEROW = 1;
const int RED_TWOGOAL = 2;
const int SKILLS_AUTO = 3;
const int BLUE_HOMEROW = 4;
const int BLUE_TWOGOAL = 5;

const double Deadzone = 0.1;

int toggleCycle = 0;
int toggleLine = 0;
int toggleNoIntake = 0;
const int tuneOne = 2720;
const int tuneTwo = 2720;
const int tuneThree = 2720;
Controller controller(ControllerId::master);
pros::Controller master(CONTROLLER_MASTER);

void initialize() {
  pros::lcd::initialize();
  pros::delay(20);
  while(true){
    if(autoValue == NO_AUTO){pros::lcd::set_text(1, "NO AUTO");} else
    if(autoValue == RED_HOMEROW){pros::lcd::set_text(1, "RED HOMEROW");} else
    if(autoValue == RED_TWOGOAL){pros::lcd::set_text(1, "RED TWO GOAL");} else
    if(autoValue == SKILLS_AUTO){pros::lcd::set_text(1, "SKILLS AUTO");} else
    if(autoValue == BLUE_HOMEROW){pros::lcd::set_text(1, "BLUE HOMEROW");} else
    if(autoValue == BLUE_TWOGOAL){pros::lcd::set_text(1, "BLUE TWO GOAL");}
    pros::delay(20);
  }
}

void disabled() {} //LEAVE THIS EMPTY

void competition_initialize() {
}

void autonomous() {
    auto chassis = ChassisControllerBuilder()
    .withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
    .withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
    .build();

    auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());

}
void opcontrol() {
  //pros::delay(1000);
	//DO NOT TOUCH THIS CODE
    auto chassis = ChassisControllerBuilder()
	   .withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
	   .withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
  	 .build();

    auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());

    while (true) {
      xModel->xArcade(
  			controller.getAnalog(ControllerAnalog::rightX), //side to side
      	controller.getAnalog(ControllerAnalog::rightY), //front back
      	controller.getAnalog(ControllerAnalog::leftX), //spin
        Deadzone
		  );
      evaluateDriver();
      /* //debugging code, dont uncomment unless you know what you're doing
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
      std::cout << "raw value: " << autoSelector.get_value() << "\n";
      */
    pros::delay(20); //NEVER DELETE THIS
	}
}
