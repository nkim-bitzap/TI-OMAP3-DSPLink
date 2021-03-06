/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *  @(#) DSP/BIOS_Kernel 5,2,5,44 09-06-2012 (cuda-u44)
 */
/*
 *  ======== dov.h ========
 *  Stacking "OVerlap" Device
 *
 */

#ifndef DOV_
#define DOV_

#include <dev.h>
#include <fxn.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DOV_Config {
    Char        INITIAL;
} DOV_Config;

extern DOV_Config *DOV;

#define DOV_init        ((Fxn)FXN_F_nop)

extern DEV_Fxns DOV_FXNS;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* DOV_ */
