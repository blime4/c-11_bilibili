
//----------------------------------------------------------------
// 就是初始化变量的时候，都可以统一使用{}来初始化

// eg:
#include<vector>
#include<complex>
using namespace std;

int values[] = {1,2,3};
vector<int> v {2,3,4,5,6};
vector<string> citis{
    "Berlin","New York"
};
complex<double> c{4.0,3.0}; //复数

//解释
/*
编译器看到{t1,t2,t3,,,tn}的时候， 会做出一个initializer_list<T>
这个initializer_list<T>其实是用array<T,n>做出来的
然后再将array里面的元素，通过函数（例如ctor）分解逐一传给函数



如果函数参数也是一个initializer_list<T>，他就会将整一个initializer_list<T>给传回去。
（就是要看传回去的构造函数，函数中要的是initializer_list<T>，就传回initializer_list<T>，否则，将array<T,n>中元素拆开传回去）

这里看不懂也没关系，后面还会详解 比如可以看看08 第三个小例子

*/