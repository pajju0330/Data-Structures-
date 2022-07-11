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
    class stack *s;
    s = new stack();
    s->top = -1;
    s->size = 100;
    s->arr = new int(s->size);
    // cout << isEmpty(s) << endl;
    // cout << isFull(s) << endl;
    for (int i = 0; i < 11; i++)
    {
        push(s,i);
    } 
    // cout << isFull(s) << endl;
    // cout << isEmpty(s) << endl;
    cout << pop(s) <<" popped"<<endl;
    cout << pop(s) <<" popped"<<endl;
    cout << pop(s) <<" popped"<<endl;
    for (int i = 1; i < s->top + 1; i++)
    {
        cout << peek(s, i) << endl;
    }

    return 0;
}