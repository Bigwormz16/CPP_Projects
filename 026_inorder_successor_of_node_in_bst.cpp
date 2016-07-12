#include <iostream>
#include <stdexcept>


template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

// Returns nullptr if there is no successor.
template <typename T>
Node<T>* inorderSuccessor(Node<T> *root, Node<T> *node)
{
    if (root == nullptr) {
        throw std::logic_error("deleteNode(): BST is empty!");
    }
    if (node == nullptr) {
        throw std::logic_error("deleteNode(): node is nullptr!");
    }

    Node<T> *successor = nullptr;
    if (node->right) {
        successor = node->right;
        while (successor->left) {
            successor = successor->left;
        }
    }
    else {
        if (node == root) {
            successor = nullptr;
        }
        else {
            Node<T> *walk = root;
            while (walk && walk != node) {
                if (node->data < walk->data) {
                    successor = walk;
                    walk = walk->left;
                }
                else {
                    walk = walk->right;
                }
            }
        }
    }

    return successor;
}

//==============================================================================
// TESTING CODE:
template <typename T>
Node<T>* getNode(T data)
{
    Node<T> *node = new Node<T>;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node<int>* getIntBST()
{
    /*
                           50
                26                     74
         13          35           67        89
    5       14          40                     95
    */
    Node<int> *root = getNode(50);
    root->left = getNode(26);
    root->left->left = getNode(13);
    root->left->left->left = getNode(5);
    root->left->left->right = getNode(14);
    root->left->right = getNode(35);
    root->left->right->right = getNode(40);
    root->right = getNode(74);
    root->right->left = getNode(67);
    root->right->right = getNode(89);
    root->right->right->right = getNode(95);

    return root;
}
//==============================================================================

int main()
{
    Node<int> *root = getIntBST();
    Node<int> *node = root->right->right->right;
    Node<int> *successor = inorderSuccessor(root, node);
    if (successor) {
        std::cout << successor->data << std::endl;
    }
    else {
        std::cout << "No successor." << std::endl;
    }
    return 0;
}
