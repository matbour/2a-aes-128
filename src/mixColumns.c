#include "includes/mixColumns.h"
#include "includes/byte.h"
#include "includes/constants.h"


byte xtime(byte x) {
    return (byte) ((x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1));
}


/**
 * Mix column operation
 * @param state
 */
void mixColumns(byte state[]) {
    byte i, a, b, c, d, e;

    for (i = 0; i < KEY_BYTES_LENGTH; i += 4) {
        a = state[i];
        b = state[i + 1];
        c = state[i + 2];
        d = state[i + 3];
        e = a ^ b ^ c ^ d;
        state[i] ^= e ^ xtime(a ^ b);
        state[i + 1] ^= e ^ xtime(b ^ c);
        state[i + 2] ^= e ^ xtime(c ^ d);
        state[i + 3] ^= e ^ xtime(d ^ a);
    }
}