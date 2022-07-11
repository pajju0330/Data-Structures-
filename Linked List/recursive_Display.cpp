#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void print_list(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int length(node *ptr)
{
    int l = 1;
    while (ptr->next != NULL)
    {
        l++;
        ptr = ptr->next;
    }
    return l;
}

void push(node **head_ref, int new_data) // adding new node at the begining
{
    node *new_node = new node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}

void insert_after(node *prev_node, int new_data) // inserting after a node
{
    if (prev_node == NULL)
    {
        cout << "GIVEN PREVIOUS NOTE CANT BE NULL";
        return;
    }
    node *new_node = new node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(node **head_ref, int new_data)
{
    node *new_node = new node();
    node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
}

int MAX(node *ptr)
{
    int max = INT32_MIN;
    while (ptr != NULL)
    {
        if (ptr->data > max)
        {
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    return max;
}

int sum_linkedlist(node *ptr)
{
    int sum = ptr->data;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        sum += ptr->data;
    }
    return sum;
}
 


int main()
{
    node *head = NULL;
    ll n , x;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
       cin>>x;
       push(&head , x);  
    }
    cout<<"Your List is :";
    print_list(head);
    append(&head ,10);
    cout<<"Reversed list is: ";
    print_list(head);
    return 0;
}