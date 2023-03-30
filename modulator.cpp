#include "ap_int.h"
#include "math.h"
#include "modulator.h"
// function that calculates sine wave samples value
void init_sine_table(ap_uint<width> *sine)
{
float temp;
init_sine: for (int i = 0; i < sine_samples; i ++)
// sin (2*pi*i / N) * (2^(width-1) - 1) + 2^(width-1) - 1, N = 2^depth
sine[i] = (ap_uint<width>)(sin(2*3.14*i/sine_samples)*(sine_ampl/2.0-1.0)+sine_ampl/2.0-1.0);
}
//   generator
void modulator(
ap_uint<1> sw0, // switch used for selecting frequency
ap_uint<1> *pwm_out) // pointer to   output
{
static ap_uint<depth> counter = 0; // counter for sine wave sample counting
static ap_uint<width> sine[sine_samples]; // samples of the sine wave signal
// sine table initialization
init_sine_table(sine);
// hold pwm_out high for specified number of clock cycles
onloop: for (ap_uint<20> j = 0; j < (ap_uint<20>)(period[sw0]*sine[counter]); j++)
{
*pwm_out = 1;
}
// hold pwm_out low for specified number of clock cycles
offloop: for (ap_uint<20> j = 0; j < (ap_uint<20>)(period[sw0]*(sine_ampl - sine[counter])); j++)
{
*pwm_out = 0;
}
counter++;
}
