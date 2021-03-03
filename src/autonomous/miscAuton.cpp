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
    1.8, // Maximum linear acceleration of the Chassis in m/s/s
    4.0 // Maximum linear jerk of the Chassis in m/s/s/s
  })
  .withOutput(chassis)
  .buildMotionProfileController();

std::shared_ptr<AsyncMotionProfileController> xDriveProfile =
AsyncMotionProfileControllerBuilder()
  .withLimits({
    1.2, // Maximum linear velocity of the Chassis in m/s
    1.8, // Maximum linear acceleration of the Chassis in m/s/s
    4.0 // Maximum linear jerk of the Chassis in m/s/s/s
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

  start(ejectorMotor, 500, 600);
  move(xDriveProfile, 0.9_ft, fwd);
  setOuttake();
  pros::delay(400);
  setInBrake();
  turn(0);

}

void noAuto(){

  pros::delay(15000);

}

void skillsAuto(){

  deployMotion();

  //first ball + corner goalmove(tankProfile, 1.3_ft, fwd);

  for (int i = 0; i < 2000; i += 5) {
    setLine();
    pros::delay(5);
  }
  move(tankProfile, 1.3_ft, fwd);
  pros::delay(500);
  setCyBrake();
  setInBrake();

  pros::delay(200);
  move(tankProfile, 0.4_ft, fwd);
  turn(53);
  move(tankProfile, 0.9_ft, fwd);
  cycle(400);
  move(tankProfile, 0.9_ft, bwd);


  //second ball + right wall goal


}
