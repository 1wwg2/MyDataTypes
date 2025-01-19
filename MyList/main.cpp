#include <iostream>
#include "mylist.h"

int main()
{
try {
    MyList list;
    list.PushBack(1);
    std::cout << std::endl;
    list.Show();
    list.Remove(3);
    list.Show();
    list.PushBack(2);
    list.Show();
} catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
} 
    return 0;
}
