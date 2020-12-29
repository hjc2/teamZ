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
//heirarchy
//pure reverse
//ejection
//cycle
//line
int evaluateDriver(){
  bool cycleValue =  cycleButton.changedToPressed();
  bool lineValue = lineButton.changedToPressed();
  bool noIntakeValue = noIntakeButton.changedToPressed();

  bool noIntakePush = noIntakeButton.isPressed();
  bool ejectValue = ejectButton.isPressed();
  bool reverseValue = reverseButton.isPressed();
  if(lineValue){ //LINE TOGGLE MODE CHECKER
    if(toggleLine){
      toggleLine = 0;
    } else {
      toggleLine = 1;
    }
  }
  /*
  if(noIntakeValue){ //NOINTAKE MODE TOGGLE CHECKER
    if(toggleNoIntake){
      toggleNoIntake = 0;
    } else {
      toggleNoIntake = 1;
    }
  }*/
   if(cycleValue){ //TOGGLE STUFF
    if(toggleCycle){
      toggleCycle = 0;
    } else {
      toggleCycle = 1;
    }
    //std::cout << "l2 button pressed";
  }

  if(ejectValue){ //EJECTION MODE
    controlIntake(FORWARD);
    controlIncycle(EJECT);
  }
  else if(reverseValue){ //PURE REVERES MODE
    controlIntake(REVERSE);
    controlIncycle(REVERSE);
  } /* else if(toggleNoIntake){ //PURE REVERES MODE
    controlIntake(BRAKE);
    controlIncycle(FORWARD);
  } */
  else if(noIntakePush){ //INTAKE MODE
    controlIntake(BRAKE);
    controlIncycle(FORWARD);
    std::cout << "l2 run";
  } else if(toggleCycle){ //INTAKE MODE
    controlIntake(FORWARD);
    controlIncycle(FORWARD);
    std::cout << "l2 run";
  } else if(toggleLine){
    controlIntake(FORWARD);
    controlIncycle(LINE);
    std::cout << "toggleLine\n";
  }
  else { //BRAKE MODE
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
  if(macro == 4){
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
void setCyBrake(){ //correct
  ejectorMotor -> move_velocity(0);
  cyclerMotor -> move_velocity(0);
  ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
//the ejection motor will reverse, the cycler motor will go full power.
void setEject(){ //correct
  ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  ejectorMotor -> move_velocity(-600);
  cyclerMotor -> move_velocity(600);
}
//both cycler and ejector motors go full power
void setCycle(){
  ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  ejectorMotor -> move_velocity(600);
  cyclerMotor -> move_velocity(400);
}
//both the ejector and cycler motors reverse
void setReverse(){
  ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  ejectorMotor -> move_velocity(-600);
  cyclerMotor -> move_velocity(-600);
}

//line sensor shenanigans
void setLine(){ //semi correct
  int top = lineSensorOne.get_value();
  int mid = lineSensorTwo.get_value();
  int bot = lineSensorThree.get_value();
  if(top < tuneOne){
    if(mid < tuneTwo){
      if(bot < tuneThree){ //TOP MID AND BOT ACTIVATED
        setCyBrake();
        setInBrake();
        std::cout << "bot activated";
      } else { //TOP AND MID ACTIVATED
        setCyBrake();
        setIntake();
        std::cout << "mid activated";
      }
    } else { //TOP ACTIVATED
      cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      ejectorMotor -> move_velocity(0);
      cyclerMotor -> move_velocity(600);
      ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      setIntake();
      std::cout << "top activated";
    }
  } else { //NO BALL
    ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    ejectorMotor -> move_velocity(100);
    cyclerMotor -> move_velocity(500);
    setIntake(); //runs intake fully
    std::cout << "no ball";
  }
}
