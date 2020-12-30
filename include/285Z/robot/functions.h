#include "main.h"
#include "../include/285Z/initRobot.h"

void testDriver();
int evaluateDriver();

bool controlIntake(int macro);

bool controlIncycle(int macro);

//INTAKE FUNCTIONS
void setInBrake();
void setOuttake();
void setIntake();

//CYCLER FUNCTIONS
void setEject();
void setCycle();
void setReverse();
void setCyBrake();
void setLine();
void setSlowed();

//R2 intake and cycler
//R1 PURE REVERSE

//L1 turn to ejector mode (overrides everything)
//
