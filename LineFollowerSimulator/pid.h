#ifndef PID_H
#define PID_H

#include "utils.h"

struct PID
{
public:
    float k_p, k_i, k_d; // pid consts
    float e_d; // last error
    float e_i; // sum of errors
    float o_min, o_max; // output limits

    // I'm making these public mostly because I'm lazy
public:
    float compute(float err);
    void set(float,float,float);
    PID(float k_p, float k_i, float k_d, float o_min = 0.0, float o_max = 1.0);
};

#endif // PID_H
