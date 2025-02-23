#include <iostream>
#include "mylist.h"

   

int main()
{
    MyList list;
    list.PushBack(1);
    list.PushBack(3);
    list.PushBack(4);
    list.Show();
    list.InsertNode1(0, 3);
    list.Show();
return 0;
}
