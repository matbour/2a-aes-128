#include <stdio.h>
#include <string.h>
#include "includes/utils.h"
#include "includes/constants.h"
#include "includes/aes.h"


int main(int argc, char *argv[]) {
    if (argc != 3) {
        // Help
        printf("Usage: ./AES128 {text} {key}\n");
        printf("Example: ./AES128 00112233445566778899aabbccddeeff 000102030405060708090a0b0c0d0e0f\n");
    } else {
        // A few length checks
        char *text = argv[1];
        char *key = argv[2];
        size_t textLength = strlen(text);
        size_t keyLength = strlen(text);

        if (textLength != 32) {
            printf("Text should be 32 hex chars (strlen(%s) = %d)\n", text, (int)textLength);
            return 1;
        } else if (strlen(key) != 32) {
            printf("Key should be 32 hex chars (strlen(%s) = %d)\n", key, (int)keyLength);
            return 1;
        } else {
            aesCipher(text, key);
        }
    }

    return 0;
}