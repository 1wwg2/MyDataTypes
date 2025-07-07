#include "../MyADT/myvector.h"
#include <iostream>

int main()
{
    //MyVector<const char*> vec("a", 7);
    MyVector<int> vec;
    vec.PushFront(1);
    vec.PushFront(2);
    vec.PushFront(3);
    vec.PopFront();
   // vec.Clear(); 
    for(int i = 0; i < vec.Size(); ++i)
    {
        std::cout << vec.At(i) << " ";
    }
    try
    {
        vec.At(-1);
    }
    catch(std::exception& exc)
    {
        std::cout << exc.what();
    }
    std::cout << std::endl;

 
}
