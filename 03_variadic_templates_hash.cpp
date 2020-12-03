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
inline void hash_val(size_t&seed,const T& val,const Types&... args){    //  如果剩下seed和val 和很多东西,就递归调用这个
    hash_combine(seed,val);
    hash_val(seed,args...);   //这里就是和02.cpp的例子一样了，自己调用自己。
}

//3
template<typename T>
inline void hash_val(size_t&seed,const T& val){     // 如果剩下seed和val,就调用这个
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
        return hash_val(c.fname,c.lname,c.no);  //因为不知道size_t,直接调用，1
    }
private:
    //这里不知道是什么type,随便写写
    CustomerHash* fname;
    CustomerHash* lname;
    CustomerHash* no;
};