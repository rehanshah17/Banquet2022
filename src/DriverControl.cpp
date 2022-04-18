//hella drivey
#include "main.h"

bool clamped = false;

void setDrive(int left, int right){
  backLeft = left;
  frontLeft = left;
  backRight = right;
  frontRight = right;
}

void setMotors() {
    //left -- drive
    //right -- turn

  double power = 2 * controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  double direction = 1.5 * controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

  int left = power + direction;
  int right = power - direction;

    //deadzones
  if (abs(power) <= 20)
    setDrive(0, 0);
  if (abs(direction) <= 20)
    setDrive(0, 0);

    //set motor power
  setDrive(left, right);
}


void moveLift() {
  bool getLiftUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
  bool getLiftDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
  const int liftSpeed = 127;

  if(getLiftUp) {
    lift = -liftSpeed;
  }
  else if(getLiftDown) {
    lift = liftSpeed;
  }
  else {
    lift = 0;
  }
}

void moveClamp() {
  bool getClampUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
  bool getClampDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
  const int clampSpeed = 50;

  okapi::Motor clamp(10);
  if(getClampUp && clamped) {
    clamped = false;
    clamp.moveRelative(0.8, 100);
    pros::delay(90);

  }
  if(getClampDown && !clamped) {
    clamped = true;
    clamp.moveRelative(-0.8, 100);
    pros::delay(90);
  }
  else {
    clamp = 0;
  }
}
