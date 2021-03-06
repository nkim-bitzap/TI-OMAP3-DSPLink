/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *  @(#) DSP/BIOS_Kernel 5,2,5,44 09-06-2012 (cuda-u44)
 */
/*
 *  ======== dgn_isin.c ========
 *  Spectron-supplied "user" function for DGN.
 *
 */

#include <std.h>
#include <stddef.h>

#include <dgn.h>

/*
 *  ======== DGN_isine ========
 *  Fill the buffer whose address is "addr" with sine values generated
 *  "size" times.
 *
 *  NOTE:  If the sampling rate is not evenly divisible by the
 *         frequency, the generated output is not a sine wave
 *         but a sequence of a sine-like wave.
 */
Void DGN_isine(DGN_GenObj *gen, Int16 *addr, size_t size)
{
    size_t         i;
#ifdef  _56_
    Int         *sineTable = (Int *)0x100;

    __asm("ori  #4,omr");       /* enable on-chip ROM */
#else

static  Int16 sineTable[256] = {
    0x0000,0x0324,0x0647,0x096A,0x0C8B,0x0FAB,0x12C8,0x15E2,
    0x18F8,0x1C0B,0x1F19,0x2223,0x2528,0x2826,0x2B1F,0x2E11,
    0x30FB,0x33DE,0x36BA,0x398C,0x3C56,0x3F17,0x41CE,0x447A,
    0x471C,0x49B4,0x4C3F,0x4EBF,0x5133,0x539B,0x55F5,0x5842,
    0x5A82,0x5CB4,0x5ED7,0x60EC,0x62F2,0x64E8,0x66CF,0x68A6,
    0x6A6D,0x6C24,0x6DCA,0x6F5F,0x70E2,0x7255,0x73B5,0x7504,
    0x7641,0x776C,0x7884,0x798A,0x7A7D,0x7B5D,0x7C29,0x7CE3,
    0x7D8A,0x7E1D,0x7E9D,0x7F09,0x7F62,0x7FA7,0x7FD8,0x7FF6,
    0x7FFF,0x7FF6,0x7FD8,0x7FA7,0x7F62,0x7F09,0x7E9D,0x7E1D,
    0x7D8A,0x7CE3,0x7C29,0x7B5D,0x7A7D,0x798A,0x7884,0x776C,
    0x7641,0x7504,0x73B5,0x7255,0x70E2,0x6F5F,0x6DCA,0x6C24,
    0x6A6D,0x68A6,0x66CF,0x64E8,0x62F2,0x60EC,0x5ED7,0x5CB4,
    0x5A82,0x5842,0x55F5,0x539B,0x5133,0x4EBF,0x4C3F,0x49B4,
    0x471C,0x447A,0x41CE,0x3F17,0x3C56,0x398C,0x36BA,0x33DE,
    0x30FB,0x2E11,0x2B1F,0x2826,0x2528,0x2223,0x1F19,0x1C0B,
    0x18F8,0x15E2,0x12C8,0x0FAB,0x0C8B,0x096A,0x0647,0x0324,
    0x0000,0xFCDB,0xF9B8,0xF695,0xF374,0xF054,0xED37,0xEA1D,
    0xE707,0xE3F4,0xE0E6,0xDDDC,0xDAD7,0xD7D9,0xD4E0,0xD1EE,
    0xCF04,0xCC21,0xC945,0xC673,0xC3A9,0xC0E8,0xBE31,0xBB85,
    0xB8E3,0xB64B,0xB3C0,0xB140,0xAECC,0xAC64,0xAA0A,0xA7BD,
    0xA57D,0xA34B,0xA128,0x9F13,0x9D0D,0x9B17,0x9930,0x9759,
    0x9592,0x93DB,0x9235,0x90A0,0x8F1D,0x8DAA,0x8C4A,0x8AFB,
    0x89BE,0x8893,0x877B,0x8675,0x8582,0x84A2,0x83D6,0x831C,
    0x8275,0x81E2,0x8162,0x80F6,0x809D,0x8058,0x8027,0x8009,
    0x8000,0x8009,0x8027,0x8058,0x809D,0x80F6,0x8162,0x81E2,
    0x8275,0x831C,0x83D6,0x84A2,0x8582,0x8675,0x877B,0x8893,
    0x89BE,0x8AFB,0x8C4A,0x8DAA,0x8F1D,0x90A0,0x9235,0x93DB,
    0x9592,0x9759,0x9930,0x9B17,0x9D0D,0x9F13,0xA128,0xA34B,
    0xA57D,0xA7BD,0xAA0A,0xAC64,0xAECC,0xB140,0xB3C0,0xB64B,
    0xB8E3,0xBB85,0xBE31,0xC0E8,0xC3A9,0xC673,0xC945,0xCC21,
    0xCF04,0xD1EE,0xD4E0,0xD7D9,0xDAD7,0xDDDC,0xE0E6,0xE3F4,
    0xE707,0xEA1D,0xED37,0xF054,0xF374,0xF695,0xF9B8,0xFCDB,
};
#endif  /* _56_ */

    for (i = (size / sizeof(Int16)); i > 0; i--) {
        *addr++ = (Int16) sineTable[gen->index] >> (gen->shift); /* modified by gain */
        gen->index += gen->step;
        gen->index = gen->index & 0xff;                 /* count % 256 */
    }
}
