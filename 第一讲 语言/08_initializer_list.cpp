// 1
// {} 可以用来设定初值
//eg:

int i ;         // i has undefined value
int j{ };       // j is initialized by 0
int * p;        // p has undefined value
int* g{ };      // q is initialized by nullptr










// 2
// initializer_list<> 的例子 这里用到了 int 的
#include<iostream>
#include<initializer_list>

// void myprint(){}
void myprint(std::initializer_list<int> vals){
    for(auto p = vals.begin(); p != vals.end(); ++p){   // 因为他就是基于array 做出来的嘛
        std::cout << *p << "\n";
    }
}

int main(){
    myprint( {12,3,5,7,11} );
    return 0;
}


/*
12
3
5
7
11
*/











// 3

using namespace std;

class P{
public:
    P(int a,int b){
        cout << "P(int,int),a="<<a<<",b="<<b<<endl;
    }
    P(initializer_list<int> initlist){
        cout << "P(initializer_list<int>),values= ";
        for(auto i : initlist){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(){
    P p(77,5);  // 括号
    P q{77,5};  // 大括号
    P r{77,5,42};
}

/*
P(int,int),a=77,b=5
P(initializer_list<int>),values= 77 5 
P(initializer_list<int>),values= 77 5 42
*/





// 4  源码分析
// 这里的源码分析，简单提一下，就跳过吧，后面的版本和视频中提到的，构造initializer_list不同了。

//视频中提到的是，编译器发现有{}，就会调用initializer_list的私有函数  constexpr initializer_list(const_iterator __a,size_type __l):_M_array(__a),_M_len(__l){} 来创建一个array 