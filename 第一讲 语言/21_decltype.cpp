

// �÷�һ��������������

template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x+y);

// �÷������ں���ģ����ʹ��

template<typename T>
void test_decltype(T obj) {
    ...
    // ����ģ��ܸ��ӵĲ�������������������obj�����ͣ�Ȼ�����ǾͿ�����decltype

    typedef typename decltype(obj)::iterator iType;
    // �൱�� typedef typename T::iterator(obj);
}


// �÷����� ��lambda��ʹ��

auto cmp = [](const Person& p1,const Person& p2) {
    return p1.last_name()<p2.last_name();
}

std::set<Person,decltype(cmp)>coll(cmp);