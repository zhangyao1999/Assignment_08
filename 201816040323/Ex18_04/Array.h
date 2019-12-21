#ifndef ARRAY_H
#define ARRAY_H
#include <iomanip>
#include <stdexcept>
#include <iostream>
using namespace std;
template <typename T>
class Array
{
    friend ostream &operator<<(ostream &output , const Array &a)
    {
        for(size_t i=0 ; i<a.size ;++i )
        {
            output << setw(12) << a.ptr[i];
            if((i+1)%4 == 0)
                output << endl;
        }
        if(a.size %4 == 0)
            output <<endl;
        return output;
    }

    friend istream &operator>>(istream &input , Array &a )
    {
        for(size_t i=0; i<a.size ;++i)
            input >> a.ptr[i];
        return input;
    }

public:
    explicit Array( T = 10);
    Array(const Array &);
    ~Array();
    size_t getSize()const;
    const Array &operator=(const Array &right)
{
    if(&right != this)
    {
        if(size !=right.size)
        {
            delete[]ptr;
            size=right.size;
            ptr=new T[size];
        }
        for(size_t i=0 ; i<size;++i)
            ptr[i] = right.ptr[i];
    }
    return *this;
}
    bool operator==(const Array &)const;
    bool operator!=(const Array &right)const
    {
        return ! (*this == right );
    }
    T &operator[](size_t);
    T operator[](size_t)const;


private:
    size_t size;
    T *ptr;
};

template <typename T>
Array<T>::Array(T arraySize)
    :size(arraySize >0 ? arraySize :
          throw invalid_argument("Array size must be greater than 0")),ptr(new T[size])
{
   for(size_t i=0;i<size;++i)
     ptr[i]=0;
}

template <typename T>
Array<T>::Array(const Array &arrayToCopy)
    :size(arrayToCopy.size),ptr(new T[size])
{
    for(size_t i=0 ;i<size ;++i)
        ptr[i]=arrayToCopy.ptr[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] ptr;
}

template <typename T>
size_t Array<T>::getSize()const
{
    return size;
}

template <typename T>
bool Array<T>::operator==(const Array &right)const
{
    if(size !=right.size)
        return false;
    for(size_t i=0;i<size ;++i)
        if(ptr[i] != right.ptr[i])
          return false;
    return true;
}

template <typename T>
T &Array<T>::operator[](size_t subscript)
{
    if(subscript <0 || subscript >= size)
        throw out_of_range("Subscript out of range");
    return ptr[subscript];
}

template <typename T>
T Array<T>::operator[](size_t subscript)const
{
    if(subscript < 0 || subscript >=size)
        throw out_of_range("Subscript out of range");
    return ptr[subscript];
}
#endif // ARRAY_H
