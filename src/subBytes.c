#include "includes/subBytes.h"
#include "includes/byte.h"
#include "includes/constants.h"


/**
 * Sub bytes for the two first lines
 */
void subBytes(byte state[]) {
    for (int i = 0; i < KEY_BYTES_LENGTH; i++) {
        state[i] = sbox[state[i]];
    }
}