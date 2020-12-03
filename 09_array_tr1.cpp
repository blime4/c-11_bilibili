#include<iostream>

template<typename _Tp ,std::size_t _Nm>
struct array{
    typedef _Tp         value_type;
    typedef _Tp*        pointer;
    typedef value_type* iterator;

    value_type _M_instances[_Nm?_Nm:1];                      // 这里在侯捷老师的STL源码分析课也说到，就是array<int,0>,也是可以的，就是默认给他分配1空间,
    iterator begin(){return iterator(&_M_instances[0]);}
    iterator end(){return iterator(&_M_instances[_Nm]);}
    //还有一些方法省略
};




// 关于array 还是请自行看侯捷老师的STL源码分析吧。