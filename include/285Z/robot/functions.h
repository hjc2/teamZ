#include "main.h"
#include "../include/285Z/initRobot.h"
//SNAILBOT DEMO CODE

bool controlIntake(bool direction, int speed);
int evaluateDriver();

bool controlIntake(int macro);
int evaluateIntakeMode();

bool controlIncycle(int macro);
int evaluateIncycleMode();

void setInBrake();
void setOuttake();
void setIntake();

void setEject();
void setCycle();
void setReverse();
void setCyBrake();
void setPush();


//R2 intake and cycler
//R1 PURE REVERSE

//L1 turn to ejector mode (overrides everything)
//
