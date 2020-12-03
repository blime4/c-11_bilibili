


struct NoCopy{
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete;                 // no copy
    NoCopy& operator=(const NoCopy&) = delete;      // no assignment
    ~NoCopy() = default;
};


struct NoDtor{
    NoDtor() = default;
    ~NoDtor() = delete; // 没有析构函数，一般不用，后果自负
};


struct PrivateCopy{ 
private:                // 给友元和成员使用
    PrivateCopy(const PrivateCopy&);            
    PrivateCopy &operator=(const PrivateCopy&);
public:
    PrivateCopy() = default;
    ~PrivateCopy();
};
