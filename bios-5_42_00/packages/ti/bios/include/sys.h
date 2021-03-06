/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *  @(#) DSP/BIOS_Kernel 5,2,5,44 09-06-2012 (cuda-u44)
 */
/*
 *  ======== sys.h ========
 *
 */

#ifndef SYS_
#define SYS_

#include <stdarg.h>
#include <fxn.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SYS_Config {
    Fxn ABORTFXN;
    Fxn ERRORFXN;
    Fxn EXITFXN;
    Fxn PUTCFXN;
} SYS_Config;

#ifdef _6x_
extern far SYS_Config *SYS;
#else
extern SYS_Config *SYS;
#endif

/*
 *  constants
 */
#define SYS_FOREVER     ((Uns)-1)       /* used by SEM_pend(), ... */
#define SYS_POLL        ((Uns)0)        /* used by SEM_pend(), ... */

/*
 *  error codes
 */
#define SYS_OK          0               /* no error */
#define SYS_EALLOC      1               /* memory allocation error */
#define SYS_EFREE       2               /* memory free error */
#define SYS_ENODEV      3               /* device driver not found */
#define SYS_EBUSY       4               /* device driver busy */
#define SYS_EINVAL      5               /* invalid parameter for device */
#define SYS_EBADIO      6               /* IO failure */
#define SYS_EMODE       7               /* bad mode for device driver */
#define SYS_EDOMAIN     8               /* domain error */
#define SYS_ETIMEOUT    9               /* timeout error */
#define SYS_EEOF        10              /* end-of-file */
#define SYS_EDEAD       11              /* previously deleted object */
#define SYS_EBADOBJ     12              /* invalid object */
#define SYS_ENOTIMPL    13              /* action not implemented */
#define SYS_ENOTFOUND   14              /* resource not found */

#define SYS_EUSER       256             /* user errors start here */

#define SYS_NUMHANDLERS 8               /* number of atexit handlers */

#define SYS_putchar(ch) (*(SYS->PUTCFXN))(ch)
#define SYS_nop() FXN_F_nop()

extern Fxn SYS_exitStack[];
extern Fxn *SYS_exitStackPtr;
extern Fxn *SYS_exitStackTop;
extern Int SYS_PUTCBEG, SYS_PUTCEND;

extern String SYS_errors[];             /* system error strings */

extern Void SYS_abort(String fmt, ...);
extern Bool SYS_atexit(Fxn fxn);
extern Void SYS_error(String s, Int errno, ...);
extern Void SYS_exit(Int status);
extern Int SYS_one(void);
extern Void SYS_printf(String fmt, ...);
extern Void SYS_sprintf(Char *buf, String fmt, ...);
extern Void SYS_start(void);
extern Void SYS_vprintf(String fmt, va_list va);
extern Void SYS_vsprintf(Char *buf, String fmt, va_list va);
extern Int SYS_zero(void);

#ifdef _BIOSROM_

extern Int (*SYS_onePtr)(Void);
extern Int (*SYS_zeroPtr)(Void);

#define SYS_oneJ()              (SYS_onePtr)()
#define SYS_zeroJ()             (SYS_zeroPtr)()

#else

#define SYS_oneJ()              SYS_one()
#define SYS_zeroJ()             SYS_zero()

#endif

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* SYS_ */
