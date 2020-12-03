//C++11 lets you use nullptr instead of 0 or NULL

void f(int);
void f(void*);

f(0); //call f(int);
f(NULL); //call f(int);
f(nullptr); //call f(void*);