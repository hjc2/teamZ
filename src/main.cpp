#include "main.h"
#include "../include/285Z/initRobot.h"
using namespace okapi;

void on_center_button() { }

void initialize() {}

void disabled() {}

void competition_initialize() {}

//xArcade(myStrafe, myForward, mySpin)
void autonomous() {
	auto autoChassis = ChassisControllerBuilder()
	.withMotors(2, -3, -5, 4) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
	.withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
	.build();
    auto xModel = std::dynamic_pointer_cast<XDriveModel>(autoChassis->getModel());
	xModel->xArcade(1,0,0);
}

void opcontrol() {
	//XDRIVE CHASSIS GENERATION
    auto chassis = ChassisControllerBuilder()
	.withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
	.withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
	.build();
    auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());
    Controller controller(ControllerId::master);
	//WHILE LOOP FOR OP
    while (true) {
        xModel->xArcade(
			controller.getAnalog(ControllerAnalog::rightX), //side to side
        	controller.getAnalog(ControllerAnalog::rightY), //front back
        	controller.getAnalog(ControllerAnalog::leftX) //spin
		);
	}
}
