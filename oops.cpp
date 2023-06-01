//OOPs - Classes and Objects
    //class -->extension of structures (in c)
    //structures and limitations
    //     ---->members are public
    //     ---->No methods
    //classes can have methods and properties
    //classes---> can make few members as private and few as public
    //structures in c++ are typedef
    //you can declare objects along with the class declaration like this:
              /*class Employee{
                  class definition
              }anu,tanu,satlu;*/
    //anu.salary = it makes no sense if salary is private

    //Nesting of member functions
#include<iostream>
#include<string>
using namespace std;

class binary{
        string s;
        
public:
    void read(void);
    void chk_bin(void);
    void ones_compliment(void);
    void display(void);
};

void binary :: read(void){
    cout<<"Enter a binary number"<<endl;
    cin>>s;
}

void binary :: chk_bin(void){
    for (int i = 0; i < s.length(); i++)
    {
        if(s.at(i)!='0' && s.at(i)!='1'){
            cout<<"Incorrect binary format"<<endl;
            exit(0);
        }
    }
}

void binary :: ones_compliment(void){
   for (int i = 0; i < s.length(); i++){
       if(s.at(i)=='0'){
           s.at(i) ='1';
       }
       else{
           s.at(i) = '0';
       }
   } 
}

void binary :: display(void){
    cout<<"Displaying your binary number"<<endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout<< s.at(i);
    }
    cout<<endl;
}
int main(){
    binary b;
    b.read();
    b.chk_bin();
    b.display();
    b.ones_compliment();
    b.display();
    
    return 0;
}