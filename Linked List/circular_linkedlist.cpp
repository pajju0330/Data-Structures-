#include <iostream>
#define ll long long int
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node *to_empty(node *head, int data)
{
    if (head != NULL)
    {
        return head;
    }
    node *p = new node();
    p->data = data;
    head = p;
    head->next = head; // list was empty so we linked it to itself
    return head;
}
node *push(node *head, int data) // insert at the begining
{
    if (head == NULL)
    {
        return to_empty(head, data);
    }
    node *p;
    p = new node();
    p->data = data;
    p->next = head->next;
    head->next = p;
    return head;
}

node *append(node *head, int data) // append at last of the list
{
    if (head == NULL)
    {
        return to_empty(head, data);
    }
    node *p = new node();
    p->data = data;
    p->next = head->next;
    head->next = p;
    head = p;
    return head;
}

node *insert(node *head, int data, int value) // insert after given value
{
    if (head == NULL)
    {
        return NULL;
    }
    node *p = new node();
    node *q = new node();
    q = head->next;
    do
    {
        if (q->data == value)
        {
            p->data = data;
            p->next = q->next;
            q->next = p;
            if (q == head)
            {
                head = p;
            }
            return head;
        }
        q = q->next;
    } while (q != head->next);
    cout << "Not Found" << endl;
    return head;
}

void print_list(node *head) // printing the list
{
    if (head == NULL)
    {
        cout << "EMPTY List" << endl;
        return;
    }
    node *p;
    p = head->next;

    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head->next);
    cout << endl;
}

void delete_element(node **head ,  int value)
{
    if (*head == NULL)
    {
        return;
    }
    if ((*head)->data == value && (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    node*last = *head , *p;
    if ((*head)->data == value)
    {
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = (*head)->next;
        free(*head);
        *head = last->next;
        return;
    }
    while (last->next != *head && last->next->data != value)
    {
        last = last->next;
    }
    if (last->next->data == value)
    {
        p = last->next;
        last->next = p->next;
        free(p);
    }
    else
    {
        cout<<"No element Found"<<endl;
    }
}

int _lenght(node* head)
{
    node *current  = head;
    ll count = 0;
    if (head == NULL)
    {
        return 0;
    }
    do
    {
        current = current->next;
        count++;
    } while (current != head);
    return count;

}
int main()
{
    node *head = NULL;
    head = to_empty(head, 8);
    print_list(head);
    head = push(head, 5);
    print_list(head);
    head = push(head, 2);
    print_list(head);
    head = append(head, 10);
    print_list(head);
    head = insert(head, 12, 2);
    print_list(head);
    delete_element(&head , 12);
    print_list(head);
    cout<<_lenght(head);
    return 0;
}