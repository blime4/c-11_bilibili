class A{
public:
    static A& getInstance() {};
    setup(){...};
private:
    A();
    A(const A& rhs);
    ...
};

A& A::getInstance(){
    static A a;
    return a;
}

int main(){
    //���÷���
    
    A::getInstance().setup();
}