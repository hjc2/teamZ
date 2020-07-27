#include "main.h"
#include "../include/285Z/initRobot.h"
#include "../include/285Z/robot/drive.h"

void on_center_button() { }

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	while (true) {
		xDrive();
		pros::delay(20);
	}
}
//