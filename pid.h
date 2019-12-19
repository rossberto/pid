/** @file pid.h
 *
 * @brief A description of the module’s purpose.
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2018 Barr Group.  All rights reserved.
 */

#ifndef PID_H
#define PID_H

typedef float Float;

typedef struct {
  Float prevUi;
  Float prevUd;
  Float prevE;
  Float Ki;
  Float Kp;
  Float Kd;
  Float Ts;
  Float N;
} ControlInstance;

void newPID(ControlInstance *control, Float Kp, Float Ki, Float Kd, Float Ts, Float N);
Float computePID(Float y, Float r, ControlInstance *control);

#endif /* MODULE_H */
