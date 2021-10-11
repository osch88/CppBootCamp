/*
    Implement a single (forward) linked list for integers, your application should be able to:
    - Add items to the end of the list
    - Remove items from the front the list
    - Print the list in the correct order
*/

#include <iostream>


typedef struct Node {
    int             data;
    struct Node     *next;    
}Node_t;


Node_t *findLast(Node_t *LinkedList) {
    if (LinkedList == nullptr) {    
        return LinkedList;
    }
    Node_t *current = LinkedList;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}


void add(Node_t *LinkedList, const int &value) {
    // 1) find the last item
    // 2)create a new node
    // 3) assign & link
    if (LinkedList == nullptr) {
        LinkedList = new Node_t;
        LinkedList->data  = value;
        LinkedList->next = nullptr;        
    } else {
        Node_t  *newNode = new Node_t,
                *lastNode = findLast(LinkedList);
        newNode->next = nullptr;
        newNode->data = value;
        lastNode->next = newNode;    
    }
}


Node_t *removeFromHead(Node_t *LinkedList) {
    if (LinkedList == nullptr) {
        return LinkedList;
    }
    /*
        1) find the head of next and set is as new head
        2) delete head
    */
    Node_t *next = LinkedList->next;
    delete LinkedList;
    return next;
}


void print(Node_t *LinkedList) {
    /*  
        1) loop over the list
        2) print things
    */
    // if (LinkedList == nullptr) return;
    while(LinkedList != nullptr) {
        std::cout << LinkedList->data << std::endl; 
        LinkedList = LinkedList->next;       
    }
    std::cout << "Something\n";
}

void deleteList(Node_t *LinkedList){
    Node_t *temp = LinkedList;
    Node_t *temp2;

    while ( temp != nullptr )
    {
        temp2 = LinkedList->next;
        delete temp;
        temp = temp2;
    }
    
}


int main (int argc, char ** argv) {

    Node_t *MY_LINKED_LIST = nullptr;
    // Not enough. Must create a intance new.
    
    
    add(MY_LINKED_LIST, 12);
    // MY_LINKED_LIST->data = 5;

    print(MY_LINKED_LIST);


    
    return 0;
}