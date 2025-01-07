#include <iostream>
#include "mylist.h"

int main()
{
try {
    MyList list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(9);
    list.PushBack(3);
    list.PushBack(4);

    list.PushFront(5);
    list.PushFront(6);
    
    list.Show();
    list.Remove(2);
    list.Show();
    std::cout << std::endl;
} catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
} 
    return 0;
}
