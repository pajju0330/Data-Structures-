#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class node{
public:
    int data;
    node *next;
    node *top;
    bool is_empty(){
        return top == NULL; // returns true if top is NULL else returns false
    }
    bool is_full(){
        return top == NULL;// returns true if top is NULL else returns false
    }
    node* push(int new_data){
        if(!top) return top;
        node *temp = new node();
        temp->data = new_data;
        temp->next = top;
        top = temp;
        return top;
    }
    void pop(){
        if(!top) return;
        node *temp = new node;
        temp = top;
        top = top->next;
        free(temp);
        return;
    }
    int peek(){
        if(!top) return -1;
        return top->data;
    }
    void printLL(){
        if(!top) return;
        node *temp = new node;
        temp = top;
        while(temp->next->next->next != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        return;
    }
};
int main()
{
    node t;
    node *head = new node;
    head = t.push(5);
    head = t.push(3);
    head = t.push(4);
    head = t.push(2);
    t.pop();
    cout<<t.peek()<<"\n";
    t.printLL();
    return 0;
}



/*

stack<ListNode*>st;

1=> n
2 => n-1

1 2 
    3 4 5 6

1   1
3   2
5   3
3   4
5   5 


3 4 5 3 4 5 3 4 5 3 4 5...


fast slow ==> meet
slow ek ek step
head ek ek

head slow ==> meet ==> entry point ||
*/