
/*
for(decl:coll){
    statement
}

*/

# include <iostream>
using namespace std;

int main(){
    for(int i : {1,2,3,4,5}) cout << i << endl;
    return 0;
}

/*
1
2
3
4
5
*/