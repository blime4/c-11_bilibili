
int maximum(int n){
    return n;
}

template<typename... Args>
int maximum(int n, Args...args) {
    return std::max(n,maximum(args...));
}