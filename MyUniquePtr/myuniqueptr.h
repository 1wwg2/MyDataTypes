#include <iostream>
template <typename T>
class MyUniquePtr
{
private:
    T* ptr;
public:
    MyUniquePtr();
    MyUniquePtr(const T& value);
    MyUniquePtr(const MyUniquePtr& other);
    MyUniquePtr(MyUniquePtr&& other);

    void operator=(const MyUniquePtr& other);
    void operator=(MyUniquePtr&& other);

    ~MyUniquePtr();

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
MyUniquePtr<T>::MyUniquePtr(const MyUniquePtr& other)
{

}
template <typename T>
MyUniquePtr<T>::MyUniquePtr(MyUniquePtr&& other)
{
}
template <typename T>
void MyUniquePtr<T>::operator=(const MyUniquePtr& other)
{
}
template <typename T>
void MyUniquePtr<T>::operator=(MyUniquePtr&& other)
{
}
template <typename T>
MyUniquePtr<T>::~MyUniquePtr()
{
    delete ptr;
    ptr = nullptr;
    std::cout << "RAII end" << std::endl;
}

