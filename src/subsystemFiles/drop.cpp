#include "main.h"

void dropMotor(int speed){
  drop_motor = speed;
}

void setDropMotor(){
  int speed = 80 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT));
  dropMotor(speed);
}
