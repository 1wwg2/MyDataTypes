#include <iostream>
#include "mylist.h"

int main()
{
    MyList list;
    list.PushBack(1);
    list.PushBack(2);
    //list.Reverse();
    list.Show();
    return 0;
}
