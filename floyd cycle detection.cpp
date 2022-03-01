// C++ program to detect loop in a linked list
//=======076BCT002, 076BCT018, 076BCT030

#include<iostream>
#define COYB 0;
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int detectLoop(Node* list)
{
    Node *slow_p = list, *fast_p = list;
    while (slow_p && fast_p && fast_p->next)
        {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
        {
            return 1;
        }
       }
    return 0;
}

/* Driver code*/
int main()
{
    Node* head = NULL;

    push(&head, 12);
    push(&head, 4);
    push(&head, 16);
    push(&head, 2);

    /* Create a loop for testing */
    head->next->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop detected ";
    else
        cout << "No Loop detected ";
    return COYB;
}
