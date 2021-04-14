#include "main.h"
#include "../include/285Z/autonomous/miscAuton.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/pid.h"

using namespace okapi; //DONT TOUCH THIS

void redHomeRow(){

  //start(ejectorMotor, 700, 600);
  setCycle();
  pros::delay(400);
  setCyBrake();
  move(tankProfile, 2.2_ft, fwd);
  setOuttake();
  pros::delay(500);
  setInBrake();
  turn(70);
  moveIntake(tankProfile, 1.8_ft, fwd, 1400);
  cycle(800);
  move(tankProfile, 6_ft, bwd);
  turn(190);
  moveIntake(tankProfile, 11_ft, fwd, 2500);
  cycle(500);
  move(tankProfile, 1_ft, bwd);
}

void redTwoGoal(){

  //start(ejectorMotor, 700, 600);
  setCycle();
  pros::delay(1100);
  setCyBrake();
  move(tankProfile, 2.2_ft, fwd);
  setOuttake();
  pros::delay(500);
  setBrakeAll();
  turn(70);
  moveIntake(tankProfile, 1.8_ft, fwd, 1000);
  setIntake();
  setCycle();
  pros::delay(900);
  setReverse();
  pros::delay(400);
  setBrakeAll();
  move(tankProfile, 1_ft, bwd);

}

void redCenter() {
  setCycle();
}

void redCorner() {
  setCycle();
}
