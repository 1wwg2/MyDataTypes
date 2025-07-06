#include <iostream>
template <typename T>
class MyUniquePtr
{
private:
    T* ptr;
public:
    MyUniquePtr();
    MyUniquePtr(const T& value);
    MyUniquePtr(const MyUniquePtr& other) = delete;
    MyUniquePtr(MyUniquePtr&& other) noexcept;

    void operator=(const MyUniquePtr& other) = delete;
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept;

    ~MyUniquePtr();
    T* get() const;

};

template <typename T>
MyUniquePtr<T>::MyUniquePtr()
{
    ptr = nullptr;
}
template <typename T>
MyUniquePtr<T>::MyUniquePtr(const T& value)
{
    ptr = new T(value);
    std::cout << "RAII started" << std::endl;
}

template <typename T>
MyUniquePtr<T>::MyUniquePtr(MyUniquePtr&& other) noexcept
{
    if(this != &other)
    {
        this->ptr = other.ptr;
        other.ptr = nullptr;        
    }
}

template <typename T>
MyUniquePtr<T>& MyUniquePtr<T>::operator=(MyUniquePtr&& other) noexcept
{
    if(this != &other)
    {
        this->ptr = other.ptr;
        other.ptr = nullptr;        
    }

    return *this;
}
template <typename T>
MyUniquePtr<T>::~MyUniquePtr()
{
    delete ptr;
    ptr = nullptr;
    std::cout << "RAII end" << std::endl;
}

template <typename T>
T* MyUniquePtr<T>::get() const
{
    if(ptr == nullptr)
    {
        return nullptr;
    }
    else
    {
        return ptr;
    }
}
