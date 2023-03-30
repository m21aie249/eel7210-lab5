#ifndef __PWM_H__
#define __PWM_H__
#include "ap_int.h"
#include <cmath>
using namespace std;
#define depth 8 // the number of bits used to represent sample count of sine wave
#define width 12 // the number of bits used to represent amplitude value
#define sine_samples 256 // maximum number of samples in one period of the signal
#define sine_ampl 4096 // maximum amplitude value of the sine wave
#define refclk_frequency 100000000 // reference clock frequency (100 MHz)
#define freq_low 1 // first frequency for the PWM signal, specified in Hz
#define freq_high 10 // second frequency for the PWM signal, specified in Hz
// minimum duration of high value of pwm signal for two different frequencies
const float period[2] = {(float)(refclk_frequency/(sine_ampl*sine_samples*freq_low)),
(float)(refclk_frequency/(sine_ampl*sine_samples*freq_high))};
// Prototype of top level function for C-synthesis
void modulator(
ap_uint<1> sw0, // switch used for selecting frequency
ap_uint<1> *pwm_out); // pointer to pwm output
#endif
