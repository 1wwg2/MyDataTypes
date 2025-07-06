#include <iostream>
#include "../MyADT/myqueue.h"

int main()
{
    MyQueue<int> queue;
    MyQueue<int> queue1;

    for(int i = 0; i < 10; ++i)
    {
        queue.Push(i);
    }

    for(int i = 0; i < 5; ++i)
    {
        queue1.Push(i);
    }
    queue.Swap(queue1);
    while (!queue.IsEmpty())
    {
        std::cout << queue.Front(); 
        queue.Pop();  
    }
    std::cout << std::endl; 
    while (!queue1.IsEmpty())
    {
        std::cout << queue1.Front(); 
        queue1.Pop();  
    }

    std::cout << std::endl; 
};

