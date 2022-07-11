#include <iostream>
#define ll long long int

using namespace std;

struct qnode
{
    int data;
    qnode *next;
    qnode(int d)
    {
        data = d;
        next = NULL;
    }
};

struct queue
{
    qnode *front, *rear;
    queue()
    {
        front = rear = NULL;
    }
    void enqueue(int x)
    {
        qnode *temp = new qnode(x);
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue()
    {
        if (front == NULL)
        {
            return;
        }
        qnode *temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete (temp);
    }
};

int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<"Queue Front: "<<(q.front)->data<<endl;
    cout<<"Queue Rear: "<<(q.rear)->data<<endl;
    return 0;
}