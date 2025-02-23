#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <exception>

template<typename T>
class MyList
{
private:
    struct Node
    {
        T value;
        Node* next;
    };
    Node* Head;
    MyList& Copy(const MyList& other);
public:
    MyList();
    MyList(const MyList& other);
    MyList(MyList&& other) noexcept;

    ~MyList();
    
    void PushBack(const T& value);
    void PushFront(const T& value);
    Node* GetHead() const; 
    void PopBack();
    void PopFront();
    void Reverse();
    void InsertNode(const T& value, int position);
    void InsertNode1(const T& value, int position);
    void Remove(const T& value);
    void Clear();
    
    bool Find(const T& value) const;
//    void MergeList(MyList& otherListHead); 
    bool IsEmpty() const;
    size_t Size() const;

    MyList& operator=(const MyList& other);
    MyList& operator=(MyList&& other) noexcept;

    int& operator[](int index);
    const int& operator[](int index) const;

    void Show() const;
};

template<typename T>
MyList<T>::MyList() : Head(nullptr) {}
template<typename T>
MyList<T>::MyList(const MyList& other) { 
    if(other.Head == nullptr) {
        std::cout << "List is empty" << std::endl;
        Head = nullptr;
        return;
    } else {
          Head = new Node {other.Head->value, nullptr};
          Node* currentOther = other.Head->next;
          Node* current = Head;
          
        while(currentOther != nullptr) {
            current->next = new Node {currentOther->value, nullptr};
            current = current->next;
            currentOther = currentOther->next;
        }
    }
}
template<typename T>
MyList<T>::MyList(MyList&& other) noexcept { 
    Head = other.Head;
    other.Head = nullptr;
}

template<typename T>
MyList<T>::~MyList() { 
    Clear(); 
}

template<typename T>
void MyList<T>::PushBack(const T& value) {
    if(Head == nullptr) {
        Head = new Node {value, nullptr};
    } else {
        Node* current = Head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node {value, nullptr};
    } 
}
template<typename T>
void MyList<T>::PushFront(const T& value)
{
    if(Head == nullptr) {
        Head = new Node { value, nullptr };
    }
    else {
        Node* temp = Head;
        Head = new Node {value , nullptr };
        Head->next = temp; 
    } 
}

template<typename T>
void MyList<T>::InsertNode1(const T& value, int position)
{
    Node* current = Head;
    int current_pos = 0;

    if(Head == nullptr)
    {
        std::cout << "List is empty, push to first position";
        Head = new Node {value, nullptr}; 
        return;
    }
    else if(position > Size())
    {
        std::cout << "Position > Size(). Error" << std::endl;
        return;
    }
    else if(position == 0)
    {
        Node* temp = Head;
        Head = new Node {value, nullptr};
        Head->next = temp;
    }
    else if(position == Size())
    {
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node{value, nullptr};
    }
    else 
    {
        while (current != nullptr)
        {
            if(current_pos + 1 == position)
            {
                Node* temp = current->next;
                current->next = new Node {value, nullptr};
                current->next->next = temp;
                return;
            }
            current = current->next;
            current_pos++;
        }
            std::cout << "Position not found" << std::endl;
    }
} 

