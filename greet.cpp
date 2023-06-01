#include<iostream>
using namespace std;

class Base1{
    public:
    void greet(){
        cout<<"How are you?"<<endl;
    }

};

class Base2{
    public:
    void greet(){
        cout<<"Kaise ho?"<<endl;
    }

};

class derived : public Base1, public Base2{
    int a;
};

class B{
    public:
    void say(){
        cout<<"Hello world"<<endl;
    }
};
class D : public B{
    int a;
    public:
    void say(){
        cout<<"Hello my name is anubhooti pandey"<<endl;
    }
};

int main(){
    //Base1 base1obj;
    //Base2 base2obj;
    //base1obj.greet();
    //return 0;

    //Ambiguity 2
    B  b;
    b.say();

    D d;
    d.say();
    return 0;
}