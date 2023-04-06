#include "CountConsonantHash.h"
int CountConsonantHash::Method(const char* s) {
    int x = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
                x++;
        if (s[i] >= 'A' && s[i] <= 'Z')
            if (s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
                x++;
    }
    return x;
}