#include <iostream>
#define ll long long int
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void push(node **head_ref, int new_data) // adding new node at the begining
{
    node *new_node = new node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}

void delete_node(node *head, node *n)
{
    if (head == n)
    {
        if (head->next = NULL)
        {
            cout << "ELEMENT CANT BE DELETED" << endl;
            return;
        }
        head->data = head->next->data;
        n = head->next;
        head->next = head->next->next;
        free(n);
        return;
    }
    node *prev = head;
    while (prev->next != NULL && prev->next != n)
    {
        prev = prev->next;
    }
    if (prev->next == NULL)
    {
        cout << "GIVEN NODE DOSENT EXIST" << endl;
        return;
    }
    prev->next = prev->next->next;
    free(n);
    return;
}

node *delete_index(node *head, int index)
{
    node *p = head;
    node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

node *delete_value(node *head, int value)
{
    node *p = head;
    node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
void print_list(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        push(&head, i);
    } 
    print_list(head);
    delete_node(head, head->next);
    print_list(head);
    delete_value(head, 2);
    print_list(head);
    delete_index(head, 5);
    print_list(head);
}