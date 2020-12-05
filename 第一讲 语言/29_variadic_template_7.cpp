#include<iostream>
#include<string>

using namespace std;

template<typename... Values> class tup;
template<> class tup<>{};

template<typename Head,typename ...Tail>
class tup<Head, Tail...>
{
    typedef tup<Tail...> composited;
protected:
    composited m_tail;
    Head m_head;
public:
    tup(){}
    tup(Head v,Tail... vtail):m_head(v),m_tail(vtail...){}
    Head head(){ return m_head;}
    composited& tail(){ return m_tail;}
};


int main(){ 
    tup<int,float,string> it1(41,6.3,"nico");
    cout << sizeof(it1) <<endl;
    cout << it1.head() <<endl;
    cout << it1.tail().head() <<endl;
    cout << it1.tail().tail().head() <<endl;


    return 0;
}

/*
56    //ÕâÀï²»Ì«¶®
41
6.3
nico
*/