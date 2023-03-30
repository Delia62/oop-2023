#define _CRT_SECURE_NO_WARNINGS
#include "JsonValue.h"
#include <string.h>

void ArrayValue::add(JsonValue* val) {
    if (count == 16)
        return;
    else {
        arry[count] = val;
        count++;
    }
}
ArrayValue::~ArrayValue() {
    delete[] arry;
}

ArrayValue::ArrayValue() {
    count = 0;
}

void ArrayValue::print(std::ostream& out) const {
    out << "[";
    for (int i = 0; i < count; i++) {
        arry[i]->print(out);
        if (i != count - 1)
            out << ", ";
    }
    out << "]";
}

void ObjectValue::add(string nume, JsonValue* val) {
    if (count == 16)
        return;
    else {
        vector[count].nume = nume;
        vector[count].value = val;
        count++;
    }
}
ObjectValue::ObjectValue() {
    count = 0;
}
ObjectValue::~ObjectValue() {
    delete[] vector;

}
void ObjectValue::print(std::ostream& out) const {
    out << "{";
    for (int i = 0; i < count; i++) {
        out << '"' << vector[i].nume << '"' << ": ";
        vector[i].value->print(out);
        if (i != count - 1)
            out << ", ";
    }
    out << "}";
}

void NumberValue::print(std::ostream& out) const {
    out << number;
}
NumberValue::NumberValue(int n) {
    number = n;
}
NumberValue::~NumberValue() {
}
void StringValue::print(std::ostream& out) const {
    out << '"' << string << '"';
}
StringValue::~StringValue() {
    delete string;
}
StringValue::StringValue(const char* str) {
    strcpy(string, str);
}

void BoolValue::print(std::ostream& out) const {
    out << (value ? "true" : "false");
}
BoolValue::BoolValue(bool c) {
    value = c;
}
BoolValue::~BoolValue() {
}
void NullValue::print(std::ostream& out) const {
    out << "null";
}
NullValue::NullValue() {
}
NullValue::~NullValue() {
}
ObjectValue::operator unsigned() const {
    return count;
}
JsonValue::~JsonValue() {
}
