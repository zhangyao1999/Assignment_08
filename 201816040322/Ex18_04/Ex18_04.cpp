// Assignment_08 : Ex18_04.cpp
// Array class test program
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include "Array.h"
using namespace std;

int main()
{
//    ifstream inClientFile( "input_data.txt", ios::in );
//
//    if ( !inClientFile )
//    {
//        cerr << "file could not be opened" << endl;
//        exit( EXIT_FAILURE );
//    }
//
//    ofstream outClientFile( "output_date.txt", ios::out );
//
//    if ( !outClientFile )
//    {
//        cerr << "file could not be opened" << endl;
//        exit( EXIT_FAILURE );
//    }

    Array < int > integers( 8 ); // 8-element Array

    Array < double > decimals; // 10-element Array by default

    Array < char > character( 15 ); // 15-element Array

    cout << fixed << setprecision( 2 );

    // print size and contents
    cout << "Size of Array integers is "
        << integers.getSize()
        << "\nArray after initialization:\n" << integers;

    cout << "Size of Array double is "
        << decimals.getSize()
        << "\nArray after initialization:\n" << decimals;

    cout << "Size of Array char is "
        << character.getSize()
        << "\nArray after initialization:\n" << character;

    // input and print
    cout << "\nPlease enter 8 integers, 10 double and 15 char" << endl;
    cin >> integers >> decimals >> character;

    cout << "\nAfter input, the Arrays contain:\n"
        << "integers:\n" << integers
        << "double:\n" << decimals
        << "char:\n" << character;

//    outClientFile << integers << decimals << character;

    // use overload subscript operator to create rvalue
    cout << "\nintegers[2] is " << integers[2];

    // use overload subscript operator to create lvalue
    cout << "\n\nAssignment 1000 to integers[2]" << endl;
    integers[2] = 1000;
    cout << "integers:\n" << integers;


    // use overload subscript operator to create rvalue
    cout << "\ndouble[3] is " << decimals[3];

    // use overload subscript operator to create lvalue
    cout << "\n\nAssignment 2000 to double[3]" << endl;
    decimals[3] = 2000;
    cout << "double:\n" << decimals;


    // use overload subscript operator to create rvalue
    cout << "\nchar[5] is " << character[5];

    // use overload subscript operator to create lvalue
    cout << "\n\nAssignment z to char[5]" << endl;
    character[5] = 'z';
    cout << "char:\n" << character;
}
