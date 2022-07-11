#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class node
{
public:
   int data;
   node *left;
   node *right;
   int height;
};

int getHeight(node *n)
{
   if (n == NULL)
      return 0;
   return n->height;
}

node *create_node(int data)
{
   node *n = new node();
   n->data = data;
   n->left = NULL;
   n->right = NULL;
   n->height = 1;
   return n;
}
int getBalanceFactor(node *n)
{
   if (n == NULL)
      return 0;
   return getHeight(n->left) - getHeight(n->right);
}
/*
      y              x
     / \            / \
    x   T3  -->   T1   y
   / \               / \
  T1  T2            T2  T3
*/
node *rightRotate(node *y)
{
   node *x = y->left;
   node *T2 = x->right;
   x->right = y;
   y->left = T2;
   y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
   x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
   return x; // becoz x is new root node.
}
node *leftRotate(node *x)
{
   node *y = x->right;
   node *T2 = y->left;
   y->left = x;
   x->right = T2;
   y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
   x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
   return x; // becoz x is new root node.
}
node *add_node(node *root, int key)
{
   if (root == NULL)
   {
      return create_node(key);
   }
   if (key < root->data)
   {
      root->left = add_node(root->left, key);
   }
   else if (key > root->data)
   {
      root->right = add_node(root->right, key);
   }
   root->height = 1 + max(getHeight(root->right), getHeight(root->right));
   int bf = getBalanceFactor(root);
   if (bf > 1 && key < root->left->data) //left left case
   {
      return rightRotate(root);
   }
   if (bf < -1 && key > root->right->data) //right right case
   {
      return leftRotate(root);
   }
   if (bf > 1 && key > root->left->data) //left right case
   {
      root->left = leftRotate(root->left);
      return rightRotate(root);
   }
   if (bf < -1 && key < root->right->data) //right left case
   {
      root->right = rightRotate(root->right);
      return leftRotate(root);
   }
   return root;
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main()
{
   node * root = NULL;
   root = add_node(root ,45);
   root = add_node(root ,4);
   root = add_node(root ,5);
   root = add_node(root ,8);
   root = add_node(root ,9);
   inOrder(root);

   return 0;
}