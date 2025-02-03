#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>

class MyList
{
private:
    struct Node
    {
        int value;
        Node* next;
    };
    Node* Head;
    MyList& Copy(const MyList& other);
public:
    MyList();
    MyList(const MyList& other);
    MyList(MyList&& other) noexcept;

    ~MyList();
    
    void PushBack(const int& value);
    void PushFront(const int& value);
    
    void PopBack();
    void PopFront();
    void Reverse();
    void InsertNode(int value, int position);
    void Remove(const int& value);
    void Clear();
    
    bool Find(const int& value) const;
    
    bool IsEmpty() const;
    size_t Size() const;

    MyList& operator=(const MyList& other);
    MyList& operator=(MyList&& other) noexcept;

    int& operator[](int index);
    const int& operator[](int index) const;

    void Show() const;
};

#endif // MYLIST_H
