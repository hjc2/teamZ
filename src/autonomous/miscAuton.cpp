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

  //line mode code
  for (int i = 0; i < 600; i += 5) {
    setLine();
    pros::delay(5);
  }
  //hood deploy

  pros::delay(500);

  xModel -> xArcade(0, 0.5, 0);
  pros::delay(600);

  xModel -> xArcade(0, 0, 0);

  rightIntake -> move_velocity(600);
  leftIntake -> move_velocity(-600);
  pros::delay(500);

  rightIntake -> move_velocity(0);
  leftIntake -> move_velocity(0);
  //intake deploy
  setCyBrake();

  pros::delay(800);

  xModel -> xArcade(0, 1, 0); //driving off of wall
  pros::delay(550);

  xModel -> xArcade(0, 0, -0.5); //tuurning to face corner goal
  pros::delay(1260);

  xModel -> xArcade(0, 0.75, 0); //driving into corner goal
  pros::delay(1600);


  xModel -> xArcade(0, 0, 0); //driving into corner goal
  setCycle();
  pros::delay(300);
  setCyBrake();
  pros::delay(400);
  setOuttake();
  pros::delay(150);

  xModel -> xArcade(0, -0.75, 0); //backing out of goal
  setCyBrake();
  setInBrake();
  pros::delay(1200);

  xModel -> xArcade(0, 0, 0);
  pros::delay(500);

    xModel -> xArcade(0, 0, 0.5); //turning to face wall goal
  for (int i = 0; i < 350; i += 5) {
    setLine();
    pros::delay(5);
  }

  xModel -> xArcade(0, 0, 0);
  pros::delay(500);

  xModel -> xArcade(0.6, 0, 0); //strafing to align with wall goal
  for (int i = 0; i < 500; i += 5) {
    setLine();
    pros::delay(5);
  }

  xModel -> xArcade(0, 0, 0);
  pros::delay(500);

    xModel -> xArcade(0, 1, 0); //driving into the wall goal
    pros::delay(1000);
    setEject();
    setIntake();

  xModel -> xArcade(0, 0, 0);
  pros::delay(1000);
  xModel -> xArcade(0, 0, 0);

  xModel -> xArcade(0, -0.4, 0); //backing out of goal
  pros::delay(1500);
  xModel -> xArcade(0, -0.7, 0); //backing out of goal
  pros::delay(400);



  xModel -> xArcade(0.6, 0, 0); //strafing to align with wall goal
  pros::delay(200);

  xModel -> xArcade(0, 0, 0.5); //turning to face center L goal
  pros::delay(350);
  xModel -> xArcade(0, 0, 0);
  pros::delay(500);
  xModel -> xArcade(0, 0.75, 0); //driving into the center L goal
  pros::delay(1000);

  setEject();
  setIntake();
      xModel -> xArcade(0, 1, 0); //driving into the wall goal
      pros::delay(1000);


    xModel -> xArcade(0, 0, 0);
    pros::delay(1000);
    xModel -> xArcade(0, 0, 0);
    xModel -> xArcade(0, 1, 0); //driving into the wall goal
    pros::delay(1000);
    xModel -> xArcade(0, -0.4, 0); //backing out of goal
    pros::delay(1500);
    xModel -> xArcade(0, -0.7, 0); //backing out of goal
    pros::delay(400);


    xModel -> xArcade(0, 0, 0.5); //turning to face ball to back wall
    pros::delay(600);

    xModel -> xArcade(0.5, 0, 0); //strafing to align with 2nd wall goal
    pros::delay(600);

    setEject();
    setIntake();
        xModel -> xArcade(0, 1, 0); //driving into the wall goal
        pros::delay(1000);


      xModel -> xArcade(0, 0, 0);
      pros::delay(1000);
      xModel -> xArcade(0, 0, 0);
      xModel -> xArcade(0, 1, 0); //driving into the wall goal
      pros::delay(1000);
      xModel -> xArcade(0, -0.4, 0); //backing out of goal
      pros::delay(1500);
      xModel -> xArcade(0, -0.7, 0); //backing out of goal
      pros::delay(400);

      xModel -> xArcade(0, 0, 0);
      pros::delay(500);
      xModel -> xArcade(1, 0.1, 0); //backing out of goal
      pros::delay(2000);

      xModel -> xArcade(0, 0, 0.5); //turning to face ball to back wall
      pros::delay(600);

      xModel -> xArcade(0, 1, 0);
      pros::delay(1500);

      xModel -> xArcade(0, -0.1, 0);
      pros::delay(1500);
      xModel -> xArcade(0, 1, 0);
      pros::delay(1500);
      xModel -> xArcade(0, -0.1, 0);
      pros::delay(1500);
      xModel -> xArcade(0, 1, 0);
      pros::delay(1500);
      xModel -> xArcade(0, -0.1, 0);
      pros::delay(1500);
      xModel -> xArcade(0, 1, 0);
      pros::delay(1500);

  xModel -> xArcade(0, 0, 0); //temp stop
  setCyBrake();
  setInBrake();
  pros::delay(100000);

  xModel -> xArcade(0, 0, 0.5); //turning to face ball to back wall
  pros::delay(600);

  xModel -> xArcade(0.5, 0, 0); //strafing to align with 2nd wall goal
  pros::delay(600);

  xModel -> xArcade(0, 0.75, 0); //driving into 2nd wall goal
  pros::delay(500);

  xModel -> xArcade(0, -0.75, 0); //backing out of 2nd wall goal
  pros::delay(800);

  xModel -> xArcade(0.5, 0, 0); //strafing to align with 2nd wall goal
  pros::delay(600);

  xModel -> xArcade(0, 0, 0.5); //turning to corner goal right
  pros::delay(600);
}
