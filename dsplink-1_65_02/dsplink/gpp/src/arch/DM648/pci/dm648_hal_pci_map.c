/** ============================================================================
 *  @file   dm648_hal_pci_map.c
 *
 *  @path   $(DSPLINK)/gpp/src/arch/DM648/pci/
 *
 *  @desc   MAP control module.
 *
 *  @ver    1.65.02.09
 *  ============================================================================
 *  Copyright (C) 2002-2012, Texas Instruments Incorporated - http://www.ti.com/
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation version 2.
 *  
 *  This program is distributed "as is" WITHOUT ANY WARRANTY of any kind,
 *  whether express or implied; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  General Public License for more details.
 *  ============================================================================
 */


/*  ----------------------------------- DSP/BIOS Link               */
#include <dsplink.h>
#include <_dsplink.h>

/*  ----------------------------------- Trace & Debug               */
#include <_trace.h>
#include <trc.h>
#include <print.h>

/*  ----------------------------------- Hardware Abstraction Layer  */
#include <dm648_hal.h>
#include <dm648_hal_pci.h>
#include <dm648_hal_pci_map.h>


#if defined (__cplusplus)
extern "C" {
#endif


/** ============================================================================
 *  @macro  COMPONENT_ID
 *
 *  @desc   Component and Subcomponent Identifier.
 *  ============================================================================
 */
#define  COMPONENT_ID       ID_ARCH_HAL_MAP


/** ============================================================================
 *  @macro  SET_FAILURE_REASON
 *
 *  @desc   Sets failure reason.
 *  ============================================================================
 */
#if defined (DDSP_DEBUG)
#define SET_FAILURE_REASON   TRC_SetReason (status, FID_C_ARCH_HAL_MAP, __LINE__)
#else
#define SET_FAILURE_REASON
#endif /* if defined (DDSP_DEBUG) */


/** ============================================================================
 *  @func   DM648_halPciMapCtrl
 *
 *  @desc   Mapping controller.
 *
 *  @modif  None.
 *  ============================================================================
 */
NORMAL_API
DSP_STATUS
DM648_halPciMapCtrl (IN      Pvoid           halObj,
                     IN      DSP_MapCtrlCmd  cmd,
                     IN      Uint32          dspBufAddr,
                     IN      Uint32          size,
                     OUT     Uint32 *        bufVirtPtr,
                     OUT     Uint32 *        bufPhysAddr,
                     OUT     Uint32 *        mappedSize)
{
    DSP_STATUS        status    = DSP_SOK ;
    DM648_pciRegs  *  pciRegs   = NULL    ;
    DM648_HalObj  *   halObject = (DM648_HalObj *) halObj ;
    Uint32            availBytes        ;

    TRC_6ENTER ("DM648_halPciMapCtrl",
                halObj,
                cmd,
                dspBufAddr,
                size,
                bufVirtPtr,
                bufPhysAddr) ;

    DBC_Require (NULL != halObject) ;

    pciRegs  = (DM648_pciRegs *) (  halObject->pci.barVirt [CFG_REGS_BAR_NO]
                                   + DM648_PCIREG_BASE
                                   - DM648_BAR2_BASE) ;
    switch (cmd) {
        case DSP_MapCtrlCmd_Map:
        {
            halObject->pci.prevPageAddr = pciRegs->PCIBAR4TRL ;
            pciRegs->PCIBAR4TRL = (dspBufAddr) & (pciRegs->PCIBAR4MSK) ;
            availBytes = (  halObject->pci.barLen [RWMEM_BAR_NO]
                          - (dspBufAddr - pciRegs->PCIBAR4TRL)) ;
             if ((availBytes > 0) && (size > 0)) {
                *bufVirtPtr  = (  halObject->pci.barVirt [RWMEM_BAR_NO]
                                + (dspBufAddr - pciRegs->PCIBAR4TRL));
                *bufPhysAddr = (  halObject->pci.barPhys [RWMEM_BAR_NO]
                                + (dspBufAddr - pciRegs->PCIBAR4TRL));
                /* Return the mapped address  and size even if avail bytes is
                 * less than size
                 */
                 if (availBytes >= size) {
                    *mappedSize = size ;
                 }
                 else {
                    *mappedSize = availBytes ;
                 }
            }
            else {
                status = DSP_ERANGE ;
                SET_FAILURE_REASON ;
            }
        }
        break ;

        case DSP_MapCtrlCmd_Unmap:
        {
            pciRegs->PCIBAR4TRL = halObject->pci.prevPageAddr ;
            halObject->pci.prevPageAddr = (Uint32) NULL ;
        }
        break ;

        case DSP_MapCtrlCmd_SetShared:
        {
            pciRegs->PCIBAR5TRL = dspBufAddr & (pciRegs->PCIBAR5MSK) ;
            availBytes = (  halObject->pci.barLen [SHMEM_BAR_NO]
                          - (dspBufAddr - pciRegs->PCIBAR5TRL)) ;

             if ((availBytes > 0) && (size > 0)) {
                if (availBytes >= size)  {
                    *bufVirtPtr  = (  halObject->pci.barVirt [SHMEM_BAR_NO]
                                    + (dspBufAddr - pciRegs->PCIBAR5TRL)) ;
                    *bufPhysAddr = (  halObject->pci.barPhys [SHMEM_BAR_NO]
                                    + (dspBufAddr - pciRegs->PCIBAR5TRL)) ;
                    *mappedSize = size ;
                }
                else {
                     PRINT_Printf ("Error: Configured shared memory Size is "
                                   "more than the size that can be configured "
                                   "through shared memory BAR %d.\n",
                                   SHMEM_BAR_NO) ;
                    status = DSP_ERANGE ;
                    SET_FAILURE_REASON ;
                }
            }
        }
        break ;

        default:
        {
            /* Unsupported MAP control command */
            status = DSP_EINVALIDARG ;
            SET_FAILURE_REASON ;
        }
        break ;
    }

    TRC_1LEAVE ("DM648_halPciIntCtrl", status) ;

    return status ;
}


#if defined (__cplusplus)
}
#endif
