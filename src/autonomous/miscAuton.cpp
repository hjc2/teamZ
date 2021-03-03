#include "main.h"
#include "../include/285Z/autonomous/miscAuton.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/pid.h"

using namespace okapi; //DONT TOUCH THIS

//INITIALIZATION CHASSIS + MP
auto chassis = ChassisControllerBuilder()
.withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
.withDimensions(AbstractMotor::gearset::green, {{3.25_in, 14_in}, imev5GreenTPR})
.build();

auto chassisStrafe = ChassisControllerBuilder()
.withMotors(-frontLeftMotorPort, frontRightMotorPort, -backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
.withDimensions(AbstractMotor::gearset::green, {{3.25_in, 14_in}, imev5GreenTPR})
.build();

std::shared_ptr<AsyncMotionProfileController> tankProfile =
AsyncMotionProfileControllerBuilder()
  .withLimits({
    1.2, // Maximum linear velocity of the Chassis in m/s
    1.6, // Maximum linear acceleration of the Chassis in m/s/s
    4 // Maximum linear jerk of the Chassis in m/s/s/s
  })
  .withOutput(chassis)
  .buildMotionProfileController();

std::shared_ptr<AsyncMotionProfileController> xDriveProfile =
AsyncMotionProfileControllerBuilder()
  .withLimits({
    1.2, // Maximum linear velocity of the Chassis in m/s
    1.6, // Maximum linear acceleration of the Chassis in m/s/s
    4 // Maximum linear jerk of the Chassis in m/s/s/s
  })
  .withOutput(chassisStrafe)
  .buildMotionProfileController();


//AUTON FUNCTIONS
//for motion profile movement ***(include _ft after distance value)***
void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir){ //movement function

    profile->generatePath({
      {0_ft,0_ft,0_deg},
      {distance, 0_ft,0_deg}},
      "M"
    );

    profile->setTarget("M", dir);
    profile->waitUntilSettled();
    profile->removePath("M");
}

void moveIntake(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir, int time){

    profile->generatePath({
    {0_ft,0_ft,0_deg},
    {distance, 0_ft,0_deg}},
    "M"
    );

    profile->setTarget("M", dir);
    for(int i = 0; i < time; i +=5){
      setLine();
      pros::delay(5);
    }
    setBrakeAll();
    profile->waitUntilSettled();
    profile->removePath("M");
}

//individual motor controller ***(negative speed for reverse)***
void start (pros::Motor *motor, uint32_t delay, std::uint32_t speed) {
  motor -> move_velocity(speed);
  pros::delay(delay);
  motor -> move_velocity(0);
}

void cycle (uint32_t time) {
  setCycle();
  pros::delay(time);
  setCyBrake();
}

void deployMotion() {

  start(ejectorMotor, 700, 600);
  move(xDriveProfile, 0.9_ft, fwd);
  setOuttake();
  pros::delay(600);
  setInBrake();

}

void noAuto(){

  pros::delay(15000);

}

void skillsAuto(){

  deployMotion();


  //first goal scoring

  turn(0);
  moveIntake(tankProfile, 2.4_ft, fwd, 2000);
  turn(45);
  move(tankProfile, 1.2_ft, fwd);
  cycle(600);


  //right wall goal

  move(tankProfile, 1.2_ft, bwd);
  turn(0);
  move(xDriveProfile, 0.45_ft, fwd);
  moveIntake(tankProfile, 0.5_ft, fwd, 1300);
  move(tankProfile, 0.35_ft, bwd);
  turn(270);
  moveIntake(tankProfile, 2.35_ft, fwd, 2200);
  turn(0);
  move(tankProfile, 0.7_ft, fwd);
  cycle(400);


  //getting red tile ball and back right corner goal

  move(tankProfile, 1.05_ft, bwd);
  turn(270);
  setReverse();
  pros::delay(300);
  setBrakeAll();
  moveIntake(tankProfile, 2.45_ft, fwd, 2200);
  turn(315);
  move(tankProfile, 2_ft, fwd);
  cycle(400);


  //scoring back wall goal

  move(tankProfile, 1.3_ft, bwd);
  turn(270);
  setReverse();
  pros::delay(200);
  setBrakeAll();
  move(xDriveProfile, 3.1_ft, fwd);
  move(tankProfile, 1.1_ft, fwd);
  cycle(600);


  //getting back left corner goal

  move(tankProfile, 0.5_ft, bwd);
  turn(185);
  moveIntake(tankProfile, 3.2_ft, fwd, 2000);
  turn(220);
  move(tankProfile, 1.9_ft, fwd);
  cycle(500);


  //right wall goal

  move(tankProfile, 2.9_ft, bwd);
  turn(90);
  moveIntake(tankProfile, 2_ft, fwd, 800);
  turn(180);
  moveIntake(tankProfile, 2.8_ft, fwd, 800);
  cycle(800);


  //final goal (front left corner goal)

  move(tankProfile, 1.05_ft, bwd);
  turn(90);
  moveIntake(tankProfile, 2.45_ft, fwd, 1400);
  turn(135);
  move(tankProfile, 2_ft, fwd);
  cycle(500);
  move(tankProfile, 2.75_ft, fwd);

}
