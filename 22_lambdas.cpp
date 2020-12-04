

// 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // 1 -

    int id = 0;
    auto f = [id]() mutable{
        cout << "id:" << id << endl;
        id++;
    };
    id = 42;
    f();
    f();
    f();
    cout << id << endl;

    // id:0
    // id:1
    // id:2
    // 42

    // 2 -
    int id = 0;
    auto f = [&id](int param) mutable{
        cout << "id:" << id << " param: "<<param << endl;
        id++;
        param++;
    };
    id = 42;
    f(7);
    f(7);
    f(7);
    cout << id << endl;   

    // id:42 param: 7
    // id:43 param: 7
    // id:44 param: 7
    // 45


    // 3 -
    
    int id = 0;
    auto f = [id]() {    //  没有mutable  id 不可变，可是后面id++,报错    表达式必须是可修改的左值C/C++(137)
        cout << "id:" << id << endl;
        id++;
    };
    id = 42;
    f();
    f();
    f();
    cout << id << endl;


    // 4 -

    vector<int> vi {5,2,8,50,83,70,590,245,59,24};
    int x =30;
    int y = 100;
    vi.erase(remove_if(vi.begin(),vi.end(),[x,y](int n){return x<n && n<y; }),vi.end());
    for(auto i:vi) cout << i << " ";
    cout << endl;
    return 0;
}

