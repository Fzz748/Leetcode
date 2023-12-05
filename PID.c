#include <stdio.h>

typedef struct {
  double setpoint;
  double kp, ki, kd;
  double pre_error;
  double integral;
} PID;

void PID_Init(PID* pid, double setpoint, double kp, double ki, double kd) {
  pid->setpoint = setpoint;
  pid->kp = kp;
  pid->ki = ki;
  pid->kd = kd;
  pid->pre_error = 0;
  pid->integral = 0;
}

double PID_Calculate(PID* pid, double current_value) {
  double error = pid->setpoint - current_value;

  // Proportional term
  double Pout = pid->kp * error;

  // Integral term
  pid->integral += error;
  double Iout = pid->ki * pid->integral;

  // Derivative term
  double derivative = error - pid->pre_error;
  double Dout = pid->kd * derivative;

  // Calculate total output
  double output = Pout + Iout + Dout;

  // Save error to next loop
  pid->pre_error = error;

  return output;
}

int main() {
  PID pid;
  PID_Init(&pid, 1.0, 1.8, 0, 0.2);
  double current_value = 0.5;
  double control_value = PID_Calculate(&pid, current_value);
  printf("Control value: %f\n", control_value);
  return 0;
}