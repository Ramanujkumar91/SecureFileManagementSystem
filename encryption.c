// encryption.c
#include "encryption.h"

#define XOR_KEY 0x5A  // You can change the key to anything

char encrypt_char(char ch) {
    return ch ^ XOR_KEY;
}

char decrypt_char(char ch) {
    return ch ^ XOR_KEY;
}
