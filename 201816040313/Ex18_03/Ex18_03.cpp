#include <iostream>
#include <array>
#include <vector>

using namespace std;

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
int main()
{
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

    return 0;
}
