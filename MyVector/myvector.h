#include <iostream>

template<typename T>
class MyVector
{
private:
    T* dynamic_vec_array;
    size_t size;
    size_t capacity;
public:
    MyVector();
    MyVector(const MyVector& other);
    MyVector(MyVector&& other);

    MyVector& operator=(const MyVector& other);
    MyVector& operator=(MyVector&& other);

    void PushBack();
    void PushFront();
    void Swap();
    void Erase();
    void Insert();
};

template<typename T>
MyVector<T>::MyVector()
{
}
template<typename T>
MyVector<T>::MyVector(const MyVector& other)
{
}template<typename T>
MyVector<T>::MyVector(MyVector&& other)
{
}
template<typename T>
typename MyVector<T>::MyVector&  MyVector<T>::operator=(const MyVector<T>& other)
{

    return *this;
}
template<typename T>
typename MyVector<T>::MyVector& MyVector<T>::operator=(MyVector<T>&& other)
{
}
template<typename T>
void MyVector<T>::PushBack()
{
}
template<typename T>
void MyVector<T>::PushFront()
{
}

template<typename T>
void MyVector<T>::Swap()
{
}
template<typename T>
void MyVector<T>::Erase()
{
}
template<typename T>
void MyVector<T>::Insert()
{
}
