#include <iostream>
#include <array>
#include <string>

using namespace std;

template <typename T>
bool isEqualTo(T &a, T &b)//isEqualTo函数
{
    if(a==b)
        return true;
    else
        return false;
}

template <typename T>
class equalment//类模板
{
public:
    equalment(T data){a=data;};
    bool operator==(equalment& b)
    {
        if(a==b.a)
        return true;
    else
        return false;
    };
private:
    T a;
};
int main()
{
    int a=1,b=2;//声明两个int类变量
    if(isEqualTo(a,b))//调用isEqualTo函数
        cout <<a<<"等于"<<b<<endl;
    else
        cout <<a<<"不等于"<<b<<endl;

    double c=1.1,d=2.1;//声明两个double类变量
    if(isEqualTo(c,d))//调用isEqualTo函数
        cout <<c<<"等于"<<d<<endl;
    else
        cout <<c<<"不等于"<<d<<endl;

    string e="七龙珠",f="孙悟空";//声明两个string类变量
    if(isEqualTo(e,f))//调用isEqualTo函数
        cout <<e<<"等于"<<f<<endl;
    else
        cout <<e<<"不等于"<<f<<endl;
    array<int,2> arr1={1,2};//声明两个array类变量
    array<int,2> arr2={1,2};
    if(isEqualTo(arr1,arr2))//调用isEqualTo函数
        cout <<"arr1"<<"等于"<<"arr2"<<endl;
    else
        cout <<"arr1"<<"不等于"<<"arr2"<<endl;

    cout<<"\n\n\n";

    equalment<int> ab(1);//声明两个数据成员是int的类
    equalment<int> bc(2);//调用重载函数==
    if(ab==bc)
        cout <<"ab"<<"等于"<<"bc"<<endl;
    else
        cout <<"ab"<<"不等于"<<"bc"<<endl;

    equalment<double> cd(1.1);//声明两个数据成员是double的类
    equalment<double> de(2.1);//调用重载函数==
    if(cd==de)
        cout <<"cd"<<"等于"<<"de"<<endl;
    else
        cout <<"cd"<<"不等于"<<"de"<<endl;

    equalment<string> ef("七龙珠");//声明两个数据成员是string的类
    equalment<string> fg("孙悟空");//调用重载函数==
    if(ef==fg)
        cout <<"ef"<<"等于"<<"fg"<<endl;
    else
        cout <<"ef"<<"不等于"<<"fg"<<endl;

}
