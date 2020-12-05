


// 劝退
// 17  template_template_parameter + alias_template

# include <string>
using namespace std;

// 等价于 template<typename T, template<class T> class Container>   



template<typename T, template<class> class Container>   


class XCLs{
private:
    Container<T> c;
public:
    XCLs(){
        for(auto i:SIZE){
            c.insert(c.end(),T());
        }

        Container<T> c1(c);
        Container<T> c2(std::move(c));
        c1.swap(c2);
    }
};


template<typename T>
using Vec = vector<T,allocator<T>>;
XCLs<string,Vec> c1;

// 你品你细品