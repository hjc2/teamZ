#pragma once
#include "main.h"

#define RELATIVE 0
#define ABSOLUTE 1

extern double kP;
extern double kI;
extern double kD;

void calibrate();
void turn(double);
