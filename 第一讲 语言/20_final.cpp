


//  final ���߱������������ܱ��̳У����ܱ�����


struct Base1 final{};

struct Derived1:Base1{}; // �������ܱ��̳�   ���ܽ���final����������������C/C++(1904)

struct  Base2 {
    virtual void f() final;
};

struct Derived2:Base2{
    void f(); // �������ܱ�����    �޷���д��final������ "Base2::f" (������ ��������:12)C/C++(1850)
}; 
