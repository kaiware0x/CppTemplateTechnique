#ifndef INTEGER_HPP
#define INTEGER_HPP

#include "Object.hpp"

class Integer : public Object
{
private:
    int value_;

public:
    Integer(int v) : value_(v) {}
    int value() const { return value_; }
};

#endif