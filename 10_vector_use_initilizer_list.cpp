

// 用法展示

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main(){

    vector<int> v1{1,2,3,4,5,6};
    vector<int> v2({1,2,3,4,5,6});
    vector<int> v3;
    v3 = {1,2,3,4,5,6};
    v3.insert(v3.begin()+2,{0,2,4,8});

    cout << "v1" << endl;
    for(auto i:v1) cout << i << " ";
    cout << endl << "v2" << endl;
    for(auto i:v2) cout << i << " ";
    cout << endl << "v3" << endl;
    for(auto i:v3) cout << i << " ";
    cout << endl;

    cout << max({})

    




    return 0;
}