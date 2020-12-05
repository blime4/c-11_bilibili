

struct Base{
    virtual void vfunc(float){ }
};
struct Derived1:Base{
    virtual void vfunc(int){ }
    //   我们想重写，但是参数写错了，编译器就不会以为我峨嵋你是重写，而是以为我们在构建一个新的函数

};

struct Derived2:Base{
    virtual void vfunc(int) override {};
    //   我们告诉了编译器，我们要重写，如果写错了，编译器会报错


    virtual void vfunc(float) override {};
    //   ok

}