#include <iostream>
#include<initializer_list>
#include <stdexcept>
template <typename T, std::size_t Size>
class Array 
{
  public:
    Array() 
    {  
      for (std::size_t i = 0; i < Size; i++) 
      {
        data[i] = T();
      }
    }
    Array(std::initializer_list<T> S)
    {
      std::size_t i=0;
      for(T value: S)
      {
        if(i<Size)
        {
          data[i++]=value;
        }
        else
        {
          throw std::out_of_range("S list size exceeds array size");
          std::cout<<"error: "<<std::endl;
         // return data[0];
        }
      }
      while (i < Size) 
      {
        data[i++] = T();
      }
    }
    std::size_t size() 
    {
        return Size;
    }
    T& operator[](std::size_t index) 
    {
      if (index >= Size) 
      {
        std::cout<<"error"<<std::endl;
        return data[0];
      }
      else
      {
        return data[index];
      }
    }
private:
    T data[Size]; 
};

int main() 
{
  Array<int, 5> intArray({1,2,3,4,5});
 // for (std::size_t i = 0; i < intArray.size(); i++) 
 // {
  //  std::cout<<intArray[i]<<std::endl;
//        intArray[i] = i * 2;
       // intArray[i]=i+1;
 // }

    std::cout << "Integer array: ";
    for (std::size_t i = 0; i < intArray.size(); i++)
    {
      std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    Array<double,6> dArray({1.11,2.13,3.15,4.36,6.23});
/*    dArray[0]=1.2;
    dArray[1]=2.5;
    dArray[2]=3.6;
    dArray[3]=4.8;
    dArray[4]=5.7;
    dArray[5]=6.4;
    for(std::size_t i=0;i<dArray.size();i++)
    {
      dArray[i]=i+1;
    }*/
    std::cout<<"dArray: ";
    for(std::size_t i=0;i<dArray.size();i++)
    {
      std::cout<<dArray[i]<<" ";
    }
    std::cout<<std::endl;

    Array<std::string, 3> stringArray({"Hello","World","!"});
   /* stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";*/
    std::cout << "String array: ";
    for (std::size_t i = 0; i < stringArray.size(); i++) 
    {
      std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

