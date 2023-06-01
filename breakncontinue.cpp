#include<iostream>
using namespace std;

int main(){
    /*for(int i = 0; i<4;i++)
    {
        cout<<i<<endl;
        if(i==2)
            break;//********it breaks the condition.
    }*/
    for(int i = 0; i<4;i++)
    {
        if(i==2){
            continue;//*********it breaks the condition and proceed to next.
    }
    cout<<i<<endl;
    }
    return 0;
}
