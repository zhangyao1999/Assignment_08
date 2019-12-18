// Assignment_08 : Array.h
// Array class definition
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

template < typename T > // function template head
class Array
{
    friend ostream & operator<<( ostream &output, const Array &a )
    {
        // output private ptr-based array
        for ( size_t i = 0; i < a.getSize(); ++i )
        {
            output << setw(12) << a.ptr[i];

            if ( ( i + 1) % 5 == 0 ) // 5 numbers per row of output
                output << endl;
        }

        if ( a.getSize() % 5 != 0 ) // end last line of output
            output << endl;

        return output; // enable cout << x << y;
    }

    friend istream & operator>>( istream &input, Array &a )
    {
        for ( size_t i = 0; i < a.getSize(); ++i )
            input >> a.ptr[i];

        return input; // enables cin >> x >> y;
    }

public:
    explicit Array( int = 10 ); // default constructor
    Array( const Array & ); // copy constructor
    ~Array() // destructor
    {
        delete [] ptr;
    }

    // return size
    size_t getSize() const
    {
        return size;
    }

    // assignment operator
    const Array & operator=( const Array &right )
    {
        if ( &right != this ) // avoid self-assignment
        {
            if ( getSize() != right.getSize() )
            {
                delete [] ptr;
                size = right.getSize();
                ptr = new T [ getSize() ];
            }

            for ( size_t i = 0; i < getSize(); ++i )
                ptr[i] = right.ptr[i]; // copy array into object
        }

        return *this; // enable x = y = z, for example
    }

    bool operator==( const Array & ) const; // equality operator

    // inequality operator; returns opposite of == operator
    bool operator!=( const Array &right ) const
    {
        return !( *this == right );
    }

    //subscript operator for non-const objects
    T &operator[]( int );

    //subscript operator for const objects
    T operator[]( int ) const;

private:
    size_t size;
    T *ptr;
};


template < typename T >
Array< T >::Array( int arraySize )
    : size( arraySize > 0 ? arraySize :
        throw invalid_argument( "Array size must be greater than 0" ) ),
      ptr( new T [ size ] )
{
    for ( size_t i = 0; i < getSize(); ++i )
        ptr[i] = 0;
}

template < typename T >
Array< T >::Array( const Array &arrayToCopy )
    : size( arrayToCopy.getSize() ),
      ptr( new T [ size ] )
{
    for ( size_t i = 0; i < getSize(); ++i )
        ptr[i] = arrayToCopy.ptr[i];
}

template < typename T >
bool Array< T >::operator==( const Array &right ) const
{
    if ( getSize() != right.getSize() )
        return false;

    for ( size_t i = 0; i < getSize(); ++i )
        if ( ptr[i] != right.ptr[i] )
        return false;

    return true;
}

template < typename T >
T &Array< T >::operator[]( int subscript )
{
    if ( subscript < 0 || subscript >= getSize() )
        throw invalid_argument( "Subscript out of range" );

    return ptr[ subscript ];
}

template < typename T >
T Array< T >::operator[]( int subscript ) const
{
    if ( subscript < 0 || subscript >= getSize() )
        throw invalid_argument( "Subscript out of range" );

    return ptr[ subscript ];
}

#endif // ARRAY_H
