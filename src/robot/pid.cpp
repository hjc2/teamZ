#include "285Z/initRobot.h"
#include "285Z/robot/pid.h"

const double GLOBAL_kP = 3;
const double GLOBAL_kI = 0.00001;
const double GLOBAL_kD = 0.1;

bool clockwise = true;

void calibrate(){
  imuSensor.reset();
}

void turn(double degrees){

  driveR.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  driveL.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

  double thetaI = imuSensor.get_heading();
  double thetaF = degrees;

  double sensorValue = thetaI;
  double turnTarget = thetaF;

  double deltaI = abs(thetaF - thetaI);

// Decides which direction to turn
  if (thetaF > thetaI && deltaI > 180) {
    clockwise = false;
  }
  else if (deltaI < 180) {
      clockwise = false;
  }

// idk lol
  if (deltaI > 180){
    if (thetaF > 180) {
      turnTarget = thetaF - 360;
    } else {
      turnTarget = thetaF;
    }

    if (thetaI > 180) {
      sensorValue = thetaI - 360;
    } else {
      sensorValue = thetaI;
    }
  }

  double error = turnTarget - sensorValue;
  double oldError = error;
  double sumError = 0;

  bool TURN_NOT_FINISH = true;
  while (TURN_NOT_FINISH) {
    sensorValue = imuSensor.get_heading();

    if (deltaI > 180){
      if (sensorValue > 180) {
        sensorValue = sensorValue - 360;
      }
    }

    //PROPORTIONAL
    error = turnTarget - sensorValue;
    //DERIVATIVE
    double changeInError = error - oldError;
    //INTEGRAL
    if (abs(error) < 50) {
      sumError += error;
    } else {
      sumError = 0; //might be += 0?
    }

    //P, I, D
    double P = GLOBAL_kP * error;
    double I = GLOBAL_kI * sumError;
    double D = GLOBAL_kD * changeInError;

    double sum = P + I + D;

    if (clockwise) {
      driveL.moveVelocity(sum);
      driveR.moveVelocity(-sum);
    } else {
      driveL.moveVelocity(-sum);
      driveR.moveVelocity(sum);
    }

    oldError = error;
    double errorThreshold = 1.5;
    double velocityThreshold = 2;

    TURN_NOT_FINISH = !((abs(error) < errorThreshold) && (abs(changeInError) < velocityThreshold));
  }
  driveL.moveVelocity(0);
  driveR.moveVelocity(0);
}
