#include <iostream>
#include "mylist.h"

int main()
{
    MyList list;
    list.PushBack(8);
    list.PushBack(9);
    list.PushBack(9);
    list.PushBack(9);
    list.PushFront(9);
    list.Show();
    std::cout << std::endl;
    list.Clear();
    list.Show(); 
    return 0;
}
