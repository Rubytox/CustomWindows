//
// Created by cFAG on 23/05/2020.
//

#include "ModularInt.h"

void ModularInt::add(int offset) {
    _value += offset;
    _value = realModulo(_value, _modulus);
}

void ModularInt::mult(int factor) {
    _value *= factor;
    _value = realModulo(_value, _modulus);
}

ModularInt::ModularInt(int value, int modulus) : _modulus(modulus) {
    _value = realModulo(value, modulus);
}

ModularInt::ModularInt(const ModularInt &other) : _modulus(other._modulus) {
    _value = realModulo(other._value, other._modulus);
}

bool ModularInt::equals(const ModularInt &other) const {
    return _value == other._value;
}

int ModularInt::realModulo(int a, int b) {
    return (a % b + b) % b;
}

bool ModularInt::lower(const ModularInt &other) const {
    return _value < other._value;
}

int ModularInt::getValue() const {
    return _value;
}

ModularInt& ModularInt::operator+=(ModularInt const& other) {
    if (_modulus != other._modulus) {
        throw std::invalid_argument("Both operands must have the same modulus.");
    }
    this->add(other._value);

    return *this;
}

ModularInt& ModularInt::operator-=(ModularInt const& other) {
    if (_modulus != other._modulus) {
        throw std::invalid_argument("Both operands must have the same modulus.");
    }
    this->add(-other._value);

    return *this;
}

ModularInt& ModularInt::operator*=(ModularInt const& other) {
    if (_modulus != other._modulus) {
        throw std::invalid_argument("Both operands must have the same modulus.");
    }
    this->mult(other._value);

    return *this;
}

ModularInt &ModularInt::operator++() {
    add(1);
    return *this;
}

ModularInt ModularInt::operator++(int) {
    ModularInt tmp = *this;
    ++*this;
    return tmp;
}

ModularInt &ModularInt::operator--() {
    add(-1);
    return *this;
}

ModularInt ModularInt::operator--(int) {
    ModularInt tmp = *this;
    --*this;
    return tmp;
}



bool operator==(ModularInt const& a, ModularInt const& b) {
    return a.equals(b);
}

bool operator!=(ModularInt const& a, ModularInt const& b) {
    return !(a == b);
}

bool operator<(ModularInt const& a, ModularInt const& b) {
    return a.lower(b);
}

bool operator<=(ModularInt const& a, ModularInt const& b) {
    return (a < b) || (a == b);
}

bool operator>(ModularInt const& a, ModularInt const& b) {
    return !(a <= b);
}

bool operator>=(ModularInt const& a, ModularInt const& b) {
    return !(a < b);
}

ModularInt operator+(ModularInt const& a, ModularInt const& b) {
    ModularInt copy(a);
    return copy += b;
}

ModularInt operator-(ModularInt const& a, ModularInt const& b) {
    ModularInt copy(a);
    return copy -= b;
}

ModularInt operator*(ModularInt const& a, ModularInt const& b) {
    ModularInt copy(a);
    return copy *= b;
}

int operator+(int left, const ModularInt& right) {
    return left += right.getValue();
}
