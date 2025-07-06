
#include "../MyADT/myhashtable.h"

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
int main()
{
    MyHashTable<int, double> table;
    table.Insert(1, 42.1);
    table.Insert(2, 41.1);
    table.Insert(8, 43.1);
    ShowValue(1, table);
    ShowValue(4, table);

    return 0;
}