template<typename T>
void MyList<T>::InsertNode(const T& value, int position) {
    if(Head == nullptr) {
        Head = new Node {value, nullptr};
    } else if(position == 0) {
        PushFront(value);
    } else if(Size() < position) {
        std::cout << "Position is bigger than size list" << std::endl;
    } else {
        Node* current = Head;
        for(int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = new Node {value, nullptr};
        current->next->next = temp;    
    }
}


template<typename T>
typename MyList<T>::Node* MyList<T>::GetHead() const {
   return Head;
} 
template<typename T>
void MyList<T>::PopBack() {
    if(Head == nullptr) { 
        std::cout << "List empty" << std::endl;
    }
    else {
        Node* current = Head;
        while (current->next->next != nullptr) {
            current = current->next; 
        }
        delete current->next->next;
        current->next->next = nullptr;
        current->next = nullptr;
    }
}

template<typename T>
void MyList<T>::PopFront() {
    if(Head == nullptr) {
        std::cout << "List empty" << std::endl;
    } else {
        Node* temp = Head;
        Head = Head->next;
        delete temp;
        temp = nullptr;        
    }
} 

template<typename T>
void MyList<T>::Reverse() {
   if(Head == nullptr) {
       std::cout << "Nothing to reverse" << std::endl;
       return;
   } else {
        Node* prev = nullptr;
        Node* current = Head;
        Node* next = nullptr; 
       while(current != nullptr) {
           next = current->next;
           current->next = prev;
           prev = current;
           current = next;
       }
       Head = prev;
   } 
}

template<typename T>
void MyList<T>::Remove(const T& value) { 
    if(Head == nullptr) { 
        std::cout << "List empty" << std::endl;
        return;
    } else {
        if(Head->value == value) {
            PopFront();
            return; 
        }
        Node* prev = nullptr;
        Node* current = Head;
        while(current != nullptr) {
            if(current->value == value) {
                Node* temp = current;
                prev->next = current->next;
                delete temp;
                return; 
            }
            prev = current;
            current = current->next;
        }
        std::cout << "Value not found" << std::endl;
    }
}

template<typename T>
void MyList<T>::Clear() {
    if(Head == nullptr) {
    } else {
        Node* current = Head;
        while(current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        
        Head = nullptr;
    }    
}

template<typename T>
bool MyList<T>::Find(const T& value) const {
  if(Head == nullptr) {
  std::cout << "List is empty" << std::endl;
  } else {
  Node* current = Head;
    while(current != nullptr) {
        if(current->value == value) { 
           return true;
        } 
        current = current->next;
    }
        return false;
    }
}

/*void MyList::MergeList(MyList& otherListHead) {
    Node* current = Head;
    Node* othercurrent = otherListHead.GetHead();
    
    Node* MergeListHead = nullptr;
    Node* CurrentMergeListHead = MergeListHead;
    while(current != nullptr && othercurrent != nullptr)
    {
        if(current->value < othercurrent->value)
        {
            CurrentMergeListHead = new Node{current->value, nullptr};
            CurrentMergeListHead = CurrentMergeListHead->next; 
        }
        current = current->next;
        othercurrent = othercurrent->next;
    }

    Head = MergeListHead;
           
}*/ 

template<typename T>
bool MyList<T>::IsEmpty() const {
    return Head == nullptr;
}

template<typename T>
size_t MyList<T>::Size() const {
    int size = 0;
    if(!IsEmpty()) {
        Node* current = Head;
        while(current != nullptr) {
            ++size;
            current = current->next;
        }
    }
    return size;
}

template<typename T>
MyList<T>& MyList<T>::operator=(const MyList<T>& other) {
    if(&other != this) {
        Clear(); 
    
    if(other.Head == nullptr) {
        std::cout << "List is empty" << std::endl;
        Head = nullptr;
    } else {
          Head = new Node {other.Head->value, nullptr};
          Node* currentOther = other.Head->next;
          Node* current = Head;
          
        while(currentOther != nullptr) {
            current->next = new Node {currentOther->value, nullptr};
            current = current->next;
            currentOther = currentOther->next;
            }
        }    
    }
    return *this;
}

template<typename T>
MyList<T>& MyList<T>::operator=(MyList<T>&& other) noexcept {
    if(this != &other) {
        Clear();
        Head = other.Head;
        other.Head = nullptr;
    }
   return *this; 
}

template<typename T>
int& MyList<T>::operator[](int index) { 
    if(IsEmpty()) {
        throw std::out_of_range("List is empty");
    }
    if(Size() < index && index < 0) {
        throw std::out_of_range("Incorrect index");
    }
    else {
        Node* current = Head;
        int i = 0;
        while(i != index) {
            current = current->next;
            ++i;
        }
        return current->value;
    }
}

template<typename T>
const int& MyList<T>::operator[](int index) const {
    if(IsEmpty()) {
        throw std::out_of_range("List is empty");
    }
    if(Size() < index && index < 0) {
        throw std::out_of_range("Incorrect index");
    }
    else {
        Node* current = Head;
        int i = 0;
        while(i != index) {
            current = current->next;
            ++i;
        }
        return current->value;
    }
}

template<typename T>
void MyList<T>::Show() const {
    if(Head == nullptr) {
        std::cout << "List is empty" << std::endl;
    }
    else {
        Node* current = Head;
        while(current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}





#endif // MYLIST_H
