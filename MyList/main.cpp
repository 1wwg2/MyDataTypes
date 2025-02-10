#include <iostream>
#include "mylist.h"

int main()
{
    MyList list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    list.PushBack(5);
    list.Show();
    list.Remove(5);
    list.Show();
    return 0;
}
