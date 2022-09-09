
#include <bits/stdc++.h>

using namespace std;

class node
{
private:
    int data;
    node *next;
public:
    node() {}
    node(int value)
    {
        data = value;
        next = NULL;
    }
    void printLL(node *n);
};

void node:: printLL(node *n)
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

node *deleteNode(node *head, node *n)
{
    node *curr = head;
    while (curr->next != n)
    {
        curr = curr->next;
    }
    curr->next = n->next;
    free(n);
    return head;
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

node *delete_index(node *head, int val)
{
    node *p = new node();
    node *q = new node();
    p = head;
    q = NULL;
    while (p->data != val && p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    if (p->data == val)
    {
        q->next = p->next;
        free(p);
    }
    return head;
}

int minimumLL(node *head)
{
    node *current = new node();
    current = head;
    int mini = INT_MAX;
    while (current != NULL)
    {
        mini = min(mini, current->data);
        current = current->next;
    }
    return mini;
}

int sum_linkedlist(node *head)
{
    node *current = new node();
    current = head;
    int sum = 0;
    while (current != NULL)
    {
        sum += current->data;
        current = current->next;
    }
    return sum;
}
/*
1)base conditions
2)recursion call
3)what to do

*/
node *reccReverseLL(node *node1)
{
    if (node1 == NULL)
        return NULL;
    if (node1->next == NULL)
    {
        *head= node1;
        return node1;
    }
    node *n = reccReverseLL(&(node1->next));
    n->next = node1;
    node1->next = NULL;
    return *head;
}

void *reverseLL(node **head)
{
    node *prev = NULL;
    node *curr = (*head);
    node *nxt = NULL;
    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    *head = prev;
}

node *reversell_knodes(node *head, int k)
{
    if (!head)
    {
        return NULL;
    }
    int count = 0;
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
    if (next != NULL)
    {
        head->next = reversell_knodes(next, k);
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

node *delindex(node *head, int index)
{
    node *current = new node();
    node *prev = new node();
    current = head;
    prev = NULL;
    while (index--)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
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
    // printLL(head);
    // cout << lenghtLL(head) << "\n";
    // cout << middle_element(head) << "\n";
    // reversell_knodes(head, 2);
    cout << minimumLL(head) << "\n";
    cout << sum_linkedlist(head) << "\n";
    reverseLL(&head);
    // delindex(head,2);
    printLL(head);
    reccReverseLL(&head);
    printLL(head);
    return 0;
}

/*
idx = 3 cnt = 4
if(cnt == idx + 1)
    head 1 2 3 5
             q  p
          q->next=p->next
          free(p)

*/