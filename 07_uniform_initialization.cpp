
//----------------------------------------------------------------
// ���ǳ�ʼ��������ʱ�򣬶�����ͳһʹ��{}����ʼ��

// eg:
#include<vector>
#include<complex>
using namespace std;

int values[] = {1,2,3};
vector<int> v {2,3,4,5,6};
vector<string> citis{
    "Berlin","New York"
};
complex<double> c{4.0,3.0}; //����

//����
/*
����������{t1,t2,t3,,,tn}��ʱ�� ������һ��initializer_list<T>
���initializer_list<T>��ʵ����array<T,n>��������
Ȼ���ٽ�array�����Ԫ�أ�ͨ������������ctor���ֽ���һ��������



�����������Ҳ��һ��initializer_list<T>�����ͻὫ��һ��initializer_list<T>������ȥ��
������Ҫ������ȥ�Ĺ��캯����������Ҫ����initializer_list<T>���ʹ���initializer_list<T>�����򣬽�array<T,n>��Ԫ�ز𿪴���ȥ��

���￴����Ҳû��ϵ�����滹����� ������Կ���08 ������С����

*/