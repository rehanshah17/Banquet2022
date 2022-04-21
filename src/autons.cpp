#include "main.h"

okapi::Motor clampO(2);
void right20()
{
  clampMove(90);
  pidTranslate(1340.0, 127);
  clampMove(-90);
  pros::delay(100);
  pidTranslate(-1200,127);
}

void right40(){
  clampMove(90);
  pidTranslate(1340.0, 127);
  clampMove(-90);
  pros::delay(100);
  pidTranslate(-765,127);
  clampMove(90);
  turn(-110,127);
  pidTranslate(250,127);


}

void clampMove(int degree){
  clampO.moveAbsolute(degree,70);
}

void left(){
  clampMove(90);
  pidTranslate(1340.0, 127);
  clampMove(-90);
  pros::delay(100);
  pidTranslate(-1300,127);
}

void progSkills() {
  pidTranslate(500.0, 127);
}
