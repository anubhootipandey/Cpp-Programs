#include<iostream>
using namespace std;

int main(){
    int x=5;
    bool res =(x==9) || (x++);
    cout<<res<<" "<<x;
    
    return 0;
}