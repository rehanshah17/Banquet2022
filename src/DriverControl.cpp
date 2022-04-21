//hella drivey
#include "main.h"

//STATE VARIABLES
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
    lift = liftSpeed;
    lift2 = liftSpeed;
  }
  else if(getLiftDown) {
    lift = -liftSpeed;
    lift2 = -liftSpeed;
  }
  else {
    lift = 0;
    lift2 = 0;
  }
}

void moveClamp() {
  bool getClampUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);
  bool getClampDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);
  const int clampSpeed = 50;

  if(getClampUp) {
    clamp = clampSpeed;
  }
  else if(getClampDown) {
    clamp = -clampSpeed;
  }
  else {
    clamp = 0;
  }
  /*okapi::Motor clamp(17);
  if(getClampUp &&clamped) {
    clamped = false;
    clamp.moveRelative(0.8, -100);
    pros::delay(90);

  }
  if(getClampDown && !clamped) {
    clamped = true;
    clamp.moveRelative(-0.8, 100);
    pros::delay(90);
  }
  else {
    clamp = 0;
  }*/
}
  void moveBackLift() {
    bool getBackLiftUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    bool getBackLiftDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
    const int backLiftSpeed = 127;

    if(getBackLiftUp) {
      backLift = backLiftSpeed;
    }
    else if(getBackLiftDown) {
      backLift = -backLiftSpeed;
    }
    else {
      backLift = 0;
    }
}
