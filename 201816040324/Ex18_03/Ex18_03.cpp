#include <iostream>

using namespace std;


template <typename T>





template <typename T>

bool operator==(const T &a,const T &b)

{

    if(b==a)

        return true;

    else

        return false;

}
bool isEqualTo (const T &a,const T &b)

{

    if(a==b)

    {

        return true;

    }

    else

        return false;

}



int main()

{

    int a=1,b=2;

    if(isEqualTo(a,b))

        cout<<"a = b"<<endl;

    else

        cout<<"a £¡=b"<<endl;




    if(isEqualTo(a,b))

        cout<<"z = x"<<endl;

    else
        cout<<"z £¡= x"<<endl;

    return 0;
