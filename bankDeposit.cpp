#include<iostream>
using namespace std;
class BankDeposit
{
    int principle;
    int years;
    float interestRate;
    float returnValue;
    
public:
 BankDeposit(){}
 BankDeposit(int p, int y, float r);
 BankDeposit(int p, int y, int r);
 void show();
};

 
 BankDeposit:: BankDeposit(int p, int y, float r)
{
    principle = p;
    years = y;
    interestRate = r;

    returnValue = principle;
    for (int i = 0; i < y; i++)
    {
        returnValue =  returnValue * (1+r);
    }
    
}
BankDeposit:: BankDeposit(int p, int y, int r)
{
    principle = p;
    years = y;
    interestRate =float(r)/100;

    returnValue = principle;
    for (int i = 0; i < y; i++)
    {
        returnValue =  returnValue * (1+interestRate);
    }
    
}
void BankDeposit :: show(){
    cout<<endl<<"Principle amount was "<<principle<<endl
    << "Return value after "<<years
    <<" is "<<returnValue<<endl;
}

int main(){
    BankDeposit bd1, bd2, bd3;
    int p, y;
    float r;
    int R;

    cout<<"Enter the value of p, y and R "<<endl;
    cin>>p>>y>>r;
    bd1 = BankDeposit(p, y, R);
    bd1.show();
    return 0;
}