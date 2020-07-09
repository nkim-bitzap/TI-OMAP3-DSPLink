/* 
 *  Copyright (c) 2008 Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 * 
 *  Contributors:
 *      Texas Instruments - initial implementation
 * 
 * */
/*!
 *  ======== Arm9.xdc ========
 *  TI Arm9 little endian target
 */
metaonly module Arm9 inherits ti.targets.arm.IArm {
    override readonly config string name        = "Arm9"; 
    override readonly config string suffix      = "9";
    override readonly config string isa         = "v5T";    
    override readonly config string rts         = "ti.targets.arm.rtsarm";

    override readonly config xdc.bld.ITarget.Module base = ti.targets.TMS470;

    override readonly config xdc.bld.ITarget.Model model = {
        endian: "little"
    };

    /*
     *  ======== compatibleSuffixes ========
     */
    override config String compatibleSuffixes[] = ["7", "470", "9t"];

    override readonly config ti.targets.ITarget.Command cc = {
        cmd:  "cl470 -c",
        opts: "-me -mv5e --abi=ti_arm9_abi"
    };

    override readonly config ti.targets.ITarget.Command asm = {
        cmd:  "cl470 -c",
        opts: "-me -mv5e --abi=ti_arm9_abi"
    };

    override readonly config ti.targets.ITarget.Command lnk = {
        cmd:  "lnk470",
        opts: "--silicon_version=5e --strict_compatibility=on"
    };

    /*!
     *  ======== linkLib ========
     *  Default TMS470 cgtools runtime library to link with executable
     *  (comes from $rootDir/lib)
     */
    config string linkLib = "rts32e.lib";    
}
/*
 *  @(#) ti.targets.arm; 2, 0, 1, 0,189; 12-18-2009 11:42:08; /db/ztree/library/trees/xdctargets/xdctargets-b30x/src/
 */

