/*   Do *not* directly modify this file.  It was    */
/*   generated by the Configuration Tool; any  */
/*   changes risk being overwritten.                */

/* INPUT scale.cdb */

/* MODULE PARAMETERS */
-u _FXN_F_nop
GBL_USERINITFXN = _FXN_F_nop;

-u DDR2
MEM_SEGZERO = DDR2;
-u DDR2
MEM_MALLOCSEG = DDR2;

-u _CLK_gethtime
CLK_TIMEFXN = _CLK_gethtime;
-u HWI_F_dispatch
CLK_HOOKFXN = HWI_F_dispatch;

-u _KNL_tick
PRD_THOOKFXN = _KNL_tick;

-u DDR2
RTDX_DATAMEMSEG = DDR2;

-u DDR2
HST_DSMBUFSEG = DDR2;

-u GBL_NULL
SWI_EHOOKFXN = GBL_NULL;
-u GBL_NULL
SWI_IHOOKFXN = GBL_NULL;
-u SWI_F_exec
SWI_EXECFXN = SWI_F_exec;
-u SWI_F_run
SWI_RUNFXN = SWI_F_run;

-u DDR2
TSK_STACKSEG = DDR2;
-u _FXN_F_nop
TSK_VCREATEFXN = _FXN_F_nop;
-u _FXN_F_nop
TSK_VDELETEFXN = _FXN_F_nop;
-u _FXN_F_nop
TSK_VEXITFXN = _FXN_F_nop;

-u GBL_NULL
IDL_CALIBRFXN = GBL_NULL;

-u _UTL_doAbort
SYS_ABORTFXN = _UTL_doAbort;
-u _UTL_doError
SYS_ERRORFXN = _UTL_doError;
-u _UTL_halt
SYS_EXITFXN = _UTL_halt;
-u _UTL_doPutc
SYS_PUTCFXN = _UTL_doPutc;

-u _FXN_F_nop
GIO_CREATEFXN = _FXN_F_nop;
-u _FXN_F_nop
GIO_DELETEFXN = _FXN_F_nop;
-u _FXN_F_nop
GIO_PENDFXN = _FXN_F_nop;
-u _FXN_F_nop
GIO_POSTFXN = _FXN_F_nop;

-u _FXN_F_nop
PWRM_PWRM_SLOTHOOKFXN = _FXN_F_nop;
-u _FXN_F_nop
PWRM_PWRM_SHAREDRESOURCEFXN = _FXN_F_nop;

