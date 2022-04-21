#include "main.h"

okapi::Motor clampO(17);
void right()
{
  clampDown(90);
  pidTranslate(1200.0, 127);
  pros::delay(3000);
  clampDown(-90);
}

void clampDown(int degree){
clampO.moveAbsolute(degree,70);
}

void left(){

}

void progSkills() {
  pidTranslate(500.0, 127);
}
