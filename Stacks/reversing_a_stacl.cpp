/*Harry Style*/

#include <iostream>
#define ll long long int
using namespace std;
class stack
{
public:
    int size;
    int top;
    int *arr;
};

int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(stack *ptr, int val)
{
    if (isFull(ptr))
    {
        cout << "Stack is already Full" << endl;
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
}

int pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(stack *ptr, int i)
{
    if ((ptr->top - i + 1) < 0)
    {
        cout << "InValid Position" << endl;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

int main()
{
    stack *s;
    stack *s2;
    s = new stack();
    s2 = new stack();
    ll n, x;
    cin >> n;
    s->top = -1;
    s->size = n;
    s2->size = n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(s, x);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<peek(s, i)<<" ";
    }
}