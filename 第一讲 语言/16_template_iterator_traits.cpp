template<typename Container>
void test_moveable(Container c){

    typedef typename iterator_traits<typename Container::iterator>::value_type Valtype;
    // ��ע��һ��
    // iterator_traits ��ȡ�� �����õ� value_type ����������� ���忴STLԴ��
    // ����������ҵ�һ��
    /*
    struct Iterator_traitss
{
    typedef typename Iterator::iterator_catergory   iterator_category;    
    typedef typename Iterator::value_type       value_type;
    typedef typename Iterator::pointer      pointer;
    typedef typename Iterator::reference    ����������reference;
    typedef typename Iterator::difference_type      difference_type;
};
    */


    for(long i= 0;i<SIZE;++i){
        s.insert(c.end(),Valtype());

        // �����Valtype() ���Ǵ���һ��Valtype���͵���ʱ��������˼
    }

    // ����ʡ��
}