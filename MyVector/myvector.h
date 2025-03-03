#ifndef MY_VECTOR
#define MY_VECTOR

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
    MyVector(const T& value,  const int _size);
    MyVector(const MyVector& other);
    MyVector(MyVector&& other);

    MyVector& operator=(const MyVector& other);
    MyVector& operator=(MyVector&& other);

    void PushBack(const T& value);
    void PushFront(const T& value);
    void Swap();
    void Erase();
    void Insert();

    size_t Size();
    T& At(size_t index);

    const T& operator[](size_t index) const;
    T& operator[](size_t index);

};

template<typename T>
MyVector<T>::MyVector()
{
    dynamic_vec_array = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
MyVector<T>::MyVector(const T& value, const int _size)
{
    size = 0;
    capacity = _size * 2;
    dynamic_vec_array = new T[capacity]; 
    for(int i = 0; i < _size; ++i)
    {
        dynamic_vec_array[i] = value;
    }
    size = _size;
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other)
{
    dynamic_vec_array = new T[other.capacity];
    size = other.size;
    capacity = other.capacity;

    for(int i = 0; i < size; ++i)
    {
        dynamic_vec_array[i] = other.dynamic_vec_array[i];
    }
}
    
template<typename T>
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
void MyVector<T>::PushBack(const T& value)
{
    if(size == 0)
    {
        if(dynamic_vec_array)
            delete [] dynamic_vec_array;
       
        ++size;
        capacity = size * 2;
        dynamic_vec_array = new T[capacity];
        dynamic_vec_array[0] = value;
    }
    else if(size  < capacity) 
    {
        dynamic_vec_array[size] = value;
        ++size; 
    }
    else 
    {
        capacity = capacity * 2;
        T* new_arr = new T[capacity];
        for(int i = 0; i < size; ++i)
        {
           new_arr[i] = dynamic_vec_array[i]; 
        }
        delete [] dynamic_vec_array;
        dynamic_vec_array = new_arr;
        dynamic_vec_array[size] = value;
        ++size;
    }
}
template<typename T>
void MyVector<T>::PushFront(const T& value)
{
    if(size == 0)
    {
        if(dynamic_vec_array)
            delete [] dynamic_vec_array;
        
        size = 1;
        capacity = 2;
        dynamic_vec_array = new T[capacity];
        dynamic_vec_array[0] = value;
    } 
    else if (size < capacity)
    {
        std::cout << "www" << std::endl;
        for(int i = 0; i < size; ++i)
        {
            dynamic_vec_array[i + 1] = dynamic_vec_array[i];
        }

        dynamic_vec_array[0] = value;
        ++size;
    }
    else 
    {
        capacity = capacity * 2;
        T* new_arr = new T[capacity];

        for(int i = 0; i < size; ++i)
        {
            new_arr[i] = dynamic_vec_array[i];
        }
        for(int i = 0; i < size; ++i)
        {
            new_arr[i + 1] = new_arr[i];
        };
        new_arr[0] = value;
        ++size;
        delete [] dynamic_vec_array;
        dynamic_vec_array = new_arr;
    }
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
template<typename T>
size_t MyVector<T>::Size()
{
    return size;
}

template<typename T>
T& MyVector<T>::At(size_t index)
{
    return dynamic_vec_array[index];
}

template<typename T>
const T& MyVector<T>::operator[](size_t index) const
{
    return dynamic_vec_array[index];
}

template<typename T>
T& MyVector<T>::operator[](size_t index)
{
    return dynamic_vec_array[index];
}

#endif // MY_VECTOR
