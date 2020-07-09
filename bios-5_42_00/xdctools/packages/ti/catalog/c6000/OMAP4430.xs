/*
 *  Copyright (c) 2012 by Texas Instruments and others.
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
 *  ======== OMAP4430.xs ========
 *
 */

/*
 *  ======== OMAP4430.getMemoryMap ========
 *  Returns the memory map as seen by a program running on this device
 *  when the registers are set as specified by the regs hash.
 */
function getMemoryMap(regs)
{
    return (this.memMap);
}

/*
 *  ======== instance$meta$init ========
 */
function instance$meta$init()
{

    var HDVICP2 = xdc.useModule("ti.catalog.peripherals.hdvicp2.HDVICP2");

    this.hdvicp0 = HDVICP2.create({ name: "HDVICP0", baseAddr: 0xBA000000, intNum:45});
}
/*
 *  @(#) ti.catalog.c6000; 1, 0, 0, 0,399; 8-17-2012 22:13:34; /db/ztree/library/trees/platform/platform-n27x/src/
 */

