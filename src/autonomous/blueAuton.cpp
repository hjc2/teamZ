#include "main.h"
#include "../include/285Z/autonomous/miscAuton.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/pid.h"

using namespace okapi;

void blueHomeRow() {

  setCycle();
  pros::delay(300);
  setCyBrake();
  moveOuttake(tankProfile, 2.2_ft, fwd, 600);

  turn(75);
  moveIntake(tankProfile, 1.8_ft, fwd, 1400);
  cycle(650);
  move(tankProfile, 3.2_ft, bwd);

  turn(210);
  move(tankProfile, 5_ft, fwd);
  turn(160);
  moveIntake(tankProfile, 4_ft, fwd, 1400);
  cycle(650);
  move(tankProfile, 1_ft, bwd);

}

void blueCenter() {

  setCycle();
  pros::delay(300);
  setCyBrake();
  moveOuttake(tankProfile, 2.2_ft, fwd, 400);

  turn(285);
  moveIntake(tankProfile, 1.8_ft, fwd, 1200);
  cycle(1300);
  move(tankProfile, 3.95_ft, bwd);

  turn(60);
  move(tankProfile, 0.67_ft, fwd);
  move(xDriveProfile, 4_ft, bwd);

}

void blueCorner() {

  setCycle();
  pros::delay(300);
  setCyBrake();
  moveOuttake(tankProfile, 2.4_ft, fwd, 600);

  turn(75);
  moveIntake(tankProfile, 1.8_ft, fwd, 1400);
  cycle(1700);
  move(tankProfile, 1_ft, bwd);

}
