

struct Base{
    virtual void vfunc(float){ }
};
struct Derived1:Base{
    virtual void vfunc(int){ }
    //   ��������д�����ǲ���д���ˣ��������Ͳ�����Ϊ�Ҷ���������д��������Ϊ�����ڹ���һ���µĺ���

};

struct Derived2:Base{
    virtual void vfunc(int) override {};
    //   ���Ǹ����˱�����������Ҫ��д�����д���ˣ��������ᱨ��


    virtual void vfunc(float) override {};
    //   ok

}