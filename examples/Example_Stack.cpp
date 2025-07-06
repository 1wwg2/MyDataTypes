
#include <iostream>
#include "../MyADT/MyStack.h" 
int main() {
    MyStack<int> stack;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    std::cout << "Верхний элемент: " << stack.Top() << std::endl; // ожидаем 30

    stack.Pop();
    std::cout << "После Pop верхний элемент: " << stack.Top() << std::endl; // ожидаем 20

    std::cout << "Размер стека: " << stack.Size() << std::endl; // ожидаем 2

    std::cout << "Стек пуст? " << (stack.IsEmpty() ? "Да" : "Нет") << std::endl;

    MyStack<int> otherStack;
    otherStack.Push(40);
    otherStack.Push(50);

    std::cout << "Верхний элемент второго стека: " << otherStack.Top() << std::endl; // ожидаем 50

    stack.Swap(otherStack);

    std::cout << "\nПосле обмена:" << std::endl;
    std::cout << "Верхний элемент первого стека: " << stack.Top() << std::endl;  // ожидаем 50
    std::cout << "Верхний элемент второго стека: " << otherStack.Top() << std::endl; // ожидаем 20

    return 0;
}
