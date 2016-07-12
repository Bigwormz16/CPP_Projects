#include <iostream>
#include <limits>   // for std::numeric_limits
#include <functional>
#include <vector>

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

/* THIS FUNCTION WILL FAIL (WRONG ALGORITHM)
template <typename T>
bool isBst(Node<T> *root)
{
    if (root)   // if root is not null
    {
        if (root->left && root->left->data > root->data)
            return false;
        else if (root->right && root->right->data <= root->data)
            return false;
        else
        {
            return isBst(root->left) && isBst(root->right);
        }
    }
    return true;
}
*/

/* Using the concept of range checking for each element.
O(n) time complexity.
Call with the minimum and maximum allowed values for root of type T. */
template <typename T>
bool isBst_1(Node<T> *root, T minVal, T maxVal)
{
    if (root == nullptr)
        return true;

    if (root->data > minVal && root->data <= maxVal &&
        isBst_1(root->left, minVal, root->data) &&
        isBst_1(root->right, root->data, maxVal))
        return true;
    else
        return false;
}

/* Utility function for isBst_2.
Traverses a BST in-order and saves the data of each node in a vector passed
as argument. */
template <typename T>
void isBst_2_util(Node<T> *root, std::vector<T> &seq)
{
    if (root == nullptr) {
        return;
    }
    isBst_2_util(root->left, seq);
    seq.push_back(root->data);
    isBst_2_util(root->right, seq);
}

/* Using the property of BST that in-order traversal of a BST produces
a sorted list. */
template <typename T>
bool isBst_2(Node<T> *root)
{
    std::vector<T> seq;
    isBst_2_util(root, seq);
    for (unsigned int i = 0; i < seq.size() - 1; ++i) {
        if (seq[i] > seq[i+1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    using namespace std;

    /* binary tree 1: Not a BST.
                        50
                26              67
            13      74      35      89
        5
    */
    Node<int> *root1 = getNode(50);
    root1->left = getNode(26);
    root1->left->left = getNode(13);
    root1->left->right = getNode(74);
    root1->left->left->left = getNode(5);
    root1->right = getNode(67);
    root1->right->left = getNode(35);
    root1->right->right = getNode(89);

    /* binary tree 2: Is a BST.
                        50
                26              74
            13      35      67      89
        5
    */
    Node<int> *root2 = getNode(50);
    root2->left = getNode(26);
    root2->left->left = getNode(13);
    root2->left->right = getNode(35);
    root2->left->left->left = getNode(5);
    root2->right = getNode(74);
    root2->right->left = getNode(67);
    root2->right->right = getNode(89);

    int intMin = numeric_limits<int>::min();
    int intMax = numeric_limits<int>::max();

    cout << boolalpha;
    cout << "isBst_1(): (binary tree 1): " << isBst_1(root1, intMin, intMax) << "\n";
    cout << "isBst_1(): (binary tree 2): " << isBst_1(root2, intMin, intMax) << "\n";
    cout << "\n";
    cout << "isBst_2(): (binary tree 1): " << isBst_2(root1) << "\n";
    cout << "isBst_2(): (binary tree 2): " << isBst_2(root2) << endl;

    return 0;
}
