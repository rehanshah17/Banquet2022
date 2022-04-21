#include "main.h"

double kP = 0.225;
double kI = 0.0;
double kD = 0.0;

void pidTranslate(double units, int maxV) {
  double direction = abs(units) / units;

  double lastErr = 0.0;
  double err = 0.0;

  double proportion = 0.0;
  double integral = 0.0;
  double derivative = 0.0;

  resetMotorEncoders();

  while(getAvgEncoder() < abs(units)) {
    err = abs(units) - getAvgEncoder();

    proportion = err;
    integral += err;
    derivative = err - lastErr;

    double power = (proportion * kP) + (integral * kI) + (derivative * kD);


    if(abs(power) > maxV)
    {
      setDrive(direction * maxV, direction * maxV);
    } else {
      setDrive(power * direction, power * direction);
    }

    lastErr = err;

    pros::delay(10);
  }

  setDrive(-10 * direction, -10 * direction);
  pros::delay(10);

  setDrive(0, 0);
}

void resetValues()
{
  /*
  proportion = 0.0;
  derivative = 0.0;
  integral = 0.0;
  err = 0.0;
  lastErr = 0.0;*/
}
