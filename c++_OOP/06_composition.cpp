#include <deque>
using namespace std;


template<class T>
class queue{
protected:
    deque<T> c;
public:
    bool empty() const { return c.empty(); }
    size_type size() const { return c.size(); }
    reference front() { return c.front(); }
    reference back() { return c.back(); }

    void push(const value_type& x){c.push_back(x);}
    void pop() {c.pop_front();}
};