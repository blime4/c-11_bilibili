
// ��
//����ֱ���õ�08 �����Ӱ�
#include<iostream>
#include<initializer_list>

// void myprint(){}
void myprint(std::initializer_list<int> vals){
    for(auto p = vals.begin(); p != vals.end(); ++p){   // ��Ϊ�����ǻ���array ����������
        std::cout << *p << "\n";
    }
}

int main(){
    myprint( {12,3,5,7,11} );
    return 0;
}