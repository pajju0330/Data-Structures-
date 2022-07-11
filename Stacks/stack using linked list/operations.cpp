#include <iostream>
#define ll long long int
using namespace std;
class node
{
public:
    int data;
    node *next;
};

int isempty(node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(node *top)
{
    node *p = new node();
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

node *push(node *top, int data)
{
    if (!isFull(top))
    {
        node *new_node = new node();
        new_node->data = data;
        new_node->next = top;
        top = new_node;
        return top;
    }
    cout << "Stack Overflow" << endl;
}
void print_stack(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

node *pop(node *top)
{
    if (!isempty(top))
    {
        node *n = top;
        top = top->next;
        free(n);
        return top;
    }
    cout << "Stack underflow" << endl;
}

int peek(node *top , int position)
{
    int i = 0;
    node *ptr = top;
    for (int i = 0; i < position -1 && ptr != NULL; i++)
    {
        ptr= ptr->next;
    }
    if (ptr != NULL && position >=1)
    {
        return ptr->data;
    }
    return -1;
}
int main()
{
    node *top = new node(); 
    top = NULL;
    int x;
    for (int i = 0; i < 10; i++)
    {
        cin>>x;
        top  = push(top , x);
    }
    int n ;
    cin>>n;
    print_stack(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    print_stack(top);
    cout<<"VALUE AT INDEX "<< n << " IS "<<peek(top ,n)<<endl;

    return 0;
}