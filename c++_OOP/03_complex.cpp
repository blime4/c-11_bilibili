#include<iostream>
using namespace std;

class complex{
public:
    complex(double r,double i) :re(r),im(i) {}
    complex& operator += (const complex&);
    double real() const { return re;}   // 如果你的函数，没有改变data，一定要加上const
    double imag() const { return im;}

    double no_real() { return re;;}
    double no_imag() { return im;}

    int func(const complex& param){  // 相同class的各个object互为友元  
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



// 全域函数
inline double
imag(const complex& x){
    return x.imag();
}

inline double
real(const complex& x){
    return x.real();
}

// 非成员函数重载

inline complex  // 这里一定要return by value，如果是引用的话，临时对象死掉了，引用就会出错
operator + (const complex& x,double y){
    return complex (real (x) + y,imag(x));  // 这里是创建一个临时对象，然后马上返回。
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

    // // 测试一下没有const的情况
    // cout<<c1.no_real()<<endl;    //立刻报错
    // cout<<c1.no_imag()<<endl;

    // 全域函数
    cout<<imag(c1)<<endl;
    cout<<real(c1)<<endl;
}