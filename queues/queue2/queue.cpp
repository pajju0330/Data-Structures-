#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Queue{
private:
    int front;
    int rear;
    int capacity;
    int* queue;
public:
    Queue(){} //empty constructor
    Queue(int data){    //constructor
        capacity = data;
        front = 0 ;
        rear = 0;
        queue = new int;  
    }
    //push in queue
    bool isFull(){
        return rear == capacity;
    }
    void enqueue(int new_data){
        if(isFull()) return;
        queue[rear] = new_data;
        rear++;
        return;
    }
    bool isEmpty(){
        return rear = front;
    }
    //popping the data
    void dequeue(){
        if(isEmpty()) return;
        for (int i = 0; i < rear-1; i++)
        {
            queue[i] = queue[i+1];
        }
        rear--;
        return;
    }
    void printq(){
        if(isEmpty()) return;
        for (int i = front; i < rear ; i++)
        {
            cout<<"<--"<<queue[i];
        }
        return;
    }
    int front(){
        if(isEmpty()) return 0;
        return queue[front];
    }
};

int main()
{
    Queue q(10);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(13);
    q.printq();
    return 0;
}


/*
  
_______________
front       rear
_______________
<-- capacity-->



1 2 2 3 4
_ 1 2 3 4 


Dequque
Deque --> Double Edged queue

*/