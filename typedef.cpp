#include<iostream>
using namespace std;

typedef struct employee//typedef means in the place of struct employee we can write ep also.
{
    /* data */
    int eId;
    char favchar;
    float salary;
}ep;

union money
{
    /* data */
    int house;
    char car;
    float pounds;
};


int main(){
    enum meal{breakfast,lunch,dinner};
    cout<<breakfast;
    cout<<lunch;
    cout<<dinner;
    //ep anu;
    //union money m1;
    //m1.house = 34;
    //m1.car ='c';
    //cout<<m1.house;
    

    
    ////anu.eId = 1;
    //anu.favchar = 'c';
    //anu.salary = 120000000;
    //cout<<"The value is "<<anu.eId<<endl;
    //cout<<"The value is "<<anu.favchar<<endl;
    //cout<<"The value is "<<anu.salary<<endl;

    return 0;
}