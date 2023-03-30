#include <iostream>
#include "ap_int.h"
#include "modulator.h"
using namespace std;
ap_uint<1> pwm_out; // pulse width modulated signal
int main(int argc, char **argv)
{
for (int i = 0; i < 4; i ++)
modulator(0, &pwm_out);
for (int i = 0; i < 16; i ++)
modulator(1, &pwm_out);
return 0;
}
