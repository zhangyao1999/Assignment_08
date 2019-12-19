#include <iostream>

using namespace std;
template <class T>
bool isEqualTo(T pt1,T pt2)
{
    if(pt1==pt2)//to compare two numbers;
        return true;
    return false;
}

template <class T>
class Test
{
public:
    bool isEqualTo(Test & parameter2)
    {
        if(*this==parameter2)//to compare two numbers
            return true;
        return false;
    }
    T getNumber()const
    {
        return number;
    }
    void setNumber(T num)
    {
        this->number=num;
    }
    bool operator==(Test & parameter2)
    {
        if((*this).getNumber()==parameter2.getNumber())//to compare two data of object
            return true;
        return false;
    }
private:
    T number;
};
/*
template <class K>
class Test2
{
public:
    bool isEqualTo(Test2 & parameter2)
    {
        if((*this)==parameter2)
            return true;
        return false;
    }
    K getNumber()const
    {
        return number;
    }
    void setNumber(K num)
    {
        this->number=num;
    }
private:
    K number;
};
*/
int main()
{
    cout<<"Compare two int number by isEqualTo() function:12==13"<<endl;
    cout<<isEqualTo(12,13)<<endl;
    cout<<"Compare two int number by isEqualTo() function:12==12"<<endl;
    cout<<isEqualTo(12,12)<<endl<<endl;
    cout<<"Compare two double number by isEqualTo() function:14.5==16.5"<<endl;
    cout<<isEqualTo(14.5,16.5)<<endl;
     cout<<"Compare two double number by isEqualTo() function:14.5==14.5"<<endl;
    cout<<isEqualTo(14.5,14.5)<<endl<<endl;
    cout<<"Compare two string  by isEqualTo() function:\"hello\"==\"hello\""<<endl;
    cout<<isEqualTo("hello","hello")<<endl;
    cout<<"Compare two string  by isEqualTo() function:\"hello\"==\"hi\""<<endl;
    cout<<isEqualTo("hello","hi")<<endl<<endl;
/*
    Test2<int>test1;
    Test2<int>test2;
    test1.setNumber(10);
    test2.setNumber(10);
    cout<<test1.isEqualTo(test2);
*/
    cout<<"If the == operator is not overloaded, an error is reported, as follows:"<<endl;
    cout<<"error: no match for 'operator==' in '*(Test2<int>*)this == parameter2'|"<<endl<<endl;
    cout<<"After overloading the == operator, the program runs as follows"<<endl;
    Test<int>test3;
    test3.setNumber(10);
    Test<int>test4;
    test4.setNumber(10);
    cout<<"Compare two User-defined types with the same content,the program runs as follows"<<endl;
    cout<<test3.isEqualTo(test4);
    return 0;
}
