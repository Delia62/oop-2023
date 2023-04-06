#pragma once
#include "Hash.h"

class CountVowelsHash : public Hash {
  public:
    int Method(const char*) override;
};
