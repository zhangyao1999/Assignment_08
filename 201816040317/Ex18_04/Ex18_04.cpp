#include <iostream>
#include<iomanip>
#include<stdexcept>

#include"Array.h"

using namespace std;



int main()
{
    Array<int> integers1(5);
    Array<int> integers2(15);
    Array<double> dou1(5);
    Array<double> dou2(15);
    if(integers1!=integers2)
        cout<<"integers1 and integers2 are not equal"<<endl;
    if(integers1!=integers2)
        cout<<"integers1 and integers2 are equal"<<endl;
}
