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

void autonomous() {
    auto chassis = ChassisControllerBuilder()
    .withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
    .withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
    .build();

  auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());
  //RED AUTO
  //rightwards, forwards, cw?
  //getting off the wall
  xModel->xArcade(0.25, 0, 0);
  pros::delay(250); //moves right ~1 tile

  //turning towards topleft goal
  xModel->xArcade(0,0,0.24); //ccw turn 45 deg
  pros::delay(250);

  //driving into the top red goal
  xModel->xArcade(0,0.25,0); //moves forward til into goal
  setIntake(); //turns on intake to grab tl red ball
  setCyBrake(); //brakes cycler to keep ball from going up
  pros::delay(250); //waits
  setInBrake(); //turns off intake to stop the blue balls from coming into it
  pros::delay(120);

  //scoring in topleft goal
  xModel->xArcade(0,0,0); //stops at the goal
  setCycle(); //turns on cycler to score in tl goal
  pros::delay(200); //time the cycler will run for
  setCyBrake();
  pros::delay(200); //making sure we dont have a trailing shot

  //backing out of the goal
  xModel -> xArcade(0, -0.2, 0); //backing up from the goal
  pros::delay(250); //time for the bot to back up

  //turning towards red driver station
  xModel->xArcade(0,0,0.24); //ccw turn 45 deg
  pros::delay(250);

  //strafing to middle goal
  xModel->xArcade(-0.2,0,0); //strafing left to the middle goal
  pros::delay(250); //time to get to the middle goal

  //driving into the middle red goal
  xModel->xArcade(0,0.25,0); //moves forward til into goal
  setInBrake(); //making sure intake is off
  setCyBrake(); //brakes cycler to keep ball from going up
  pros::delay(250); //waits

  //scoring in middle red goal
  xModel->xArcade(0,0,0); //stops at the goal
  setCycle(); //turns on cycler to score in tl goal
  pros::delay(200); //time the cycler will run for
  setCyBrake(); //turns off the cycler
  pros::delay(200); //making sure we dont have a trailing shot
  setReverse(); //making sure there were no blue balls that got into our robot
  setOuttake(); //making sure there were no blue balls that got into our robot
  pros::delay(100); //feel like there should be a delay between this movement

  //backing up to the white line
  xModel->xArcade(0, -0.2, 0); //speed it backsup at
  pros::delay(250); //time to backup for

  //strafing left to the bottom red goal
  xModel->xArcade(-0.2, 0, 0); //speed it strafes left at
  pros::delay(250); //time to strafe left for

  //turning to face the bottom red goal
  xModel->xArcade(0, 0, -0.1);
  pros::delay(250); //time to turn to the left

  //driving forward to the bottom red goal
  xModel->xArcade(0, 0.5, 0);
  pros::delay(250); //time to drive to the goal

  //scoring into the bottom red goal
  setCycle(); //turning on the intake
  pros::delay(2000); //runs til the end of the auton
  setCyBrake();
}

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
