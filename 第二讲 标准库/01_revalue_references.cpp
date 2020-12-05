

/*   右值引用  &&
Rvalue references are a new reference type
introduced in C++Ox
that help solve the problem of unnecessary
copying and enable
perfect forwarding. When the right-hand side of an assignment isan rvalue, then the left-hand side object can steal resources fromthe right-hand side object rather than performing a separate
allocation, thus enabling move semantics.
*/

// 老师的都是伪代码，就不写了，就看02 的例子吧
