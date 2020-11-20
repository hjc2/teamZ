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
int toggleNoIntake = 0;
const int tuneOne = 2720;
const int tuneTwo = 2720;
const int tuneThree = 2720;
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
    std::cout << "Red 3 Goal Auto" << "\n";
    //rightwards, forwards, cw?
    //getting off the wall
    xModel->xArcade(0.6, 0, 0);
    pros::delay(1200); //moves right ~1 tile

    //turning towards topleft goal
    xModel->xArcade(0,0,-0.4); //ccw turn 45 deg
    pros::delay(500);

    //deploy
    xModel->xArcade(0,0,0); //sit still
    setOuttake();
    ejectorMotor -> move_velocity(600);
    pros::delay(400);
    setInBrake();
    ejectorMotor -> move_velocity(0);

    //driving into the top red goal
    xModel->xArcade(0,0.6,0); //moves forward til into goal
    pros::delay(400);
    setOuttake();
    ejectorMotor -> move_velocity(600);
    setIntake(); //turns on intake to grab tl red ball
    setCyBrake(); //brakes cycler to keep ball from going up
    pros::delay(600); //waits
    setInBrake(); //turns off intake to stop the blue balls from coming into it
    pros::delay(120);

    //scoring in topleft goal
    xModel->xArcade(0,0,0); //stops at the goal
    setInBrake();
    setCycle(); //turns on cycler to score in tl goal
    pros::delay(400); //time the cycler will run for
    setCyBrake();
    pros::delay(200); //making sure we dont have a trailing shot

    //backing out of the goal
    xModel -> xArcade(0, -0.6, 0); //backing up from the goal
    setReverse();
    setIntake();
    pros::delay(80);
    setCyBrake();
    setOuttake();
    pros::delay(500);
    setInBrake();
    pros::delay(1120); //time for the bot to back up

    //turning towards red driver station
    xModel->xArcade(0,0,-0.4); //ccw turn 45 deg
    pros::delay(450);

    //strafing to middle goal
    xModel->xArcade(-0.6,0,0); //strafing left to the middle goal
    pros::delay(1250); //time to get to the middle goal

    //driving into the middle red goal
    xModel->xArcade(0,0.7,0); //moves forward til into goal
    setIntake(); //making sure intake is off
    setCycle(); //brakes cycler to keep ball from going up
    pros::delay(100);
    setInBrake();
    setCyBrake();
    pros::delay(1000); //waits for this time

    //scoring in middle red goal
    setInBrake();
    xModel->xArcade(0,0,0); //stops at the goal
    setCycle(); //turns on cycler to score in tl goal
    pros::delay(600); //time the cycler will run for
    setCyBrake(); //turns off the cycler
    pros::delay(600); //making sure we dont have a trailing shot
    setReverse(); //making sure there were no blue balls that got into our robot
    setOuttake(); //making sure there were no blue balls that got into our robot
    pros::delay(600); //feel like there should be a delay between this movement

    //backing up to the white line
    xModel->xArcade(0, -1, 0); //speed it backsup at
    pros::delay(600); //time to backup for

    //strafing left to the bottom red goal
    xModel->xArcade(-1, 0, 0); //speed it strafes left at
    pros::delay(700); //time to strafe left for

    //turning to face the bottom red goal
    xModel->xArcade(0, 0, -0.6);
    pros::delay(350); //time to turn to the left;ix

    //driving forward to the bottom red goal
    xModel->xArcade(0, 0.5, 0);
    setIntake();
    pros::delay(800); //time to drive to the goal

    //scoring into the bottom red goal
    setCycle(); //turning on the intake
    setIntake();
    pros::delay(1500);
    setInBrake();
    pros::delay(500); //runs til the end of the auton
    setIntake();
    setEject();
    pros::delay(300);
    //backing out of the goal
    xModel->xArcade(0, -1, 0);
    pros::delay(400);
    xModel->xArcade(0, 0, 0);
    setOuttake();
  }  //RED THREE GOAL

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
      /*
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
      if(autoSelector.get_value() > 3296 && autoSelector.get_value() < 4097){ std::cout << "Red 3 Goal Auto" << "\n";}
      else if(autoSelector.get_value() > 2496 && autoSelector.get_value() < 3295){ std::cout << "Red 2 Goal Auto" << "\n";}
      else if(autoSelector.get_value() > 1696 && autoSelector.get_value() < 2495){ std::cout << "No Auto" << "\n";}
      else if(autoSelector.get_value() > 896 && autoSelector.get_value() < 1695){ std::cout << "Blue 2 Goal Auto" << "\n";}
      else if(autoSelector.get_value() > 0 && autoSelector.get_value() < 895){ std::cout << "Blue 3 Goal Auto" << "\n";}
    pros::delay(20);
	}
}
