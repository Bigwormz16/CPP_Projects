#include <iostream>
#include <stdexcept>

template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <typename T>
class Bst
{
private:
    Node<T> *m_root;

public:
    Bst() : m_root{nullptr}
    {   }

    void insert(T data)
    {
        Node<T> *newNode = new (std::nothrow) Node<T>;
        if (newNode == nullptr)
        {
            std::cerr << "insert(): Error: Cannot allocate memory for new node!" << std::endl;
            return;
        }
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (m_root == nullptr)
        {
            m_root = newNode;
            return;
        }

        Node<T> *walk = m_root;
        while (true)
        {
            if (data <= walk->data)
            {   // enter the left subtree
                if (walk->left) // if left subtree exists
                {
                    walk = walk->left;
                }
                else
                {
                    walk->left = newNode;
                    break;
                }
            }
            else
            {   // enter the right subtree
                if (walk->right)    // if right subtree exists
                {
                    walk = walk->right;
                }
                else
                {
                    walk->right = newNode;
                    break;
                }
            }
        }
    }

    // Returns nullptr if not found or if tree is empty
    Node<T>* search(T data)
    {
        Node<T> *walk = m_root;
        while (true)
        {
            if (walk)
            {
                if (data == walk->data)
                {
                    break;
                }
                else if (data < walk->data)
                {
                    walk = walk->left;
                }
                else
                {
                    walk = walk->right;
                }
            }
            else    // if walk is nullptr
            {
                break;
            }
        }
        return walk;
    }

    T minValue()
    {
        Node<T> *walk = m_root;
        if (walk == nullptr)
        {
            throw std::logic_error("Illegal: minValue() when BST is empty!");
        }

        // The left most node has the minimum value.
        while (true)
        {
            if (walk->left)
            {
                walk = walk->left;
            }
            else
            {
                break;
            }
        }
        return walk->data;
    }

    T maxValue()
    {
        Node<T> *walk = m_root;
        if (walk == nullptr)
        {
            throw std::logic_error("Illegal: minValue() when BST is empty!");
        }

        // The right most node has the max vale.
        while (true)
        {
            if (walk->right)
            {
                walk = walk->right;
            }
            else
            {
                break;
            }
        }
        return walk->data;
    }
};


int main()
{
    using namespace std;
    Bst<int> IntBst;
    IntBst.insert(100);
    IntBst.insert(-1);
    IntBst.insert(100);
    IntBst.insert(200);
    IntBst.insert(50);

    Node<int> *someNode = IntBst.search(50);
    if (someNode)
    {
        cout << "Found: " << someNode->data << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    int min = IntBst.minValue();
    int max = IntBst.maxValue();
    cout << "Min: " << min << ", Max: " << max << endl;
    return 0;
}
