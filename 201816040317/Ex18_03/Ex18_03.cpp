#include <iostream>
#
using namespace std;


template <typename T>
bool isEqualTo (const T &a,const T &b)
{
    if(a!=b)
    {
        return false;
    }
    else
        return true;
}

template <typename T>
bool operator==(const T &a,const T &b)
{
    if(b==a)
        return true;
    else
        return false;
}

int main()
{
    int a=1,b=2;
    double z=1.0,x=2.2;
    if(isEqualTo(a,b))
    {
        cout<<"a is equal b"<<endl;
    }
    else
    {
        cout<<"a is not equal b"<<endl;
    }
   /*if(isEqualTo(a,z))
    {
        cout<<"a is equal z"<<endl;
    }
    else
    {
        cout<<"a is not equal z"<<endl;
    }
    if(isEqualTo(z,b))
    {
        cout<<"b is equal z"<<endl;
    }
    else
    {
        cout<<"z is not equal b"<<endl;
    }*/
    if(isEqualTo(z,x))
    {
        cout<<"z is equal x"<<endl;
    }
    else
    {
        cout<<"z is not equal x"<<endl;
    }
    return 0;
}

