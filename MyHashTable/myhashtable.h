#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "../MyVector/myvector.h"
#include "../MyDList/mydlist.h"
#include <iostream>

template <typename Key, typename Value>
class MyHashTable { private:
    struct HashNode {
        Key key;
        Value value;
    };

    MyVector<MyDList<HashNode>> buckets;
    size_t capacity;

    size_t hashFunction(const Key& key) const {
        std::hash<Key> hasher;
        return hasher(key) % capacity;
    }

public:
    MyHashTable(size_t size) : capacity(size), buckets(size) {}

    void insert(const Key& key, const Value& value) {
        size_t index = hashFunction(key);
        HashNode node{key, value};
        buckets[index].PushBack(node);
    }


void print() const {
    for (size_t i = 0; i < capacity; i++) {
        std::cout << "Bucket " << i << ": ";
        auto temp = buckets[i].GetHead();
        while (temp) {
            std::cout << "(" << temp->value.key << ", " << temp->value.value << ") ";  
            temp = temp->next;
        }
        std::cout << "\n";
    }
}

};

#endif // MYHASHTABLE_H

