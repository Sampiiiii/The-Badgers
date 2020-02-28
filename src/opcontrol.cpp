#include "main.h"

void opcontrol(){
  while (true) {
    setDriveMotors();
    pickup();
    setElevMotors();
    setDropMotor();
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
      autonomous();
      opcontrol();
    }
  }
}
