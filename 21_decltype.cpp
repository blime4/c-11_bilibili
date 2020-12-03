

// 用法一：声明返回类型

template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x+y);

// 用法二：在函数模板中使用

template<typename T>
void test_decltype(T obj) {
    ...
    // 这里模拟很复杂的操作，以至于我们忘了obj的类型，然后我们就可以用decltype

    typedef typename decltype(obj)::iterator iType;
    // 相当于 typedef typename T::iterator(obj);
}


// 用法三： 在lambda中使用

auto cmp = [](const Person& p1,const Person& p2) {
    return p1.last_name()<p2.last_name();
}

std::set<Person,decltype(cmp)>coll(cmp);