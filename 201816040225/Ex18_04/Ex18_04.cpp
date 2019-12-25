#include<iostream>
#include<stdexcept>
#include<iomanip>
#include"Array.h"
using namespace std;
int main()
{
    Array <int>integers1(7);//Array
    Array <int>integers2(10);//10 element Array
    cout<<"Size of Array integers1 is"
    <<integers1.getSize()//get size
    <<"\nArray after initialization:\n"<<integers1;

    cout<<"\nSize of Array integer2 is:"
    <<integers2.getSize()//get size
    <<"\nArray after initialization:\n"<<integers2;

    cout<<"\nEnter 17 integers:"<<endl;
    cin>>integers1>>integers2;
    cout<<"\nAfter input,the Array contain:\n"
    <<"integers1:\n"<<integers1
    <<"integers2:\n"<<integers2;

    cout<<"\nEvaluating:integer1!=integers2"<<endl;
    if(integers1!=integers2)//overload != operator
        cout<<"integers1 and integers2 are not equal"<<endl;

    Array <int>integers3(integers1);//copy constructor

    cout<<"\nSize of Array integers3 is"
    <<integers3.getSize()
    <<"\nArray after initialization:\n"<<integers3;

    cout<<"\nAssigning integers2 to integers1:"<<endl;
    integers1=integers2;//copy
    cout<<"integers1:\n"<<integers1
    <<"integers:\n"<<integers2;

    cout<<"\nEvaluating:integers1==integers2"<<endl;
    if(integers1==integers2)//overload operator ==
     cout<<"integers1 and integers2 are equal"<<endl;

     cout<<"\ninteger1[5] is "<<integers1[5];

     cout<<"\n\nAssigning 1000 to integers[5]"<<endl;
     integers1[5]=1000;
     cout<<"integers1:\n"<<integers1;

     try
     {
         cout<<"\n\nAssigning 1000 to integers[15]"<<endl;
         integers1[15]=1000;
     }
     catch(out_of_range &ex)
     {
         cout<<"An excepting occurred: "<<ex.what()<<endl;
     }

}

