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

  //deploy
  deployMotion();


  //first goal scoring

  turn(0);
  for(int time = 0; time < 30; time +=5){
    setLine();
    pros::delay(5);
  }
  move(tankProfile, 2.3_ft, fwd);
  setCyBrake();
  setInBrake();
  turn(45);
  move(tankProfile, 1.2_ft, fwd);
  cycle(300);


  //right wall goal

  move(tankProfile, 3.4_ft, bwd);
  turn(270);
  setLine();
  move(tankProfile, 1.3_ft, fwd);
  turn(0);
  move(tankProfile, 1.9_ft, fwd);
  setInBrake();
  setCyBrake();
  cycle(400);


  //getting red tile ball and back right corner goal

  move(tankProfile, 1.2_ft, bwd);
  turn(270);
  setLine();
  move(tankProfile, 2.7_ft, fwd);
  //setBrakeAll();
  turn(315);
  move(tankProfile, 1.5_ft, fwd);
  cycle(500);


  //scoring back center wall goal

  move(tankProfile, 0.8_ft, bwd);
  turn(270);
  move(xDriveProfile, 3.5_ft, fwd);
  move(tankProfile, 0.7_ft, fwd);
  cycle(500);


  //getting back left corner goal

  move(tankProfile, 0.7_ft, bwd);
  turn(180);
  setLine();
  move(tankProfile, 2.6_ft, fwd);
  //setBrakeAll();
  turn(225);
  move(tankProfile, 1.1_ft, fwd);
  cycle(500);
  move(tankProfile, 3.4_ft, bwd);


  //center + right wall goals

  turn(90);
  setLine();
  move(tankProfile, 1.1_ft, fwd);
  //setBrakeAll();
  turn(0);
  move(tankProfile, 1_ft, fwd);
  setOuttake();
  pros::delay(1500);
  setInBrake();
  cycle(500);


  turn(180);
  setLine();
  move(tankProfile, 2.4_ft, fwd);
  //setBreakAll();
  cycle(300);
  move(tankProfile, 2.2_ft, bwd);
  turn(90);
  setEject();
  pros::delay(400);
  setCyBrake();
  setLine();
  move(tankProfile, 1.7_ft, fwd);


  //final goal (front left corner goal)

  turn(135);
  move(tankProfile, 1.6_ft, fwd);
  cycle(600);
  move(tankProfile, 0.6_ft, bwd);

}
