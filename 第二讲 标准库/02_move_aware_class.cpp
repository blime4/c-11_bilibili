#include<iostream>
#include<string>

using namespace std;


struct MyString{
public:                         // 测试程序用
    static size_t DCtor;        // 累计default_ctor的呼叫次数，以下类推
    static size_t Ctor;         // ctor
    static size_t CCtor;        // copy_ctor
    static size_t CAsgn;        // copy_asgn
    static size_t MCtor;        // move_ctor
    static size_t MAsgn;        // move_asgn
    static size_t Dtor;         // dtor
private:
    char* _data; 
    size_t _len;
    void _init_data(const char *s){
        _data = new char[_len + 1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    };
public:
    
    // default constructor
    MyString() : _data(NULL), _len(0) {++DCtor;}
    
    // constructor
    MyString(const char *p):_len(strlen(p)){
        ++Ctor;
        _init_data(p);
    }

    // copy constructor
    MyString(const MyString & str) : _len(str._len){
        ++CCtor;
        _init_data(str._data);
    }

    // move constructor  这里就是右值引用 一定要noexcept
    MyString(MyString&& str) noexcept : _data(str._data), _len(str._len){
        ++MCtor;
        str._len = 0;           // 把原来的长度设为零
        str._data = NULL;       // 然后将原来的指针指向空，重要，这一步是交给析构函数判断，
                                // 如果没有设置为空，在调用结束之后，str的析构函数，就会将str._data的东西给释放掉。
                                // 然后赋值的_data就会指向一个空内容，变成野指针（我猜的）
                                // 所以在析构函数还要声明①
    }

    // copy assignment
    MyString& operator = (const MyString& str){
        ++CAsgn;
        // 自我赋值检查
        if(this != &str){ // 是不是自己赋值自己
            if(_data) delete _data;  //先把原来的内容释放
            _len = str._len;
            _init_data(str._data); // copy
        }else{}     // 自己赋值自己，什么都不用做
        return *this;
    }

    // move assignment
    MyString& operator=(MyString&& str) noexcept{
        ++MAsgn;
        // 自我赋值检查
        if(this != &str){
            if(_data) delete _data;
            _len = str._len;
            _data = str._data; // MOVE ， 浅拷贝
            str._len = 0;
            str._data = NULL; // 重要
        }
        return *this;
    }

    // dtor
    virtual ~MyString() {
        ++Dtor;
        // 声明①
        if(_data){ // 如果不是NULL的话，就删掉，指向内容，是NULL的话，说明已经有人在用了，就不要删除了
            delete _data;
        }
    }

    // 以下仍是测试用到的代码

    bool operator< (const MyString& rhs) const{
        return string(this->_data)<string(rhs._data);
    }

    bool operator== (const MyString& rhs) const{
        return string(this->_data)==string(rhs._data);
    }

    char* get() const { return _data; }
};


size_t MyString::DCtor = 0;
size_t MyString::Ctor = 0;
size_t MyString::CCtor = 0;
size_t MyString::CAsgn = 0;
size_t MyString::MCtor = 0;
size_t MyString::MAsgn = 0;
size_t MyString::Dtor = 0;


namespace std{
    template<>
    struct hash<MyString>{
        size_t operator()(const MyString& s) const noexcept{
            return hash<string>()(string(s.get()));
        }
    };
}


// 测试程序 伪代码

#include<typeinfo>
template<typename T>
void output_static_data(const T& myStr){
    cout<<typeid(myStr).name()<<"--"<<endl;
    cout<<"CCtor="<<T::CCtor
        <<"MCtor="<<T::MCtor
        <<"MAsgn="<<T::MAsgn
        <<"Dtor="<<T::Dtor
        <<"Ctor="<<T::Ctor
        <<"DCtor="<<T::DCtor<<endl;
}

template<typename M,typename NM>
void test_moveable(M c1,NM c2,long& value){
    char buf[10];
    
    typedef typename iterator_traits<typename M::iterator>::value_type V1type;
    clock_t timeStart = clock();
    for(long i=0;i<value;++i){
        snprintf(buf,10,"%d",rand());
        auto ite = c1.end();
        c1.insert(ite,V1type(buf));
    }
    cout << "construction, milli-seconds:"<<clock()-timeStart<<endl;
    cout << "size()="<<c1.size()<<endl;
}



// 就到此为止，推荐看侯捷老师的STL源码教程，溜了溜了