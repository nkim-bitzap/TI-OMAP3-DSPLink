/** ============================================================================
 *  @file   tskMpcsXfer.h
 *
 *  @path   $(DSPLINK)/dsp/src/samples/mpcsxfer/
 *
 *  @desc   Header file for MPCSXFER application.
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


#if !defined (TSKMPCSXFER_)
#define TSKMPCSXFER_


/*  ----------------------------------- DSP/BIOS Headers            */
#include <sem.h>

/*  ----------------------------------- DSP/BIOS LINK Headers       */
#include <mpcs.h>

/*  ----------------------------------- Sample Headers              */
#include <mpcsxfer_config.h>


#if defined (__cplusplus)
extern "C" {
#endif /* defined (__cplusplus) */


/** ============================================================================
 *  @name   TSKMPCSXFER_TransferInfo
 *
 *  @desc   Structure used to keep various information needed by various phases
 *          of the application.
 *
 *  @field  mpcsHandle
 *              Handle to the MPCS object created on the GPP-side.
 *  @field  dataBuf
 *              Pointer to the shared data buffer used by the application.
 *  @field  ctrlBuf
 *              Pointer to the shared control structure used by the application.
 *  @field  notifySemObj
 *              Semaphore used for getting notification of the data and control
 *              buffer pointers allocated by the GPP-side application.
 *  @field  numIterations
 *              Number of iterations of data transfer to be done.
 *  @field  bufferSize
 *              Size of data buffer to be transferred.
 *  ============================================================================
 */
typedef struct TSKMPCSXFER_TransferInfo_tag {
    MPCS_Handle     mpcsHandle ;
    Uint16 *        dataBuf ;
    MPCSXFER_Ctrl * ctrlBuf ;
    SEM_Obj         notifySemObj ;
    Uint32          numIterations ;
    Uint32          bufferSize ;
} TSKMPCSXFER_TransferInfo ;


/** ============================================================================
 *  @func   TSKMPCSXFER_create
 *
 *  @desc   Create phase function of MPCSXFER application.
 *
 *  @arg    transferInfo
 *              Information for transfer.
 *
 *  @ret    SYS_OK
 *              Successful operation.
 *          SYS_EBADIO
 *              Failure occured while doing IO.
 *
 *  @enter  None
 *
 *  @leave  None
 *
 *  @see    None
 *  ============================================================================
 */
Int TSKMPCSXFER_create (TSKMPCSXFER_TransferInfo ** transferInfo) ;

/** ============================================================================
 *  @func   TSKMPCSXFER_execute
 *
 *  @desc   Excecute phase function of MPCSXFER application.
 *
 *  @arg    transferInfo
 *              Information for transfer.
 *
 *  @ret    SYS_OK
 *              Successful operation.
 *          SYS_EBADIO
 *              Failure occured while doing IO.
 *
 *  @enter  None
 *
 *  @leave  None
 *
 *  @see    None
 *  ============================================================================
 */
Int TSKMPCSXFER_execute (TSKMPCSXFER_TransferInfo * transferInfo) ;

/** ============================================================================
 *  @func   TSKMPCSXFER_delete
 *
 *  @desc   Delete phase function of MPCSXFER application.
 *
 *  @arg    transferInfo
 *              Information for transfer.
 *
 *  @ret    SYS_OK
 *              Successful operation.
 *          SYS_EBADIO
 *              Failure occured while doing IO.
 *
 *  @enter  None
 *
 *  @leave  None
 *
 *  @see    None
 *  ============================================================================
 */
Int TSKMPCSXFER_delete (TSKMPCSXFER_TransferInfo * transferInfo) ;


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */


#endif /* !defined (TSKMPCSXFER_) */
