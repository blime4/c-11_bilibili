
class StringRep{  // Body
    friend class String;
    StringRep(const char* s);
    ~StringRep();
    int count;
    char* rep;
};


class String{   // Handle
public:
    String();
    String(const char* s);
    String(const String& s);
    String& operator=(const String& s);
    ~String();
private:
    StringRep* rep;  // 不同步创建，调用时创建
};