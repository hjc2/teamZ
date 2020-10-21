#include "main.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"
#pragma once

bool controlIntake(bool direction, int speed){
  //NEVER PUT ANYTHING INTO THIS,
  //intakeRight.move_voltage(speed);
}

bool controlIntake(int macro){
  if(macro == 0){    //brake mode code
    rightIntake -> move_voltage(0);
    leftIntake -> move_voltage(0);
    rightIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    leftIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  } else
  if(macro == 1){    //intake mode code
    rightIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    leftIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    rightIntake -> move_voltage(-12000);
    leftIntake -> move_voltage(12000);
  } else
  if(macro == 2){    //outtake mode code
    rightIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    leftIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    rightIntake -> move_voltage(12000);
    leftIntake -> move_voltage(-12000);
  } else {    //manual control code

  }
}

int evaluateIntakeMode(){
  bool intakeValue = intakeButton.changedToPressed();
  bool outtakeValue = outtakeButton.isPressed();
  if(intakeValue == 1){
    if(toggleIntake == 0){
      controlIntake(FORWARD);
      toggleIntake = 1;
    } else {
      controlIntake(BRAKE);
      toggleIntake = 0;
    }
  } else
  if(outtakeValue == 1){
    controlIntake(REVERSE);
    //toggleIntake = 1;
  } else if(!toggleIntake){
    controlIntake(BRAKE);
  } else if(toggleIntake){
    controlIntake(FORWARD);
  } else {
    controlIntake(BRAKE);
  }
}

bool controlIncycle(int macro){
  if(macro == 0){    //brake mode code
    ejectorMotor -> move_voltage(0);
    cyclerMotor -> move_voltage(0);
    ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  } else
  if(macro == 1){    //intake mode code
    ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    ejectorMotor -> move_voltage(-12000);
    cyclerMotor -> move_voltage(12000);
  } else
  if(macro == 2){    //outtake mode code
    ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    ejectorMotor -> move_voltage(12000);
    cyclerMotor -> move_voltage(-12000);
  } else {    //manual control code

  }
}

int evaluateIncycleMode(){
  bool incycleValue = incycleButton.changedToPressed();
  bool outcycleValue = outcycleButton.isPressed();
  if(incycleValue == 1){
    if(toggleIntake == 0){
      controlIncycle(FORWARD);
      toggleIntake = 1;
    } else {
      controlIncycle(BRAKE);
      toggleIntake = 0;
    }
  } else
  if(outcycleValue == 1){
    controlIncycle(REVERSE);
    //toggleIntake = 1;
  } else if(!toggleIntake){
    controlIncycle(BRAKE);
  } else if(toggleIntake){
    controlIncycle(FORWARD);
  } else {
    controlIncycle(BRAKE);
  }
}
/*
bool controlIncycle(int macro){
  if(macro == 0){    //brake mode code
    intakeLeft.move_voltage(0);
    intakeRight.move_voltage(0);
    intakeLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    intakeRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  } else
  if(macro == 1){    //intake mode code
    intakeLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intakeRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intakeLeft.move_voltage(12000);
    intakeRight.move_voltage(12000);
  } else
  if(macro == 2){    //outtake mode code
    intakeLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intakeRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intakeLeft.move_voltage(-12000);
    intakeRight.move_voltage(-12000);
  } else {    //manual control code

  }
}
*/
