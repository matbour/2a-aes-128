#ifndef AES128_UTILS_H
#define AES128_UTILS_H

#include "byte.h"

byte *stringToHex(const char *string);

void printHex(byte data[], int length);

void printlnHex(byte data[], int length);

#endif //AES128_UTILS_H
