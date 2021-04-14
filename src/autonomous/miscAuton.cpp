#include "main.h"
#include "../include/285Z/autonomous/miscAuton.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/pid.h"

using namespace okapi; //DONT TOUCH THIS

/*void deployMotion() {

  setCycle();
  pros::delay(600);
  setCyBrake();

  move(xDriveProfile, 0.9_ft, fwd);

  setOuttake();
  pros::delay(500);
  setInBrake();

}*/

void noAuto(){

  pros::delay(15000);

}

void skillsAuto(){


  pros::delay(15000);
  //deployMotion();

  //first goal scoring

  //moveIntake(tankProfile, 2.2_ft, fwd, 1300);
  //turn(45);
  //move(tankProfile, 1_ft, fwd);
  //cycle(600);


  //right wall goal
  /*
  moveOuttake(tankProfile, 3.7_ft, bwd, 300);
  turn(270);
  moveIntake(tankProfile, 1.5_ft, fwd, 1100);
  turn(0);
  moveIntake(tankProfile, 2.3_ft, fwd, 1200);
  cycle(600);


  //getting red tile ball and back right corner goal

  moveOuttake(tankProfile, 1.2_ft, bwd, 300);
  turn(270);
  setReverse();
  pros::delay(300);
  setBrakeAll();
  moveIntake(tankProfile, 2.2_ft, fwd, 2200);
  turn(315);
  move(tankProfile, 2_ft, fwd);
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

  move(tankProfile, 4_ft, bwd);

  */
}