/* OBJECT ALIASES */
_CACHE_L2 = CACHE_L2;
_CACHE_L1P = CACHE_L1P;
_CACHE_L1D = CACHE_L1D;
_DDR2 = DDR2;
_L1DSRAM = L1DSRAM;
_IRAM = IRAM;
_DSPLINKMEM = DSPLINKMEM;
_POOLMEM = POOLMEM;
_RESET_VECTOR = RESET_VECTOR;
_PRD_clock = PRD_clock;
_HWI_RESET = HWI_RESET;
_HWI_NMI = HWI_NMI;
_HWI_RESERVED0 = HWI_RESERVED0;
_HWI_RESERVED1 = HWI_RESERVED1;
_HWI_INT4 = HWI_INT4;
_HWI_INT5 = HWI_INT5;
_HWI_INT6 = HWI_INT6;
_HWI_INT7 = HWI_INT7;
_HWI_INT8 = HWI_INT8;
_HWI_INT9 = HWI_INT9;
_HWI_INT10 = HWI_INT10;
_HWI_INT11 = HWI_INT11;
_HWI_INT12 = HWI_INT12;
_HWI_INT13 = HWI_INT13;
_HWI_INT14 = HWI_INT14;
_HWI_INT15 = HWI_INT15;
_EVENT4 = EVENT4;
_EVENT5 = EVENT5;
_EVENT6 = EVENT6;
_EVENT7 = EVENT7;
_EVENT8 = EVENT8;
_EVENT9 = EVENT9;
_EVENT10 = EVENT10;
_EVENT11 = EVENT11;
_EVENT12 = EVENT12;
_EVENT13 = EVENT13;
_EVENT14 = EVENT14;
_EVENT15 = EVENT15;
_EVENT16 = EVENT16;
_EVENT17 = EVENT17;
_EVENT18 = EVENT18;
_EVENT19 = EVENT19;
_EVENT20 = EVENT20;
_EVENT21 = EVENT21;
_EVENT22 = EVENT22;
_EVENT23 = EVENT23;
_EVENT24 = EVENT24;
_EVENT25 = EVENT25;
_EVENT26 = EVENT26;
_EVENT27 = EVENT27;
_EVENT28 = EVENT28;
_EVENT29 = EVENT29;
_EVENT30 = EVENT30;
_EVENT31 = EVENT31;
_EVENT32 = EVENT32;
_EVENT33 = EVENT33;
_EVENT34 = EVENT34;
_EVENT35 = EVENT35;
_EVENT36 = EVENT36;
_EVENT37 = EVENT37;
_EVENT38 = EVENT38;
_EVENT39 = EVENT39;
_EVENT40 = EVENT40;
_EVENT41 = EVENT41;
_EVENT42 = EVENT42;
_EVENT43 = EVENT43;
_EVENT44 = EVENT44;
_EVENT45 = EVENT45;
_EVENT46 = EVENT46;
_EVENT47 = EVENT47;
_EVENT48 = EVENT48;
_EVENT49 = EVENT49;
_EVENT50 = EVENT50;
_EVENT51 = EVENT51;
_EVENT52 = EVENT52;
_EVENT53 = EVENT53;
_EVENT54 = EVENT54;
_EVENT55 = EVENT55;
_EVENT56 = EVENT56;
_EVENT57 = EVENT57;
_EVENT58 = EVENT58;
_EVENT59 = EVENT59;
_EVENT60 = EVENT60;
_EVENT61 = EVENT61;
_EVENT62 = EVENT62;
_EVENT63 = EVENT63;
_EVENT64 = EVENT64;
_EVENT65 = EVENT65;
_EVENT66 = EVENT66;
_EVENT67 = EVENT67;
_EVENT68 = EVENT68;
_EVENT69 = EVENT69;
_EVENT70 = EVENT70;
_EVENT71 = EVENT71;
_EVENT72 = EVENT72;
_EVENT73 = EVENT73;
_EVENT74 = EVENT74;
_EVENT75 = EVENT75;
_EVENT76 = EVENT76;
_EVENT77 = EVENT77;
_EVENT78 = EVENT78;
_EVENT79 = EVENT79;
_EVENT80 = EVENT80;
_EVENT81 = EVENT81;
_EVENT82 = EVENT82;
_EVENT83 = EVENT83;
_EVENT84 = EVENT84;
_EVENT85 = EVENT85;
_EVENT86 = EVENT86;
_EVENT87 = EVENT87;
_EVENT88 = EVENT88;
_EVENT89 = EVENT89;
_EVENT90 = EVENT90;
_EVENT91 = EVENT91;
_EVENT92 = EVENT92;
_EVENT93 = EVENT93;
_EVENT94 = EVENT94;
_EVENT95 = EVENT95;
_EVENT96 = EVENT96;
_EVENT97 = EVENT97;
_EVENT98 = EVENT98;
_EVENT99 = EVENT99;
_EVENT100 = EVENT100;
_EVENT101 = EVENT101;
_EVENT102 = EVENT102;
_EVENT103 = EVENT103;
_EVENT104 = EVENT104;
_EVENT105 = EVENT105;
_EVENT106 = EVENT106;
_EVENT107 = EVENT107;
_EVENT108 = EVENT108;
_EVENT109 = EVENT109;
_EVENT110 = EVENT110;
_EVENT111 = EVENT111;
_EVENT112 = EVENT112;
_EVENT113 = EVENT113;
_EVENT114 = EVENT114;
_EVENT115 = EVENT115;
_EVENT116 = EVENT116;
_EVENT117 = EVENT117;
_EVENT118 = EVENT118;
_EVENT119 = EVENT119;
_EVENT120 = EVENT120;
_EVENT121 = EVENT121;
_EVENT122 = EVENT122;
_EVENT123 = EVENT123;
_EVENT124 = EVENT124;
_EVENT125 = EVENT125;
_EVENT126 = EVENT126;
_EVENT127 = EVENT127;
_KNL_swi = KNL_swi;
_TSK_idle = TSK_idle;
_ZCPYLINK_TSK_OBJ = ZCPYLINK_TSK_OBJ;
_LOG_system = LOG_system;
_trace = trace;

