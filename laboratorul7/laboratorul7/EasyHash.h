#pragma once
#include "Hash.h"
class EasyHash : public Hash {
  public:
    int Method(const char*) override;
};
