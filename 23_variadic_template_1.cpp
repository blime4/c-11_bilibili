


//  这个就是 02 的例子


#include<iostream>
#include<bitset>

using namespace std;

void myprint(){} //处理剩下零个参数的时候，什么都不做

template<typename T, typename... Types>    // 偏特化
void myprint(const T&firsrArg,const Types&... args){
    cout<<firsrArg<<endl;
    myprint(args...);
}

int main(){
    myprint(123,"abc",bitset<16>(250),1.2);
}

/*
123
abc
0000000011111010
1.2
*/