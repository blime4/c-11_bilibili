 




void foo() noexcept; // 就是在这个函数的时候，不抛异常,异常会在调用这个函数的上一层抛异常，如果一直不抛异常，最终的std::terminate()函数还是会调用std::abort(),抛异常中断程序
// 相当于 void foo() noexcept（true)；·

void swap(Type& x,Type& y) noexcept(noexcept(x.swap(y))){  // 这里就是，如果x.swap(y)不出错。则这个函数不抛异常。
    x.swap(y);
}

 /*

 You need to inform C++(specifically std:vector) that your move constructorand destructor does not throw. 
 Then the move constructor will be called whenthe vector grows. 
 If the constructor is not noexcept, std::vector can't use it.
 since then it can't ensure the exception guarantees demanded by the standard.

 翻译就是，如果想让你写的函数，容器里面也有，容器选择用你的函数，而不用本身自带的，你一定要告诉容易，你的函数，不会报异常，这样容器才敢用

 */


// 伪代码


class MySting{
private:
    char* _data;
    size_t _len;
...
public:
    MySting(MySting&& str) noexcept : _data(str._data), _len(str._len){...}
    MySting& operator=(MySting&& str) noexcept{...return *this;}
}