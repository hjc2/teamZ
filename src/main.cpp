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
int toggleIntake = 0;
int toggleIncycle = 0;
int toggleCycle = 0;

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

    //MOVES FORWARD TO TOUCH GOAL
    xModel ->xArcade(0, 0.5, 0);
    controlIntake(FORWARD);
    controlIncycle(BRAKE);
    pros::delay(500);
    for(double i = 0.5; i < 1; i+=0.01){ //SLOWING DOWN AND ENTERING THE GOAL
      xModel ->xArcade(0, i, 0);
      pros::delay(10);
    }
    //TURNS OFF THE INTAKE AND SHOOTS IT INTO THE GOAL
    controlIntake(BRAKE);
    pros::delay(50);
    controlIncycle(FORWARD);
    for(double i = 0; i < 1; i+=0.01){ //BACKING UP SPEEDING UP
      xModel ->xArcade(0, -i, 0);
      pros::delay(10);
    }
    for(double i = 0; i > 0; i-=0.01){ //BACKING UP SLOWING DOWN
      xModel ->xArcade(0, -i, 0);
      pros::delay(10);
    }

    pros::delay(100);
    //STRAFING TO THE MIDDLE GOAL
    for(double i = 0; i < 1; i+=0.01){ //BACKING UP SPEEDING UP
      xModel ->xArcade(i, 0, 0);
      pros::delay(10);
    }
    for(double i = 0; i > 0; i-=0.01){ //BACKING UP SLOWING DOWN
      xModel ->xArcade(0, -i, 0);
      pros::delay(10);
    }



    //FIRST AUTON/*
    /*
    int xVelocity = 0;
    int yVelocity = 0;

    yVelocity = -0.1
    while(yVelocity < 1){
      xModel ->xArcade(xVelocity, yVelocity, 0);
      xVelocity += 0.01;
      yVelocity += 0.01;
    }

/*

	pros::delay(20);
	for(float i  = 0; i < 1; i+=0.01){
		int y = 1 - i;
        xModel->xArcade(i/2,y/2,0);
		pros::delay(20);
	}
  */
	xModel->xArcade(0,0.25,0);
  pros::delay(6000);
  for(float i = 0; i += 0.01; i < 1){
    xModel->xArcade(0, i, 0);
    pros::delay(10);
  }
  for(float i = 1; i -= 0.01; i > 0){
    xModel->xArcade(0, i, 0);
  }
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
      
    evaluateDriver();
    //controlIntake(BRAKE);
    //controlIncycle(BRAKE);
    //evaluateIntakeMode();
    //evaluateIncycleMode();
    //rightIntake -> move_voltage(12000);
    pros::delay(20);
    std::cout << lineSensorOne.get_value() << "\n";
	}
}
