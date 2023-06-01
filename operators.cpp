#include<iostream>
//There are two types of header files:
//1.System header files:It comes with the compiler.
//2.User defined header files:It is written by the programmar.
//include "this.h"-->This will produce an error if this.h is not present in the current directory.
using namespace std;
int main()
{
    int a=4, b=6;
    cout<<"Operators in c++:"<<endl;
    cout<<"Following are the types of operators in c++:"<<endl;
    //Arithmetic opertaors
    cout<<"The value of a + b is "<<a+b<<endl;
    cout<<"The value of a - b is "<<a-b<<endl;
    cout<<"The value of a * b is "<<a*b<<endl;
    cout<<"The value of a / b is "<<a/b<<endl;
    cout<<"The value of a % b is "<<a%b<<endl;
    cout<<"The value of a++ is "<<a++<<endl;
    cout<<"The value of ++a is "<<++a<<endl;
    cout<<"The value of a-- is "<<a--<<endl;
    cout<<"The value of --a is "<<--a<<endl;
    cout<<endl;

    //Assignment operator-->used to assign values to variables.
    //int a=3, b=9;
    //char d='d';

    //Comparison operator
    cout<<"Following are the types of comparison operators in c++:"<<endl;
    cout<<"The value of a==b is "<<(a==b)<<endl;
    cout<<"The value of a!=b is "<<(a!=b)<<endl;
    cout<<"The value of a<b is "<<(a<b)<<endl;
    cout<<"The value of a>b is "<<(a>b)<<endl;
    cout<<"The value of a<=b is "<<(a<=b)<<endl;
    cout<<"The value of a>=b is "<<(a>=b)<<endl;
    cout<<endl;

    //Logical operator
    cout<<"Following are the types of logical operators in c++:"<<endl;
    cout<<"The value of this logical and operator ((a==b) && (a<b) is:"<<((a==b) && (a<b))<<endl;
    cout<<"The value of this logical or operator ((a==b) || (a<b) is:"<<((a==b) || (a<b))<<endl;
    cout<<"The value of this logical not operator (!(a==b)) is:"<<(!(a==b))<<endl;
    
    return 0;
}