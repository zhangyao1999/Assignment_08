#include<iostream>
#include<iomanip>
#include<stdexcept>
using namespace std;
template<typename T>
class Array//define class
{
    friend istream &operator>>(istream &input,Array &a)//operator >>
    {
        for(size_t i=0;i<a.size;++i)
            input>>a.ptr[i];
        return input;
    }
friend ostream &operator<<(ostream &output,const Array &a)//operator <<
    {
        for(size_t i=0;i<a.size;++i)
        {
            output<<setw(12)<<a.ptr[i];
            if((i+1)%4==0)//four numbers per row of output
                output<<endl;
        }
        if(a.size%4!=0)//end last line of output
            output<<endl;
        return output;
    }
public:
    //explicit Array(int=10);
    Array<T>(int arraySize)
    :size(arraySize>0?arraySize:
          throw invalid_argument("Array size must be greater than 0")),
          ptr(new T[size])
          {
              for(size_t i=0;i<size;i++)
                ptr[i]=0;
          }//Array default constructor
    Array(const Array &arrayToCopy)
    :size(arrayToCopy.size),
    ptr(new T[size])
    {
        for(size_t i=0;i<size;++i)
            ptr[i]=arrayToCopy.ptr[i];
    }//copy constructor
    ~Array()
    {
        delete [] ptr;
    }//destructor
    size_t getSize()const
    {
        return size;
    }//getSize function
    const Array &operator=(const Array &right)//operator=
    {
        if(&right!=this)
        {
            if(size!=right.size)
            {
                delete [] ptr;
                size =right.size;
                ptr=new T [size];
            }
            for(size_t i=0;i<size;++i)
                ptr[i]=right.ptr[i];
        }
        return *this;
    }
    bool operator==(const Array &right)const//operator ==
    {
        if(size!=right.size)
            return false;
        for(size_t i=0;i<size;++i)
        if(ptr[i]!=right.ptr[i])
            return false;
        return true;
    }
    bool operator!=(const Array &right)const//operator!=
    {
        return!(*this==right);
    }
    int &operator[](int subscript)//function operator []
    {
        if(subscript<0||subscript>=size)
            throw out_of_range("Subscript out of range");
        return ptr[subscript];
    }
    int operator[](int subscript)const//function operator []
    {
        if(subscript<0||subscript>=size)
            throw out_of_range("Subscript out of range");
        return ptr[subscript];
    }
private://data member
    size_t size;
    T *ptr;
};
