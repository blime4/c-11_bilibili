#include<iostream>

template<typename _Tp ,std::size_t _Nm>
struct array{
    typedef _Tp         value_type;
    typedef _Tp*        pointer;
    typedef value_type* iterator;

    value_type _M_instances[_Nm?_Nm:1];                      // �����ں����ʦ��STLԴ�������Ҳ˵��������array<int,0>,Ҳ�ǿ��Եģ�����Ĭ�ϸ�������1�ռ�,
    iterator begin(){return iterator(&_M_instances[0]);}
    iterator end(){return iterator(&_M_instances[_Nm]);}
    //����һЩ����ʡ��
};




// ����array ���������п������ʦ��STLԴ������ɡ