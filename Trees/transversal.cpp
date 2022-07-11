#include <bits/stdc++.h>
#define ll long long int

using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
};

node *create_node(int data)
{
    node *n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(node *root)
{
    if (root!= NULL)
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(node *root)
{
    if (root!= NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}
void inOrder(node *root)
{
    if (root!= NULL)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
int main()
{
    node *p = new node();
    p = create_node(7);
    p->left = create_node(2);
    p->right = create_node(1);
    p->left->left = create_node(0);
    p->left->right = create_node(4);
    preOrder(p);
    cout<<endl;
    postOrder(p);
    cout<<endl;
    inOrder(p);
    return 0;
}
