

#include <iostream>
using namespace std;

template<typename T, typename... Args>
void printf(const char *s,T value,Args... args){
    while(*s){
        if(*s == '%' && *(++s) != '%'){
            std::cout << value;
            printf(++s,args...);
            return;
        }
    }
    cout << *s++;
}

void print(const char *s){
    while(*s){
        if(*s == '%' && *(++s) != '%') throw std::runtime_error("error");
    cout << *s++;
    }
}