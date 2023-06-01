#include<iostream>
using namespace std;

int main(){
    int marks[4]={36,45,69,84};
    int mathmarks[4];
    mathmarks[0]=2267;
    mathmarks[1]=247;
    mathmarks[2]=869;
    mathmarks[3]=567;

    cout<<"These are maths marks"<<endl;
    cout<<mathmarks[0]<<endl;
    cout<<mathmarks[1]<<endl;
    cout<<mathmarks[2]<<endl;
    cout<<mathmarks[3]<<endl;

    //You can change the value of an array 
    marks[2]=455;
    cout<<"These are marks"<<endl;
    //cout<<marks[0]<<endl;
    //cout<<marks[1]<<endl;
    //cout<<marks[2]<<endl;
    //cout<<marks[3]<<endl;

    //*********FOR LOOP USED IN ARRAYS**********

    for(int i=0;i<4;i++)
    {
        cout<<"The value of marks "<<i<<" is "<<marks[i]<<endl;
    }
    
    //**********WHILE LOOP USED IN ARRAYS**********
    //int i =0;
    //while(i<4){
     //   cout<<marks[i]<<endl;
      //  i++;
    //}

    //********DO WHILE LOOP IN ARRAYS***********
    //int i=0;
    //do
    //{
     //   cout<<marks[i]<<endl;
     //   i++;
    //}while(i<4);

    //*********POINTERS AND ARRAYS*************
    int*p=marks;
    cout<<*(p++)<<endl;
    cout<<*(++p)<<endl;
    //cout<<"The value of marks[0] is "<<*p<<endl;
    //cout<<"The value of marks[0] is "<<*(p+1)<<endl;
    //cout<<"The value of marks[0] is "<<*(p+2)<<endl;
    //cout<<"The value of marks[0] is "<<*(p+3)<<endl;


    
    return 0;
}