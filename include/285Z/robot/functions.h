#pragma once
#include "main.h"

//SNAILBOT DEMO CODE
bool intakeControl(bool overRide, int io);
bool fwControl(bool overRide, int io);
bool beltControl(bool overRide, int io);

extern bool fwToggler;
extern bool intakeToggler;
extern bool beltToggler;