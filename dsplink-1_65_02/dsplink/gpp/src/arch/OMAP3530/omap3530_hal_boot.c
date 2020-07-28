/** ============================================================================
 *  @file   omap3530_hal_boot.c
 *
 *  @path   $(DSPLINK)/gpp/src/arch/OMAP3530/
 *
 *  @desc   Boot control module.
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
#include <omap3530_hal.h>
#include <omap3530_hal_boot.h>


#if defined (__cplusplus)
extern "C" {
#endif


/** ============================================================================
 *  @macro  COMPONENT_ID
 *
 *  @desc   Component and Subcomponent Identifier.
 *  ============================================================================
 */
#define  COMPONENT_ID       ID_ARCH_HAL_BOOT


/** ============================================================================
 *  @macro  SET_FAILURE_REASON
 *
 *  @desc   Sets failure reason.
 *  ============================================================================
 */
#if defined (DDSP_DEBUG)
#define SET_FAILURE_REASON   TRC_SetReason (status, FID_C_ARCH_HAL_BOOT, __LINE__)
#else
#define SET_FAILURE_REASON
#endif /* if defined (DDSP_DEBUG) */


/*  ============================================================================
 *  @const  CONTROL_IVA2_BOOTADDR_OFFSET,
 *          CONTROL_IVA2_BOOTMOD_OFFSET
 *
 *  @desc   Offsets of the DSP BOOT ADDR register
 *  ============================================================================
 */
#define CONTROL_IVA2_BOOTADDR_OFFSET  0x190
#define CONTROL_IVA2_BOOTMOD_OFFSET   0x194


/*******************************************************************************
  @func  OMAP3530_halBootCtrl
  @desc  DSP Boot controller
*******************************************************************************/

NORMAL_API DSP_STATUS OMAP3530_halBootCtrl(IN Pvoid halObj,
                                           IN DSP_BootCtrlCmd cmd,
                                           IN OUT Pvoid arg)
{
  DSP_STATUS status = DSP_SOK;
  OMAP3530_HalObj *halObject = NULL;

  TRC_3ENTER("OMAP3530_halBootCtrl", halObj, cmd, arg);

  DBC_Require(NULL != halObj);

  halObject = (OMAP3530_HalObj*) halObj;

  switch (cmd) {
    case DSP_BootCtrlCmd_SetEntryPoint:
    {
      /* Set the boot address */
      REG(halObject->generalCtrlBase + CONTROL_IVA2_BOOTADDR_OFFSET) =
        ((Uint32)arg & 0xFFFFFC00);


      /* Set the boot mode */
      REG(halObject->generalCtrlBase + CONTROL_IVA2_BOOTMOD_OFFSET) =
        (Uint32) 0;

      break;
    }

    case DSP_BootCtrlCmd_SetBootComplete:
    {
      /* Do nothing here for OMAP3530 gem */
      break;
    }

    case DSP_BootCtrlCmd_ResetBootComplete:
    {
       /* Do nothing here for OMAP3530 gem */
       break;
    }

    default:
    {
      /* Unsupported interrupt control command */
      status = DSP_EINVALIDARG;
      SET_FAILURE_REASON;
      break;
    }
  }

  TRC_1LEAVE("OMAP3530_halBootCtrl", status);
  return status;
}


#if defined (__cplusplus)
}
#endif
