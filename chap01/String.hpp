#ifndef STRING_HPP
#define STRING_HPP

#include "Object.hpp"

#include <cstring>

class String : public Object
{
private:
    char *value_;

public:
    String(const char *str)
    {
        strcpy(value_ = new char[strlen(str) + 1], str);
    }
    ~String()
    {
        delete[] value_;
    }

    const char *value() const { return value_; }
};

#endif // STRING_HPP