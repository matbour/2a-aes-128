#include <stdio.h>
#include <stdlib.h>
#include "includes/aes.h"
#include "includes/utils.h"
#include "includes/constants.h"
#include "includes/addRoundKey.h"
#include "includes/expandKey.h"
#include "includes/subBytes.h"
#include "includes/shiftRows.h"
#include "includes/mixColumns.h"


/**
 * Cipher a text using a key
 * @param textString the text to cipher
 * @param keyString the cipher key
 * @return the ciphered text
 */
byte *aesCipher(char *textString, char *keyString) {
    byte *key;
    byte *text;
    byte *expandedKey;
    byte *state = (byte *) (malloc(KEY_BYTES_LENGTH * sizeof(byte *)));
    byte round = 0;
    byte a = 0;

    // Initialize vars
    printf("INITIALIZATION:\n");
    text = stringToHex(textString);
    key = stringToHex(keyString);
    expandedKey = expandKey(key);

    // Copy text to state
    for (a = 0; a < KEY_BYTES_LENGTH; a++) {
        state[a] = text[a];
    }

    printf("Text: ");
    printlnHex(text, KEY_BYTES_LENGTH);

    printf("Key:  ");
    printlnHex(key, KEY_BYTES_LENGTH);

    printf("Expanded key:\n");
    printlnHex(expandedKey, EXPANED_KEY_BYTES_LENGTH);


    // Starting Cipher
    printf("\n\nCIPHER (ENCRYPT)\n");

    // Round 0
    printf("round[ %d].input  ", round);
    printlnHex(state, KEY_BYTES_LENGTH);

    // AddRoundKey
    printf("round[ %d].k_sch  ", round);
    printlnHex(expandedKey + (KEY_BYTES_LENGTH * (round)), KEY_BYTES_LENGTH);
    addRoundKey(state, expandedKey + (KEY_BYTES_LENGTH * round));

    // Round 1 to 9
    for (round = 1; round <= 9; round++) {
        // Start
        printf("round[ %d].start  ", round);
        printlnHex(state, KEY_BYTES_LENGTH);

        // SubBytes
        subBytes(state);
        printf("round[ %d].s_box  ", round);
        printlnHex(state, KEY_BYTES_LENGTH);

        // ShiftRows
        shiftRows(state);
        printf("round[ %d].s_row  ", round);
        printlnHex(state, KEY_BYTES_LENGTH);

        // MixColumns
        mixColumns(state);
        printf("round[ %d].m_col  ", round);
        printlnHex(state, KEY_BYTES_LENGTH);

        // AddRoundKey
        printf("round[ %d].k_sch  ", round);
        printlnHex(expandedKey + (KEY_BYTES_LENGTH * (round)), KEY_BYTES_LENGTH);
        addRoundKey(state, expandedKey + (KEY_BYTES_LENGTH * round));
    }

    // Round 10
    printf("round[%d].start  ", round);
    printlnHex(state, KEY_BYTES_LENGTH);

    // SubBytes
    subBytes(state);
    printf("round[%d].s_box  ", round);
    printlnHex(state, KEY_BYTES_LENGTH);

    // ShiftRows
    shiftRows(state);
    printf("round[%d].s_row  ", round);
    printlnHex(state, KEY_BYTES_LENGTH);

    // AddRoundKey
    printf("round[%d].k_sch  ", round);
    printlnHex(expandedKey + (KEY_BYTES_LENGTH * (round)), KEY_BYTES_LENGTH);
    addRoundKey(state, expandedKey + (KEY_BYTES_LENGTH * round));

    // Output
    printf("round[%d].output ", round);
    printlnHex(state, KEY_BYTES_LENGTH);

    return state;
}