#include<iostream>
using namespace std;

class Employee{
    int id;
    static int count;
public:
    void setData(void){
        cout<<"Enter the id"<<endl;
        cin>>id;
        count ++;
    }
    void getData(void){
        cout<<"The id of this employee is "<< id <<" and this is employee number "<<count<<endl;
    }
    static void getCount(void){
        cout<<"The value of count is "<<count<<endl;
    }
};

//Count is the static data member of class Employee
int Employee :: count;//defaul value is 0

int main(){
    Employee anu,tanu;
    
    //anu.id = 1;
    //anu.count=1;//cannot do this as id and count are private

    anu.setData();
    anu.getData();
    Employee :: getCount();

    tanu.setData();
    tanu.getData();
    Employee :: getCount();

    return 0;
}