


struct NoCopy{
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete;                 // no copy
    NoCopy& operator=(const NoCopy&) = delete;      // no assignment
    ~NoCopy() = default;
};


struct NoDtor{
    NoDtor() = default;
    ~NoDtor() = delete; // û������������һ�㲻�ã�����Ը�
};


struct PrivateCopy{ 
private:                // ����Ԫ�ͳ�Աʹ��
    PrivateCopy(const PrivateCopy&);            
    PrivateCopy &operator=(const PrivateCopy&);
public:
    PrivateCopy() = default;
    ~PrivateCopy();
};
