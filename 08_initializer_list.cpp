// 1
// {} ���������趨��ֵ
//eg:

int i ;         // i has undefined value
int j{ };       // j is initialized by 0
int * p;        // p has undefined value
int* g{ };      // q is initialized by nullptr










// 2
// initializer_list<> ������ �����õ��� int ��
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
    P p(77,5);  // ����
    P q{77,5};  // ������
    P r{77,5,42};
}

/*
P(int,int),a=77,b=5
P(initializer_list<int>),values= 77 5 
P(initializer_list<int>),values= 77 5 42
*/





// 4  Դ�����

