#ifndef RWPROPERTY_HPP
#define RWPROPERTY_HPP

template <class T, class Object,              // プロパティの型、オーナーの型
          T (Object::*real_getter)() const,   // getter
          T (Object::*real_setter)(const T &) // setter
          >
class RWProperty
{
    Object *my_object;

public:
    using value_type = T;

    // プロパティのオーナー(所有者) を設定
    void operator()(Object *obj) { my_object = obj; }

    // 関数呼び出しによるGet,Set
    T operator()() const { return (my_object->*real_getter)(); }
    T operator()(const T &value) { return (my_object->*real_setter)(value); }

    // メンバ関数Get,Set
    T get() const { return (my_object->*real_getter)(); }
    T set(const T &value) { return (my_object->*real_setter)(value); }

    // =演算子によるアクセス
    operator T() const { return (my_object->*real_getter)(); }
    T operator=(const T &value) { return (my_object->*real_setter)(value); }
};

#endif // RWPROPERTY_HPP