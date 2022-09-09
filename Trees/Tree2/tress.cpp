#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class node{
private:
    int data;
    node* left;
    node* right;
public:
    void PreOrder(node *root);
    void InOrder(node *root);
    void PostOrder(node *root);
};

void node:: PreOrder(node *root){
    if(!root) return;
    cout<<root->data;  //root
    PreOrder(root->left); //left
    PreOrder(root->right); //Right

}
void node:: InOrder(node *root){
    if(!root) return;
    PreOrder(root->left); //left
    cout<<root->data;  //root
    PreOrder(root->right); //Right

}
void node:: PostOrder(node *root){
    if(!root) return;
    PreOrder(root->left); //left
    PreOrder(root->right); //Right
    cout<<root->data;  //root

}

int main()
{
   return 0;
}