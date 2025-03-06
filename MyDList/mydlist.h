#include <iostream>
#include <memory>
template<typename T>
class MyDList
{
private:
    struct Node
    {
        T value;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* tail;
    size_t size;
public:
    MyDList();
    MyDList(const MyDList&& other);
    MyDList(MyDList&& other) noexcept;

    MyDList& operator=(const MyDList& other);
    MyDList& operator=(MyDList&& other) noexcept;

    ~MyDList();

    void PushBack(const T& value);
    void PushFront(const T& value);
    
    void PopBack();
    void PopFront();

    T& Front();
    const T& Front() const;

    T& Back();
    const T& Back() const;

    void Remove(const T& value);
    bool Find(const T& value);

    void Reverse();
    void Clear();
    bool isEmpty() const;

    void Show() const;
    size_t Size() const;
};
template <typename T> 
MyDList<T>::MyDList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template <typename T> 
MyDList<T>::MyDList(const MyDList&& other)
{
    if(other.size != 0)
    {
    }
}
template <typename T> 
MyDList<T>::MyDList(MyDList&& other) noexcept
{
}
template <typename T> 
MyDList<T>& MyDList<T>::operator=(const MyDList& other)
{
}
template <typename T> 
MyDList<T>& MyDList<T>::operator=(MyDList&& other) noexcept
{
}
template <typename T> 
MyDList<T>::~MyDList()
{
}
template <typename T> 
void MyDList<T>::PushBack(const T& value)
{
    if(size == 0)
    {
       head = new Node {value, nullptr, nullptr};
       tail = head;
    }
    else
    {
        tail->next = new Node{value, tail, nullptr};
        tail = tail->next;
    }
    ++size;
}
template <typename T> 
void MyDList<T>::PushFront(const T& value)
{
}
template <typename T> 
void MyDList<T>::PopBack()
{
}
template <typename T> 
void MyDList<T>::PopFront()
{
}
template <typename T> 
T& MyDList<T>::Front()
{
}
template <typename T> 
const T& MyDList<T>::Front() const
{
}
template <typename T> 
T& Back()
{
}
template <typename T> 
const T& MyDList<T>::Back() const
{
}
template <typename T> 
void MyDList<T>::Remove(const T& value)
{
}
template <typename T> 
bool MyDList<T>::Find(const T& value)
{
}
template <typename T> 
void MyDList<T>::Reverse()
{
}
template <typename T> 
void MyDList<T>::Clear()
{
    if(size != 0)
    {
        Node* current = head;
        while(current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
}

template <typename T> 
bool MyDList<T>::isEmpty() const
{
    return size == 0;
}
template <typename T> 
void MyDList<T>::Show() const
{
    if(size != 0)
    {
        Node* current = head;
        while(current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    else 
    {
        std::cout << "List is Empty!" << std::endl;
        return;
    }
}


template <typename T> 
size_t MyDList<T>::Size() const
{
    return size;
}
