#include "HashManager.h"
#include "Hash.h"
#include <cstdio>

void HashManager::print_hashes(const char* s) {
    for (int i = 0; i < count; i++)
        printf("%s, %d\n", lung_hash[i].nume, lung_hash[i].hash->Method(s));
}
HashManager::HashManager() {
    count = 0;
}
Hash*& HashManager::operator[](const char* s) {
    lung_hash[count].nume = s;
    return lung_hash[count++].hash;
}
int HashManager::Method(const char* s) {
    int x = 0;
    for (int i = 0; s[i] != '\0'; i++)
        x += (int) s[i];
    return x;
}