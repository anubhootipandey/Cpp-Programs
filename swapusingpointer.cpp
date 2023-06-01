#include<iostream>
using namespace std;

//This will not swap a and b
void swap(int a, int b){//temp a  b
    int temp = a;       //4    4  5
    a = b;              //4    5  5
    b = temp;           //4    5  4 
}
//call by reference using pointers
void swapPointer(int* a, int* b){//temp a  b
    int temp = *a;       //4    4  5
    *a = *b;              //4    5  5
    *b = temp;           //4    5  4 
}
//call by reference using C++ reference variables
void swapReferenceVar(int &a, int &b){//temp a  b
    int temp = a;       //4    4  5
    a = b;              //4    5  5
    b = temp;           //4    5  4 
}

int main(){
    int x =4, y =5;
    //cout<<"The sum of 4 and 5 is "<<sum(a, b);
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl;
    //swap(a, b);//----->this will not swap a and b
    //swapPointer(&x, &y);//----->this will swap a and b using pointer
    swapReferenceVar(x, y);//----->this will swap a and b using pointer
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl;
    return 0;
}