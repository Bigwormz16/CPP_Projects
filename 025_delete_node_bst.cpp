#include <iostream>
#include <string>
#include <stdexcept>
#include <deque>
#include <vector>
#include <ctime>


template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

// Warning: Doesn't check if root or node is nullptr.
template <typename T>
Node<T>* getParentNode(Node<T> *root, Node<T> *node)
{
    // Termination condition.
    if (root == nullptr) {
        return root;
    }

    if ((root->left && root->left == node) || (root->right && root->right == node))
    {
        return root;
    }
    else
    {
        // Check if left/right subtree has parent of node.
        Node<T> *parent = getParentNode(root->left, node);
        return ( parent ? parent : getParentNode(root->right, node));
    }
}

// Deletes node and returns its child.
template <typename T>
Node<T>* deleteNodeWithZeroOrOneChild(Node<T> *node)
{
    Node<T>* child = nullptr;
    if (node->left) {
        child = node->left;
    }
    else {
        child = node->right;
    }
    delete node;
    return child;
}

// Deletes node and returns new(if node was root) root.
template <typename T>
Node<T>* deleteNodeInBST(Node<T> *root, Node<T> *node)
{
    if (root == nullptr) {
        throw std::logic_error("deleteNode(): BST is empty!");
    }
    if (node == nullptr) {
        throw std::logic_error("deleteNode(): node is nullptr!");
    }

    /* If `node` has both children we swap it with min value in right subtree
    and delete the node with which we swapped it which has only one child.
    If `node` has zero or only one child, we delete it.
    We then set child of deleted node to be the child of it's parent. */

    if (node->left && node->right) {
        Node<T> *parent = node;
        Node<T> *swapNode = node->right;
        while (swapNode->left) {
            parent = swapNode;
            swapNode = swapNode->left;
        }
        node->data = swapNode->data;
        Node<T> *child = deleteNodeWithZeroOrOneChild(swapNode);
        if (parent == node) {
            parent->right = child;
        }
        else {
            parent->left = child;
        }
    }
    else if (node->left || node->right) {
        if (node == root) {
            if (node->left) {
                root = root->left;
            }
            else {
                root = root->right;
            }
            deleteNodeWithZeroOrOneChild(node);
        }
        else {
            Node<T> *parent = getParentNode(root, node);
            Node<T> *child = deleteNodeWithZeroOrOneChild(node);
            if (child->data <= parent->data) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
    }
    else {
        if (node == root) {
            delete node;
            root = nullptr;
        }
        else {
            Node<T> *parent = getParentNode(root, node);
            if (parent->left == node) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
            deleteNodeWithZeroOrOneChild(node);
        }
    }

    return root;
}


//==============================================================================
// TESTING CODE:
//--------------

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
                26              74
            13      35      67      89
        5                               95
    */
    Node<int> *root = getNode(50);
    root->left = getNode(26);
    root->left->left = getNode(13);
    root->left->right = getNode(35);
    root->left->left->left = getNode(5);
    root->right = getNode(74);
    root->right->left = getNode(67);
    root->right->right = getNode(89);
    root->right->right->right = getNode(95);

    return root;
}

// Sets elements of `seq` to level order traversal of binary tree.
template <typename T>
void levelOrderTraversal(Node<T> *root, std::vector<T> &seq)
{
    using namespace std;
    deque< Node<T>* > roots;
    roots.push_back(root);
    while (roots.size())
    {
        if (roots.front())  // if node is not null
        {
            seq.push_back(roots.front()->data);
            roots.push_back(roots.front()->left);
            roots.push_back(roots.front()->right);
        }
        roots.pop_front();
    }
}

void testCode()
{
    using namespace std;
    // This is the BST we are testing on:
    /*
                        50
                26              74
            13      35      67      89
        5                               95
    */
    Node<int> *root = getIntBST();

    cout << "Test case 1: ";    // root=50, node=26
    root = deleteNodeInBST(root, root->left);
    vector<int> intended = {50, 35, 74, 13, 67, 89, 5, 95};
    vector<int> result;
    levelOrderTraversal(root, result);
    if (result == intended) {
        cout << "pass\n";
    }
    else {
        cout << "fail !!!\n";
    }

    cout << "Test case 2: ";    // root=50, node=50
    root = getIntBST();
    root = deleteNodeInBST(root, root);
    intended = {67, 26, 74, 13, 35, 89, 5, 95};
    result.clear();
    levelOrderTraversal(root, result);
    if (result == intended) {
        cout << "pass\n";
    }
    else {
        cout << "fail !!!\n";
    }

    cout << "Test case 3: ";    // root=89, node=89
    root = getIntBST();
    root = deleteNodeInBST(root->right->right, root->right->right);
    intended = {95};
    result.clear();
    levelOrderTraversal(root, result);
    if (result == intended) {
        cout << "pass\n";
    }
    else {
        cout << "fail !!!\n";
    }

    cout << "Test case 4: ";    // root=50, node=89
    root = getIntBST();
    root = deleteNodeInBST(root, root->right->right);
    intended = {50, 26, 74, 13, 35, 67, 95, 5};
    result.clear();
    levelOrderTraversal(root, result);
    if (result == intended) {
        cout << "pass\n";
    }
    else {
        cout << "fail !!!\n";
    }

    cout << "Test case 5: ";    // root=13, node=13
    root = getIntBST();
    root = deleteNodeInBST(root->left->left, root->left->left);
    intended = {5};
    result.clear();
    levelOrderTraversal(root, result);
    if (result == intended) {
        cout << "pass\n";
    }
    else {
        cout << "fail !!!\n";
    }

    cout << "Test case 6: ";    // root=50, node=13
    root = getIntBST();
    root = deleteNodeInBST(root, root->left->left);
    intended = {50, 26, 74, 5, 35, 67, 89, 95};
    result.clear();
    levelOrderTraversal(root, result);
    if (result == intended) {
        cout << "pass\n";
    }
    else {
        cout << "fail !!!\n";
    }

    cout << "Test case 7: ";    // root=50, node=35
    root = getIntBST();
    root = deleteNodeInBST(root, root->left->right);
    intended = {50, 26, 74, 13, 67, 89, 5, 95};
    result.clear();
    levelOrderTraversal(root, result);
    if (result == intended) {
        cout << "pass\n";
    }
    else {
        cout << "fail !!!\n";
    }

    cout << "Test case 8: ";    // root=50, node=67
    root = getIntBST();
    root = deleteNodeInBST(root, root->right->left);
    intended = {50, 26, 74, 13, 35, 89, 5, 95};
    result.clear();
    levelOrderTraversal(root, result);
    if (result == intended) {
        cout << "pass\n";
    }
    else {
        cout << "fail !!!\n";
    }

    cout << "Test case 9: ";    // root=95, node=95
    root = getIntBST();
    root = deleteNodeInBST(root->right->right->right, root->right->right->right);
    intended = {};
    result.clear();
    levelOrderTraversal(root, result);
    if (result == intended) {
        cout << "pass\n";
    }
    else {
        cout << "fail !!!\n";
    }
}

//==============================================================================


int main()
{
    using namespace std;

    clock_t begin = clock();
    testCode();
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "\n(Took " << elapsed_secs * 1000000 << " micro-seconds)" << endl;

    return 0;
}
