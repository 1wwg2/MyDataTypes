#include <iostream>

template<typename T>
class MySharedPtr
{
private:
    int* RefCount = nullptr;
    T* ptr = nullptr;
   void release()
   {
        if(RefCount != nullptr)
        {
            --(*RefCount);
            if((*RefCount) == 0)
            {
                delete RefCount;
                RefCount = nullptr;
                delete ptr;
                ptr = nullptr;
            }
        }
   }

public:
    MySharedPtr() : ptr(nullptr), RefCount(nullptr) {};
    
    MySharedPtr(T* ptr) : ptr(ptr)
    {
        RefCount = new int (1);
    }

    MySharedPtr(const MySharedPtr& other)
    {
        ptr = other.ptr;
        RefCount = other.RefCount;
        if(RefCount)
        {
            ++(*RefCount);
        }
        else if(ptr)
        {
            RefCount = new int(1);
        }
    }
    
    MySharedPtr(MySharedPtr&& other) noexcept
    {
        ptr = other.ptr;
        other.ptr = nullptr;
        RefCount = other.RefCount;
        other.RefCount = nullptr;
    }
    
    ~MySharedPtr()
    {
        release();
    }

    MySharedPtr& operator=(const MySharedPtr& other)
    {
        if(this != &other)
        {
            release();
            ptr = other.ptr;
            RefCount = other.RefCount;
            if(RefCount)
            {
                ++(*RefCount);
            }
            else if(ptr)
            {
                RefCount = new int(1);
            }
        }
            
        return *this;
    }

    MySharedPtr& operator=(MySharedPtr&& other) noexcept
    {
        if(this != &other)
        {
            release();
            ptr = other.ptr;
            other.ptr = nullptr;
            RefCount = other.RefCount;
            other.RefCount = nullptr;
        }
        
        return *this;
    }

    T* get()
    {
        return ptr;
    }
    
    int use_count()
    {
       return  *RefCount == 0 ? 0 : *RefCount;
    }
};

