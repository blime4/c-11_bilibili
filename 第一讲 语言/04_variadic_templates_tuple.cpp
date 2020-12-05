#include<functional>

template<typename... Values> class tuple;
template<> class tuple<>{};

template<typename Head,typename...Tail>
class tuple<Head,Tail...> : private tuple<Hail...>{
    typedef tuple<Tail...> inherited;
protected:
    Head m_head;
public:
    tuple(){}
    tuple(Head v,Tail... vtail):m_head(v),inherited(vtail...){}
    typename Head::type head(){return m_head;}     // �����������ģ�����ʾ���벻ͨ������Ϊ�����Ƴ�Head::type
    // �ں�����ʦҲ���ᵽ��Ӧ�����������ַ�����
    // 1
    // Head head(){return m_head;} 
    // 2
    // auto head()->decltype(m_head) {return m_head;}
    inherited&tail(){return *this;}

};