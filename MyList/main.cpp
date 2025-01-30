#include <iostream>
#include "mylist.h"

int main()
{
    MyList list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.Show();
    MyList list1 (list);
    list1.Show();
    return 0;
}
