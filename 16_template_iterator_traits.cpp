template<typename Container>
void test_moveable(Container c){

    typedef typename iterator_traits<typename Container::iterator>::value_type Valtype;
    // 简单注释一下
    // iterator_traits 萃取器 可以拿到 value_type 等五个东西。 具体看STL源码
    // 比如我随便找到一个
    /*
    struct Iterator_traitss
{
    typedef typename Iterator::iterator_catergory   iterator_category;    
    typedef typename Iterator::value_type       value_type;
    typedef typename Iterator::pointer      pointer;
    typedef typename Iterator::reference    　　　　　reference;
    typedef typename Iterator::difference_type      difference_type;
};
    */


    for(long i= 0;i<SIZE;++i){
        s.insert(c.end(),Valtype());

        // 这里的Valtype() 就是创建一个Valtype类型的临时变量的意思
    }

    // 后面省略
}