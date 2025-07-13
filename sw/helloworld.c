// Copyright (c) 2024 ETH Zurich and University of Bologna.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

// Authors:
// - Philippe Sauter <phsauter@iis.ee.ethz.ch>
// - <you>           (bit-reversal test integration)

#include "uart.h"
#include "print.h"
#include "timer.h"
#include "gpio.h"
#include "util.h"


//bitrev 
#define BITREV_BASE   0x20001000UL
#define BITREV_IN     (*(volatile uint32_t *)(BITREV_BASE + 0x0))
#define BITREV_OUT    (*(volatile uint32_t *)(BITREV_BASE + 0x4))
#define BITREV_STAT   (*(volatile uint32_t *)(BITREV_BASE + 0x8))

#define K   10u               // must match RTL parameter BITREV_K
#define N   (1u << K)         // 1024-point frame


// ------------------------- ROM helper --------------------------------
void read_name(void)
{
    for (const char *p = (const char *)USER_ROM_BASE_ADDR; *p != 0; ++p)
        putchar(*p);
    printf("\n");
    uart_write_flush();
}

// ------------------------- simple integer sqrt -----------------------
static uint32_t isqrt(uint32_t n)
{
    uint32_t res = 0, bit = 1u << 30;
    while (bit > n) bit >>= 2;
    while (bit) {
        if (n >= res + bit) {
            n -= res + bit;
            res = (res >> 1) + bit;
        } else {
            res >>= 1;
        }
        bit >>= 2;
    }
    return res;
}

static inline uint32_t reverse_bits_k(uint32_t x)
{
    /* Reverse low K bits of x (bit-twiddling classic) */
    x = ((x & 0x55555555u) << 1)  | ((x & 0xAAAAAAAAu) >> 1);
    x = ((x & 0x33333333u) << 2)  | ((x & 0xCCCCCCCCu) >> 2);
    x = ((x & 0x0F0F0F0Fu) << 4)  | ((x & 0xF0F0F0F0u) >> 4);
    x = ((x & 0x00FF00FFu) << 8)  | ((x & 0xFF00FF00u) >> 8);
    x = (x << 16) | (x >> 16);
    return x >> (32u - K);
}

static void bitrev_selftest(void)
{
    printf("Bit-reversal self-test…\n");

    /* 1. Push one natural-order frame */
    for (uint32_t i = 0; i < N; ++i)
        BITREV_IN = i;

    /* 2. Pull it back and check */
    uint32_t errors = 0;

    for (uint32_t i = 0; i < N; ++i) {
        while ((BITREV_STAT & 1u) == 0) ;          // wait for valid
        uint32_t sample  = BITREV_OUT;             // read consumes word
        uint32_t expect  = reverse_bits_k(i);
        if (sample != expect) {
            printf("Mismatch @%u: got %u, exp %u\n",
                   i, sample, expect);
            ++errors;
        }
    }

    if (errors == 0)
        printf("Bit-reversal test PASSED for %u-point frame\n", N);
    else
        printf("Bit-reversal test FAILED (%u errors)\n", errors);

    uart_write_flush();
}

// =====================================================================

int main(void)
{
    uart_init();

    // ------------------------------------------------------------
    // 1) Hello-world and peripheral demos
    // ------------------------------------------------------------
    printf("Hello World!\n");
    uart_write_flush();

    gpio_set_direction(0xFFFF, 0x000F);      // low 4 as outputs
    gpio_write(0x0A);
    gpio_enable(0xFF);
    asm volatile("nop; nop; nop; nop; nop;");
    printf("GPIO (expect 0xA0): 0x%x\n", gpio_read());

    gpio_toggle(0x0F);
    asm volatile("nop; nop; nop; nop; nop;");
    printf("GPIO (expect 0x50): 0x%x\n", gpio_read());

    uint32_t t0 = get_mcycle();
    uint32_t r  = isqrt(1234567890UL);
    uint32_t t1 = get_mcycle();
    printf("isqrt result: 0x%x, cycles: 0x%x\n", r, t1 - t0);

    printf("Tick\n");
    sleep_ms(10);
    printf("Tock\n");
    uart_write_flush();

    read_name();

    // ------------------------------------------------------------
    // 2) Bit-reversal verification
    // ------------------------------------------------------------
    bitrev_selftest();


    return 0;
}
