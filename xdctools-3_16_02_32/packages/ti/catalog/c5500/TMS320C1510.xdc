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
 *  ======== TMS320C1510.xdc ========
 *
 */
package ti.catalog.c5500;

/*!
 *  ======== TMS320C1510 ========
 *  The C1510 device data sheet module.
 *
 *  This module implements the xdc.platform.ICpuDataSheet interface and is 
 *  used by platforms to obtain "data sheet" information about this device.
 */
metaonly module TMS320C1510 inherits IOMAP
{
instance:
    override config string   cpuCoreRevision = "1.0";
};
/*
 *  @(#) ti.catalog.c5500; 1, 0, 0, 0,214; 12-9-2009 17:22:33; /db/ztree/library/trees/platform/platform-k27x/src/
 */

