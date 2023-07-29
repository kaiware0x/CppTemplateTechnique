#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

// テンプレートクラス自体を型引数に取る.
template <
    template <class T, class A = allocator<T>>
    class Container
>
class Phonebook
{
    struct Record
    {
        string name;
        string phone;
        Record(const string &n, const string &p) : name(n), phone(p) {}
        friend ostream &operator<<(ostream &stream, const Record &r)
        {
            return stream << r.name << ':' << r.phone;
        }
    };

    // コンテナの中身の型はここで指定。
    Container<Record> book;

public:
    void add(const string &name, const string &phone)
    {
        book.emplace_back(name, phone);
    }
    void print(ostream &stream) const
    {
        copy(begin(book), end(book),
             ostream_iterator<Record>(stream, "\n"));
    }
};

#endif // PHONEBOOK_HPP