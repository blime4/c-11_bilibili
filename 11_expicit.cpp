// 1
// explicit ���÷�
// explicit ��ȷָ���ǲŵ��ã���ֹ��������ʽ���и�ʽת��


struct Complex {
    int real,imag;

    Complex(int re,int im=0):real(re),imag(im){}
    Complex operator+(const Complex &x){ return Complex((real+x.real),(imag+x.imag));}
};

struct Complex_1 {
    int real,imag;

    explicit 
    Complex_1(int re,int im=0):real(re),imag(im){}
    Complex_1 operator+(const Complex_1 &x){ return Complex_1((real+x.real),(imag+x.imag));}
};

int main(){

    Complex c1(12,5); 
    Complex c2 = c1 +5 ;     // ok  ��ʽ��5����Complex(5)

    Complex_1 c3(12,5);
    Complex_1 c4 = c3 + 5 ;  // error ��������ʽ���ã�����  error: no match for 'operator+' (operand types are 'Complex_1' and 'int')

}


// 2 
// explicit for ctors taking more than one argument 
// �°汾���ԣ�����βε�ʱ��Ҳ������explicit

#include <iostream>
using namespace std;

class P{
public:
    explicit P(int a,int b,int c){
        cout << a << b << c <<endl;
    }
};



