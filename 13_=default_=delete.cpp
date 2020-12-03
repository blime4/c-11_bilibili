/*
��������ж�����һ��ctor�����������Ͳ����ٸ���һ��default ctor o
�����ǿ�Ƽ���=default,�Ϳ������«P��֤ʹ��default ctor 
*/


class Foo{
public:
    Foo(int i):_i(i){}
    Foo() = default; // �������������������
    Foo(const Foo& x):_i(x._i){}
    // FOO(const Foo&) = default            // �����������ظո�д��Foo(const Foo& x)
    // Foo(const Foo&) = delete;            // �����������ظո�д��Foo(const Foo& x)
    Foo& operator=(const Foo& x) { _i = x._i; return *this; }
    // Foo& operator=(const Foo&) = default;        // �����������ظո�д��
    // Foo& operator=(const Foo&) = delete;         // �����������ظո�д��

    void func2() = delete;
    ~Foo() = default;

private:
    int _i;
};

/*
=default;��� Big-Five֮���Ǻ���)?�������壬�������         

    ���캯��
    ��ͨ����
    ��������
    ���ƹ��캯��
    operator=

=delete;������κκ�������.(0ֻ���virtual����)
*/