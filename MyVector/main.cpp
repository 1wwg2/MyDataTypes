#include "myvector.h"
#include <iostream>

int main()
{
    //MyVector<const char*> vec("a", 7);
    MyVector<int> vec;
    vec.PushFront(1);
    vec.PushFront(2);
    vec.PushFront(3);
    vec.PopFront();
    
    MyVector<int> vec1;
    vec.Swap(vec1);
    for(int i = 0; i < vec1.Size(); ++i)
    {
        std::cout << vec1.At(i) << " ";
    }
    std::cout << std::endl;

 
}
