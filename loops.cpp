#include<iostream>
using namespace std;
int main()
{
    /*Loop in C++:
    There are three types of loops in c++:
    1.For Loop
    2.while loop
    3.do-while loop
    */
   /*For loop in C++*/
   //Syntax for for loop
   //for(initialization;condition;updation)
   //{
       //loop body(C++code)
   //}

   //for (int i = 0; i < 4; i++)
   //{
       /* code */
    //  cout<<i<<endl;
   //}
   //Example of infinite loop
   //for (int i = 0; 34 <= 4; i++)
   //{
       /* code */
     //  cout<<i<<endl;
   //}

   /*while loop in c++*/
   //Syntax:
   //while(condition):
   //{
       //c++ statements;
   //}

   //Printing 1 to 40 using while loop
   int i=1;
   while(i<=40){
      cout<<i<<endl;
      i++;
   }
   int i=1;
   do{
      cout<<i<<endl;
      i++;
   }
   while(i<=40);
   
   
   
   

   return 0;
}