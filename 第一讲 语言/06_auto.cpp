
// 略
//这里直接用到08 的例子吧
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