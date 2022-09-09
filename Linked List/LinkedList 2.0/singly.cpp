#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class node{
private:
    int data;
    node* next;
public:
    void printLL(node *head);
    node* toEmpty(node *head, int new_data);
    node* push(node *head, int new_data);
    node* append(node *head, int new_data);
    node* insert(node *head, int new_data,int idx);
    node* deleteNode(node *head, node *n);
    node* deleteIdx(node *head, int idx);
    node* deleteVal(node *head, int val);
    node *reversekLL(node **head, int k);
    int lengthLL(node *head);
    int sumLL(node *head);
    int maxLL(node *head);
    int minLL(node *head);
    int middleLL(node *head);
    void reverseLL(node **head);
};

void node:: printLL(node *head){
    node *curr = new node();
    curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<"\n";
}
node* node:: toEmpty(node *head, int new_data){
    node *newNode = new node();
    newNode->data = new_data;
    newNode->next = NULL;
    head = newNode;
    return head;
}
node* node:: push(node *head, int new_data){
    if(head == NULL) return toEmpty(head, new_data);
    node *newNode = new node();
    newNode->data = new_data;
    newNode->next = head;
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
    curr->next = newNode;
    return head;
}

node* node:: deleteNode(node *head, node *n){
    node* curr = new node();
    curr = head;
    while(curr->next != n){
        curr = curr->next;
    }
    curr->next = n->next;
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

int node::lengthLL(node *head){
    int len = 0;
    node* curr = new node();
    curr = head;
    while(curr!= NULL){
        len++;
        curr = curr->next;
    }
    return len;
}

int node::sumLL(node *head){
    int sum = 0;
    node* curr = new node();
    curr = head;
    while(curr!= NULL){
        sum += curr->data;
        curr = curr->next;
    }
    return sum;
}

int node::maxLL(node *head){
    int maxi = INT_MIN;
    node* curr = new node();
    curr = head;
    while(curr!= NULL){
        maxi = max(maxi,curr->data);
        curr = curr->next;
    }
    return maxi;
}
int node::minLL(node *head){
    int mini = INT_MAX;
    node* curr = new node();
    curr = head;
    while(curr!= NULL){
        mini = min(mini,curr->data);
        curr = curr->next;
    }
    return mini;
}
int node::middleLL(node *head){
    int len = lengthLL(head);
    int mid = len/2;
    node* curr = new node();
    curr = head;
    while(mid--){
        curr = curr->next;
    }
    return curr->data;
}

void node::reverseLL(node **head){
    node *prev = NULL;
    node *nxt  = NULL;
    node *curr = (*head);
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    (*head) = prev;
}

node* node::reversekLL(node **head,int k){
    if(head == NULL) return (*head);
    node *curr = (*head);
    node *prev = NULL;
    node *nxt = NULL;
    int cnt = 0;
    while(cnt < k && curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        cnt++;
    }
    if(nxt){
        (*head)->next = reversekLL(&nxt,k);
    }
    (*head) = prev;
    return (*head);
}

int main()
{
    node list1;
    node *head = new node();
    head = list1.toEmpty(head,7);
    head = list1.push(head,10);
    head = list1.push(head,5);
    head = list1.push(head,8);
    list1.printLL(head);
    head = list1.append(head,12);
    head = list1.append(head,14);
    list1.printLL(head);
    list1.deleteIdx(head,2);
    list1.printLL(head);
    cout<<"Length:: "<<list1.lengthLL(head)<<"\n";
    cout<<"Sum:: "<<list1.sumLL(head)<<"\n";
    cout<<"Max:: "<<list1.maxLL(head)<<"\n";
    cout<<"Min:: "<<list1.minLL(head)<<"\n";
    cout<<"Mid:: "<<list1.middleLL(head)<<"\n";
    list1.reverseLL(&head);
    list1.printLL(head);
    list1.reverseLL(&head);
    list1.printLL(head);
    list1.reversekLL(&head,2);
    list1.printLL(head);
    return 0;
}

