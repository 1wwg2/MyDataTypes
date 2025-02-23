#include "mylist.h"
#include <exception>

MyList::MyList() : Head(nullptr) {}

MyList::MyList(const MyList& other) { 
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
MyList::MyList(MyList&& other) noexcept { 
    Head = other.Head;
    other.Head = nullptr;
}

MyList::~MyList() { 
    Clear(); 
}

void MyList::PushBack(const int& value) {
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
void MyList::PushFront(const int& value)
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



void MyList::InsertNode1(int value, int position)
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


void MyList::InsertNode(int value, int position) {
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

MyList::Node* MyList::GetHead() const {
   return Head;
} 
void MyList::PopBack() {
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
void MyList::PopFront() {
    if(Head == nullptr) {
        std::cout << "List empty" << std::endl;
    } else {
        Node* temp = Head;
        Head = Head->next;
        delete temp;
        temp = nullptr;        
    }
} 

void MyList::Reverse() {
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

void MyList::Remove(const int& value) { 
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

void MyList::Clear() {
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

bool MyList::Find(const int& value) const {
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

bool MyList::IsEmpty() const {
    return Head == nullptr;
}

size_t MyList::Size() const {
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

MyList& MyList::operator=(const MyList& other) {
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

MyList& MyList::operator=(MyList&& other) noexcept {
    if(this != &other) {
        Clear();
        Head = other.Head;
        other.Head = nullptr;
    }
   return *this; 
}

int& MyList::operator[](int index) { 
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

const int& MyList::operator[](int index) const {
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

void MyList::Show() const {
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
