#include <iostream>

struct Node
{
    int data;
    struct Node *next;
};

void printListForward(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    std::cout << head->data << "\n";
    printListForward(head->next);
}

void printListBackwards(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    printListBackwards(head->next);
    std::cout << head->data << "\n";
}

int main()
{
    Node *n1 = new Node;
    Node *n2 = new Node;
    Node *n3 = new Node;
    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;

    Node *head = n1;

    printListForward(head);
    std::cout << "\n";
    printListBackwards(head);

    return 0;
}
