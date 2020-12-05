#include<iostream>
#include<string>

using namespace std;


struct MyString{
public:                         // ���Գ�����
    static size_t DCtor;        // �ۼ�default_ctor�ĺ��д�������������
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

    // move constructor  ���������ֵ���� һ��Ҫnoexcept
    MyString(MyString&& str) noexcept : _data(str._data), _len(str._len){
        ++MCtor;
        str._len = 0;           // ��ԭ���ĳ�����Ϊ��
        str._data = NULL;       // Ȼ��ԭ����ָ��ָ��գ���Ҫ����һ���ǽ������������жϣ�
                                // ���û������Ϊ�գ��ڵ��ý���֮��str�������������ͻὫstr._data�Ķ������ͷŵ���
                                // Ȼ��ֵ��_data�ͻ�ָ��һ�������ݣ����Ұָ�루�Ҳµģ�
                                // ����������������Ҫ������
    }

    // copy assignment
    MyString& operator = (const MyString& str){
        ++CAsgn;
        // ���Ҹ�ֵ���
        if(this != &str){ // �ǲ����Լ���ֵ�Լ�
            if(_data) delete _data;  //�Ȱ�ԭ���������ͷ�
            _len = str._len;
            _init_data(str._data); // copy
        }else{}     // �Լ���ֵ�Լ���ʲô��������
        return *this;
    }

    // move assignment
    MyString& operator=(MyString&& str) noexcept{
        ++MAsgn;
        // ���Ҹ�ֵ���
        if(this != &str){
            if(_data) delete _data;
            _len = str._len;
            _data = str._data; // MOVE �� ǳ����
            str._len = 0;
            str._data = NULL; // ��Ҫ
        }
        return *this;
    }

    // dtor
    virtual ~MyString() {
        ++Dtor;
        // ������
        if(_data){ // �������NULL�Ļ�����ɾ����ָ�����ݣ���NULL�Ļ���˵���Ѿ����������ˣ��Ͳ�Ҫɾ����
            delete _data;
        }
    }

    // �������ǲ����õ��Ĵ���

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


// ���Գ��� α����

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



// �͵���Ϊֹ���Ƽ��������ʦ��STLԴ��̳̣���������