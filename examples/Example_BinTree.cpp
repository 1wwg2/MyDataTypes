#include <iostream>
#include "../MyADT/mybinarytree.h"

template <typename T>
void ShowValue(const T& value)
{
    std::cout << value << " ";
}

template <typename T>
void Show(const MyBinaryTree<T>& tree)
{
    std::cout << "Tree elements: ";
    tree.DoForAllElements(ShowValue<T>);
    std::cout << std::endl;
}

int main()
{
    MyBinaryTree<int> tree = {7, 5, 1, 0, 6, 4};
    std::cout << *tree.Find(5);
}

