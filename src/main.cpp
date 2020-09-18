#include "main.h"
#include "../include/285Z/initRobot.h"
using namespace okapi; //DONT TOUCH THIS

void on_center_button() { }

void initialize() {}

void disabled() {} //LEAVE THIS EMPTY

void competition_initialize() {}

//xArcade(myStrafe, myForward, mySpin)
void autonomous() {
}

void opcontrol() {

	//DO NOT TOUCH THIS CODE
    auto chassis = ChassisControllerBuilder()
	.withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
	.withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
	.build();
    auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());
    Controller controller(ControllerId::master);
	//DO NOT TOUCH THIS CODE

	//WHILE LOOP FOR OPCONTROL
    while (true) {
		//DO NOT TOUCH THIS CODE
        xModel->xArcade(
			controller.getAnalog(ControllerAnalog::rightX), //side to side
        	controller.getAnalog(ControllerAnalog::rightY), //front back
        	controller.getAnalog(ControllerAnalog::leftX) //spin
		);
		//DO NOT TOUCH THIS CODE
		pros::delay(20);
	}
}
