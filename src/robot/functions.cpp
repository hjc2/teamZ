#include "main.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"

using namespace okapi;

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
  /*
   if(cycleValue){ //TOGGLE STUFF
    if(toggleCycle){
      toggleCycle = 0;
    } else {
      toggleCycle = 1;
    }
    //std::cout << "l2 button pressed";
  }*/
  toggleCycle = cycleValue;

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
    controlIncycle(SLOWED);
    std::cout << "SLOWED run";
  } else if(cycleButton.isPressed()){ //INTAKE MODE
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
  if(macro == BRAKE){    //brake mode code
    setInBrake();
  } else
  if(macro == FORWARD){    //intake mode code
    setIntake();
  } else
  if(macro == REVERSE){    //outtake mode code
    setOuttake();
  } else {    //manual control code

  }
}

//takes macro
bool controlIncycle(int macro){
  if(macro == BRAKE){    //brake mode code
    setCyBrake();
  } else
  if(macro == FORWARD){    //intake mode code
    setCycle();
  } else
  if(macro == REVERSE){    //outtake mode code
    setReverse();
  } if(macro == EJECT){ //ejectorMode
    setEject();
  }  else
  if(macro == LINE){ //line mod
    setLine();
  } else
  if(macro == SLOWED){ //no intake mode
    setSlowed();
  } else {    //manual control code

  }
}

//INTAKE FUNCTIONS
//breaks intake, cycler, and ejector
void setBrakeAll() {
  setInBrake();
  setCyBrake();
}
//motors will stop and brake
void setInBrake(){
  rightIntake -> move_velocity(0);
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
  ejectorMotor -> move_velocity(600);
  cyclerMotor -> move_velocity(600);
}
//both cycler and ejector motors go full power
void setCycle(){
  ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  ejectorMotor -> move_velocity(-600);
  cyclerMotor -> move_velocity(600);
}
//both the ejector and cycler motors reverse
void setReverse(){
  ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  ejectorMotor -> move_velocity(600);
  cyclerMotor -> move_velocity(-600);
}
//cycler runs slower and ejector runs full speed
void setSlowed(){
  ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  ejectorMotor -> move_velocity(-600);
  cyclerMotor -> move_velocity(600);
}
//line sensor shenanigans
void setLine(){ //semi correct
  int top = lineSensorOne.get_value();
  int bot = lineSensorTwo.get_value();
  int top2 = lineSensorThree.get_value(); //for accuracy

  if(top < tuneOne){
    //&& (top2 < tuneOne)
    if(bot < tuneTwo){ //ALL ACTIVATED
      setCyBrake();
      setInBrake();
    } else { //TOP ACTIVATED
      cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      ejectorMotor -> move_velocity(0);
      cyclerMotor -> move_velocity(300);
      ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      setIntake();
    }
  } else { //NO BALL
    ejectorMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    cyclerMotor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    ejectorMotor -> move_velocity(0);
    cyclerMotor -> move_velocity(600);
    setIntake(); //runs intake fully
  }
}

//AUTON functions
void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir){ //movement function

    profile->generatePath({
      {0_ft,0_ft,0_deg},
      {distance, 0_ft,0_deg}},
      "M"
    );

    profile->setTarget("M", dir);
    profile->waitUntilSettled();
    profile->removePath("M");
}

void moveIntake(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir, int time){

    profile->generatePath({
    {0_ft,0_ft,0_deg},
    {distance, 0_ft,0_deg}},
    "M"
    );

    profile->setTarget("M", dir);

    for(int i = 0; i < time; i +=5){
      setLine();
      pros::delay(5);
    }

    setBrakeAll();
    profile->waitUntilSettled();
    profile->removePath("M");
}

void moveOuttake(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir, int time){

    profile->generatePath({
    {0_ft,0_ft,0_deg},
    {distance, 0_ft,0_deg}},
    "M"
    );

    profile->setTarget("M", dir);

    setOuttake();
    setReverse();
    pros::delay(time);
    setBrakeAll();

    profile->waitUntilSettled();
    profile->removePath("M");
}

void cycle (uint32_t time) {
  setCycle();
  pros::delay(time);
  setBrakeAll();
}
