#include "includes/utils.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "includes/byte.h"
#include "includes/constants.h"


/**
 * Convert a string to a table of bytes
 * @param string
 * @return
 */
byte *stringToHex(const char *string) {
    size_t len = strlen(string); // Get string length

    if (len % 2 != 0) {
        return NULL;
    }

    size_t final_len = len / 2;

    byte *result = (byte *) malloc((final_len) * sizeof(*result));

    for (size_t i = 0, j = 0; j < final_len; i += 2, j++) {
        result[j] = (byte) ((string[i] % 32 + 9) % 25 * 16 + (string[i + 1] % 32 + 9) % 25);
    }

    return result;
}


/**
 * Print a table of bytes
 * @param data
 * @param length
 */
void printHex(byte data[], int length) {
    for (int i = 0; i < length; i++) {
        if (i > 0 && i % 16 == 0) {
            printf("\n");
        }
        printf("%02x ", data[i]);
    }
}


/**
 * Print a table of bytes with a line ending
 * @param data
 * @param length
 */
void printlnHex(byte data[], int length) {
    printHex(data, length);
    printf("\n");
}