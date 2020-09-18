#include "main.h"
#include "../include/285Z/initRobot.h"
using namespace okapi;

void on_center_button() { }

void initialize() {}

void disabled() {}

void competition_initialize() {}

//xArcade(myStrafe, myForward, mySpin)
void autonomous() {
	/*
	auto autoChassis = ChassisControllerBuilder()
	.withMotors(2, -3, -5, 4) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
	.withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
	.withOdometry()
	.buildOdometry();
    auto xModel = std::dynamic_pointer_cast<XDriveModel>(autoChassis->getModel());
	autoChassis->setState({0_in, 0_in, 0_deg});
	pros::delay(20);
	autoChassis->driveToPoint({1_ft, 1_ft});
	*/
	//autoChassis->turnToAngle(90_deg);
	//autoChassis.waitUntilSettled();

	/*
	while(1){
		xModel->xArcade(0.1,0,0);
		pros::delay(1000);
		xModel->xArcade(0,0.1,0);
		pros::delay(1000);
		//xModel->xArcade(0,0.1,0);
		//pros::delay(1000);
	}*/
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
