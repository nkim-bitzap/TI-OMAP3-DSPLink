/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *  @(#) DSP/BIOS_Kernel 5,2,5,44 09-06-2012 (cuda-u44)
 */
/*
 *  ======== utl_putc.c ========
 *
 *  Utility functions for working with the trace buffer.
 *
 */

#pragma CODE_SECTION(UTL_doPutc, ".bios")

#include <std.h>
#include <sys.h>
#include <string.h>
#include <utl.h>

#ifdef _6x_
#define FAR far
#else
#define FAR
#endif

/*
 *  ======== UTL_doPutc ========
 */

Void UTL_doPutc(Char c)
{
    static Char FAR *cptr = (Char *)&SYS_PUTCBEG;
    static Char FAR *cbeg = (Char *)&SYS_PUTCBEG;
    static Char FAR *cend = (Char *)&SYS_PUTCEND;

    *cptr++ = c;
    if (cptr >= cend) {
        cptr = cbeg;
    }
}


