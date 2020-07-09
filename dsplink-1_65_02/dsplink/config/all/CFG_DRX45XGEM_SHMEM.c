/** ============================================================================
 *  @file   CFG_DRX45XGEM_SHMEM.c
 *
 *  @path   $(DSPLINK)/config/all/
 *
 *  @desc   Defines the configuration information for DSP/BIOS LINK for the
 *          Jacinto platform.
 *
 *  @ver    1.65.02.09
 *  ============================================================================
 *  Copyright (C) 2002-2012, Texas Instruments Incorporated -
 *  http://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  
 *  *  Neither the name of Texas Instruments Incorporated nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  ============================================================================
 */


/*  ----------------------------------- DSP/BIOS LINK Headers       */
#include <dsplink.h>
#include <procdefs.h>


#if defined (__cplusplus)
EXTERN "C" {
#endif /* defined (__cplusplus) */


/** ============================================================================
 *                                DSPLINK MEMORY SECTION DIAGRAM
 *
 *         |--------------[ 0xXXXXXX00 ]---------------------------------|
 *         |                                                             |
 *         |                   RESET VECTOR (0x80)                       |
 *         |               Last two nibbles must be zero                 |
 *         |                                                             |
 *         |-------------------------------------------------------------|
 *         |                                                             |
 *         |                   DSP CODE/DATA                             |
 *         |               DSP executable is loaded to this section      |
 *         |                                                             |
 *         |=============================================================|
 *         |                                                             |
 *         |                   DSPLINK SHARED MEMORY0                    |
 *         |               Shared control structure is loaded here       |
 *         |                                                             |
 *         |-------------------------------------------------------------|
 *         |                                                             |
 *         |                   DSPLINK SHARED MEMORY1                    |
 *         |               Shared control structure is loaded here       |
 *         |                                                             |
 *         |-------------------------------------------------------------|
 *         |                                                             |
 *         |                   POOL Buffer Memory                        |
 *         |               Pool's buffers are created in this area       |
 *         |                                                             |
 *         |-------------------------------------------------------------|
 *
 *  ============================================================================
 */

/** ============================================================================
 *  @name   DRVHANDSHAKEPOLLCOUNT
 *
 *  @desc   POLL Count for Driver handshake.
 *  ============================================================================
 */
#define  DRVHANDSHAKEPOLLCOUNT        ((Uint32) 100000000u)

/** ============================================================================
 *  @name   RESETCTRLADDR
 *
 *  @desc   Indicates the start address of Reset Ctrl memory region.
 *          last two nibbles must be zero i.e. align to 256 boundary.
 *  ============================================================================
 */
#define  RSTENTRYID         0u
#define  RESETCTRLADDR      0x87E00000u
#define  RESETCTRLSIZE      0x0080u

/** ============================================================================
 *  @name   CODEMEMORYADDR/CODEMEMORYSIZE
 *
 *  @desc   Indicates startaddress/size for dsplink code region.
 *  ============================================================================
 */
#define  CODEENTRYID        1u
#define  CODEMEMORYADDR     (RESETCTRLADDR + RESETCTRLSIZE)
#define  CODEMEMORYSIZE     0xFFF80u

/** ============================================================================
 *  @name   SHAREDENTRYID/SHAREDMEMORYADDR/SHAREDMEMORYSIZE
 *
 *  @desc   Indicates startaddress/size for dsplink shared memory region.
 *  ============================================================================
 */
#define  SHAREDENTRYID0     2u
#define  SHAREDMEMORYADDR0  (CODEMEMORYADDR + CODEMEMORYSIZE)
#define  SHAREDMEMORYSIZE0  0x5000u

/** ============================================================================
 *  @name   SHAREDENTRYID/SHAREDMEMORYADDR/SHAREDMEMORYSIZE
 *
 *  @desc   Indicates startaddress/size for dsplink shared memory region.
 *  ============================================================================
 */
#define  SHAREDENTRYID1     3u
#define  SHAREDMEMORYADDR1  (SHAREDMEMORYADDR0 + SHAREDMEMORYSIZE0)
#define  SHAREDMEMORYSIZE1  0x2B000u

/** ============================================================================
 *  @name   POOLMEMORYADDR/POOLMEMORYSIZE
 *
 *  @desc   Indicates startaddress/size for dsplink POOL memory region.
 *  ============================================================================
 */
#define  POOLENTRYID        4u
#define  POOLMEMORYADDR     (SHAREDMEMORYADDR1 + SHAREDMEMORYSIZE1)
#define  POOLMEMORYSIZE     0x000D0000u

/** ============================================================================
 *  @name   LINKCFG_memTable_00
 *
 *  @desc   Memory table ID 0.
 *  ============================================================================
 */
STATIC LINKCFG_MemEntry  LINKCFG_memTable_00 [] =
{
    {
        RSTENTRYID,                        /* ENTRY          : Entry number */
        "RESETCTRL",                       /* NAME           : Name of the memory region */
        RESETCTRLADDR,                     /* ADDRPHYS       : Physical address */
        RESETCTRLADDR,                     /* ADDRDSPVIRT    : DSP virtual address */
        (Uint32) -1u,                      /* ADDRGPPVIRT    : GPP virtual address (if known) */
        RESETCTRLSIZE,                     /* SIZE           : Size of the memory region */
        TRUE,                              /* SHARED         : Shared access memory? */
        FALSE,                             /* SYNCD          : Synchornized? */
    },
    {
        CODEENTRYID,                       /* ENTRY          : Entry number */
        "DDR",                             /* NAME           : Name of the memory region */
        CODEMEMORYADDR,                    /* ADDRPHYS       : Physical address */
        CODEMEMORYADDR,                    /* ADDRDSPVIRT    : DSP virtual address */
        (Uint32) -1u,                      /* ADDRGPPVIRT    : GPP virtual address (if known) */
        CODEMEMORYSIZE,                    /* SIZE           : Size of the memory region */
        TRUE,                              /* SHARED         : Shared access memory? */
        FALSE,                             /* SYNCD          : Synchornized? */
    },
    {
        SHAREDENTRYID0,                   /* ENTRY          : Entry number */
        "DSPLINKMEM",                     /* NAME           : Name of the memory region */
        SHAREDMEMORYADDR0,                /* ADDRPHYS       : Physical address */
        SHAREDMEMORYADDR0,                /* ADDRDSPVIRT    : DSP virtual address */
       (Uint32) -1u,                      /* ADDRGPPVIRT    : GPP virtual address (if known) */
        SHAREDMEMORYSIZE0,                /* SIZE           : Size of the memory region */
        TRUE,                             /* SHARED         : Shared access memory? */
        FALSE,                            /* SYNCD          : Synchornized? */
    },
    {
        SHAREDENTRYID1,                   /* ENTRY          : Entry number */
        "DSPLINKMEM1",                    /* NAME           : Name of the memory region */
        SHAREDMEMORYADDR1,                /* ADDRPHYS       : Physical address */
        SHAREDMEMORYADDR1,                /* ADDRDSPVIRT    : DSP virtual address */
        (Uint32) -1u,                     /* ADDRGPPVIRT    : GPP virtual address (if known) */
        SHAREDMEMORYSIZE1,                /* SIZE           : Size of the memory region */
        TRUE,                             /* SHARED         : Shared access memory? */
        FALSE,                            /* SYNCD          : Synchornized? */
    },
    {
        POOLENTRYID,                       /* ENTRY          : Entry number */
        "POOLMEM",                         /* NAME           : Name of the memory region */
        POOLMEMORYADDR,                    /* ADDRPHYS       : Physical address */
        POOLMEMORYADDR,                    /* ADDRDSPVIRT    : DSP virtual address */
        (Uint32) -1u,                      /* ADDRGPPVIRT    : GPP virtual address (if known) */
        POOLMEMORYSIZE,                    /* SIZE           : Size of the memory region */
        TRUE,                              /* SHARED         : Shared access memory? Logically */
        FALSE,                             /* SYNCD          : Synchornized? */
    },
    {
        5u,                                /* ENTRY          : Entry number */
        "DSPIRAM",                         /* NAME           : Name of the memory region */
        0x11800000u,                       /* ADDRPHYS       : Physical address */
        0x11800000u,                       /* ADDRDSPVIRT    : DSP virtual address */
        (Uint32) -1l,                      /* ADDRGPPVIRT    : GPP virtual address (if known) */
        0x10000u,                          /* SIZE           : Size of the memory region */
        TRUE,                              /* SHARED         : Shared access memory? */
        FALSE,                             /* SYNCD          : Synchornized? */
    },
    {
        6u,                                /* ENTRY          : Entry number */
        "DSPL1DRAM",                       /* NAME           : Name of the memory region */
        0x11F04000u,                       /* ADDRPHYS       : Physical address */
        0x11F04000u,                       /* ADDRDSPVIRT    : DSP virtual address */
        (Uint32) -1l,                      /* ADDRGPPVIRT    : GPP virtual address (if known) */
        0xC000u,                           /* SIZE           : Size of the memory region */
        TRUE,                              /* SHARED         : Shared access memory? */
        FALSE,                             /* SYNCD          : Synchornized? */
    }
} ;

/** ============================================================================
 *  @name   LINKCFG_memTables
 *
 *  @desc   Array of memory tables in the system.
 *  ============================================================================
 */
STATIC LINKCFG_MemEntry * LINKCFG_memTables [] =
{
    LINKCFG_memTable_00         /* Memory Table 0 */
} ;

/** ============================================================================
 *  @name   LINKCFG_ipsTable_00
 *
 *  @desc   IPS table ID 0.
 *  ============================================================================
 */
STATIC LINKCFG_Ips  LINKCFG_ipsTable_00 [] =
{
    {
        "IPS",                  /* NAME           : Name of the Inter-Processor-Signaling component */
        (Uint32) 32u,           /* NUMIPSEVENTS   : Number of IPS events to be supported */
        SHAREDENTRYID0,         /* MEMENTRY       : Memory entry ID (-1 if not needed) */
        (Uint32) 49u,           /* GPPINTID       : Interrupt no. to used by the IPS on GPP-side. (-1 if uni-directional to DSP) */
        (Uint32) 16u,           /* DSPINTID       : Interrupt no. to used by the IPS on DSP-side. (-1 if uni-directional to GPP) */
        (Uint32) 4u,            /* DSPINTVECTORID : Interrupt vector no. to used by the IPS on DSP-side. (-1 if uni-directional to GPP) */
        (Uint32) 50000000u,     /* ARGUMENT1      : Poll value for which IPS waits while sending event (-1 if infinite) */
        0u                      /* ARGUMENT2      : Second IPS-specific argument */
    },
    {
        "IPS",                  /* NAME           : Name of the Inter-Processor-Signaling component */
        (Uint32) 32u,           /* MAXIPSEVENTS   : Number of IPS events to be supported */
        SHAREDENTRYID1,         /* MEMENTRY       : Memory entry ID (-1 if not needed) */
        (Uint32) 50u,           /* GPPINTID       : Interrupt no. to used by the IPS on GPP-side. (-1 if uni-directional to DSP) */
        (Uint32) 17u,           /* DSPINTID       : Interrupt no. to used by the IPS on DSP-side. (-1 if uni-directional to GPP) */
        (Uint32) 5u,            /* DSPINTVECTORID : Interrupt vector no. to used by the IPS on DSP-side. (-1 if uni-directional to GPP) */
        (Uint32) 50000000u,     /* ARGUMENT1      : Poll value for which IPS waits while sending event (-1 if infinite) */
        0u                      /* ARGUMENT2      : Second IPS-specific argument */
    }
} ;

/** ============================================================================
 *  @name   LINKCFG_ipsTables
 *
 *  @desc   Array of IPS tables in the system.
 *  ============================================================================
 */
STATIC LINKCFG_Ips * LINKCFG_ipsTables [] =
{
    LINKCFG_ipsTable_00         /* IPS Table 0 */
} ;

/** ============================================================================
 *  @name   LINKCFG_poolTable_00
 *
 *  @desc   Pool table ID 0.
 *  ============================================================================
 */
STATIC LINKCFG_Pool  LINKCFG_poolTable_00 [] =
{
    {
        "SMAPOOL",              /* NAME           : Name of the pool */
        SHAREDENTRYID1,         /* MEMENTRY       : Memory entry ID (-1 if not needed) */
        (Uint32) POOLMEMORYSIZE,      /* POOLSIZE       : Size of the pool (-1 if not needed) */
        (Uint32) -1l,           /* IPSID          : ID of the IPS used */
        (Uint32) -1l,           /* IPSEVENTNO     : IPS Event number associated with POOL */
        POOLENTRYID,            /* POOLMEMENTRY   : Pool memory region section ID  */
        0x0u,                   /* ARGUMENT1      : First Pool-specific argument */
        0x0u                    /* ARGUMENT2      : Second Pool-specific argument */
    }
} ;

/** ============================================================================
 *  @name   LINKCFG_poolTables
 *
 *  @desc   Array of Pool tables in the system.
 *  ============================================================================
 */
STATIC LINKCFG_Pool * LINKCFG_poolTables [] =
{
    LINKCFG_poolTable_00       /* Pool Table 0 */
} ;

/** ============================================================================
 *  @name   LINKCFG_dataTable_00
 *
 *  @desc   Data driver table ID 0.
 *  ============================================================================
 */
STATIC LINKCFG_DataDrv  LINKCFG_dataTable_00 [] =
{
    {
        "ZCPYDATA",             /* NAME           : Name of the data driver */
        0u,                     /* BASECHANNELID  : Base channel ID for the driver */
        16u,                    /* NUMCHANNELS    : Number of channels supported */
        16384u,                 /* MAXBUFSIZE     : Maximum size of buffer supported (-1 if no limit) */
        SHAREDENTRYID1,         /* MEMENTRY       : Memory entry ID (-1 if not needed) */
        0u,                     /* POOLID         : Pool id for allocating buffers */
        1u,                     /* QUEUELENGTH    : Queue length for the data driver */
        1u,                     /* IPSID          : ID of the IPS used */
        1u,                     /* IPSEVENTNO     : IPS Event number associated with data Driver */
        0x0u,                   /* ARGUMENT1      : First data driver specific argument */
        0x0u                    /* ARGUMENT2      : Second data driver specific argument */
    }
} ;

/** ============================================================================
 *  @name   LINKCFG_dataTables
 *
 *  @desc   Array of Data driver tables in the system.
 *  ============================================================================
 */
STATIC LINKCFG_DataDrv * LINKCFG_dataTables [] =
{
    LINKCFG_dataTable_00        /* Data Table 0 */
} ;

/** ============================================================================
 *  @name   LINKCFG_mqtObjects
 *
 *  @desc   Array of Message Queue Transport objects in the system.
 *  ============================================================================
 */
STATIC LINKCFG_Mqt  LINKCFG_mqtObjects [] =
{
    {
        "ZCPYMQT",              /* NAME           : Name of the Message Queue Transport */
        SHAREDENTRYID1,         /* MEMENTRY       : Memory entry ID (-1 if not needed) */
        (Uint32) -1l,           /* MAXMSGSIZE     : Maximum message size supported (-1 if no limit) */
        1u,                     /* IPSID          : ID of the IPS used */
        0u,                     /* IPSEVENTNO     : IPS Event number associated with MQT */
        0x0u,                   /* ARGUMENT1      : First MQT-specific argument */
        0x0u                    /* ARGUMENT2      : Second MQT-specific argument */
    }
} ;

/** ============================================================================
 *  @name   LINKCFG_ringIoObjects
 *
 *  @desc   Array of RINGIO objects in the system.
 *  ============================================================================
 */
STATIC LINKCFG_RingIo  LINKCFG_ringIoObjects [] =
{
    {
        "RINGIOTABLE",          /* NAME           : Name of the RingIO Table */
        SHAREDENTRYID0,         /* MEMENTRY       : Memory entry ID (-1 if not needed) */
        64u,                    /* NUMENTRIES     : Number of RingIO entries supported */
        0u,                     /* IPSID          : ID of the IPS used */
        0u                      /* IPSEVENTNO     : IPS Event number associated with RingIO */
    }
} ;

/** ============================================================================
 *  @name   LINKCFG_mplistObjects
 *
 *  @desc   Array of MPLIST objects in the system.
 *  ============================================================================
 */
STATIC LINKCFG_MpList  LINKCFG_mplistObjects [] =
{
    {
        "MPLISTTABLE",          /* NAME           : Name of the MpList Table */
        SHAREDENTRYID1,         /* MEMENTRY       : Memory entry ID (-1 if not needed) */
        64u,                    /* NUMENTRIES     : Number of MpList entries supported */
        (Uint32) -1l,           /* IPSID          : ID of the IPS used */
        (Uint32) -1l            /* IPSEVENTNO     : IPS Event number associated with MpList */
    }
} ;

/** ============================================================================
 *  @name   LINKCFG_mpcsObjects
 *
 *  @desc   Array of MPCS objects in the system.
 *  ============================================================================
 */
STATIC LINKCFG_Mpcs  LINKCFG_mpcsObjects [] =
{
    {
        "MPCS",                 /* NAME           : Name of the MPCS Table */
        SHAREDENTRYID1,         /* MEMENTRY       : Memory entry ID (-1 if not needed) */
        256u,                   /* NUMENTRIES     : Number of MPCS entries supported */
        (Uint32) -1l,           /* IPSID          : ID of the IPS used */
        (Uint32) -1l            /* IPSEVENTNO     : IPS Event number associated with MPCS */
    }
} ;

/** ============================================================================
 *  @name   LINKCFG_gppObject
 *
 *  @desc   Configuration object for the GPP.
 *  ============================================================================
 */
STATIC LINKCFG_Log  LINKCFG_logObject = {
    FALSE,             /* GDMSGQPUT         : GPP->DSP MSG Transfer  - MSGQ_put call */
    FALSE,             /* GDMSGQSENDINT     : GPP->DSP MSG Transfer  - GPP sends interrupt */
    FALSE,             /* GDMSGQISR         : GPP->DSP MSG Transfer  - DSP receives interrupt */
    FALSE,             /* GDMSGQQUE         : GPP->DSP MSG Transfer  - Message queued at DSP */
    FALSE,             /* DGMSGQPUT         : DSP->GPP MSG Transfer  - MSGQ_put call */
    FALSE,             /* DGMSGQSENDINT     : DSP->GPP MSG Transfer  - DSP sends interrupt */
    FALSE,             /* DGMSGQISR         : DSP->GPP MSG Transfer  - GPP receives interrupt */
    FALSE,             /* DGMSGQQUE         : DSP->GPP MSG Transfer  - Message queued at GPP */
    FALSE,             /* GDCHNLISSUESTART  : GPP->DSP CHNL Transfer - Entering inside ISSUE call */
    FALSE,             /* GDCHNLISSUEQUE    : GPP->DSP CHNL Transfer - ISSUE: Buffer is queued in internal structure on GPP */
    FALSE,             /* GDCHNLISSUECOMPL  : GPP->DSP CHNL Transfer - ISSUE call completed */
    FALSE,             /* GDCHNLXFERSTART   : GPP->DSP CHNL Transfer - Initiating a buffer transfer by GPP */
    FALSE,             /* GDCHNLXFERPROCESS : GPP->DSP CHNL Transfer - Actual transfer of buffer is going to take place */
    FALSE,             /* GDCHNLXFERCOMPL   : GPP->DSP CHNL Transfer - Buffer transfer is complete */
    FALSE,             /* GDCHNLRECLSTART   : GPP->DSP CHNL Transfer - Entering RECLAIM call */
    FALSE,             /* GDCHNLRECLPEND    : GPP->DSP CHNL Transfer - RECLAIM: Wait on a semaphore */
    FALSE,             /* GDCHNLRECLPOST    : GPP->DSP CHNL Transfer - RECLAIM: Posting the Semaphore */
    FALSE,             /* GDCHNLRECLCOMPL   : GPP->DSP CHNL Transfer - RECLAIM call completed */
    FALSE,             /* DGCHNLISSUEQUE    : DSP->GPP CHNL Transfer - ISSUE: Buffer is queued in internal structure on DSP */
    FALSE,             /* DGCHNLXFERSTART   : DSP->GPP CHNL Transfer - Initiating a buffer transfer by DSP */
    FALSE,             /* DGCHNLXFERPROCESS : DSP->GPP CHNL Transfer - Actual transfer of buffer is going to take place */
    FALSE,             /* DGCHNLXFERCOMPL   : DSP->GPP CHNL Transfer - Buffer transfer is complete */
    FALSE,             /* DGCHNLRECLPEND    : DSP->GPP CHNL Transfer - RECLAIM: Wait on a semaphore */
    FALSE,             /* DGCHNLRECLPOST    : DSP->GPP CHNL Transfer - RECLAIM: Posting the Semaphore */
    10u,               /* MSGIDRANGESTART   : MSG ID range: lower limit */
    20u                /* MSGIDRANGEEND     : MSG ID range: upper limit */
} ;

/** ============================================================================
 *  @name   LINKCFG_linkDrvObjects
 *
 *  @desc   Array of Link driver objects in the system.
 *  ============================================================================
 */
STATIC LINKCFG_LinkDrv  LINKCFG_linkDrvObjects [] =
{
    {
        "SHMDRV",                                                 /* NAME           : Name of the link driver */
        DRVHANDSHAKEPOLLCOUNT,                                    /* HSHKPOLLCOUNT  : Poll value for which handshake waits (-1 if infinite) */
        SHAREDENTRYID1,                                           /* MEMENTRY       : Memory entry ID (-1 if not needed) */
        0u,                                                       /* IPSTABLEID     : ID of the IPS table used */
        sizeof (LINKCFG_ipsTable_00) / sizeof (LINKCFG_Ips),      /* IPSENTRIES     : Number of IPS supported */
        0u,                                                       /* POOLTABLEID    : ID of the POOL table */
        sizeof (LINKCFG_poolTable_00) / sizeof (LINKCFG_Pool),    /* NUMPOOLS       : Number of POOLs supported */
        0u,                                                       /* DATATABLEID    : ID of the data driver table */
        sizeof (LINKCFG_dataTable_00) / sizeof (LINKCFG_DataDrv), /* NUMDATADRV     : Number of data drivers supported */
        0u,                                                       /* MQTID          : ID of the MQT */
        0u,                                                       /* RINGIOTABLEID  : RingIO Table Id used for this DSP */
        0u,                                                       /* MPLISTTABLEID  : MpList Table Id used for this DSP */
        0u                                                        /* MPCSTABLEID    : MPCS Table ID used for this DSP */
    }
} ;

/** ============================================================================
 *  @name   LINKCFG_dspObjects
 *
 *  @desc   Array of configuration objects for the DSPs in the system.
 *  ============================================================================
 */
STATIC LINKCFG_Dsp  LINKCFG_dspObject =
{
    "DRA44XGEM",                                              /* NAME           : Name of the DSP */
    DspArch_C64x,                                             /* ARCHITECTURE   : DSP architecture */
    "COFF",                                                   /* LOADERNAME     : Name of the DSP executable loader */
    FALSE,                                                    /* AUTOSTART      : Autostart the DSP (Not supported) */
    "DEFAULT.OUT",                                            /* EXECUTABLE     : Executable for autostart */
    DSP_BootMode_Boot_Pwr,                                    /* DOPOWERCTRL    : Link does the Power Ctrl of DSP. */
    RESETCTRLADDR,                                            /* RESUMEADDR     : Resume address */
    RESETCTRLADDR,                                            /* RESETVECTOR    : Reset Vector for the DSP */
    RESETCTRLSIZE,                                            /* RESETCODESIZE  : Size of code at DSP Reset Vector */
    1u,                                                       /* MADUSIZE       : DSP Minimum Addressable Data Unit */
    (Uint32) -1l,                                             /* CPUFREQ        : DSP Frequency (in KHz), -1 if default setting is to be used */
    Endianism_Little,                                         /* ENDIAN         : DSP Endianism */
    FALSE,                                                    /* WORDSWAP       : Words must be swapped when writing to memory */
    0u,                                                       /* MEMTABLEID     : ID of the memory table used */
    sizeof (LINKCFG_memTable_00)/sizeof (LINKCFG_MemEntry),   /* MEMENTRIES     : Number of entries in memory table */
    0u,                                                       /* LINKDRVID      : ID of the link driver used */
    0u,                                                       /* ARG1           : Bus No of PCI card */
    0u,                                                       /* ARG2           : Slot No of PCI card */
    0u,                                                       /* ARG3           : DSPLINK Shared memory region for control data structures creation */
    0u ,                                                      /* ARG4           : Unused */
    (Uint32) -1l                                              /* ARG5           : EDMA channel number,  Unused  for DRA44X*/
} ;

/** ============================================================================
 *  @name   DRA44XGEM_SHMEM_Config
 *
 *  @desc   DSP/BIOS LINK configuration structure.
 *  ============================================================================
 */
LINKCFG_DspConfig  DRA44XGEM_SHMEM_Config = {
    (LINKCFG_Dsp *)       &LINKCFG_dspObject,                   /* DSPOBJECTS     : Array of DSP objects */
    sizeof (LINKCFG_linkDrvObjects)/sizeof (LINKCFG_LinkDrv),   /* NUMLINKDRVS    : Number of Link Drviers*/
    (LINKCFG_LinkDrv *)   LINKCFG_linkDrvObjects,               /* LINKDRVOBJECTS : Array of Link Driver objects */
    sizeof (LINKCFG_memTables)/sizeof (LINKCFG_MemEntry *),     /* NUMMEMTABLES   : Number of memory tables */
    (LINKCFG_MemEntry **) LINKCFG_memTables,                    /* MEMTABLES      : Array of Memory tables */
    sizeof (LINKCFG_ipsTables)/sizeof (LINKCFG_Ips *),          /* NUMIPSTABLES   : Number of IPS tables */
    (LINKCFG_Ips **)      LINKCFG_ipsTables,                    /* IPSTABLES      : Array of IPS tables */
    sizeof (LINKCFG_poolTables)/sizeof (LINKCFG_Pool *),        /* NUMPOOLTABLES  : Number of POOL tables */
    (LINKCFG_Pool **)     LINKCFG_poolTables,                   /* POOLTABLES     : Array of Pool tables */
    sizeof (LINKCFG_dataTables)/sizeof (LINKCFG_DataDrv *),     /* NUMDATATABLES  : Number of data tables */
    (LINKCFG_DataDrv **)  LINKCFG_dataTables,                   /* DATATABLES     : Array of data tables */
    sizeof (LINKCFG_mqtObjects)/sizeof (LINKCFG_Mqt),           /* NUMMQTS        : Number of MQTs */
    (LINKCFG_Mqt *)       LINKCFG_mqtObjects,                   /* MQTOBJECTS     : Array of MQT objects */
    sizeof (LINKCFG_ringIoObjects)/sizeof (LINKCFG_RingIo),     /* NUMRINGIOTABLES: Number of RINGIO tables */
    (LINKCFG_RingIo *)    LINKCFG_ringIoObjects,                /* RINGIOOBJECTS  : Array of RINGIO objects */
    sizeof (LINKCFG_mplistObjects)/sizeof (LINKCFG_MpList),     /* NUMMPLISTTABLES: Number of MPLIST tables */
    (LINKCFG_MpList *)    LINKCFG_mplistObjects,                /* MPLISTOBJECTS  : Array of MPLIST objects */
    sizeof (LINKCFG_mpcsObjects)/sizeof (LINKCFG_Mpcs),         /* NUMMPCSTABLES  : Number of MPCS tables */
    (LINKCFG_Mpcs *)      LINKCFG_mpcsObjects,                  /* MPCSOBJECTS    : Array of MPCS objects */
    (LINKCFG_Log *)       &LINKCFG_logObject,                   /* LOGOBJECT      : Pointer to LOG object */
} ;


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
