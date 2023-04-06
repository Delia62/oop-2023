#include "EasyHash.h"
int EasyHash::Method(const char* s) {
    int x = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                x += (int) s[i] * 10;
            else
                x += (int) s[i] * 11;
        else
            x += (int) s[i] * 12;
    }
    return x;
}