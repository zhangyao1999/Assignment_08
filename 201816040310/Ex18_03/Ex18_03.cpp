#include <iostream>

using namespace std;

class Object
{
public:
    Object(int a) : a(a) {}

private:
    int a;
};

class ObjectPlus
{
public:
    ObjectPlus(int a) : a(a) {}
    bool operator==(ObjectPlus &rt) //重载 == 操作符
    {
        return this->a == rt.a;
    }
    void setA(int a) { this->a = a; }

private:
    int a;
};

template <typename T>
bool isEqualTo(T &a, T &b)
{
    return a == b;
}

int main()
{
    int a = 1, b = 3;
    double c = 3, d = 3;
    cout << "int     a ?= b " << isEqualTo(a, b) << endl;
    cout << "double  c ?= d " << isEqualTo(c, d) << endl;
    /*
    Object x(2), y(2);
    cout << "Object  x ?= y " << isEqualTo(x, y) << endl; //编译出错 error: no match for ‘operator==’
*/
    ObjectPlus x(2), y(4);
    cout << "ObjectP x ?= y " << isEqualTo(x, y) << endl;
    y.setA(2);		//更改y的a
    cout << "After change a" << endl;
    cout << "ObjectP x ?= y " << isEqualTo(x, y) << endl;
}