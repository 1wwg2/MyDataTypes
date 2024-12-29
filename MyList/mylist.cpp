#include "mylist.h"

MyList::MyList() : Head(nullptr) {}
//MyList::MyList(const MyList& other){}
//MyList::MyList(MyList&& other) noexcept{}

MyList::~MyList(){}

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

void MyList::Remove(const int& value){}


void MyList::Clear() {
    if(Head == nullptr) {
        std::cout << "List empty" << std::endl;
    } else {
        Node* current = Head;
        while(current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        current = nullptr;
        Head = nullptr;
    }    
}

/*bool MyList::Find(const int& value) const {
    if(Head == nullptr) {
        std::cout << "List is empty" << std::endl;
    } else {
        Node* current = Head;
        while(current != nullptr) {
            
    }

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

//MyList& MyList::operator=(const MyList& other){}
//MyList& MyList::operator=(MyList&& other) noexcept{}

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
    }
}
