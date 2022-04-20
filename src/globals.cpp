#include "main.h"

// 1: Ports    2: Gearset (Red, Green, Blue) 3: Asks if reversed or not (true if reversed)   4. Encode units to degrees
pros::Motor frontRight(3, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor backRight(5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor frontLeft(8, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor backLeft(6, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Motor lift(4, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor lift2(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Motor clamp(11,pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor backLift(13,pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_ROTATIONS);

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);
