#include<iostream>
using namespace std;
template<class T>
T suma(T a, T b) {
    return a+b;
}
template<class T>
T resta(T a, T b) {
    return a-b;
}
template<class Function>
Function return_function(char c)
{
    if(c == 's')
        return suma;
    return resta;
}
int main()
{    
    cout << return_function<int(*)(int,int)>('s')(2,2) << endl;
}