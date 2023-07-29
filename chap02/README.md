# Chapter 2 テンプレートの基礎

テンプレートクラスの実装をcppとhppに分けたいなら、cppに明示的に実体化を書けば良い。
関数単位での実体化も可能。

```cpp :sample.hpp
template <class T>
class MyClass {
public:
    void func();
};
```

```cpp :sample.cpp
template class MyClass<int>;
template void MyClass<int>::func();
```


## Two-Phase Name Lookup

テンプレートの名前解決は2段階。

**テンプレートが定義された時点 Point of Definition**
テンプレートパラメータに依存しない名前の解決が行われる。
non-dependent name

**テンプレートがインスタンス化された(使われた)時点 Point of Instantiation**
テンプレートパラメータに依存する名前の解決が行われる。
dependent name

## typename限定子

`<`と`>`が比較演算子と解釈されないようにできる。

```cpp
template<class T>
int foo(T x, int n)
{
    return x.template get<3>(n);
}
```

## 明示的特殊化

具体的な型に対する特殊化。

```cpp
template<class T>
void print(T x) { std::cout << x << endl; }

template<>
void print(std::string x) { std::cout << '"' << x << '"' << endl; }
```

## 部分特殊化

特定の型のパターンに対する特殊化。

```cpp
template<class T>
void print(T x) { std::cout << x << endl; }

template<class T>
void print(T* x) { std::cout << *x << endl; }
```

```cpp
namespace std {
    template<class Iterator>
    struct iterator_traits {
        typedef value_type = Iterator::value_type;
        //...
    };

    // ポインタに対する部分特殊化
    template<class T>
    struct iterator_traits<T*> {
        typedef value_type = T;
        //...
    };
}

template<class Iterator>
typename std::iterator_traits<Iterator>::value_type
    get_value(Iterator iter)
{
    return *iter;
}
```

## 関数の呼び出し優先順位

```cpp
template<class T> T sqrt(T);
template<class T> complex<T> sqrt(complex<T>);
double sqrt(double);

complex<double> z;

sqrt(2); 
// → sqrt<int>(int)
// 引数intが型変換されずに呼ばれる。

sqrt(2.0); 
// → sqrt(double)
// テンプレートでない関数が優先的に呼ばれる

sqrt(z);  
// → sqrt(complex<double>)
// 最も専門特化しているテンプレート関数が呼ばれる
```