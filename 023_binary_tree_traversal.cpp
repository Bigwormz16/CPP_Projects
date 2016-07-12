#include <iostream>
#include <deque>

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

// Breadth-first or level order traversal
template <typename T>
void traverseBreadthFirst(Node<T> *root)
{
    using namespace std;
    deque< Node<T>* > roots;
    roots.push_back(root);
    cout << "Breadth-first/level-order traversal:\n";
    while (roots.size())
    {
        if (roots.front())  // if node is not null
        {
            cout << roots.front()->data << " ";
            roots.push_back(roots.front()->left);
            roots.push_back(roots.front()->right);
        }
        roots.pop_front();
    }
    cout << endl;
}

// Depth-first traversals(pre-, in- and post- order):

template <typename T>
void traversePreorder(Node<T> *root)
{
    if (root == nullptr)
        return;

    std::cout << root->data << " ";
    traversePreorder(root->left);
    traversePreorder(root->right);
}

template <typename T>
void traverseInorder(Node<T> *root)
{
    if (root == nullptr)
        return;

    traverseInorder(root->left);
    std::cout << root->data << " ";
    traverseInorder(root->right);
}

template <typename T>
void traversePostorder(Node<T> *root)
{
    if (root == nullptr)
        return;

    traversePostorder(root->left);
    traversePostorder(root->right);
    std::cout << root->data << " ";
}

int main()
{
    using namespace std;

    Node<int> *root = getNode(50);
    root->left = getNode(13);
    root->left->left = getNode(26);
    root->left->right = getNode(89);
    root->right = getNode(67);
    root->right->left = getNode(35);
    root->right->right = getNode(74);
    root->right->left->left = getNode(5);
    /*
                        50
            13                  67
        26      89          35      74
                        5
    */

    traverseBreadthFirst(root);
    cout << "\n";

    cout << "Depth-first (pre-order) traversal:\n";
    traversePreorder(root);
    cout << "\n\n";

    cout << "Depth-first (in-order) traversal:\n";
    traverseInorder(root);
    cout << "\n\n";

    cout << "Depth-first (post-order) traversal:\n";
    traversePostorder(root);
    cout << endl;

    return 0;
}
