#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class node{
private:
    int data;
    node* next;
    node* prev;
public:
    void printDLL(node *head);
    node* push(node *head, int new_data);
    node* toEmpty(node *head, int new_data);
    node* append(node *head, int new_data);
    node* insert(node *head, int new_data,int idx);
    node* deleteNode(node *head, node *n);
    node* deleteIdx(node *head, int idx);
    node* deleteVal(node *head, int val);
    void reverse(node *head);
};

void node:: printDLL(node *head){
    node *curr = new node();
    curr = head;
    while(curr->next != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<"\n";
}
node* node:: toEmpty(node *head, int new_data){
    node *newNode = new node();
    newNode->data = new_data;
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return head;
}
node* node:: push(node *head, int new_data){
    if(head == NULL) return toEmpty(head, new_data);
    node *newNode = new node();
    newNode->data = new_data;
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    head = newNode;
    return head;

}
node* node:: append(node *head, int new_data){
    if(head == NULL) return toEmpty(head, new_data);
    node *last = new node();
    last = head;
    while(last->next != NULL){
        last = last->next;
    }
    node *newNode = new node();
    newNode->data = new_data;
    newNode->next = NULL;
    last->next = newNode;
    newNode->prev = last;
    return head;
}

node* node:: insert(node *head, int new_data,int idx){
    node* curr = new node();
    curr = head; 
    idx--;
    while(idx--){
        curr = curr->next;
    }
    node* newNode = new node();
    newNode->data = new_data;
    newNode->next = curr->next;
    curr->next->prev = newNode;
    curr->next = newNode;
    newNode->prev = curr;
    return head;
}

node* node:: deleteNode(node *head, node *n){
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
    return head;
}

node* node:: deleteIdx(node *head, int idx){
    node *n  = new node();
    n = head;
    while(idx--){
        n = n->next;
    }
    deleteNode(head,n);
    return head;
}

node* node:: deleteVal(node *head, int val){
    node *n  = new node();
    n = head;
    while(n->data != val && n->next != NULL){
        n = n->next;
    }
    if(n->data != val){
        cout<<"Data doesn't exist\n";
        return head;
    }
    deleteNode(head,n);
    return head;
}
void node:: reverse(node *head){
    node *n = new node();
    n = head;
    while(n->next != NULL){
        n = n->next;
    }
    while(n->prev != NULL){
        cout<<n->data<<" ";
        n = n->prev;
    }
}

int main()
{
    node list1;
    node *head = new node();
    head = list1.toEmpty(head,7);
    head = list1.push(head,10);
    head = list1.push(head,5);
    head = list1.push(head,8);
    list1.printDLL(head);
    head = list1.append(head,12);
    head = list1.append(head,14);
    list1.printDLL(head);
    // list1.deleteIdx(head,2);
    list1.deleteVal(head,13);
    list1.printDLL(head);
    list1.reverse(head);
    return 0;
}

/*
1 element kami print hot ahe
reverse actuall kasa karaych
min,max,sum,length

singly => Sakshi
circular => Sakshi
doubly => Prajwal

10 que || Standard
10 que || LeetCode

*/