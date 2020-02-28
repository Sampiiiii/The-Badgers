#include "main.h"

void ElevMotor(int speed) {
  elev_motor = speed;
}

void setElevMotors() {
  int speed = 40 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
  ElevMotor(speed);
}
