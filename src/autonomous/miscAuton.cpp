#include "main.h"
#include "../include/285Z/autonomous/miscAuton.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/pid.h"

using namespace okapi; //DONT TOUCH THIS

void noAuto(){ //DONT CHANGE THIS, IT'S MEANT TO SIT STILL

  turn(30);

  //pros::delay(15000);

  //uncomment when done testing IMU + Motion Profile

}

void skillsAuto(){ //SKILLS AUTO

  auto chassis = ChassisControllerBuilder()
  .withMotors(frontLeftMotorPort, frontRightMotorPort, backRightMotorPort, backLeftMotorPort) //tl, tr, br, bl //  .withMotors(frontLeftMotor, frontRightMotor, backRightMotor, backLeftMotor)
  .withDimensions(AbstractMotor::gearset::green, {{3.25_in, 14_in}, imev5GreenTPR})
  .build();

  std::shared_ptr<AsyncMotionProfileController> profileController =
  AsyncMotionProfileControllerBuilder()
    .withLimits({
      1.2, // Maximum linear velocity of the Chassis in m/s
      1.2, // Maximum linear acceleration of the Chassis in m/s/s
      4.0 // Maximum linear jerk of the Chassis in m/s/s/s
    })
    .withOutput(chassis)
    .buildMotionProfileController();

  profileController->generatePath({
    {0_ft, 0_ft, 0_deg},
    {5_ft, 0_ft, 0_deg}},
    "A"
  );

  profileController->setTarget("A");
  profileController->waitUntilSettled();
  profileController->removePath("A");

}
