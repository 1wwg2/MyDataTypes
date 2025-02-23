#include <iostream>
#include "mylist.h"

   

int main()
{
    MyList list;
    list.PushBack(1);
    list.PushBack(3);
    list.PushBack(4);
    list.Show();
    MyList list2;
    list2.PushBack(1);
    list2.PushBack(2);
    list2.PushBack(4);
    list2.Show();

    list.MergeList(list2);

    list.Show();
return 0;
}
