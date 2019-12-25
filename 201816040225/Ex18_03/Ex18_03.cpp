#include <iostream>
#include<string>
using namespace std;
template< typename T >
T isEqualTo(T &a,T &b)//Function 模板
{
    if(a==b)//judge a and b
       {
        cout<<"they are equal to each other\n";
        return true;
       }
    else
        {
        cout<<"they are not equal to each other\n";}
        return false;
}

class Compare//The class of Compare
{
    public:

        Compare()//constructor definition
        {
        a1=0;
        }
        Compare(int n)//constructor
        :a1(n)
        {
        }
    bool operator==( const Compare &right)//overload == operator
    {
        if(a1==right.a1)
            return true;
            //cout<<"they are equal to each other\n";}
        else
            return false;
            //cout<<"they are not equal to each other\n";}
    }
    int a1;//data member

};

int main()
{
    int a=1;int b=4;//type int
    Compare A(5);//object A
    Compare B(5);//object B

    double c=9.0; double d=9.0;//type double
    isEqualTo(a,b);
    isEqualTo(c,d);

    if(A==B)//use overload operator==
        cout<<"they are equal to each other\n";
    else
        cout<<"they are not equal to each other\n";

}
