
#include "../MyADT/mydlist.h"
int main()
{
    MyDList<int> list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    list.Show();
    list.Reverse();
    list.Show();
    return 0;
}

