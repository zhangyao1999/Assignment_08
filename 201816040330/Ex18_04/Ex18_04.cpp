#include<iostream>
#include "Array.h"
#include <string>
int main()
{
    Array<int> integers1(5);
    Array<int> integers2(15);    //ten-element int Array
    Array<double> dou1(5);  //seven-element double Array
    Array<double> dou2(15);
    cout<<"please input:"<<endl;
    cin >> integers1 >> integers2;
    cout << "integer1:\n" << integers1<< "integer2:\n" << integers2;
    cout << "\ninteger1 != integer2" << endl;
    if(integers1 != integers2)//use overloaded inequality (!=) operator
    {
        cout << "They are not equal" << endl;
    }
    integers1 = integers2;  //note target Array is smaller
    //use overloaded assignment (==) operator
    cout << "\n integer1 == integer2" << endl;

    if(integers1 == integers2)
    {
        cout << "They are equal" << endl;
    }

    cin >> dou1 >> dou2;
    cout<< "dou1:\n" << dou1<< "dou2:\n" << dou2;
    if(dou1 != dou2)//use overloaded inequality (!=) operator
    {
        cout << "They are not equal" << endl;
    }

    if(dou1 == dou2)
    {
        cout << "They are equal" << endl;
    }
}   //end main
