#include <exception>
#include <iostream>
#include <initializer_list>

template <typename T>
class MyBinaryTree
{
private:
    struct Node
    {
        T value;
        Node* left;
        Node* right;
    };

    Node* Root = nullptr;
    template<typename Func>
    void DoForNode(const Node* node, Func function) const; 

    void RemoveSubTree(Node* node);
    Node* Delete(Node* node, const T value);
    Node* FindMinimun(Node* node);
    size_t Size(const Node* node) const;
    void CopyTree(Node*&  tree1, const Node*& tree2);
    const T* FindRecursive(Node* root, const T& value) const;
public:
    MyBinaryTree() = default;
    MyBinaryTree(const MyBinaryTree& other);
    MyBinaryTree(MyBinaryTree&& other);
    MyBinaryTree(std::initializer_list<T> initlist);
    
    ~MyBinaryTree();

    MyBinaryTree& operator=(const MyBinaryTree& other);
    MyBinaryTree& operator=(MyBinaryTree&& other);

    template<typename Func>
    void DoForAllElements(Func function) const;

    bool Insert(const T& value);
    void Clear();
    void Delete();
    const T* Find(const T& value) const;
    bool IsEmpty();
    size_t Size() const;
};
        
template<typename T>
template<typename Func>
void MyBinaryTree<T>::DoForNode(const Node* node, Func function) const 
{
    if(node != nullptr)
    {
        if(node->left != nullptr)
        {
            DoForNode(node->left, function);
        }
        function(node->value);
        if(node->right != nullptr)
        {
            DoForNode(node->right, function);
        }
    }
}
template<typename T>
void MyBinaryTree<T>::RemoveSubTree(Node* node)
{
    if(node == nullptr)
    {
        return;
    }
    RemoveSubTree(node->left);
    RemoveSubTree(node->right);
    delete node;
}
template<typename T>
typename MyBinaryTree<T>::Node* MyBinaryTree<T>::Delete(Node* node, const T value)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    if(value < node->left)
    {
        node->left = Delete(node->left, value);
    }
    else if(value > node->right)
    {
        node->right = Delete(node->right, value);
    }
    else
    {
        if(node->right == nullptr && node->left == nullptr)
        {
            delete node;
            node = nullptr;
        } 
        else if(node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            node = temp;
        }
        else if(node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            node = temp;
        }
        else
        {
            Node* temp = FindMinimun(node);
            node->value = temp->value;
            node->right = Delete(node->right, temp->value);
        }
    }

    return node;
}
template<typename T>
typename MyBinaryTree<T>::Node* MyBinaryTree<T>::FindMinimun(Node* node)
{
    if(node != nullptr)
    {
        if(node->left == nullptr)
        {
            return node;
        }
        return FindMinimun(node->left);
    }
    return nullptr;
}
template<typename T>
size_t MyBinaryTree<T>::Size(const Node* node) const
{
    if(node == nullptr)
    {
        return 0; } 
    return 1 + Size(node->left) + Size(node->right);
}
template<typename T> void MyBinaryTree<T>::CopyTree(Node*&  tree1, const Node*& tree2)
{   if(tree2 == nullptr)
    {
        return;
    }
    tree1 = new Node {tree2->value, nullptr, nullptr};
    CopyTree(tree1->left, tree2->left);
    CopyTree(tree1->right, tree2->right);
}
template<typename T>
MyBinaryTree<T>::MyBinaryTree(const MyBinaryTree& other)
{
    CopyTree(Root, other.Root);
}
template<typename T>
MyBinaryTree<T>::MyBinaryTree(MyBinaryTree&& other)
{
    Root = other.Root;
    other.Root = nullptr;
}
template<typename T>
MyBinaryTree<T>::MyBinaryTree(std::initializer_list<T> initlist)
{
    for(auto iter = initlist.begin(); iter != initlist.end(); ++iter)
    {
       Insert(*iter); 
    }
}
template<typename T>
MyBinaryTree<T>::~MyBinaryTree()
{
    Clear();
}
template<typename T>
typename MyBinaryTree<T>::MyBinaryTree& MyBinaryTree<T>::operator=(const MyBinaryTree& other)
{
    if(this != &other)
    {
        Clear();
        CopyTree(Root, other.Root);
        return *this;
    }
}
template<typename T>
typename MyBinaryTree<T>::MyBinaryTree& MyBinaryTree<T>::operator=(MyBinaryTree&& other)
{
    if(this != other)
    {
        Clear();
        Root = other.Root;
        other.Root = nullptr;
    }
    return *this;
}
template<typename T>
template<typename Func>
void MyBinaryTree<T>::DoForAllElements(Func function) const
{
    DoForNode(Root, function);
}
template<typename T>
bool MyBinaryTree<T>::Insert(const T& value)
{
    if(Root == nullptr)
    {
        Root = new Node{value, nullptr, nullptr};
        return true;
    }
    Node* current = Root;
    while(current != nullptr)
    {
        if(value == current->value)
        {
            std::cout << "Value already in tree." << std::endl;
            return false;
        }
        else if(value < current->value)
        {
            if(current->left == nullptr)
            {
                current->left = new Node{value, nullptr, nullptr};
                return true;
            }
            current = current->left;
        }
        else 
        {
            if(current->right == nullptr)
            {
                current->right = new Node{value, nullptr, nullptr};
                return true;
            }
            current = current->right;
        }
    }
    return false;
}

template<typename T>
void MyBinaryTree<T>::Clear()
{
    if(Root != nullptr)
    {
        RemoveSubTree(Root); 
        Root = nullptr;
    }
}
template<typename T>
void MyBinaryTree<T>::Delete()
{
    Root = Delete(Root);
}
template<typename T>
const T* MyBinaryTree<T>::Find(const T& value) const
{  
   /* Node* current = Root; 
    while(current != nullptr)
    {
        if(value < current->value)
        {
            current = current->left;
        }
        else if(value > current->value)
        {
            current = current->right;
        }
        else
        {
            return &current->value;
        }
        return nullptr; 
    }
    */
     return FindRecursive(Root, value);
}


template<typename T>
const T* MyBinaryTree<T>::FindRecursive(Node* root, const T& value) const
{
    if(value == root->value)
    {
        return &root->value;
    }
    else if (value < root->value)
    {
        return FindRecursive(root->left, value);
    }
    else if(value > root->value)
    {
        return FindRecursive(root->right, value);
    }
    return nullptr;
}
template<typename T>
bool MyBinaryTree<T>::IsEmpty()
{
    return Root == nullptr;
}
template<typename T>
size_t MyBinaryTree<T>::Size() const
{
    return Size(Root);
}
