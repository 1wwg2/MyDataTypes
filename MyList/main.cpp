#include <iostream>
#include "mylist.h"

int main()
{
try {
    MyList list;
    list.PushBack(8);
    list.PushBack(9);
    list.PushBack(9);
    list.PushBack(9);
    list.PushFront(4);
    list.PushFront(3);
    list.Show();
    std::cout << std::endl;
    int value = list[-1]; 
} catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
} 
    return 0;
}
