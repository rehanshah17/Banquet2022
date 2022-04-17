//hella drivey
#include "main.h"

void setDrive(int left, int right){
  backLeft.move_voltage(left);
  frontLeft.move_voltage(left);
  frontRight.move_voltage(right);
  frontRight.move_voltage(right);
}

void setMotors() {
    //left -- drive
    //right -- turn

  double power = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  double direction = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

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
  const int liftSpeed = 100;

  if(getLiftUp) {
    lift = liftSpeed;
  }
  else if(getLiftDown) {
    lift = -liftSpeed;
  }
  else {
    lift = 0;
  }
}

void moveClamp() {
  bool getClampUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
  bool getClampDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
  const int clampSpeed = 100;

  if(getClampUp) {
    lift = clampSpeed;
  }
  else if(getClampDown) {
    lift = -clampSpeed;
  }
  else {
    lift = 0;
  }
}
