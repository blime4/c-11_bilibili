


//  ������� 02 ������


#include<iostream>
#include<bitset>

using namespace std;

void myprint(){} //����ʣ�����������ʱ��ʲô������

template<typename T, typename... Types>    // ƫ�ػ�
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