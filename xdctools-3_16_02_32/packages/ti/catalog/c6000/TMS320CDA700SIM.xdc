/*
 *  Copyright (c) 2009 by Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 *
 * */

/*
 *  ======== TMS320DA700SIM.xdc ========
 *
 */
package ti.catalog.c6000;

/*!
 *  ======== TMS320CDA700SIM ========
 *  The C67P device data sheet module.
 *
 *  This module implements the xdc.platform.ICpuDataSheet interface and is 
 *  used by platforms to obtain "data sheet" information about this device.
 */
metaonly module TMS320CDA700SIM inherits IAntara
{
instance:
    override config string   cpuCore        = "67x+SIM";
};
/*
 *  @(#) ti.catalog.c6000; 1, 0, 0, 0,214; 12-9-2009 17:20:21; /db/ztree/library/trees/platform/platform-k27x/src/
 */

