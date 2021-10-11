#include <iostream>


struct Node{
    int data;
    struct Node *next = nullptr;
};

typedef Node Node_t;

void add(Node_t *LinkedList, int value){
    /*
        1) Find the last element
        2) Create new instance of Node
        3) Add value
        4) Update Last -> next
    */
    Node_t *tmp = LinkedList;                   // Why creating a new pointer? To avoid mixing with the original?
    while (tmp->next != nullptr){               // 1) Find the last element
        tmp = tmp->next;
    }

    Node_t *newNode = new Node_t;               // 2) Create new instance of Node
    newNode->data = value;                      // 3) Add value
    tmp->next = newNode;                        // 4) Update Last/Current -> next

}

void remove();

void print(Node_t *LinkedList){
    do
    {
        std::cout << LinkedList->data << std::endl;
    }   while (LinkedList->next != nullptr);
}



int main(){

    Node_t *LinkedList = nullptr;

    add(LinkedList, 20);
    add(LinkedList, 40);

    // print(LinkedList);

    return 0;
}