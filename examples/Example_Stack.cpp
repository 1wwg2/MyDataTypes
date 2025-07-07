#include <iostream>
#include "../MyADT/MyStack.h"

int main() {
    MyStack<int> stack;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    std::cout << "Top element: " << stack.Top() << std::endl; // expect 30

    stack.Pop();
    std::cout << "Top element after Pop: " << stack.Top() << std::endl; // expect 20

    std::cout << "Stack size: " << stack.Size() << std::endl; // expect 2

    std::cout << "Is stack empty? " << (stack.IsEmpty() ? "Yes" : "No") << std::endl;

    MyStack<int> otherStack;
    otherStack.Push(40);
    otherStack.Push(50);

    std::cout << "Top element of second stack: " << otherStack.Top() << std::endl; // expect 50

    stack.Swap(otherStack);

    std::cout << "\nAfter swap:" << std::endl;
    std::cout << "Top element of first stack: " << stack.Top() << std::endl;  // expect 50
    std::cout << "Top element of second stack: " << otherStack.Top() << std::endl; // expect 20

    return 0;
}