/* MODULE GBL */

SECTIONS {
   .vers (COPY): {} /* version information */
}

-priority
--trampolines
--"diag_suppress=16002"
-llnknone.a64P
-ldrivers.a64P         /* device drivers support */
-lsioboth.a64P         /* supports both SIO models */
-lbios3430.a64P        /* BIOS clock specific library */
-lbios.a64P            /* DSP/BIOS support */
-lrts64plus.lib        /* C and C++ run-time library support */


_GBL_CACHE = GBL_CACHE;
_BCACHE_bootInit=_BCACHE_setCacheToSram;

/* MODULE MEM */
-stack 0x1000
MEMORY {
   CACHE_L2    : origin = 0x10808000,  len = 0x8000
   CACHE_L1P   : origin = 0x10e04000,  len = 0x4000
   CACHE_L1D   : origin = 0x10f10000,  len = 0x8000
   DDR2        : origin = 0x88100080,  len = 0x7efff80
   L1DSRAM     : origin = 0x10f04000,  len = 0x4000
   IRAM        : origin = 0x107f8000,  len = 0x10000
   DSPLINKMEM  : origin = 0x88000000,  len = 0x30000
   POOLMEM     : origin = 0x88030000,  len = 0xd0000
   RESET_VECTOR : origin = 0x88100000, len = 0x80
}
/* MODULE CLK */
SECTIONS {
   .clk: {
        
        *(.clk) 
   } > DDR2, RUN_START(CLK_A_TABBEG) 
}
_CLK_PRD = CLK_PRD;
_CLK_COUNTSPMS = CLK_COUNTSPMS;
_CLK_REGS = CLK_REGS;
_CLK_USETIMER = CLK_USETIMER;
_CLK_TIMERNUM = CLK_TIMERNUM;
_CLK_TDDR = CLK_TDDR;

/* MODULE PRD */
SECTIONS {
   .prd: RUN_START(PRD_A_TABBEG), RUN_END(PRD_A_TABEND) {
   } > DDR2
}
PRD_A_TABLEN = 0;

_HWI_CFGDISPATCHED = HWI_CFGDISPATCHED;

/* MODULE SWI */
SECTIONS {
   .swi: RUN_START(SWI_A_TABBEG), RUN_END(SWI_A_TABEND) {
   } > DDR2
}
SWI_A_TABLEN = 1;

/* MODULE TSK */
SECTIONS {
   .tsk: {
        *(.tsk) 
   } > DDR2
}

/* MODULE IDL */
SECTIONS {
   .idl: {
        *(.idl) 
   } > DDR2, RUN_START(IDL_A_TABBEG)
   
   .idlcal: {
        *(.idlcal) 
   } > DDR2, RUN_START(IDL_A_CALBEG) 
}


LOG_A_TABLEN = 2; _LOG_A_TABLEN = 2;

PIP_A_TABLEN = 0;

