struct _List_node_base{
    _List_node_base* _M_next;
    _List_node_base* _M_prev;
};

template<typename _Tp>
struct _List_node : public _List_node_base{  // inheritance
    _Tp _M_data;
};



// base class µÄdtor±ØÐëÊÇvirtual
