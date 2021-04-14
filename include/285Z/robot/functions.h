#include "main.h"
#include "../include/285Z/initRobot.h"

void testDriver();
int evaluateDriver();

bool controlIntake(int macro);

bool controlIncycle(int macro);

//INTAKE FUNCTIONS
void setBrakeAll();
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

//AUTON FUNCTIONS
void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir);
void moveIntake(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir, int time);
void moveOuttake(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir, int time);
void cycle (uint32_t delay);

const bool fwd {false};
const bool bwd {true};
