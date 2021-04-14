#include "main.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/autonomous/blueAuton.h"
#include "../include/285Z/autonomous/redAuton.h"
#include "../include/285Z/autonomous/miscAuton.h"
#include "../include/285Z/robot/pid.h"

using namespace okapi; //DONT TOUCH THIS

const int BRAKE = 0;
const int FORWARD = 1;
const int REVERSE = 2;
const int EJECT = 3;
const int LINE = 4;
const int SLOWED = 5;

const double Deadzone = 0.1;

int toggleCycle = 0;
int toggleLine = 0;
int toggleNoIntake = 0;

const int tuneOne = 2400; //both top sensor threshold
const int tuneTwo = 2900; //mid sensor threshold

int i = 0;
bool isPressed = 0;

Controller controller(ControllerId::master);
pros::Controller master(CONTROLLER_MASTER);

typedef void (*AutonFunctions) ();
AutonFunctions autList [] = {
  redHomeRow,
  redCenter,
  redCorner,
  blueHomeRow,
  blueCenter,
  blueCorner
};

std::string autStringList [] =
{
  "Red Home Row",
  "Red 3 Goal Center",
  "Red 3 Goal Corner",
  "Blue Home Row",
  "Blue 3 Goal Center",
  "Blue 3 Goal Corner"
};


//initializing profileControllers
std::shared_ptr<ChassisController>chassis = ChassisControllerBuilder()
.withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
.withDimensions(AbstractMotor::gearset::green, {{3.25_in, 14_in}, imev5GreenTPR})
.build();

std::shared_ptr<okapi::ChassisController> chassisStrafe = ChassisControllerBuilder()
.withMotors(-frontLeftMotorPort, frontRightMotorPort, -backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
.withDimensions(AbstractMotor::gearset::green, {{3.25_in, 14_in}, imev5GreenTPR})
.build();

std::shared_ptr<AsyncMotionProfileController> tankProfile =
AsyncMotionProfileControllerBuilder()
  .withLimits({
    2.4, // Maximum linear velocity of the Chassis in m/s
    4, // Maximum linear acceleration of the Chassis in m/s/s
    6 // Maximum linear jerk of the Chassis in m/s/s/s
  })
  .withOutput(chassis)
  .buildMotionProfileController();

std::shared_ptr<AsyncMotionProfileController> xDriveProfile =
AsyncMotionProfileControllerBuilder()
  .withLimits({
    2.4, // Maximum linear velocity of the Chassis in m/s
    4, // Maximum linear acceleration of the Chassis in m/s/s
    6 // Maximum linear jerk of the Chassis in m/s/s/s
  })
  .withOutput(chassisStrafe)
  .buildMotionProfileController();

void initialize() {

  pros::lcd::initialize();

  imuSensor.reset();
  while(imuSensor.is_calibrating()){
    pros::delay(15);
  }

  pros::delay(20);

  while (true) {
    if (autoSelectorLeft.get_value() and !isPressed) {
      if (i > 0) {i -= 1; isPressed = true;}}
    else if (autoSelectorRight.get_value() and !isPressed) {
      if (i < 5) {i += 1; isPressed = true;}}
    else if(!autoSelectorLeft.get_value() && !autoSelectorRight.get_value()){isPressed = false;}

    pros::lcd::set_text(1, autStringList[i]);
    pros::delay(20);
  }

}

void disabled() {} //LEAVE THIS EMPTY

void competition_initialize() {

    pros::lcd::initialize();

    imuSensor.reset();
    while(imuSensor.is_calibrating()){
      pros::delay(15);
    }

    pros::delay(20);

    while (true) {
    if (autoSelectorLeft.get_value() and !isPressed) {
      if (i > 0) {i -= 1; isPressed = true;}}
    else if (autoSelectorRight.get_value() and !isPressed) {
      if (i < 5) {i += 1; isPressed = true;}}
    else if(!autoSelectorLeft.get_value() && !autoSelectorRight.get_value()){isPressed = false;}

      pros::lcd::set_text(1, autStringList[i]);
      pros::delay(20);
    }

}

void autonomous() {
  autList[i];
}

void opcontrol() {
  //pros::delay(1000);
	//DO NOT TOUCH THIS CODE

    auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());

    while (true) {
      xModel->xArcade(
  			controller.getAnalog(ControllerAnalog::rightX), //side to side
      	controller.getAnalog(ControllerAnalog::rightY), //front back
      	controller.getAnalog(ControllerAnalog::leftX), //spin
        Deadzone
		  );
      evaluateDriver();

    pros::delay(20); //NEVER DELETE THIS
	}
}



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
