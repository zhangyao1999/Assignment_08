#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;
template<class K>
class Array
{
    friend std::ostream &operator<<(std::ostream &output,const Array<K> &a)//
    {
        for(size_t i=0;i<a.size;++i)//to print all numbers of the a
        {
            output<<setw(12)<<a.ptr[i];//to set the form of print
            if((i+1)%4==0)
                output<<endl;
        }
        if(a.size%4!=0)
            output<<endl;
        return output;//return the ostream
    }
    friend std::istream &operator>>(std::istream &input,Array<K> &a)
    {
        for(size_t i=0;i<a.size;++i)// Enter data into a
        input>>a.ptr[i];
        return input;//return the istream
    }
public:
    Array(int arraySize)//constructor with one parameter
    {
        if(arraySize>0)//Validate data
            size=arraySize;
        else
            throw invalid_argument("Array size must be greater than 0");//return the information of error
        ptr=new K[size];//Dynamic memory allocation
        for(size_t i=0;i<size;++i)//initialize the array
            ptr[i]=0;
    }
    Array(const Array<K> &arrayToCopy)
    {
        size=arrayToCopy.size;//copy the size of the arrayToCopy
        ptr=new K[size];//Dynamic memory allocation
        for(size_t i=0;i<size;++i)//Copy one by one
        ptr[i]=arrayToCopy.ptr[i];
    }
    ~Array()
    {
        delete [] ptr;//delete the memory
    }
    size_t getSize()const
    {
        return size;
    }
    const Array<K> &operator=(const Array<K> &right)//overload the = function
    {
        if(&right!=this)//avoid self-assignment
        {
            if(size!=right.size)
            {
                delete [] ptr;//Release space
                size=right.size;//copy the size
                ptr=new K[size];//Dynamic memory allocation

            }
            for(size_t i=0;i<size;++i)
            {
                ptr[i]=right.ptr[i];//copy the numbers one by one
            }
        }
        return *this;
    }
   bool operator==(const Array<K> &right)const//overload the == function
    {
        if(size!=right.size)//Judgement size
            return false;
        for(size_t i=0;i<size;++i)//One by one comparison
            if(ptr[i]!=right.ptr[i])
                return false;
        return true;
    }
    bool operator!=(const Array<K> &right)const//overload the != function
    {
        return !(*this==right);
    }
    K &operator[](int subscript)//overload the [] function
    {
        if(subscript <0||subscript>=size)
            throw out_of_range("Subscript out of the range");//return the information of error
        return ptr[subscript];
    }
    K operator[](int subscript)const//overload the [] function
    {
        if(subscript <0||subscript >=size)
            throw out_of_range("Subscript out of the range");//return the information of error
        return ptr[subscript];
    }
private:
    size_t size;
    K *ptr;
};
int main()
{
    Array<int> objectA(10);//create a Array named objectA of integer
    cout<<"Please enter 10 integer numbers"<<endl;
        cin>>objectA;//enter ten integer numbers
    Array<double> objectB(10);//create a Array named objectB of double
    cout<<"Please enter 10 double numbers"<<endl;
    cin>>objectB;//enter ten double numbers
    Array<char> objectC(10);//create a Array named objectC of char
    cout<<"Please enter 10 characters"<<endl;
    cin>>objectC;//enter ten characters

    cout<<"Storing int type data with custom template class,the data are as follows"<<endl;
    cout<<objectA;//print ten integer numbers of objectA
    cout<<"Storing int type data with custom template class,the data are as follows"<<endl;
    cout<<objectB;//print ten double numbers of objectB
    cout<<"Storing int type data with custom template class,the data are as follows"<<endl;
    cout<<objectC;//print ten characters of objectC
    return 0;
}
