#include "main.h"
#include "../include/285Z/robot/functions.h"
#include "../include/285Z/initRobot.h"

bool pushIntake(bool value){
    if(value){
        intakeLeft.move_voltage(12000);
        intakeRight.move_voltage(12000);
    } else {
        intakeLeft.move_voltage(0);
        intakeRight.move_voltage(0);
    }
}
