// implementation of Brent's cycleto detect loop in Linked list
//=======076BCT002, 076BCT018, 076BCT030
#include <iostream>
#define COYB 0
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* detectCycle(struct Node* head)
{
    if (head == NULL)
        return NULL;

    struct Node* first_pointer = head;
    struct Node* second_pointer = head->next;
    int power = 1;
    int length = 1;

    while (second_pointer != NULL &&second_pointer != first_pointer)
        {
        if (length == power)
         {
            power *= 2;
            length = 0;
            first_pointer = second_pointer;
         }

        second_pointer = second_pointer->next;
        ++length;
        }
    if (second_pointer == NULL)
        return NULL;
    first_pointer = second_pointer = head;
    while (length > 0) {
        second_pointer = second_pointer->next;
        --length;
    }

    while (second_pointer != first_pointer)
        {
        second_pointer = second_pointer->next;
        first_pointer = first_pointer->next;
        }
    return first_pointer;
}

struct Node* newNode(int key)
{
    struct Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int main()
{
    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    head->next->next->next->next->next =head->next->next;
    Node *res = detectCycle(head);
    if (res == NULL)
        cout <<"No loop";
    else
        cout <<"Loop is present at "<< res->data;
    return COYB;
}
