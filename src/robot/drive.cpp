#include "main.h"
#include "../include/285Z/robot/drive.h"
#include "../include/285Z/initRobot.h"

bool hDrive(bool overRide, int ioLeft, int ioRight, bool brake){
    if(overRide){
        if(brake){
            driveMotorTopLeft.set_brake_mode(MOTOR_BRAKE_BRAKE);
            driveMotorBackLeft.set_brake_mode(MOTOR_BRAKE_BRAKE);
            driveMotorTopRight.set_brake_mode(MOTOR_BRAKE_BRAKE);
            driveMotorBackRight.set_brake_mode(MOTOR_BRAKE_BRAKE);

            driveMotorTopLeft.move_voltage(0);
            driveMotorBackLeft.move_voltage(0);
            driveMotorTopRight.move_voltage(0);
            driveMotorBackRight.move_voltage(0);
            return(0);
        } else {
            driveMotorTopLeft.set_brake_mode(MOTOR_BRAKE_COAST);
            driveMotorBackLeft.set_brake_mode(MOTOR_BRAKE_COAST);
            driveMotorTopRight.set_brake_mode(MOTOR_BRAKE_COAST);
            driveMotorBackRight.set_brake_mode(MOTOR_BRAKE_COAST);

            driveMotorTopLeft.move_voltage(ioLeft);
            driveMotorBackLeft.move_voltage(ioLeft);
            driveMotorTopRight.move_voltage(ioRight);
            driveMotorBackRight.move_voltage(ioRight);
            return(1);
        }
    } else {
            driveMotorTopLeft.set_brake_mode(MOTOR_BRAKE_COAST);
            driveMotorBackLeft.set_brake_mode(MOTOR_BRAKE_COAST);
            driveMotorTopRight.set_brake_mode(MOTOR_BRAKE_COAST);
            driveMotorBackRight.set_brake_mode(MOTOR_BRAKE_COAST);

            driveMotorTopLeft.move_voltage(controller.getAnalog(okapi::ControllerAnalog::leftY)*12000);
            driveMotorBackLeft.move_voltage(controller.getAnalog(okapi::ControllerAnalog::leftY)*12000);
            driveMotorTopRight.move_voltage(controller.getAnalog(okapi::ControllerAnalog::rightY)*12000);
            driveMotorBackRight.move_voltage(controller.getAnalog(okapi::ControllerAnalog::rightY)*12000);
            return(1);
    }
}