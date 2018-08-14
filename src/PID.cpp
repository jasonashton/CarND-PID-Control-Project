#include "PID.h"
#include <algorithm>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
  p_error = cte;
  i_error += cte;

  d_error = cte - prev_cte;
  prev_cte = cte;
}

double PID::TotalError() {
  return p_error * Kp_ + i_error * Ki_ + d_error * Kd_;
}

