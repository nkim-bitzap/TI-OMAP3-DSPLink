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
 *  ======== OMAP3530.xdc ========
 *
 */
package ti.catalog.c6000;

/*!
 *  ======== OMAP3530 ========
 *  OMAP3530 device data sheet module
 *
 *  This module implements the xdc.platform.ICpuDataSheet interface and is 
 *  used by platforms to obtain "data sheet" information about this device.
 */
metaonly module OMAP3530 inherits IOMAP3xxx
{

instance:
    override config string   cpuCoreRevision = "2.1";
};
/*
 *  @(#) ti.catalog.c6000; 1, 0, 0, 0,214; 12-9-2009 17:20:20; /db/ztree/library/trees/platform/platform-k27x/src/
 */

