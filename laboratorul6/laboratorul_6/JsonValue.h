#pragma once
#include <iostream>
#include <string>
using namespace std;

class JsonValue {
  public:
    virtual ~JsonValue() = 0;
    virtual void print(std::ostream& out) const = 0;
};

class ArrayValue : public JsonValue {
    JsonValue* arry[16];
    int count;

  public:
    ~ArrayValue();
    ArrayValue();
    void add(JsonValue* val);
    void print(std::ostream& out) const override;
};

class NumberValue : public JsonValue {
    int number;

  public:
    ~NumberValue();
    NumberValue(int n);
    void print(std::ostream& out) const override;
};

class StringValue : public JsonValue {
    char string[256];

  public:
    ~StringValue();
    StringValue(const char* str);
    void print(std::ostream& out) const override;
};
struct obj {
    JsonValue* value;
    string nume;
};
class ObjectValue : public JsonValue {
  private:
    obj vector[16];
    int count;

  public:
    ~ObjectValue();
    ObjectValue();
    void add(string nume, JsonValue* val);
    operator unsigned() const;
    void print(std::ostream& out) const override;
};

class BoolValue : public JsonValue {
  private:
    bool value;

  public:
    ~BoolValue();
    BoolValue(bool c);
    void print(std::ostream& out) const override;
};

class NullValue : public JsonValue {
  public:
    ~NullValue();
    NullValue();
    void print(std::ostream& out) const override;
};
