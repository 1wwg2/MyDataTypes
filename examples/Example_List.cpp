#include <iostream>
#include <string>
   
#include "../MyADT/mylist.h"

int main()
{
    MyList <std::string> list;
    list.PushBack("alo");
    list.PushBack("hlo");
    list.PushBack("roror");
    list.Show();
    list.InsertNode1("kfajfa", 3);
    list.Show();
return 0;
}
