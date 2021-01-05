#pragma once

#include "main.h"
#include "../include/285Z/autonomous/miscAuton.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"
using namespace okapi; //DONT TOUCH THIS

void noAuto(){ //DONT CHANGE THIS, IT'S MEANT TO SIT STILL
  pros::delay(15000);
}
void skillsAuto(){ //SKILLS AUTO
  auto chassis = ChassisControllerBuilder()
  .withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
  .withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
  .build();

  auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());

  ejectorMotor -> move_velocity(600);
  pros::delay(500);
  ejectorMotor -> move_velocity(0);
  pros::delay(500);
  //hood deploy stuff

  rightIntake -> move_velocity(600);
  leftIntake -> move_velocity(-600);
  pros::delay(500);
  rightIntake -> move_velocity(0);
  leftIntake -> move_velocity(0);
  //intake deploy

  for (int i = 0; i < 5000; i += 5) {
    setLine();
    pros::delay(5);
  }

  xModel -> xArcade(0, 0.3, 0);
  pros::delay(200);

}
