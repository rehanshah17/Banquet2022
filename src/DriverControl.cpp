//hella drivey
#include "main.h"

void setDrive(int left, int right){
  backLeft = left;
  frontLeft = left;
  frontRight = right;
  backRight = right;
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
  const int liftVelocity = 100;

  if(getLiftUp) {
    lift = liftVelocity;
  }
  else if(getLiftDown) {
    lift = -liftVelocity;
  }
  else {
    lift = 0;
  }
}
