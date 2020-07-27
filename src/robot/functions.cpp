#include "main.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/functions.h"
/*
bool fwToggler = false;
bool intakeToggler = false;
bool beltToggler = false;

//select one of the functions to use by commenting one of them out
//pushControlFunctions
bool intakeControl(bool overRide, int io){
    if(overRide){
        if(io == 0){
            leftIntakeMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
            fwMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
            leftIntakeMotor.move_voltage(0);
            fwMotor.move_voltage(0);
            return(false);
        } else {
            leftIntakeMotor.set_brake_mode(MOTOR_BRAKE_COAST);
            fwMotor.set_brake_mode(MOTOR_BRAKE_COAST);
            leftIntakeMotor.move_voltage(io);
            fwMotor.move_voltage(-1 * io);
            return(true);
        }
    } else {
        if(controller.getDigital(okapi::ControllerDigital::intakeButton) == 0){
            leftIntakeMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
            fwMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
            leftIntakeMotor.move_voltage(0);
            fwMotor.move_voltage(0);
            return(false);
        } else {
            leftIntakeMotor.set_brake_mode(MOTOR_BRAKE_COAST);
            fwMotor.set_brake_mode(MOTOR_BRAKE_COAST);
            leftIntakeMotor.move_voltage(io);
            fwMotor.move_voltage(-1 * io);
            return(true);
        }
    }
}
bool intakeTogglerControl(){}

bool fwControl(bool overRide, int io){
    if(overRide){
        if(io == 0){
            fwMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
            fwMotor.move_voltage(0);
            return(false);            
        } else {
            fwMotor.set_brake_mode(MOTOR_BRAKE_COAST);
            fwMotor.move_voltage(-1 * io);
            return(true);
        }
    } else {
        if(controller.getDigital(okapi::ControllerDigital::fwButton) == 0){
            fwMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
            fwMotor.move_voltage(0);
            return(false);
        } else {
            fwMotor.set_brake_mode(MOTOR_BRAKE_COAST);
            fwMotor.move_voltage(-1 * io);
            return(true);
        }
    }
}
bool fwTogglerControl(){
    if(fwToggler){
        fwToggler.set
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
bool beltTogglerControl();
*/