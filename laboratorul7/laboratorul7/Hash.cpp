#include "Hash.h"
int Hash::Method(const char* s) {
    int x = 0;
    for (int i = 0; s[i] != '\0'; i++)
        x += (int) s[i];
    return x;
}