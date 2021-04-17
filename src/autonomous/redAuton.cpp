#include "main.h"
#include "../include/285Z/autonomous/miscAuton.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/pid.h"

using namespace okapi; //DONT TOUCH THIS

void redHomeRow() {

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

void redCenter() {

  setCycle();
  pros::delay(300);
  setCyBrake();
  moveOuttake(tankProfile, 2.2_ft, fwd, 400);

  turn(290);
  moveIntake(tankProfile, 1.8_ft, fwd, 1400);
  cycle(2000);
  move(tankProfile, 2.3_ft, bwd);

  turn(35);
  moveIntake(tankProfile, 2_ft, fwd, 1400);
  move(xDriveProfile, 1.5_ft, bwd);

}

void redCorner() {

  setCycle();
  pros::delay(300);
  setCyBrake();
  moveOuttake(tankProfile, 2.4_ft, fwd, 600);

  turn(75);
  moveIntake(tankProfile, 1.8_ft, fwd, 1400);
  cycle(2000);
  move(tankProfile, 1_ft, bwd);

}
