#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <stdexcept>
template <typename T1>
class Array
{
    friend std::ostream &operator<<(std::ostream &output,const Array<T1> &right)
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
    friend std::istream &operator>>(std::istream &input, Array<T1> &right)
    {
        for(size_t i=0;i<right.size;++i)
        {
            input>>right.ptr[i];
        }
        return input;
    }
public:
    explicit Array(int=6);
    Array( const Array<T1> &);
    ~Array()
    {
        delete [] ptr;
    }
    size_t getSize()const
    {
        return size;
    }
    const Array &operator=(const Array<T1> &right)
    {
        if(&right!=this)
        {
            if(size!=right.size)
            {
                delete [] ptr;
                size=right.size;
                ptr=new T1[size];
            }
            for(size_t i=0;i<size;++i)
            {
                ptr[i]=right.ptr[i];
            }
        }
        return *this;

    }
    bool operator==(const Array<T1> &right)const
    {
        if(size!=right.size)
            return false;
        if(ptr!=right.ptr)
            return false;
        return true;

    }
    bool operator!=(const Array<T1> &right)const
    {
        if(size!=right.size)
            return true;
        if(ptr!=right.ptr)
            return true;
        return false;
    }
    T1 &operator[](int subscript)
    {
        if(subscript<0||subscript>=size)
            throw std::out_of_range("Subscript out of range");
        return ptr[subscript];
    }
    T1 operator[](int subscript)const
    {
        if(subscript<0||subscript>=size)
            throw std::out_of_range("Subscript out of range");
        return ptr[subscript];
    }
private:
    T1 *ptr;
    size_t size;
};
template <typename T1>
Array<T1>::Array(int arraySize)
{
    if(arraySize>0)
        size=arraySize;
    else
        throw std::invalid_argument("Array size must be greater than 0");
    ptr=new T1[size];
    for(size_t i=0;i<size;++i)
    ptr[i]=0;
}
template <typename T1>
Array<T1>::Array(const Array<T1> &right)
:size(right.size),
ptr(new T1 [size])
{
    for(size_t i=0;i<size;++i)
    {
        ptr[i]=right.ptr[i];
    }

}


#endif // ARRAY_H_INCLUDED
