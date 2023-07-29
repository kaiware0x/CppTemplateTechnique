#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Object.hpp"


class Vector : public Object
{
private:
    /* data */
    Object **data_;
    int capacity_;
    int size_;

public:
    Vector() : data_(0), capacity_(0), size_(0) {}
    ~Vector()
    {
        for (int i = 0; i < size_; i++)
        {
            delete data_[i];
        }
        delete[] data_;
    }

    void add(Object *item)
    {
        /// 格納領域が不足するなら、領域の再割当てを行う.
        if (size_ == capacity_)
        {
            capacity_ += 10;
            Object **tmp = new Object *[capacity_];
            for (int i = 0; i < size_; i++)
            {
                tmp[i] = data_[i];
            }

            delete[] data_;
            data_ = tmp;
        }

        data_[size_++] = item;
    }

    Object *at(int index)
    {
        if (index < 0 || index >= size_)
        {
            return nullptr;
        }
        return data_[index];
    }

    int size() const { return size_; }
};


#endif