/* MODULE PWRM */
__PWRM_SCM_BASEADDR = 0x48002000;
__PWRM_CM_BASEADDR = 0x48004000;
__PWRM_PRM_BASEADDR = 0x48306000;
__PWRM_IVAMMU_BASEADDR = 0x5d000000;
__PWRM_USETIMER = PWRM_PWRM_USETIMER;
__PWRM_TIMERINTRMASK = PWRM_PWRM_TIMERINTRMASK;
__PWRM_TIMERBASEADDR = 0x0;
__PWRM_TIMERINPUTCLK = 32;
__PWRM_TIMERPERIOD = 10; 

SECTIONS {
        .bss:     {} > DDR2

        .hwi_vec: {
            *(.hwi_vec)
        } align = 0x400, RUN_START(HWI_A_VECS) > DDR2

        .far:     {} > DDR2

        .sysdata: {} > DDR2

        .dio: {} > DDR2

        .dsm: {} > DDR2

        .udev: {} > DDR2

        frt:    {} > DDR2

        .mem: 	  {} > DDR2

        .bios:    {} > DDR2

        .cio:     {} > DDR2

        .data:    {} > DDR2

        .gio:     {} > DDR2

        .pinit:   {} > DDR2

        .sys:     {} > DDR2

        .sysregs: {} > DDR2

        .text:    {} > DDR2

        .cinit:    {} > DDR2

        .devtable: {} > DDR2

        .switch:    {} > DDR2

        .gblinit:    {} > DDR2

        .sysinit:    {} > DDR2

        .trcdata:    {} > DDR2

        .hwi: {}  > DDR2

        .pwrm_warmBoot: {} > DDR2

        .pwrm_contextBuffer: {} > DDR2

        .TSK_idle$stk: {
            *(.TSK_idle$stk)
        } > DDR2

        .ZCPYLINK_TSK_OBJ$stk: {
            *(.ZCPYLINK_TSK_OBJ$stk)
        } > DDR2

        /* LOG_system buffer */
        .LOG_system$buf: align = 0x100 {} > DDR2

        /* trace buffer */
        .trace$buf: align = 0x80 {} > DDR2

        GROUP {
         .const: align = 0x8 {} 
         .printf (COPY): {} 
        } > DDR2

        .args: align=4 fill=0 {
            *(.args)
            . += 0x32;
        } > DDR2

        .trace: fill = 0x0  align = 0x4 {
           _SYS_PUTCBEG = .;
           . += 0x200;
           _SYS_PUTCEND = . - 1;
        } > DDR2

        .hst: RUN_START(HST_A_TABBEG), RUN_START(_HST_A_TABBEG), RUN_END(HST_A_TABEND), RUN_END(_HST_A_TABEND) {
        } > DDR2

        .log: RUN_START(LOG_A_TABBEG), RUN_START(_LOG_A_TABBEG), RUN_END(LOG_A_TABEND), RUN_END(_LOG_A_TABEND) {
        } > DDR2

        .pip: RUN_START(PIP_A_TABBEG), RUN_START(_PIP_A_TABBEG), RUN_END(PIP_A_TABEND), RUN_END(_PIP_A_TABEND) {
        } > DDR2

        .sts: RUN_START(STS_A_TABBEG), RUN_START(_STS_A_TABBEG), RUN_END(STS_A_TABEND), RUN_END(_STS_A_TABEND) {
        } > DDR2

        .stack: align = 0x8 {
            GBL_stackbeg = .;
            *(.stack)
            GBL_stackend = GBL_stackbeg + 0x1000 - 1;
            _HWI_STKBOTTOM = GBL_stackbeg + 0x1000 - 8;
            _HWI_STKTOP = GBL_stackbeg;
        } > DDR2

        .DDR2$heap: {
            . += 0x10000;
        } RUN_START(DDR2$B), RUN_START(_DDR2_base), RUN_SIZE(DDR2$L), RUN_SIZE(_DDR2_length) > DDR2

}

