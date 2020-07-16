#include "main.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/functions.h"

bool intakeControl(bool overRide, int io){
    if(overRide){
        leftIntakeMotor.move_voltage(io);
        rightIntakeMotor.move_voltage(-1 * io);
    } else {

    }
}

bool fwControl(bool overRide, int io){
    if(overRide){

    } else {
        
    }
}

bool beltControl(bool overRide, int io){
    if(overRide){
        if(io == 0){
            beltMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
            beltMotor.move_voltage(0);
            return(false);
            } else {
            beltMotor.set_brake_mode(MOTOR_BRAKE_COAST);
            beltMotor.move_voltage(io);
            return(true);
        }
    } else {
        if(controller.getDigital(okapi::ControllerDigital::beltButton) == 0){
            beltMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
            beltMotor.move_voltage(0);
            return(false);
        } else {
            beltMotor.set_brake_mode(MOTOR_BRAKE_COAST);
            beltMotor.move_voltage(12000);
            return(true);
        }
    }
}
