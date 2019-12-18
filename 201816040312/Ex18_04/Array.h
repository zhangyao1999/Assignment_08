#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;
template <typename T>
class Array
{
    friend ostream &operator<<(ostream &output,const Array<T> &a)
    {
        //output private ptr-based array
        for(size_t i=0;i<a.size;++i)
        {
            output<<setw(12)<<a.ptr[i];
            if((i+1)%4==0)//4 numbers per row of output
                output<<endl;
        }//end for
        if(a.size%4!=0)//end last line of output
            output<<endl;
        return output;//enables cout<<x<<y;
    };//end function operator<<
   //overloaded input operator for class Array
   //input values for entir Array
    friend istream &operator>>(istream &input, Array<T> &right)
    {
        for(size_t i=0; i<right.size; ++i)
        {
            input>>right.ptr[i];
        }
        return input;
    };//end function
public:
    explicit Array(int arraysize)
    :size(arraysize>0 ? arraysize:throw invalid_argument("array size must be greater than 0"))//default constructor
    {
        ptr=new T[size];
        for(size_t i=0;i<size;++i)
        {
            ptr[i]=0;//set pointer-based array element
        }
    };//end array default constructor
    Array( const Array<T> &arraytocopy)
    :size(arraytocopy.size),ptr(new T[size])
    {
        for(size_t i=0;i<size;++i)
            ptr[i]=arraytocopy.ptr[i];//copy into object
    };//end Array copy constructor
    //destructor for class Array
    ~Array()
    {
        delete [] ptr;//release pointer-based array space
    };
    size_t getSize()const
    {
        return size;//number of elements in Array
    };//end function getsize
    //overloaded assignment operator
    //const return avoids:(a1=a2)=a3
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
    //determine if two Arrays are equal and
    //return true ,otherwise return false
    bool operator==(const Array<T> &right)const
    {
        if(size!=right.size)
            return false;//arrays of different number of element
        for(size_t i=0;i<size;++i)
            if(ptr[i]!=right.ptr[i])
               return false;//Array contents are not equal
        return true;//Arrays are equal
    };//end function operator==
    bool operator!=(const Array<T> &right)const
    {
       return !(*this==right);//invokes Array::operator==
    };//end function operator!=
    //subscript operator for non-const objects returns modifiable lvalue
    T &operator[](int subscript)
    {
        //check for subscript out-of-range-error
        if(subscript<0||subscript>=size)
            throw std::out_of_range("Subscript out of range");
        return ptr[subscript];//reference return
    };//end function operator[]
    T operator[](int subscript)const
    {
        //check for subscript out-of-range-error
        if(subscript<0||subscript>=size)
            throw std::out_of_range("Subscript out of range");
        return ptr[subscript];
    };//end function operator[]
private:
    T *ptr;
    size_t size;
};
#endif // ARRAY_H
