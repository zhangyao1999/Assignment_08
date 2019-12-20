#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iomanip>
#include <array>
#include <iostream>
#include <string>

using namespace std;
template<class T>
class Array
{
    friend ostream &operator<<(ostream &output,const Array &a)
    {
        //output private ptr-based array
        for(size_t i=0;i<a.size;++i)
        {
            output<<setw(12)<<a.ptr[i];

            if((i+1)%4==0)//4 numbers pre row of output
                output<<endl;
        }
        if(a.size%4!=0)
            output<<endl;

        return output;
    }


    friend istream &operator>>(istream &input,Array &a)
    {
        for (size_t i=0;i<a.size;++i)
        {
            input>>a.ptr[i];
        }
        return input;
    }

public:
    Array(int arraySize):size(arraySize>0?arraySize:throw invalid_argument("Array size must be greater than 0")),
    ptr(new T[size])
    {
        for (size_t i=0;i<size;++i)
            ptr[i]=0;//set pointer-based array element
    }


    Array(const Array &arrayToCopy):size(arrayToCopy.size),ptr(new T[size])
    {
        for (size_t i=0;i<size;++i)
            ptr[i]=arrayToCopy.ptr[i];//copy into object
    }


    ~Array()
    {
        delete []ptr;
    }//destructor


    size_t getSize()const
    {
        return size;
    }



    const Array& operator=(const Array &right)
    {
        if(&right!=this)
        {
            if(size!=right.size)
            {
                delete []ptr;
                size=right.size;
                ptr=new T[size];
            }
            for(size_t i=0;i<size;++i)
            {
                ptr[i]=right.ptr[i];

            }
        }
        return *this;
    }



    bool operator==(const Array &right)const
    {
        if(size!=right.size)
            return false;
        for(size_t i=0;i<size;++i)
        {
            if(ptr[i]!=right.ptr[i])
                return false;
        }
        return true;
    }//end function operator==



    bool operator!=(const Array &right)const
    {
        return !(*this==right);
    }//end function operator!=



    T operator[](int t)
    {
        if(t<0||t>=size)
            throw out_of_range("t out of range");
        return ptr[t];
    }


    T operator[](int t)const
    {
        if(t<0||t>=size)
            throw out_of_range("t out of range");
        return ptr[t];
    }


private:
    size_t size;
    T *ptr;


};

#endif // ARRAY_H_INCLUDED
