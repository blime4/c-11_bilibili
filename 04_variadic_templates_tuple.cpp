#include<functional>

template<typename... Values> class tuple;
template<> class tuple<>{};

template<typename Head,typename...Tail>
class tuple<Head,Tail...> : private tuple<Hail...>{
    typedef tuple<Tail...> inherited;
public:
    tuple(){}
    tuple(Head v,Tail... vtail):m_head(v),inherited(vtail...){}
    typename Head::typr head(){return m_head;}
    inherited&tail(){return *this;}
protected:
    Head m_head;
};