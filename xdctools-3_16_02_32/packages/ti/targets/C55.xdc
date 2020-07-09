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
/*
 *  ======== C55.xdc ========
 *
 */

/*!
 *  ======== C55 ========
 *  TI C55 target
 */
metaonly module C55 inherits ti.targets.ITarget {
    override readonly config string name                = "C55";        
    override readonly config string suffix              = "55";
    override readonly config string isa                 = "55"; 
    override readonly config xdc.bld.ITarget.Model model= {
        endian: "big"
    };
    override readonly config string rts                 = "ti.targets.rts5500";

    override readonly config ITarget.Command ar = {
        cmd: "ar55",
        opts: "rq"
    };

    override readonly config ITarget.Command cc = {
        cmd: "cl55 -c",
        opts: ""
    };

    override readonly config ITarget.Command vers = {
        cmd: "cl55",
        opts: ""
    };

    override readonly config ITarget.Command asm = {
        cmd: "cl55 -c",
        opts: ""
    };

    override readonly config ITarget.Command lnk = {
        cmd: "lnk55",
        opts: ""
    };

    /*!
     *  ======== asmOpts ========
     *  User configurable assembler options.
     *
     *  Defaults:
     *  @p(dlist)
     *      -`-qq`
     *          super quiet mode
     */
    override config ITarget.Options asmOpts = {
        prefix: "-qq",
        suffix: ""
    };

    /*!
     *  ======== ccOpts ========
     *  User configurable compiler options.
     *
     *  Defaults:
     *  @p(dlist)
     *      -`-qq`
     *          super quiet mode
     *      -`-pdsw225`
     *          generate a warning for implicitly declared functions; i.e.,
     *          functions without prototypes
     *      -`-Dfar= `
     *          ignore keyword far; this allows one to write code that can
     *          be compiled in large model and small model without #ifdef's
     */
    override config ITarget.Options ccOpts = {
        prefix: "-qq -pdsw225 -Dfar= ",
        suffix: ""
    };

    /*!
     *  ======== lnkOpts ========
     *  User configurable linker options.
     *
     *  Defaults:
     *  @p(dlist)
     *      -`-w`
     *          Display linker warnings
     *      -`-q`
     *          Quite run
     *      -`-u`
     *          Place unresolved external symbol into symbol table
     *      -`-c`
     *          ROM autoinitialization model
     *      -`-m`
     *          create a map file
     *      -`-l`
     *          archive library file as linker input
     */
    override config ITarget.Options lnkOpts = {
        prefix: "-w -q -u _c_int00",
        suffix: "-c -m $(XDCCFGDIR)/$@.map -l $(rootDir)/lib/rts55.lib"
    };

    override config string includeOpts = "-I$(rootDir)/include";

    final override readonly config string sectMap[string] = [
        [".text",     "code"],
        [".stack",    "stack"],
        [".sysstack", "stack"],
        [".bss",      "data"],
        [".cinit",    "code"],
        [".pinit",    "code"],
        [".cio",      "code"],
        [".args",     "data"],
        [".const",    "data"],
        [".data",     "data"],
        [".switch",   "code"],
        [".sysmem",   "code"],
        [".far",      "data"],
        ["vectors",   "data"],
    ];

    override readonly config xdc.bld.ITarget.StdTypes stdTypes = {
        t_IArg          : { size: 2, align: 2 },
        t_Char          : { size: 1, align: 1 },
        t_Double        : { size: 2, align: 2 },
        t_Float         : { size: 2, align: 2 },
        t_Fxn           : { size: 2, align: 2 },
        t_Int           : { size: 1, align: 1 },
        t_Int8          : { size: 1, align: 1 },
        t_Int16         : { size: 1, align: 1 },
        t_Int32         : { size: 2, align: 2 },
        t_Int40         : { size: 4, align: 2 },
        t_Long          : { size: 2, align: 2 },
        t_LDouble       : { size: 2, align: 2 },
        t_LLong         : { size: 4, align: 2 },
        t_Ptr           : { size: 1, align: 1 },
        t_Short         : { size: 1, align: 1 },
    };

    override readonly config Int bitsPerChar = 16;
};
/*
 *  @(#) ti.targets; 1, 0, 3,372; 12-18-2009 11:42:07; /db/ztree/library/trees/xdctargets/xdctargets-b30x/src/
 */

