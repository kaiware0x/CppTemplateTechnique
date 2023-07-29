#ifndef DEFINE_MAX_HPP
#define DEFINE_MAX_HPP

#define name2(x, y) x##y
#define declare(x, y) name2(x, declare)(y)
#define implement(x, y) name2(x, implement)(y)

// 関数MAXの 宣言 に展開される
#define MAXdeclare(type) \
    type MAX(type)(type x, type y);

// 関数MAXの定義に展開される
#define MAXimplement(type)         \
    type MAX(type)(type x, type y) \
    {                              \
        return x < y ? y : x;      \
    }

// MAX(###) を MAX### に置換する
#define MAX(type) name2(MAX, type)

#endif // DEFINE_MAX_HPP