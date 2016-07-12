#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

// Find height of a binary tree.
template <typename T>
int findHeight(Node<T> *root)
{
    if (root == nullptr)    // base case (termination condition)
    {
        return -1;
        // If only the root node is present, returning 0 would result in height=1
    }

    return std::max(findHeight(root->left), findHeight(root->right)) + 1;
}

// A FunctionObject that returns true if the argument is not a nullptr.
// See [http://en.cppreference.com/w/cpp/algorithm/all_any_none_of] and
// [http://en.cppreference.com/w/cpp/concept/Predicate]
template <typename T>
struct IsNotNull
{
    // Implicit conversion of Node<T>* to type bool.
    // nullptr evaluates to false value
    bool operator()(Node<T>* node) { return node; }
};

// Find height iteratively instead of recursively.
template <typename T>
int findHeightIter(Node<T> *root)
{
    using namespace std;
    vector< Node<T>* > roots;
    roots.push_back(root);
    int height = -1;
    while (any_of(roots.cbegin(), roots.cend(), IsNotNull<T>()))
    {
        ++height;
        int numRoots = roots.size();
        vector< Node<T>* > subRoots;
        for (int i = 0; i < numRoots; ++i)
        {
            // If root is not null (dereferencing nullptr leads to segfault).
            if (roots[i])
            {
                subRoots.push_back(roots[i]->left);
                subRoots.push_back(roots[i]->right);
            }
        }
        roots.clear();
        roots = subRoots;
        subRoots.clear();
    }
    return height;
}

template <typename T>
Node<T>* getNode(T data)
{
    Node<T> *node = new Node<T>;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int main()
{
    using namespace std;

    // Create a binary tree
    Node<int> *root = getNode(1);
    root->left = getNode(2);
    root->left->right = getNode(3);
    root->left->right->left = getNode(4);

    cout << "Height = " << findHeight(root) << " (recursive)\n" <<
        "Height = " << findHeightIter(root) << " (iterative)" << endl;

    return 0;
}
