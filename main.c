

/**
 * main.c
 */



//#include "IQmathCPP.h"

//#include "svgen_mf.h"
#include "main.h"
typedef struct {
    int freq;   /* Frequency input Q15 */
    int fl;     /* Freq below which vout=vmin:Q15 Input  */
    int fh;     /* Freq above which vout=vmax Q15 Input  */
    int slope;  /* Slope of the Vhz profile:  Q15 Input  */
    int vmax;   /* Voltage output above fmax  Q15 Input  */
    int vmin;   /* Voltage output below fmin  Q15 Input  */
    int vout;   /* Computed output voltage    Q15 Output */
    int (*calc)();  /* Ptr to the calculation function   */
} VHZPROFILE;

//void DeviceInit();
//SVGENMF sv1=SVGEN_DEFAULTS;  /* Instance the first object */
//SVGENMF sv2 =SVGEN_DEFAULTS;  /* Instance the second object*/
//VHZPROFILE vhz1 = DEFAULT_PROFILE;
//VHZPROFILE vhz2 = DEFAULT_PROFILE;

VHZPROF vhz1 = VHZPROF_DEFAULTS;
int main(void){
//    DeviceInit();
    vhz1.LowFreq = _IQ(0.2);
       vhz1.HighFreq = _IQ(0.5);
       vhz1.FreqMax = _IQ(1);
       vhz1.VoltMax = _IQ(0.95);
       vhz1.VoltMin = _IQ(0.2);
	return 0;
}
void interrupt periodic_interrupt_isr(){
    VHZ_PROF_MACRO(vhz1);
    printf("V: %d\nHz: %d", vhz1.VoltOut, vhz1.Freq);
}
