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
    MyDList(const MyDList& other);
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
MyDList<T>::MyDList(const MyDList& other) : head(nullptr), tail(nullptr), size(0)
{
    if(other.size == 0)
    {
        return;
    }

    head = new Node {other.head->value, nullptr, nullptr};
    Node* current = head;
    Node* otherCurrent = other.head->next;
    tail = head;

    while(otherCurrent != nullptr)
    {    
        current->next = new Node {otherCurrent->value, current, nullptr};
        current = current->next;
        otherCurrent = otherCurrent->next;
        tail = tail->next;
    }
    size = other.size;    

}
template <typename T> 
MyDList<T>::MyDList(MyDList&& other) noexcept
{
    head = other.head;
    tail = other.tail;
    size = other.size; 
    other.size = 0;
    other.tail = 0;
    other.head = 0;
}
template <typename T> 
MyDList<T>& MyDList<T>::operator=(const MyDList& other)
{
    if(other != &this)
    {
        Clear();

        head = new Node {other.head->value, nullptr, nullptr};
        Node* current = head;
        Node* otherCurrent = other.head->next;

        while(otherCurrent != nullptr)
        {    
            current->next = new Node {otherCurrent->value, current, nullptr};
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        size = other.size;   
    }
}
template <typename T> 
MyDList<T>& MyDList<T>::operator=(MyDList&& other) noexcept
{
   if(other != &this) 
   {
        Clear();
        head = other.head;
        tail = other.tail;
        size = other.size; 
        other.size = 0;
        other.tail = 0;
        other.head = 0;
   }
}
template <typename T> 
MyDList<T>::~MyDList()
{
    Clear();
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
    if(size == 0)
    {
        head = new Node {value, nullptr, nullptr};
        tail = head;
    }
    else
    {
        Node* current = head;
        head = new Node {value, nullptr, current};
        head->next->prev = head;
    }
    ++size;
}
template <typename T> 
void MyDList<T>::PopBack()
{
    if(size == 0)
    {
        return;
    }
    else if(size == 1)
    {
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
    else
    {
        Node* temp = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;
        delete temp; 
    }
    --size;

}
template <typename T> 
void MyDList<T>::PopFront()
{
    if(size == 0)
    {
        return;
    }
    else if(size == 1)
    {
        delete head;
        tail = nullptr;
        head = nullptr;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        head->next->prev = nullptr;
        delete temp;
    }
}
template <typename T> 
T& MyDList<T>::Front()
{
    if(size != 0)
    {
        return head->value;
    }
}
template <typename T> 
const T& MyDList<T>::Front() const
{
    if(size != 0)
    {
        return head->value;
    }
}
template <typename T> 
T& MyDList<T>::Back()
{
    if(size !=0)
    {
        return tail->value;
    }
}
template <typename T> 
const T& MyDList<T>::Back() const
{
    if(size !=0)
    {
        return tail->value;
    }
}
template <typename T> 
void MyDList<T>::Remove(const T& value)
{
    if(size == 0)
    {
        return;
    }
    else if(tail->value == value)
    {
        PopBack();
        return;
    }
    else if(head->value == value)
    {
        PopFront();
        return;
    }
    else 
    {
        Node* current = head;
        while(current != nullptr)
        {
            if(current->value == value)
            {
                Node* temp = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete temp;
                --size;
                return;
            }
            current = current->next;
        }
        std::cout << "Value not found" << std::endl;
    }
}
template <typename T> 
bool MyDList<T>::Find(const T& value)
{
    if(size != 0)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if(value == current->value)
            {
                return true;
            }
            current = current->next;
        }
    }
    return false;
}
template <typename T> 
void MyDList<T>::Reverse()
{
    tail = head;
    Node* current = head;
    Node* temp = nullptr;
    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if(temp != nullptr)
    {
        head = temp->prev;
    }

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
