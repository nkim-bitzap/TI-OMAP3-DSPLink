/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *  @(#) DSP/BIOS_Kernel 5,2,5,44 09-06-2012 (cuda-u44)
 */
/*
 *  ======== pmi_init.c ========
 *
 *  PMI module initialization.
 *
 */

#include <pmi.h>

/*
 *  ======== PMI_init ========
 */
PMI_Status PMI_init(void)
{
    PMI_Status status = PMI_OK;
    static unsigned initialized = 0;

    if (initialized == 0) {
        PMI_initPLL(PMI_CPU);
        PMI_initPLL(PMI_PER);
        PMI_initVoltageControl();
        initialized = 1;
    }

    return(status);
}


