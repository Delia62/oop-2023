#include "CountVowelsHash.h"
int CountVowelsHash::Method(const char* s) {
    int x = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <='Z'))
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                x++;
    return x;
}