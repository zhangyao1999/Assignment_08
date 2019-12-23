#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Array.h"
using namespace std;

int main()
{
    cout << fixed << setprecision(2) ;
    Array<int> integers1(7);
    Array<double> Floatings2;
    cout << "Size of Array integers1 is "
         << integers1.getSize()
         << "\nArray after initialization:\n" << integers1 ;
    cout << "\nSize of Array Floatings2 is "
         << Floatings2.getSize()
         << "\nArray after initialization:\n" << Floatings2 ;
    cout << "\nEnter 17 integers:" << endl;
    cin >> integers1 >> Floatings2 ;
    cout << "\nAfter input ,the Arrays contain:\n"
         << "integers1:\n" << integers1
         << "\nFloatings2:\n" << Floatings2;
    cout << "\n\nAssigning 1000 to integersq[5]" << endl;
    integers1[5] = 1000;
    cout << "integers1\n" << integers1;
}
