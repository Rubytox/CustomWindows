//
// Created by cFAG on 23/05/2020.
//

#pragma once

#include <stdexcept>

/**
 * Invariant: _value is always in the range [0, _modulus[.
 */
class ModularInt {
private:
    int _value;
    int _modulus;

    void add(int offset);
    void mult(int factor);
    static int realModulo(int a, int b);

public:
    ModularInt(int value, int modulus);
    ModularInt(ModularInt const& other);

    [[nodiscard]] int getValue() const;

    [[nodiscard]] bool equals(ModularInt const& other) const;
    [[nodiscard]] bool lower(ModularInt const& other) const;

    ModularInt& operator+=(ModularInt const& other);
    ModularInt& operator++();  // prefix
    ModularInt operator++(int);   // postfix

    ModularInt& operator-=(ModularInt const& other);
    ModularInt& operator--();  // prefix
    ModularInt operator--(int);   // postfix

    ModularInt& operator*=(ModularInt const& other);
};

bool operator==(ModularInt const& a, ModularInt const& b);
bool operator!=(ModularInt const& a, ModularInt const& b);
bool operator<(ModularInt const& a, ModularInt const& b);
bool operator<=(ModularInt const& a, ModularInt const& b);
bool operator>(ModularInt const& a, ModularInt const& b);
bool operator>=(ModularInt const& a, ModularInt const& b);

ModularInt operator+(ModularInt const& a, ModularInt const& b);
ModularInt operator-(ModularInt const& a, ModularInt const& b);
ModularInt operator*(ModularInt const& a, ModularInt const& b);
int operator+(int left, const ModularInt& right);


