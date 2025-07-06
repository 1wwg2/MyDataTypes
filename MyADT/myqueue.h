#include <list>
#include <iostream>
template <typename T>
class MyQueue
{
private: 
    std::list<T> queue;
public:
    MyQueue() = default;
    MyQueue(const MyQueue& other) = default;
    MyQueue(MyQueue&& other) = default;

    ~MyQueue() = default;

    MyQueue& operator=(const MyQueue& other) = default;
    MyQueue& operator=(MyQueue&& other) = default;
    
    void Pop();
    void Push(const T& value);
    size_t Size() const;
    T& Front();
    void Swap(MyQueue& oter) noexcept;
    bool IsEmpty();
    T& Back();

};

template<typename T>
void MyQueue<T>::Pop() 
{
    queue.pop_front();
}

template<typename T>
void MyQueue<T>::Push(const T& value)
{
    queue.push_back(value);
}
template<typename T>
size_t MyQueue<T>::Size() const
{
   return queue.size();
}

template<typename T>
T& MyQueue<T>::Front()
{   
    return queue.front();
}

template<typename T>
void MyQueue<T>::Swap(MyQueue<T>& other) noexcept
{
    std::list<T> temp = other.queue;
    other.queue = queue;
    queue = temp; 
}

template<typename T>
bool MyQueue<T>::IsEmpty()
{
    return queue.empty();
}

template<typename T>
T& MyQueue<T>::Back()
{
    return queue.back();
}
