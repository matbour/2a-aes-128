#include "includes/addRoundKey.h"
#include "includes/byte.h"
#include "includes/constants.h"


/**
 * AddRoundKey step: make state XOR roundKey
 */
void addRoundKey(byte state[], const byte roundKey[]) {
    for (int i = 0; i < KEY_BYTES_LENGTH; i++) {
        state[i] ^= roundKey[i];
    }
}
