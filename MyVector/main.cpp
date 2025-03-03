#include "myvector.h"
#include <iostream>

int main()
{
    MyVector<int> vec;
    vec.PushBack(1);
    vec.PushBack(2);
    vec.PushBack(3);
    vec.PushBack(7);
    vec.PushBack(1);
    std::cout << vec.Size() << std::endl;
    
    for(int i = 0; i < vec.Size(); ++i)
    {
        std::cout << vec.At(i) << " ";
    }
 
}
