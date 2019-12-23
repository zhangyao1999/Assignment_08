#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

template <typename T>
class Array
{
    friend std::ostream &operator<<(std::ostream &output,const Array<T> &right)
    {
        for(size_t i=0;i<right.size;++i)
        {
            output<<std::setw(12)<<right.ptr[i];

            if((i+1)%4==0)
                output<<std::endl;
        }
        if(right.size%4!=0)
        {
            output<<std::endl;
        }
        return output;
    }

    friend std::istream &operator>>(std::istream &input, Array<T> &right)
    {
        for(size_t i=0;i<right.size;++i)
        {
            input>>right.ptr[i];
        }
        return input;
    }
public:
    explicit Array( int = 10 ); // default constructor
    Array( const Array & ); // copy constructor
    ~Array()
    {
        delete [] ptr;
    }

    size_t getsize()const
    {
        return size;
    }

    const Array &operator=(const Array<T> &right)
    {
        if(&right!=this)//avoid self-assignment
        {
            //for Arrays of different sizes,deallocate original
            //left-side Array,then allocate new left-side Array
            if(size!=right.size)
            {
                delete [] ptr;//release space
                size=right.size;//resize this object
                ptr=new T[size];//create space for Array copy
            }//end inner if
            for(size_t i=0; i<size; ++i)
            {
                ptr[i]=right.ptr[i];//copy array into object
            }//end outer if
        }
        return *this;//enables x=y=z,for example

    };//end function operator =

    bool operator==(const Array<T> &right)const
    {
        if(size!=right.size)
            return false;
        if(ptr!=right.ptr)
            return false;
        return true;

    }


    bool operator!=(const Array &right)
    {
        return !(*this==right);
    }

    T operator[](int t)
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
