#include<functional>
 
// 1 
template<typename... Types>  
inline size_t hash_val(const Types&... types){
    size_t seed = 0;
    hash_val(seed,args...);
    return seed;
}

// 2 
template<typename T,typename... Types>
inline void hash_val(size_t&seed,const T& val,const Types&... args){    //  ���ʣ��seed��val �ͺܶණ��,�͵ݹ�������
    hash_combine(seed,val);
    hash_val(seed,args...);   //������Ǻ�02.cpp������һ���ˣ��Լ������Լ���
}

//3
template<typename T>
inline void hash_val(size_t&seed,const T& val){     // ���ʣ��seed��val,�͵������
    hash_combine(seed,val);
}

//4
template<typename T>
inline void hash_combine(size_t&seed,const T& val){
    seed ^= std::hash<T>()(val)+0x9e3779b9+(seed<<6)+(seed>>2);
}


class CustomerHash{
public:
    std::size_t operator()(const CustomerHash& c) const {
        return hash_val(c.fname,c.lname,c.no);  //��Ϊ��֪��size_t,ֱ�ӵ��ã�1
    }
private:
    //���ﲻ֪����ʲôtype,���дд
    CustomerHash* fname;
    CustomerHash* lname;
    CustomerHash* no;
};