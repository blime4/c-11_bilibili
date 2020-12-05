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
    typename Head::type head(){return m_head;}     // 这个是有问题的，会提示编译不通过，因为不能推出Head::type
    // 在后面老师也会提到，应该用以下两种方法。
    // 1
    // Head head(){return m_head;} 
    // 2
    // auto head()->decltype(m_head) {return m_head;}
    inherited&tail(){return *this;}

};