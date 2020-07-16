#include "main.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/functions.h"

bool intakeControl(bool overRide, int io){
    if(overRide){
        leftIntakeMotor.move_voltage(io*12000);
        rightIntakeMotor.move_voltage(-io*12000)
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

    } else {

    }
}
