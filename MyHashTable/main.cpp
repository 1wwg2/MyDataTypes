
#include "myhashtable.h"

int main() {
    MyHashTable<std::string, int> table(5);

    table.insert("apple", 10);
    table.insert("banana", 20);
    table.insert("cherry", 30);

    table.print();

    return 0;
}

