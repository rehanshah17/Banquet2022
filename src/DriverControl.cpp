//hella drivey
#include "main.h"

//STATE VARIABLES
bool clamped = false;

void setDrive(int left, int right){
  backLeft.move_voltage(left * 70);
  frontLeft.move_voltage(left * 70);
  backRight.move_voltage(right * 70);
  frontRight.move_voltage(right * 70);
}

void setMotors() {
    //left -- drive
    //right -- turn

  double power =  controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
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

  okapi::Motor clampOO(2);

  if(getClampUp){
    clampOO.moveAbsolute(90,100);
  }
  if(getClampDown){
    clampOO.moveAbsolute(-90,100);
  }

}
  void moveBackLift() {
    bool getBackLiftUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    bool getBackLiftDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
    const int backLiftSpeed = 127;

    if(getBackLiftUp) {
      backLift = -backLiftSpeed;
    }
    else if(getBackLiftDown) {
      backLift = backLiftSpeed;
    }
    else {
      backLift = 0;
    }
}
