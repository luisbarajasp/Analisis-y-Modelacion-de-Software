#include<iostream>
using namespace std;
template<class T>
T suma(T a, T b)
{
    return (a+b);
}
template<class Function, class T>
T doOperation(T a, T b, Function func)
{
    return func(a, b);
}
int main()
{
    cout << doOperation(5,5,suma<int>);
}