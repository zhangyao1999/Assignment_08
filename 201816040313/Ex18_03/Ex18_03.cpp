#include <iostream>
#include <array>
#include <vector>
#include <deque>

using namespace std;
//isEqualTo function template
template <typename T>
bool isEqualTo(const T &a,const T &b)
{
    if(a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//user defined class Stack,is uesd for talking about isEqualTo function,that is to say that overloads the function template in the class template
template <typename T>
class Stack
{
public:
    template <typename T1>
    bool isEqualTo(const T1 &a,const T1 &b)
    {
        if(a==b)
       {
           return true;
       }
       else
       {
           return false;
       }
    }
};

//user defined class NewStack,is used for talking about overloading of the equality operator
template <typename T>
class NewStack
{
public:
    NewStack(T th){data=th;}
    bool operator==(const NewStack<T> &right)const;
private:
    T data;
};
template <typename T>
bool NewStack<T>::operator==(const NewStack<T> &right)const
{
    if(data==right.data)
    {
        return true;
    }
    else
    {
        return false;
    }
}



int main()
{
    cout<<"test isEqualTo function template"<<endl;
    int s=1,d=2;
    if(isEqualTo(s,d))
        cout<<" s and d are equal"<<endl;
    else
        cout<<" s and d are not equal"<<endl;
    double q=3.4,w=3.5;
    if(isEqualTo(q,w))
        cout<<" q and w are equal"<<endl;
    else
        cout<<" q and w are not equal"<<endl;
    char v[4]={'y','o','u'};
    char g[4]={'a','r','e'};
    if(isEqualTo(v,g))
        cout<<" v and g are equal"<<endl;
    else
        cout<<" v and g are not equal"<<endl;
    string e="zhujianhui",r="zhaorui";
    if(isEqualTo(e,r))
        cout<<" e and r are equal"<<endl;
    else
        cout<<" e and r are not equal"<<endl;
    array<int,5>cats={0,1,1,1,1};
    array<int,5>dogs={0,1,1,1,1};
    if(isEqualTo(cats,dogs))
        cout<<" cats and dogs are equal"<<endl;
    else
        cout<<" cats and dogs are not equal"<<endl;
    vector<double>boy={9,2,5,2,1,0};
    vector<double>girl={1,3,1,4,1,1};
     if(isEqualTo(boy,girl))
        cout<<" boy and girl are equal"<<endl;
    else
        cout<<" boy and girl are not equal"<<endl;
    cout<<endl;





    cout<<"test user defined class 's isEqualTo function"<<endl;
    Stack<int>intStack;
    int s1=1,d1=2;
    if(intStack.isEqualTo(s,d))
        cout<<" s1 and d1 are equal"<<endl;
    else
        cout<<" s1 and d1 are not equal"<<endl;
    Stack<double>doubleStack;
    double q1=3.4,w1=3.5;
    if(doubleStack.isEqualTo(q,w))
        cout<<" q1 and w1 are equal"<<endl;
    else
        cout<<" q1 and w1 are not equal"<<endl;
    Stack<char>charStack;
    char v1[4]={'y','o','u'};
    char g1[4]={'a','r','e'};
    if(charStack.isEqualTo(v1,g1))
        cout<<" v1 and g1 are equal"<<endl;
    else
        cout<<" v1 and g1 are not equal"<<endl;
    Stack<string>stringStack;
    string e1="zhujianhui",r1="zhaorui";
    if(stringStack.isEqualTo(e1,r1))
        cout<<" e1 and r1 are equal"<<endl;
    else
        cout<<" e1 and r1 are not equal"<<endl;
    Stack<int>arrayStack;
    array<int,5>cats1={0,1,1,1,1};
    array<int,5>dogs1={0,1,1,1,1};
    if(arrayStack.isEqualTo(cats1,dogs1))
        cout<<" cats1 and dogs1 are equal"<<endl;
    else
        cout<<" cats1 and dogs1 are not equal"<<endl;
    Stack<double>vectorStack;
    vector<double>boys={9,2,5,2,1,0};
    vector<double>girls={1,3,1,4,1,1};
     if(vectorStack.isEqualTo(boys,girls))
        cout<<" boys and girls are equal"<<endl;
    else
        cout<<" boys and girls are not equal"<<endl;
    cout<<endl;





    cout<<"test overloads the equality operator"<<endl;
    NewStack<int>intStack1(2);
    NewStack<int>intStack2(2);
    if(intStack1==intStack2)
        cout<<" intStack1 and intStack2 are equal"<<endl;
    else
        cout<<" intStack1 and intStack2 are not equal"<<endl;
    NewStack<double>doubleStack1(2.5);
    NewStack<double>doubleStack2(2.6);
    if(doubleStack1==doubleStack2)
        cout<<" doubleStack1 and doubleStack2 are equal"<<endl;
    else
        cout<<" doubleStack1 and doubleStack2 are not equal"<<endl;
    NewStack<char>charStack1('s');
    NewStack<char>charStack2('n');
    if(charStack1==charStack2)
        cout<<" charStack1 and charStack2 are equal"<<endl;
    else
        cout<<" charStack1 and charStack2 are not equal"<<endl;
    NewStack<string>stringStack1("beloved");
    NewStack<string>stringStack2("negotiation");
    if(stringStack1==stringStack2)
        cout<<" stringStack1 and stringStack2 are equal"<<endl;
    else
        cout<<" stringStack1 and stringStack2 are not equal"<<endl;
    cout<<endl;



    return 0;
}
