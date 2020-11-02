#include "main.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"
#pragma once
void testDriver(){
  if(cycleButton.isPressed()){
    setIntake();
    setCycle();
  } else {
    setInBrake();
    setCyBrake();
  }
}
int evaluateDriver(){
  bool cycleValue =  cycleButton.changedToPressed();
  bool ejectValue = ejectButton.isPressed();
  bool reverseValue = reverseButton.isPressed();
  bool lineValue = lineButton.isPressed();
  if(lineValue){
    if(toggleLine){
      controlIntake(FORWARD);
      controlIncycle(LINE);
      toggleLine = 0;
    } else {
      controlIntake(BRAKE);
      controlIntake(BRAKE);
      toggleLine = 1;
    }
  }
  if(cycleValue){ //TOGGLE STUFF
    if(toggleCycle){
      controlIntake(FORWARD);
      controlIncycle(FORWARD);
      toggleCycle = 0;
    } else {
      controlIntake(BRAKE);
      controlIntake(BRAKE);
      toggleCycle = 1;
    }
  }
  else if(ejectValue){ //EJECTION MODE
    controlIntake(FORWARD);
    controlIncycle(EJECT);
  }
  else if(reverseValue){ //PURE REVERES MODE
    controlIntake(REVERSE);
    controlIncycle(REVERSE);
  } else if(toggleCycle){ //INTAKE MODE
    controlIntake(FORWARD);
    controlIncycle(FORWARD);
  } else { //BRAKE MODE
    controlIntake(BRAKE);
    controlIncycle(BRAKE);
  }
  return(0);
}

//takes macro
bool controlIntake(int macro){
  if(macro == 0){    //brake mode code
    setInBrake();
  } else
  if(macro == 1){    //intake mode code
    setIntake();
  } else
  if(macro == 2){    //outtake mode code
    setOuttake();
  } else {    //manual control code

  }
}

//takes macro
bool controlIncycle(int macro){
  if(macro == 0){    //brake mode code
    setCyBrake();
  } else
  if(macro == 1){    //intake mode code
    setCycle();
  } else
  if(macro == 2){    //outtake mode code
    setReverse();
  } if(macro == 3){ //ejectorMode
    setEject();
  }  else
  if(macro ==4){
    setLine();
  } else {    //manual control code

  }
}

//INTAKE FUNCTIONS
//motors will stop and brake
void setInBrake(){
  rightIntake -> move_voltage(0);
  leftIntake -> move_velocity(0);
  rightIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  leftIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
//motors will reverse and go full power
void setOuttake(){
  rightIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  leftIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  rightIntake -> move_velocity(600);
  leftIntake -> move_velocity(-600);
}
//motors will intake at full power
void setIntake(){
  rightIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  leftIntake -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  rightIntake -> move_velocity(-600);
  leftIntake -> move_velocity(600);
}

//CYCLER FUNCTIONS
//both motors will stop and brake
void setCyBrake(){
  ejectorMotor -> move_velocity(0);
  cyclerMotor -> move_velocity(0);
  ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
//the ejection motor will reverse, the cycler motor will go full power.
void setEject(){
  ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  ejectorMotor -> move_velocity(600);
  cyclerMotor -> move_velocity(-600);
}
//both cycler and ejector motors go full power
void setCycle(){
  ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  ejectorMotor -> move_velocity(-600);
  cyclerMotor -> move_velocity(-600);
}
//both the ejector and cycler motors reverse
void setReverse(){
  ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  ejectorMotor -> move_velocity(600);
  cyclerMotor -> move_velocity(600);
}
//line sensor shenanigans
void setLine(){
  if(1 == 1/** input the line sensor condition equation here**/){ //line sensor activated
    ejectorMotor -> move_velocity(0);
    cyclerMotor -> move_velocity(-600);
    ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  } else {//line sensor deactivated
    ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    ejectorMotor -> move_velocity(-600);
    cyclerMotor -> move_velocity(-600);
  }
}
