#pragma once
#include "Hash.h"
class HashManager : public Hash {
  public:
    struct hash_elem {
        Hash* hash;
        const char* nume;
    } lung_hash[4];
    int count;
    int Method(const char*) override;
    void print_hashes(const char*);
    HashManager();
    Hash*& operator[] (const char*);
};
