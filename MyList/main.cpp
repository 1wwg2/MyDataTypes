#include <iostream>
#include "mylist.h"

int main()
{
try {
    MyList list;
    std::cout << std::endl;
    list.Show();
    std::cout <<  list.Find(3) << std::endl;;
    list.Show();
} catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
} 
    return 0;
}
