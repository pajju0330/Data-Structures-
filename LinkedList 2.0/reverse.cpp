#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

void printLL(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void insert(node **head, int val)
{
    node *new_node = new node(val);
    new_node->next = (*head);
    *head = new_node;
}

void insert_after(node *head, int index, int val)
{
    node *new_node = new node(val);
    node *temp = head;
    if (index == 0)
    {
        insert(&temp, val);
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void append(node *head, int val)
{
    node *new_node = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
}

void reversell(node **head)
{
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

node* reversell_knodes(node *head , int k)
{
    if (!head)
    {
        return NULL;
    }
    int count  = 0;
    node *prev = NULL;
    node *current = head;
    node *next = NULL;
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next!= NULL)
    {
        head->next = reversell_knodes(next , k);
    }
    return prev;
}

int lenghtLL(node *head)
{
    node *current = head;
    int cnt = 0;
    while (current != NULL)
    {
        current = current->next;
        cnt++;
    }
    return cnt;
}

int middle_element(node *head)
{
    int length = lenghtLL(head);
    int middle = length / 2;
    node *current = head;
    while (middle--)
    {
        current = current->next;
    }
    return current->data;
}

node* delindex(node *head, int index)
{
    node *current = head;
    node *next = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
        next = next->next;
    }
    current->next = next->next;
    free(next);
    return head;
}

int main()
{
    node *head = NULL;
    insert(&head, 5);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    insert_after(head, 3, 4);
    append(head, 6);
    printLL(head);
    // reversell(&head);
    // printLL(head);
    // cout << lenghtLL(head) << "\n";
    // cout << middle_element(head) << "\n";
    reversell_knodes(head, 2);
    printLL(head);
    return 0;
}