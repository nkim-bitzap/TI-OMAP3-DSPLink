/** ============================================================================
 *  @file   da8xxgem_hal_boot.h
 *
 *  @path   $(DSPLINK)/gpp/src/inc/sys/arch/DA8XXGEM/
 *
 *  @desc   Hardware Abstraction Layer for Primus Boot controller.
 *          Defines the Platform specific HAL (Hardware Abstraction Layer)
 *          object.
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


#if !defined (DA8XXGEM_HAL_BOOT_H)
#define DA8XXGEM_HAL_BOOT_H


/*  ----------------------------------- DSP/BIOS Link               */
#include <dsplink.h>


#if defined (__cplusplus)
extern "C" {
#endif


/** ============================================================================
 *  @func   DA8XXGEM_halBootCtrl
 *
 *  @desc   Boot controller.
 *
 *  @arg    halObj.
 *              Pointer to HAL object.
 *  @arg    cmd.
 *              Command.
 *  @arg    arg.
 *              Command specific arguments.
 *
 *  @ret    DSP_SOK
 *              Operation successfully completed.
 *          DSP_EINVALIDARG
 *              Unsupported interrupt control command.
 *
 *  @enter  None.
 *
 *  @leave  None.
 *
 *  @see    None
 *  ============================================================================
 */
NORMAL_API
DSP_STATUS
DA8XXGEM_halBootCtrl (IN         Pvoid           halObj,
                      IN         DSP_BootCtrlCmd cmd,
                      IN OUT     Pvoid           arg) ;

#if defined (__cplusplus)
}
#endif


#endif  /* !defined (DA8XXGEM_HAL_BOOT_H) */
