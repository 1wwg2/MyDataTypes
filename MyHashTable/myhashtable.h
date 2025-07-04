#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <iostream>
#include <memory>
#include <stdexcept>


template<typename Key, typename Value>
class MyHashTable
{
private:
    struct HashNode
    {
        Key key;
        Value value;
        std::unique_ptr<HashNode> next;
    };
    size_t size;
    HashNode** table;

    size_t HashFunction(const Key& key) const
    {
        return std::hash<Key>()(key) % size;
    }
    void Clear()
    {
        for(int i = 0; i < size; ++i)
        {
            HashNode* curr = table[i];
            while(curr != nullptr)
            {
                std::unique_ptr<HashNode>temp (std::move(curr->next));
                delete curr;
                curr = temp.release();
            }
        }
    }


public:

    MyHashTable(size_t _size = 10)
    {
        size = _size;
        table = new HashNode* [size]{};
    }
    MyHashTable(const MyHashTable& other) = delete;
    MyHashTable& operator=(const MyHashTable& other) = delete;
       
    ~MyHashTable()
    {
       Clear();
       delete[] table;
    } 

    void Insert(const Key& key, const Value& value)
    {
       size_t Hash = HashFunction(key);
       
       HashNode*& node = table[Hash]; //попробовать сделать без курент а просто тейбл хеш 
       while(node != nullptr)
       {
           if(node->key == key)
           {
              node->value = value;
              return;
           }
           node = node->next.get();
       }
       node = new HashNode{key, value, std::unique_ptr<HashNode>(nullptr)}; //разобраться с умными узателями, 
    }

    const Value& Search(const Key& key) const    //разобраться почему ссылка
    { 
        size_t Hash = HashFunction(key);
        HashNode* node = table[Hash];

        while(node != nullptr)
        {
            if(node->key == key)
            {
                return node->value;
            }
            node = node->next.get();
        }
        throw std::out_of_range("Value not Search");
    }

    bool Remove(const Key& key)
    {
        size_t Hash = HashFunction(key);
        HashNode*& node = table[Hash];
        if(node == nullptr)
        {
            return false;
        }
        if(node->key == key)
        {
            std::unique_ptr<HashNode> temp(std::move(node->next));
            delete node;
            node = temp.release();
            return true;
        }

        HashNode* prev = node;
        HashNode* curr = node->next.get(); 
        while(curr != nullptr)
        {
            if(node->key == key)
            {
                std::unique_ptr<HashNode> temp (std::move(curr->next));
                prev->next = std::move(temp);
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

};


#endif // MYHASHTABLE_H
