

// alias 别名

template<typename T>
using Vec = std::vector<T,MyAlloc<T>>;   // MyAlloc是一个自己写的分配器，关于分配器的内容，还是建议看侯捷老师的STL源码分析

Vec<int> coll;
