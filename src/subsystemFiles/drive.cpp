#include "main.h"
#include "math.h"

//"Helper" Functions
void setDrive(int left, int right){
  back_left_motor = left;
  back_right_motor = right;
  front_left_motor = left;
  front_right_motor = right;
}

void resetDriveEncoders() {
  back_left_motor.tare_position();
  back_right_motor.tare_position();
  front_left_motor.tare_position();
  front_right_motor.tare_position();
}

double averageDriveEncoderValue() {
  return fabs((back_left_motor.get_position() + back_right_motor.get_position() + front_left_motor.get_position() + front_right_motor.get_position()) / 4);
}

// OpControl Functions
void setDriveMotors(){
  int drive = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int turning = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
  int right = drive - turning;
  int left = drive + turning;
  setDrive(left, right);
}

//Autonomous functions
void translate(int units, int voltage){
    // Work out direction, based on the units
  int direction = abs(units) / units; //Either 1(forward) or -1(backwards)

  //reset motor encoders
  resetDriveEncoders();

  /*
  double max_raw_value = std::max(front_left,std::max(back_left,std::max(front_right, std::max(back_right, 100.0))));

  front_left = front_left / max_raw_value * 100;
  back_left = back_left / max_raw_value * 100;
  front_right = front_right / max_raw_value * 100;
  back_right = back_right / max_raw_value * 100;
  */
  //drive forward until units are reached
  while(averageDriveEncoderValue() < abs(units)) {
    setDrive(voltage * direction, voltage * direction);
    pros::delay(10);
  }

  //brief brake
  pros::delay(100); //Test this value

  //set drive back to neutral
  setDrive(0,0);
}
