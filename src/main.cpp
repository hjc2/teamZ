#include "main.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/functions.h"
using namespace okapi; //DONT TOUCH THIS

void on_center_button() { }

void initialize() {}

void disabled() {} //LEAVE THIS EMPTY

void competition_initialize() {}

//xArcade(myStrafe, myForward, mySpin)

void autonomous() {
	//pass x,y,t, xn, yn, tn to robot
	//need to make the robot have the ability to move at an angle while progress to the goal

	//rotate the controller by the extent of the theta
	//find angle by side side, back back //contAngle = tan(contY / contX);
	//add theta to angle //movementAngle = contAngle + robotTheta;
	//convert composite angle back to x y input for xArcade.  //xArcadeX = 1 * cos(movementAngle)

	//DO NOT TOUCH THIS CODE
    auto chassis = ChassisControllerBuilder()
	.withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
	.withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
	.build();
    auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());

	pros::delay(20);
	for(float i  = 0; i < 1; i+=0.01){
		int y = 1 - i;
        xModel->xArcade(i/2,y/2,0);
		pros::delay(20);
	}
	xModel->xArcade(0,0,0);

	//take the input and strafe to it

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

  double analogLeftStick = controller.getAnalog(ControllerAnalog::rightX);
	//WHILE LOOP FOR OPCONTROL
    while (true) {
		//DO NOT TOUCH THIS CODE
        xModel->xArcade(
			controller.getAnalog(ControllerAnalog::rightX), //side to side
        	controller.getAnalog(ControllerAnalog::rightY), //front back
        	controller.getAnalog(ControllerAnalog::leftX) //spin
		);
		//DO NOT TOUCH THIS CODE
		pushIntake(controller.getDigital(ControllerDigital::R2));
		pros::delay(20);
	}
}
