/*
    Implement a single (forward) linked list for integers, your application should be able to:
    - Add items to the end of the list
    - Remove items from the front the list
    - Print the list in the correct order
*/

#include <iostream>

typedef struct Node
{
    int data;
    struct Node *next = nullptr;
} Node_t;

Node_t *findLast(Node_t *LinkedList)
{
    if (LinkedList == nullptr)
    {
        return LinkedList;
    }
    Node_t *current = LinkedList;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    return current;
}

void add(Node_t *LinkedList, const int &value)
{
    /*
        1) find the last item
        2) create a new node
        3) assign & link
    */
    if (LinkedList == nullptr)
    {
        LinkedList = new Node_t;
        LinkedList->data = value;
        LinkedList->next = nullptr;
    }
    else
    {
        Node_t *newNode = new Node_t,
               *lastNode = findLast(LinkedList);
        newNode->next = nullptr;
        newNode->data = value;
        lastNode->next = newNode;
    }
}

Node_t *removeFromHead(Node_t *LinkedList)
{
    /*
        1) find the head of next and set is as new head
        2) delete head
    */
    if (LinkedList == nullptr)
    {
        return LinkedList;
    }

    Node_t *next = LinkedList->next;
    delete LinkedList;
    return next;
}

void print(Node_t *_LinkedList)
{
    /*  
        1) loop over the list
        2) print things
    */
    if (_LinkedList == nullptr)
    {
        std::cout << "LinkedList == nullptr\n";
        return;
    }
    while (_LinkedList != nullptr)
    {
        std::cout << _LinkedList->data << std::endl;
        _LinkedList = _LinkedList->next;
    }
}

void deleteList(Node_t *LinkedList)
{
    Node_t *current = LinkedList;
    Node_t *tempNext;

    while (current != nullptr)
    {
        tempNext = current->next;
        delete current;
        current = tempNext;
    }
}

int main(int argc, char **argv)
{

    // Node_t *LinkedList = nullptr;
    Node_t *LinkedList = new Node_t;
    LinkedList->data = 5;
    // Not enough. Must create a intance new.

    add(LinkedList, 10);
    add(LinkedList, 15);
    add(LinkedList, 20);

    LinkedList = removeFromHead(LinkedList);

    print(LinkedList);

    deleteList(LinkedList);

    return 0;
}