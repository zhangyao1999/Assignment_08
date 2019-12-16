#include <iostream>
#include "Array.h"
#include <stdexcept>
#include <iomanip>
using namespace std;

int main()
{
    Array<int>array1(5);
    cout<<array1.getSize();
    cout<<endl;
    cout<<"Enter 5 figure:"<<endl;
    cin>>array1;
    cout<<array1;
    cout<<array1[4];
    array1[3]=521;
    cout<<endl;
    cout<<array1[3];
    cout<<endl;
    cout<<array1;
    cout<<endl;



    Array<int>array2(7);
    cout<<array2.getSize();
    cout<<endl;
    cout<<"Enter 7 figure:"<<endl;
    cin>>array2;
    cout<<array2;
    cout<<endl;
    array1=array2;
    cout<<array1<<endl;


    if(array1!=array2)
        cout<<"array1 and array2 are not equal"<<endl;
    if(array1==array2)
        cout<<"array1 and array2 are equal"<<endl;

    Array<int>array3(array2);
    cout<<array3.getSize();
    cout<<endl;

    cout<<array3;
    cout<<endl;



    if(array2==array3)
        cout<<"array2 and array3 are equal"<<endl;
    if(array2!=array3)
        cout<<"array2 and array3 are not equal"<<endl;


}
