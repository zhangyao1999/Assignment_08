#include <iostream>
#include <array>
#include <string>
using namespace std;

template< typename T >
class biger
{
public:
    biger(T=0);
    ~biger(){}
    bool operator==(const biger&);
    T getbiger()
    {
        return x;
    }
private:
    T x;
};
template< typename T >
biger<T>::biger(T t)
{
    x=t;
}
template< typename T >
bool biger<T>::operator==(const biger&right)
{
  return x==right.x;
}

template < typename T >
    bool isEqualTo (T value1,T value2)
    {
        if(value1==value2)
            return true;
        else
            return false;
    }
int main()
{
    biger<int> int1(1),int2(1);
    if(isEqualTo(int1,int2))
        cout<< int1.getbiger() << " is equal to " << int2.getbiger() <<endl ;
    else
        cout<< int1.getbiger() << " is not equal to " << int2.getbiger() <<endl;
    biger<char> char1('m'),char2('n');
    if(isEqualTo(char1,char2))
        cout<< char1.getbiger() << " is equal to " << char2.getbiger()<<endl ;
    else
        cout<< char1.getbiger() << " is not equal to " << char2.getbiger()<<endl ;

    string s1("happy"),s2("happy");
    if(isEqualTo(s1,s2))
        cout<< s1 << " is equal to " << s2 <<endl ;
    else
        cout<< s1 << " is not equal to " << s2 <<endl ;
}
