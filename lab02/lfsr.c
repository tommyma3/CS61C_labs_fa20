#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(uint16_t x,
                 uint16_t n) {
    
    x = x >> n;
    return x & 1;
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(uint16_t * x,
             uint16_t n,
             uint16_t v) {
    *x = (*x & ~(1 << n)) | (v << n);
}


void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    uint16_t b0 = get_bit(*reg, 0);
    uint16_t b2 = get_bit(*reg, 2);
    uint16_t b3 = get_bit(*reg, 3);
    uint16_t b5 = get_bit(*reg, 5);

    uint16_t val = b5 ^ b3 ^ b2 ^ b0;

    *reg = *reg >> 1;
    set_bit(reg, 15, val);
}

