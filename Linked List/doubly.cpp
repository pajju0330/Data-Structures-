#include <iostream>
#define ll long long int
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

void print_list(node *n)
{
    while (n->next != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void push(node **head, int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;
    (*head)->prev = new_node;
    *head = new_node;
    return;
}

void _insert(node **head, int index, int value)
{
    int k = 0;
    node *temp = new node();
    temp = *head;
    while (k < index && temp->next != NULL)
    {
        k++;
        temp = temp->next;
    }
    // cout<<head<<endl;
    if (k != index)
    {
        cout << "Desired index dosent not exist\n";
        return;
    }
    node *new_node = new node();
    new_node->data = value;
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next)
    {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    return;
}

int main()
{
    node *head = new node();
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    print_list(head);
    _insert(&head , 0  ,1);
    print_list(head);
    return 0;
}