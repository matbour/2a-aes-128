#include <stdlib.h>
#include "includes/expandKey.h"
#include "includes/byte.h"
#include "includes/constants.h"


/**
 * Rotate left a 32-bits word
 * @param in
 * Example: rotate(AA345678) = 345678AA
 */
void rotate(byte *in) {
    byte a, c;
    a = in[0];
    for (c = 0; c < 3; c++)
        in[c] = in[c + 1];
    in[3] = a;
}


/**
 * Expand a key
 * @param key
 * @return
 */
byte *expandKey(const byte key[]) {
    byte *expandedKey = (byte *) malloc((EXPANED_KEY_BYTES_LENGTH) * sizeof(byte));

    // Copy the original key at the begiing of the expanded key
    for (byte i = 0; i < KEY_BYTES_LENGTH; i++) {
        expandedKey[i] = key[i];
    }

    int currentKeyLength = KEY_BYTES_LENGTH; // Set to 6 bytes from the copy
    byte rconIteration = 1;
    byte temp[4];

    while (currentKeyLength < EXPANED_KEY_BYTES_LENGTH) {
        for (byte i = 0; i < 4; i++) {
            temp[i] = expandedKey[i + currentKeyLength - 4];
        }

        if (currentKeyLength % KEY_BYTES_LENGTH == 0) {
            rotate(temp);

            for (char i = 0; i < 4; i++) {
                temp[i] = sbox[temp[i]];
            }

            temp[0] ^= rcon[rconIteration - 1];

            rconIteration++;
        }

        for (byte i = 0; i < 4; i++) {
            expandedKey[currentKeyLength] = expandedKey[currentKeyLength - KEY_BYTES_LENGTH] ^ temp[i];
            currentKeyLength++;
        }
    }

    return expandedKey;
}
