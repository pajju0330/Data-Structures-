#include <iostream>
#define ll long long int
using namespace std;
#define MAX  1000

class stack
{
    int top;

public:
    stack() { top = -1; }
    int push(int x);
    int pop();
    int peek();
    int a[MAX];
    int is_empty();
};

int stack::push(int x)
{
    if (top >= MAX - 1)
    {
        cout << "Stack Overflow" << endl;
        return 0;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed inside" << endl;
        return 1;
    }
}

int stack::pop()
{
    if (top < 0)
    {
        cout << "Empty" << endl;
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

int stack::peek()
{
    if (top < 0)
    {
        cout << "Empty" << endl;
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}
int stack::is_empty()
{
    return (top < 0);
}

int main()
{
    ll n;
    class stack st;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    cout<<st.pop()<<" popped from the stack"<<endl;
    cout<<"Elements in the stack are ";
    while (!st.is_empty())
    {
        cout<<st.peek()<<" ";
        st.pop();
    }
    return 0;
}

