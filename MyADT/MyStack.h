#include <list>

template<typename T>
class MyStack
{
private:
    std::list<T> stack;
public:
    void Push(const T& value);
    void Pop();
    T& Top();
    bool IsEmpty() const;
    size_t Size() const;
    void Swap(MyStack<T>& other) noexcept;
};


template <typename T>
void MyStack<T>::Push(const T& value)
{
    stack.push_front(value);
}
template <typename T>
void MyStack<T>::Pop()
{
    stack.pop_front();
}    
template <typename T>
T& MyStack<T>::Top()
{
    return stack.front();
}
template <typename T>
bool MyStack<T>::IsEmpty() const
{
    return stack.empty();
}
template <typename T>
size_t MyStack<T>::Size() const
{
    return stack.size();
}
template <typename T>
void MyStack<T>::Swap(MyStack<T>& other) noexcept
{
    std::list<T> temp = other.stack;
    other.stack = stack;
    stack = temp;
}
