#include "main.h"
#include "../include/285Z/autonomous/miscAuton.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/pid.h"

using namespace okapi; //DONT TOUCH THIS

//AUTON FUNCTIONS
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
  turn(0);

}

void noAuto(){

  pros::delay(15000);

}

void skillsAuto(){

  deployMotion();

  //first goal scoring

  moveIntake(tankProfile, 2.25_ft, fwd, 2000);
  turn(45);
  move(tankProfile, 0.8_ft, fwd);
  cycle(400);


  //right wall goal

  move(tankProfile, 3.35_ft, bwd);
  turn(270);
  moveIntake(tankProfile, 1.35_ft, fwd, 1100);
  turn(0);
  moveIntake(tankProfile, 1.9_ft, fwd, 1200);
  cycle(400);


  //getting red tile ball and back right corner goal

  move(tankProfile, 1.2_ft, bwd);
  turn(270);
  setReverse();
  pros::delay(300);
  setBrakeAll();
  moveIntake(tankProfile, 2.4_ft, fwd, 2200);
  turn(315);
  move(tankProfile, 2.2_ft, fwd);
  cycle(400);


  //scoring back wall goal

  move(tankProfile, 1.4_ft, bwd);
  turn(270);
  setReverse();
  pros::delay(250);
  setBrakeAll();
  move(xDriveProfile, 2.6_ft, fwd);
  move(tankProfile, 0.9_ft, fwd);
  cycle(600);


  //getting back left corner goal

  move(tankProfile, 0.4_ft, bwd);
  turn(180);
  moveIntake(tankProfile, 3.2_ft, fwd, 2200);
  turn(225);
  move(tankProfile, 1.2_ft, fwd);
  cycle(600);


  //right wall goal

  move(tankProfile, 3.25_ft, bwd);
  turn(90);
  moveIntake(tankProfile, 1.9_ft, fwd, 1300);
  turn(180);
  moveIntake(tankProfile, 1.9_ft, fwd, 1650);
  cycle(400);


  //final goal (front left corner goal)

  move(tankProfile, 1.2_ft, bwd);
  turn(90);
  moveIntake(tankProfile, 2.35_ft, fwd, 2400);
  turn(135);
  move(tankProfile, 2_ft, fwd);
  cycle(400);

  move(tankProfile, 3_ft, bwd);

}
