#include <iostream>
#include "MySharedPtr.h"

int main()
{
    MySharedPtr<int> ptr1(new int(10));
    MySharedPtr<int> ptr2 = ptr1;  
    MySharedPtr<int> ptr3 = std::move(ptr2);  

    std::cout << *ptr3.get() << ", Use Count: " << ptr3.use_count() << std::endl;
    return 0;
}
