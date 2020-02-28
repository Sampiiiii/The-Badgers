#include "main.h"

//"Helper" Motors
void setPickupMotors(int speed) {
  left_pickup_motor = speed;
  right_pickup_motor = speed;
}

void pickup(){
  int speed = 100 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
  setPickupMotors(speed);
}
