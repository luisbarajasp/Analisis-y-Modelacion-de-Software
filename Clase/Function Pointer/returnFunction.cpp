#include<iostream>
using namespace std;


//complex way
int(*return_function(char c))(int,int) 
{           // function that receives a char a returns a function (function 
            // that receives 2 int's and return an int) 
    if(c == 's')
        return suma;
    return resta;
}

//easy way using typedef
typedef int(*Function)(int,int);
Function returnFunction(char c)
{
    if(c == 's')
        return suma;
    return resta;    
}
int main()
{
    cout << return_function('s')(2,2) << endl;
    cout << returnFunction('r')(4,2) << endl;
}

