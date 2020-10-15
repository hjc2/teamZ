#include "main.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/robot/autFunctions.h"

using namespace okapi; //DONT TOUCH THIS

const int BRAKE = 0;
const int FORWARD = 1;
const int REVERSE = 2;
const double Deadzone = 0.1;
int toggleIntake = 0;
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
  //https://okapilib.github.io/OkapiLib/md_docs_tutorials_walkthrough_odometry.html
  //https://okapilib.github.io/OkapiLib/md_docs_tutorials_walkthrough_odometry.html
    auto chassis = ChassisControllerBuilder()
	   .withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
     .withSensors(
        ADIEncoder{leftEncoderPortOne, leftEncoderPortTwo}, //left encoder
        ADIEncoder{rightEncoderPortOne, rightEncoderPortTwo}, //right encoder
        ADIEncoder{middleEncoderPortOne, middleEncoderPortTwo} //middle encoder
     )
     .withOdometry({{2.75_in, 7_in, 1_in, 2.75_in}, quadEncoderTPR})
	   .withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
	   .buildOdometry();
  auto xOdom = std::dynamic_pointer_cast<ThreeEncoderXDriveModel>(chassis -> getModel());

    currentPosition = chassis -> getState();
    /*
    chassis -> setState({0_in, 0_in, 0_deg});
    pros::delay(1000);
    chassis -> moveDistance(2_ft);
    chassis -> waitUntilSettled();
    chassis -> moveDistance(10_ft);

    /*
    auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());

	pros::delay(20);
	for(float i  = 0; i < 1; i+=0.01){
		int y = 1 - i;
        xModel->xArcade(i/2,y/2,0);
		pros::delay(20);
	}
	xModel->xArcade(0,0,0);
  */
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

    while (true) {
      xModel->xArcade(
  			controller.getAnalog(ControllerAnalog::rightX), //side to side
      	controller.getAnalog(ControllerAnalog::rightY), //front back
      	controller.getAnalog(ControllerAnalog::leftX), //spin
        Deadzone
		  );
    evaluateIntakeMode();
    //rightIntake -> move_voltage(12000);
    pros::delay(20);
	}
}
