#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>


template<typename Key, typename Value>
class MyHashTable
{
private:
    struct HashNode
    {
        Key key;
        Value value;
        std::unique_ptr<HashNode> next;

        HashNode(const Key& k, const Value& v, std::unique_ptr<HashNode> n = nullptr) : key(k), value(v), next(std::move(n)) {}
        ~HashNode() { std::cout << "Node was deleted, key is " << key << std::endl;}
    };
    size_t size;
    //HashNode** table;
    std::vector<std::unique_ptr<HashNode>> table;
    size_t HashFunction(const Key& key) const
    {
        return std::hash<Key>()(key) % size;
    }
    /* void Clear() */
    /* { */
    /*     for(int i = 0; i < size; ++i) */
    /*     { */
    /*         HashNode* curr = table[i].get(); */
    /*         while(curr != nullptr) */
    /*         { */
    /*             std::unique_ptr<HashNode>temp (std::move(curr->next)); */
    /*             delete curr; */
    /*             curr = temp.release(); */
    /*         } */ /*     } */
    /* } */


public:

    MyHashTable(size_t _size = 10) : table(_size)
    {
        size = _size;
        
        //table = new HashNode* [size]{};

    }
    MyHashTable(const MyHashTable& other) = delete;
    MyHashTable& operator=(const MyHashTable& other) = delete;
       
    ~MyHashTable()
    {
       //Clear();
       //delete[] table;
    } 

    void Insert(const Key& key, const Value& value)
    {
       size_t Hash = HashFunction(key);
       
      HashNode* node = table[Hash].get();
       while(node != nullptr)
       {
           if(node->key == key)
           {
              node->value = value;
              return;
           }
           node = node->next.get();
       }
        auto newNode = std::make_unique<HashNode>(key, value, std::move(table[Hash]));
        table[Hash] = std::move(newNode);
     }

    const Value& Search(const Key& key) const        
    { 
        size_t Hash = HashFunction(key);
        HashNode* node = table[Hash].get();

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

template<typename Key, typename Value>
void ShowValue(const Key& key, const MyHashTable<Key, Value>& table) 
{
    try
    {
       const Value& value = table.Search(key);
       std::cout << key << ": [" << value << "]" << std::endl;
    }
    catch(const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
    }
} 



