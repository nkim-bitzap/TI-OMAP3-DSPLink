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
 *  ======== Ducati.xdc ========
 */

/*!
 *  ======== Ducati ========
 *  The Ducati device data sheet module.
 *
 *  This module implements the xdc.platform.ICpuDataSheet interface and is 
 *  used by platforms to obtain "data sheet" information about this device.
 *
 */
metaonly module Ducati inherits ti.catalog.ICpuDataSheet
{
instance:
    override config string cpuCore           = "CM3";
    override config string isa               = "v7M";
    override config string cpuCoreRevision   = "1.0";
    override config int    minProgUnitSize   = 1;
    override config int    minDataUnitSize   = 1;
    override config int    dataWordSize      = 4;

    /*!
     *  ======== memMap ========
     *  The memory map returned be getMemoryMap().
     */
    config xdc.platform.IPlatform.Memory memMap[string] = 
        ti.catalog.arm.nda.Ducati.memMap;
};
/*
 *  @(#) ti.catalog.c470.nda; 1, 0, 0, 0,46; 12-9-2009 17:28:41; /db/ztree/library/trees/platform/platform-k27x/src/
 */

