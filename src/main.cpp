#include "main.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/autonomous/blueAuton.h"
#include "../include/285Z/autonomous/redAuton.h"
#include "../include/285Z/autonomous/miscAuton.h"

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

int autoValue = 0;
int twoThree = 0;
int redBlue = 0;
int skillsNone = 0;

int toggleCycle = 0;
int toggleLine = 0;
int toggleNoIntake = 0;
const int tuneOne = 2720; //top sensor
const int tuneTwo = 2720; //mid sensor
const int tuneThree = 2720; //bottom sensor
Controller controller(ControllerId::master);
pros::Controller master(CONTROLLER_MASTER);

void evaluate_auto(){
  if(skillsNone == 0){autoValue = NO_AUTO;} else //sets it to no auto
  if(skillsNone == 1){autoValue = SKILLS_AUTO;} else //sets it to skills auto
  if(skillsNone == 2){
    if(redBlue == 0){
      if(twoThree == 0){
        autoValue = RED_HOMEROW;
      } else {
        autoValue = RED_TWOGOAL;
      }
    } else {
      if(twoThree == 0){
        autoValue = BLUE_HOMEROW;
      } else {
        autoValue = BLUE_TWOGOAL;
      }
    }
  }
}
void on_center_button(){
  if(skillsNone >= 0 && skillsNone < 3){
    if(skillsNone == 2){
      skillsNone = 0;
    } else {
      skillsNone++;
    }
  } else {
    skillsNone = 0;
  }
}

void on_left_button(){ //two or three auto selection
  if(twoThree == 0){
    twoThree = 1;
  } else {
    twoThree = 0;
  }
}
void on_right_button(){ //red or blue selection
  if(redBlue == 0){
    redBlue = 1;
  } else {
    redBlue = 0;
  }
}

void initialize() {
}

void disabled() {} //LEAVE THIS EMPTY

void competition_initialize() {

    pros::lcd::initialize();
    pros::c::lcd_register_btn1_cb(on_center_button);
    pros::c::lcd_register_btn0_cb(on_left_button);
    pros::c::lcd_register_btn2_cb(on_right_button);

    pros::delay(20);
    while(true){
      evaluate_auto();
      pros::delay(5);
      if(autoValue == NO_AUTO){pros::lcd::set_text(1, "NO AUTO");} else
      if(autoValue == RED_HOMEROW){pros::lcd::set_text(1, "RED HOMEROW");} else
      if(autoValue == RED_TWOGOAL){pros::lcd::set_text(1, "RED TWO GOAL");} else
      if(autoValue == SKILLS_AUTO){pros::lcd::set_text(1, "SKILLS AUTO");} else
      if(autoValue == BLUE_HOMEROW){pros::lcd::set_text(1, "BLUE HOMEROW");} else
      if(autoValue == BLUE_TWOGOAL){pros::lcd::set_text(1, "BLUE TWO GOAL");}
      pros::delay(5);
      pros::lcd::set_text(2, "TOP SENSOR: " + std::to_string(lineSensorOne.get_value()));
      pros::lcd::set_text(3, "MID SENSOR: " + std::to_string(lineSensorTwo.get_value()));
      pros::lcd::set_text(4, "BOTTOM SENSOR: " + std::to_string(lineSensorThree.get_value()));
      pros::delay(20);

    }
}

void autonomous() {
  evaluate_auto();
  if(autoValue == NO_AUTO){noAuto();} else
  if(autoValue == RED_HOMEROW){redHomeRow();} else
  if(autoValue == RED_TWOGOAL){redTwoGoal();} else
  if(autoValue == SKILLS_AUTO){skillsAuto();} else
  if(autoValue == BLUE_HOMEROW){blueHomeRow();} else
  if(autoValue == BLUE_TWOGOAL){blueTwoGoal();}
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
