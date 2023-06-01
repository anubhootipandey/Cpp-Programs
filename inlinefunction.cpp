#include<iostream>
using namespace std;

inline int product(int a, int b){
    //static is not recommended to use below with inline functions
    //static int c=0;//This executes only once
    //c = c + 1;//Next time this function runs, the value of c will be retained
    return a*b;
}
int moneyReceived(int currentMoney, int factor=1.04){
    return currentMoney * factor;
}

int main(){
    int a, b;
    //cout<<"Enter the value a and b"<<endl;
    //cin>>a>>b;
    //cout<<"The product of a and b is "<<product(a,b)<<endl;
    //cout<<"The product of a and b is "<<product(a,b)<<endl;
    int money = 100000;
    cout<<"If you have "<<money<<" Rs in your bank account, you will receive "<<moneyReceived(money)<<"Rs after 1 year";
    cout<<"For VIP: If you have "<<money<<" Rs in your bank account, you will receive "<<moneyReceived(money, 1.1)<<"Rs after 1 year";
    
    return 0;
    }