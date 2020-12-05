


//  final 告诉编译器，它不能被继承，不能被重载


struct Base1 final{};

struct Derived1:Base1{}; // 报错，不能被继承   不能将“final”类类型用作基类C/C++(1904)

struct  Base2 {
    virtual void f() final;
};

struct Derived2:Base2{
    void f(); // 报错，不能被重载    无法重写“final”函数 "Base2::f" (已声明 所在行数:12)C/C++(1850)
}; 
