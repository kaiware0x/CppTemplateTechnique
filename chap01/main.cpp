
#include <iostream>

#include "Vector.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "DefineMax.hpp"

using namespace std;

declare(MAX, int)
declare(MAX, double)

implement(MAX, int)
implement(MAX, double)

int main(int, char**){
    Vector v;
    v.add(new Integer(12));
    v.add(new Integer(34));
    v.add(new String("mistake"));

    // Integer n(567);
    // v.add(&n); // NG

    for (int i = 0; i < v.size(); i++)
    {
        auto ptr = static_cast<Integer*>(v.at(i));
        cout << ptr->value() << endl;
    }

    int i = 0, j = 2;
    double u = 1.23, vv = 0.12;

    cout << MAX(int)(i, j) << endl;
    cout << MAX(double)(u, vv) << endl;
}
