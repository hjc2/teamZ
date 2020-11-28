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

  xModel -> xArcade(-1, 1, 0);
  pros::delay(250);
  xModel -> xArcade(0, 0, 0);
  pros::delay(15000);
}
