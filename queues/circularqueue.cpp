#include <iostream>
#define ll long long int
using namespace std;
class queue
{
    int rear, front;
    int size;
    int *arr;

public:
    queue(int a)
    {
        front = rear = -1;
        size = a;
        arr = new int[a];
    }
    void enqueue(int value);
    int dequeue();
    void displayQueue();
};
void queue::enqueue(int value)
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
    {
        cout << "queue is full" << endl;
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
        arr[rear] = value;
    }
    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }
    else
    {
        rear++;
        arr[rear] = value;
    }
}

int queue::dequeue()
{
    if (front == -1)
    {
        cout << "queue is empty" << endl;
        return INT16_MIN;
    }
    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return data;
}

void queue::displayQueue()
{
    if (front == -1)
    {
        cout << "queue is empty" << endl;
        return;
    }
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
    else
    {
        for (int i = front; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        for (int i = 0; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
}
int main()
{
    queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.displayQueue();
    q.dequeue();
    q.dequeue();
    q.displayQueue();
    
    return 0;
}