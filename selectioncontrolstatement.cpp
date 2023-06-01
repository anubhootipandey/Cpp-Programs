#include<iostream>
using namespace std;
int main()
{
    int age; 
    cout<<"Tell me your age"<<endl;
    cin>>age;
    //**********SELECTION CONTROL STATEMENTS:if else-if else ladder*********
    //if(age<18)
    //{
      //  cout<<"You cannot come to my party"<<endl;
    //}
    //else if(age==18){
    //    cout<<"You are a kid and you get kid pass to the party"<<endl;
    //}
    //else{
      //  cout<<"You can come to my party"<<endl;
    //}

    //*******SELECTION CONTROL STRUCTURE:SWITCH CASE STATEMENTS********
    switch (age)
    {
    case 18:
        cout<<"You are 18"<<endl;
        break;

    case 22:
         cout<<"You are 22"<<endl;
         break;

    
    }
    return 0;
}