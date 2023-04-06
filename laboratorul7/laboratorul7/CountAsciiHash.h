#pragma once
#include "Hash.h"
class CountAsciiHash : public Hash{
  public:
    int Method(const char*) override;
    //int countAscii(const char* s);
};

