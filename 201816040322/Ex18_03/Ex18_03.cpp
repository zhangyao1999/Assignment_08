// Assignment_08: Ex18_03.cpp
// Test program
#include <iostream>

using namespace std;

template < typename T > // function template head
bool isEqualTo(T a, T b)
{
	return a == b;
}

template < typename T > // class template head
class A
{
	template < typename T1 > // implement friend functions outside of a class, in code::blocks must redefine the template header again
	friend bool operator==(const A<T1> &a, const A<T1> &b);

public:
	explicit A(T temp = 0) // constructor
	{
		setTest(temp);
	}

	~A() { } // destructor

	// set and get
	void setTest(T);

	T getTest() const
	{
		return test;
	}

private:
    // data member
	T test;
};

template < typename T >
void A<T>::setTest(T temp) // implement member functions outside of a class in this form
{
	test = temp;
}

template < typename T >
bool operator==(const A<T> &a, const A<T> &b)
{
	return a.test == b.test;
}

int main()
{
	int a = 3, b = 4;

	if (isEqualTo(a, b))
		cout << a << " is equal to " << b << endl;

	double x = 3.3, y = 3.3;

	if (isEqualTo(x, y))
		cout << x << " is equal to " << y << endl;

	char c = 'c', d = 'c';

	if (isEqualTo(c, d))
		cout << c << " is equal to " << d << endl;

	A < int > e, f; // A object e, f

	if (isEqualTo(e, f))
		cout << e.getTest() << " is equal to " << f.getTest() << endl;
}
