#include <iostream>
#define ll long long int
using namespace std;
class queue
{
public:
    int front;
    int rear;
    int size;
    int capacity;
    int *arr;
};

queue *create_queue(int capacity)
{
    queue *q = new queue();
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = new int(q->capacity);
    return q;
}

int isFull(queue *q)
{
    return (q->size == q->capacity); // will return 0 if q is empty
}

int isEmpty(queue *q)
{
    return (q->size == 0);
}

void enqueue(queue *q, int item)
{
    if (isFull(q))
    {
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = item;
    q->size = q->size + 1;
    cout << item << " enqueued" << endl;
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        return INT8_MIN;
    }
    int item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}

int front(queue *q)
{
    if (isEmpty(q))
    {
        return INT8_MIN;
    }
    return q->arr[q->front];
}
int rear(queue *q)
{
    if (isEmpty(q))
    {
        return INT8_MIN;
    }
    return q->arr[q->rear];
}

int main()
{
    queue *q = create_queue(1000);
    for (int i = 0; i < 10; i++)
    {
        enqueue(q,i);
    }
    cout<<dequeue(q)<<" dequeued front element"<<endl;
    cout<<"front element is "<<front(q)<<endl;
    cout<<"rear element is "<<rear(q)<<endl;
    return 0;
}