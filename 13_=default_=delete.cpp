/*
如果你自行定羲了一固ctor，那麽编辉器就不曾再给你一固default ctor o
如果你强制加上=default,就可以重新玃得证使用default ctor 
*/


class Foo{
public:
    Foo(int i):_i(i){}
    Foo() = default; // 和上面的析构函数共存
    Foo(const Foo& x):_i(x._i){}
    // FOO(const Foo&) = default            // 出错，不能重载刚刚写的Foo(const Foo& x)
    // Foo(const Foo&) = delete;            // 出错，不能重载刚刚写的Foo(const Foo& x)
    Foo& operator=(const Foo& x) { _i = x._i; return *this; }
    // Foo& operator=(const Foo&) = default;        // 出错，不能重载刚刚写的
    // Foo& operator=(const Foo&) = delete;         // 出错，不能重载刚刚写的

    void func2() = delete;
    ~Foo() = default;

private:
    int _i;
};

/*
=default;用於 Big-Five之外是何意)?→无意义，编译出错         

    构造函数
    普通函数
    析构函数
    复制构造函数
    operator=

=delete;可用於任何函数身上.(0只能於virtual函教)
*/