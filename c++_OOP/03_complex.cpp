#include<iostream>
using namespace std;

class complex{
public:
    complex(double r,double i) :re(r),im(i) {}
    complex& operator += (const complex&);
    double real() const { return re;}   // �����ĺ�����û�иı�data��һ��Ҫ����const
    double imag() const { return im;}

    double no_real() { return re;;}
    double no_imag() { return im;}

    int func(const complex& param){  // ��ͬclass�ĸ���object��Ϊ��Ԫ  
        return param.re + param.im;
    }


private:
    double re,im;

    friend complex& __doapl (complex*,const complex&);
};

inline complex&
__doapl (complex* ths,const complex& r){
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}



// ȫ����
inline double
imag(const complex& x){
    return x.imag();
}

inline double
real(const complex& x){
    return x.real();
}

// �ǳ�Ա��������

inline complex  // ����һ��Ҫreturn by value����������õĻ�����ʱ���������ˣ����þͻ����
operator + (const complex& x,double y){
    return complex (real (x) + y,imag(x));  // �����Ǵ���һ����ʱ����Ȼ�����Ϸ��ء�
}

inline complex
operator + (double x,const complex& y){
    return complex (x+real(y),imag(y));
}

inline complex
operator + (const complex& x){
    return x;
}

inline complex
operator - (const complex& x){
    return complex (-real(-x),-imag(x));
}

ostream& operator << (ostream& os , const complex& x){
    return os << "(" <<real(x) << "," << imag(x) << ")";
}

int main(){
    const complex c1(2,1);
    cout<<c1.real()<<endl;
    cout<<c1.imag()<<endl;

    // // ����һ��û��const�����
    // cout<<c1.no_real()<<endl;    //���̱���
    // cout<<c1.no_imag()<<endl;

    // ȫ����
    cout<<imag(c1)<<endl;
    cout<<real(c1)<<endl;
}