#include "main.h"
// RESET ENCODERS
void resetMotorEncoders() {
  backLeft.tare_position();
  backRight.tare_position();
  frontRight.tare_position();
  frontLeft.tare_position();
}
// GET ENCODER VALUES
double getRightEncoder() {
  return (fabs(backRight.get_position()) + fabs(frontRight.get_position())) / 2;
}
double getLeftEncoder() {
  return (fabs(frontLeft.get_position()) + fabs(backLeft.get_position())) / 2;
}
double getAvgEncoder() {
  return (fabs(backRight.get_position()) + fabs(backLeft.get_position()) +
         fabs(frontRight.get_position()) + fabs(frontLeft.get_position())) / 4;
}


void translate(int units, int voltage) {
   int direction = abs(units) / units;

   resetMotorEncoders();

   while(getAvgEncoder() < abs(units)) {
       setDrive(voltage * direction, voltage * direction);
       pros::delay(10);
   }

   setDrive(-10 * direction, -10 * direction);
   pros::delay(10);

   setDrive(0, 0);
}

void turn(int units, int voltage) {
  int direction = abs(units) / units;

  resetMotorEncoders();

  while(getAvgEncoder() < abs(units)) {
      setDrive(voltage * direction, voltage * -direction);
      pros::delay(10);
  }

  setDrive(-10 * direction, -10 * direction);
  pros::delay(10);

  setDrive(0, 0);
}

void swingLeft(int units, int voltage) {
   resetMotorEncoders();

   while(getLeftEncoder() < abs(units)) {
       setDrive(voltage, 0);
       pros::delay(10);
   }

   setDrive(-10, 0);
   pros::delay(10);

   setDrive(0, 0);
}


void swingRight(int units, int voltage) {
   resetMotorEncoders();

   while(getRightEncoder() < abs(units)) {
       setDrive(0, voltage);
       pros::delay(10);
   }

   setDrive(0, -10);
   pros::delay(10);

   setDrive(0, 0);
}
