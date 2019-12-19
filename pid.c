#include <stdio.h>
#include "pid.h"

int main(void) {
  ControlInstance control1;

  newPID(&control1, -1.1, -2.2, -3.3, 0.1, 50);

  Float result = computePID(2, 1, &control1);
  printf("k=0 -> %f\n", result);

  result = computePID(1.5, 1, &control1);
  printf("k=1 -> %f\n", result);

  result = computePID(1.2, 1, &control1);
  printf("k=2 -> %f\n", result);

  return 0;
}

void newPID(ControlInstance *control, Float Kp, Float Ki, Float Kd, Float Ts, Float N) {
  printf("Kp = %f, Ki = %f, Kd = %f and Ts = %f \n", Kp, Ki, Kd, Ts);
  control->Kp = Kp;
  control->Ki = Ki;
  control->Kd = Kd;
  control->Ts = Ts;
  control->N = N;
  control->prevUi = 0;
  control->prevUd = 0;
  control->prevE = 0;
}


Float computePID(Float y, Float r, ControlInstance *control) {
  Float e = r - y;

  Float up = e * control->Kp;
  Float ui = (control->Ki * control->Ts) * e + control->prevUi;
  Float ud = control->Kd * control->N * (e - control->prevE)/(1 + control->N * control->Ts) + control->prevUd;

  control->prevUi = ui;
  control->prevUd = ud;
  control->prevE = e;

  return up + ui + ud;
}
