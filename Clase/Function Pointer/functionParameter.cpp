#include<iostream>
using namespace std;
int suma(int a, int b)
{
    return (a+b);
}
int resta(int a, int b)
{
    return (a-b);
}
int doOperation(int a, int b, int(*func)(int,int))
{
    return func(a, b);
}
int main()
{
    cout << doOperation(5,5,suma);
    cout << doOperation(5,5,resta);
}