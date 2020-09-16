#include "main.h"
#include "../include/285Z/initRobot.h"
using namespace okapi;

void on_center_button() { }

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
    auto chassis = ChassisControllerBuilder()
	.withMotors(2, -3, -5, 4) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
	.withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
	.build();
    auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());
    Controller controller(ControllerId::master);
    while (true) {
        xModel->xArcade(
			controller.getAnalog(ControllerAnalog::rightX), //side to side
        	controller.getAnalog(ControllerAnalog::rightY), //front back
        	controller.getAnalog(ControllerAnalog::leftX) //spin
			);
	}
}
