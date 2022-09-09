#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class node
{
private:
    int data;
    node *next;

public:
    node(){};
    node *to_empty(node *head, int new_data);
    node *push(node *head, int new_data);
    node *append(node *head, int new_data);
    void printCL(node *head);
    int minimumLL(node *head);
};

void node::printCL(node *head)
{
    node *newNode = head;
    do
    {
        cout << newNode->data << " -> ";
        newNode = newNode->next;
    } while (newNode != head);
    cout << "\n";
}

node *node::to_empty(node *head, int new_data)
{
    if (head)
        return head; // head == NULL = (!head) head != NULL (head)
    node *newNode = new node();
    newNode->data = new_data;
    head = newNode;
    head->next = head;
    return head;
}

node *node::push(node *head, int new_data)
{
    if (!head)
        return to_empty(head, new_data); // head == NULL go to to_empty
    node *last = new node();
    node *newNode = new node();
    last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    newNode->next = head;
    last->next = newNode;
    newNode->data = new_data;
    head = newNode;
    return head;
}
node *node::append(node *head, int new_data)
{
    if (!head)
        return to_empty(head, new_data); // head == NULL go to to_empty
    node *last = new node();
    node *newNode = new node();
    last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->data = new_data;
    newNode->next = head;
    return head;
}

int node::minimumLL(node *head)
{
    node *current = new node();
    current = head;
    int mini = INT_MAX;
    do
    {
        mini = min(mini, current->data);
        current = current->next;
    } while (current != head);
    return mini;
}

int main()
{
    node link;
    node *head = NULL;
    head = link.to_empty(head, 10);
    head = link.append(head, 5);
    head = link.push(head, 7);
    head->printCL(head);
    cout << link.minimumLL(head);
    return 0;
}

/*

IF(STATEMENT) head != NULL
IF(head) == head != NULL
IF(!head) == head == NULL
if(!head)
*/