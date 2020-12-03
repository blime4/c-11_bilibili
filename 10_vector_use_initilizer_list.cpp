

// 用法展示

#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
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
    
// v1
// 1 2 3 4 5 6 
// v2
// 1 2 3 4 5 6 
// v3
// 1 2 0 2 4 8 3 4 5 6 


    cout<< max({45,4,12,3}) << endl;
    cout<< max({string("Ace"),string("Stacy"),string("Dong")})<< endl;

// 45
// Stacy

//max源码如下，可以看出
/*
template<class _Ty>
	_NODISCARD constexpr _Ty (max)(initializer_list<_Ty> _Ilist)
	{	// return leftmost/largest
	return ((_STD max)(_Ilist, less<>()));
	}
*/

    return 0;
}


