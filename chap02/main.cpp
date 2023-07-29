
#include <iostream>

#include "RWProperty.hpp"
#include "Phonebook.hpp"

using namespace std;

class Cat
{
    int age_;
    string name_;

private:
    int set_age(const int &age) { return age_ = age; }
    int get_age() const { return age_; }
    string set_name(const string &name) { return name_ = name; }
    string get_name() const { return name_; }

public:
    RWProperty<int, Cat, &Cat::get_age, &Cat::set_age> age;
    RWProperty<string, Cat, &Cat::get_name, &Cat::set_name> name;

    Cat()
    {
        age(this);
        name(this);
    }
};



int main(int, char **)
{
    Cat cat;
    cat.age = 4;
    cat.name = "tama";
    int age = cat.age;
    string name = cat.name;

    cout << name << " is " << age << " years old.\n";


    Phonebook<vector> pb; // どのコンテナを使うかはここで指定。
    pb.add("police", "110");
    pb.add("fire", "119");
    pb.add("weather", "177");
    pb.print(std::cout);
}
