//hella drivey
#include "main.h"

void setDrive(int left, int right){
  backLeft = left;
  frontLeft = left;
  frontRight = right;
  backRight = right;
}

void setMotors() {
//  left -- drivey
//  right -- turney

  double power = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  double direction = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

  int left = power + direction;
  int right = power - direction;

  if (abs(power) <= 20)
    setDrive(0, 0);
  if (abs(direction) <= 20)
    setDrive(0, 0);

  setDrive(left, right);
}


void moveLift(){
  bool up  = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
  bool down = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);

  if (up) {
    lift = 100;
  }
  else if (down) {
    lift = -100;
  }
  else {
    lift = 0;
  }
}
