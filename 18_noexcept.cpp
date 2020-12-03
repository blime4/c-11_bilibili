 




void foo() noexcept; // ���������������ʱ�򣬲����쳣,�쳣���ڵ��������������һ�����쳣�����һֱ�����쳣�����յ�std::terminate()�������ǻ����std::abort(),���쳣�жϳ���
// �൱�� void foo() noexcept��true)����

void swap(Type& x,Type& y) noexcept(noexcept(x.swap(y))){  // ������ǣ����x.swap(y)��������������������쳣��
    x.swap(y);
}

 /*

 You need to inform C++(specifically std:vector) that your move constructorand destructor does not throw. 
 Then the move constructor will be called whenthe vector grows. 
 If the constructor is not noexcept, std::vector can't use it.
 since then it can't ensure the exception guarantees demanded by the standard.

 ������ǣ����������д�ĺ�������������Ҳ�У�����ѡ������ĺ����������ñ����Դ��ģ���һ��Ҫ�������ף���ĺ��������ᱨ�쳣�����������Ÿ���

 */


// α����


class MySting{
private:
    char* _data;
    size_t _len;
...
public:
    MySting(MySting&& str) noexcept : _data(str._data), _len(str._len){...}
    MySting& operator=(MySting&& str) noexcept{...return *this;}
}