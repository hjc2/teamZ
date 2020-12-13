#pragma once

#include "main.h"
#include "../include/285Z/autonomous/redAuton.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"
using namespace okapi; //DONT TOUCH THIS

void redHomeRow(){
  auto chassis = ChassisControllerBuilder()
  .withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
  .withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
  .build();

  auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());

  for(float i = 0; i < 1; i += 0.01){
    xModel -> xArcade(-i/5, -i / 1.5, -i / 3);
    pros::delay(10);
  }
  for(float i = 1; i > 0; i -= 0.01){
    xModel -> xArcade(-i*i, -i, -i / 3);
    pros::delay(10);
  }
  for(float i = 0; i < 1; i += 0.01){
    xModel -> xArcade(0, i / 1.5, 0);
    pros::delay(7);
  }

  xModel -> xArcade(0,0, 0);

}
void redTwoGoal(){
  auto chassis = ChassisControllerBuilder()
  .withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
  .withDimensions(AbstractMotor::gearset::green, {{15_in, 15_in}, imev5GreenTPR})
  .build();

  auto xModel = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());

  xModel -> xArcade(-1, 0, 0);
  pros::delay(250);
  xModel -> xArcade(0, 0, 0);
  pros::delay(15000);
}
