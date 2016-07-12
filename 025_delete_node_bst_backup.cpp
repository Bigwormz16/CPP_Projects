#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <typename T>
Node<T>* getNode(T data)
{
    Node<T> *node = new Node<T>;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Returns nullptr if not found or if tree is empty.
template <typename T>
Node<T>* searchNode(T data, Node<T> *root)
{
    Node<T> *walk = root;
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

// Returns true if deletion was successful, false otherwise.
template <typename T>
bool deleteNode(T data, Node<T> *root)
{
    if (root == nullptr)
    {
        std::cerr << "deleteNode(): The binary search tree is empty!" << std::endl;
        return false;
    }

    Node<T> *found = searchNode(data, root);
    if (!found)
    {
        std::cerr << "deleteNode(): node was not found!" << std::endl;
        return false;
    }

    // If right sub-tree exists.
    if (found->right)
    {
        // find min value in right sub-tree of found.
    }
    // If only left subtree exists.
    else if (found->left)
    {
        // find max value in left sub-tree of found.
    }
    // No sub-tree exists (leaf node)
    else
    {
        ;
    }
    Node<T> *parent = getParentNode(found, root);
    if (!parent)
    {
        return false;
    }

    ;
}

int main()
{
    Node<int> *root2 = getNode(50);
    root2->left = getNode(26);
    root2->left->left = getNode(13);
    root2->left->right = getNode(35);
    root2->left->left->left = getNode(5);
    root2->right = getNode(74);
    root2->right->left = getNode(67);
    root2->right->right = getNode(89);
    /*
                        50
                26              74
            13      35      67      89
        5
    */

    ;

    return 0;
}
