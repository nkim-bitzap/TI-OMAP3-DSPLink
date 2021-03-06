/** ============================================================================
 *  @file   CFG_ARM.c
 *
 *  @path   $(DSPLINK)/config/all/
 *
 *  @desc   Defines the configuration information for GPP - ARM9.
 *
 *  @ver    1.65.02.09
 *  ============================================================================
 *  Copyright (C) 2002-2012, Texas Instruments Incorporated -
 *  http://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  
 *  *  Neither the name of Texas Instruments Incorporated nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  ============================================================================
 */


/*  ----------------------------------- DSP/BIOS LINK Headers       */
#include <dsplink.h>
#include <procdefs.h>


#if defined (__cplusplus)
EXTERN "C" {
#endif /* defined (__cplusplus) */


/** ============================================================================
 *  @name   LINKCFG_gppOsObject
 *
 *  @desc   Extern declaration for the OS-specific configuration object.
 *          NOTE: This object is defined in the GPP OS-specific configuration
 *          file CFG_<GPPOS>.c.
 *          The type of this object is also OS-specific and is defined in
 *          linkcfgdefs_os.h for each GPP OS.
 *  ============================================================================
 */
extern LINKCFG_GppOs LINKCFG_gppOsObject ;


/** ============================================================================
 *  @name   LINKCFG_gppObject
 *
 *  @desc   Configuration object for the GPP.
 *  ============================================================================
 */
LINKCFG_Gpp  LINKCFG_gppObject = {
    "ARM9",                                   /* NAME           : Name of the GPP */
    16,                                       /* MAXMSGQS       : Maximum MSGQs that can be opened */
    16,                                       /* MAXCHNLQUEUE   : Maximum Queue Length for all channels */
    (Uint32) -1,                              /* POOLTABLEID    : ID of the POOL table (-1 if not needed) */
    0,                                        /* NUMPOOLS       : Number of POOLs supported */
    (LINKCFG_GppOs *) &LINKCFG_gppOsObject    /* GPPOSOBJECT    : Pointer to GPP OS object */
} ;


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

