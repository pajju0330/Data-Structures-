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
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
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

int isBST(node *root)
{
    if (root != NULL)
    {
        static node *prev = NULL;
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}

void search(node *root, int val)
{
    if (root != NULL)
    {
        if (root->data > val)
        {
            search(root->left, val);
        }
        else if (root->data < val)
        {
            search(root->right, val);
        }
        else
        {
            cout << "Found" << endl;
            return;
        }
    }
    else
    {
        cout << "does not exist" << endl;
        return;
    }
}

void searchintr(node *root, int val)
{
    while (root != NULL)
    {
        if (root->data == val)
        {
            cout << "found"
                 << "\n";
            return;
        }
        else if (root->data > val)
        {
            root = root->left;
        }
        else if (root->data < val)
        {
            root = root->right;
        }
    }
    cout << "not found\n";
    return;
}

void add_node(node *root, int key)
{
    node *prev = NULL;
    node *ptr;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    node *new_node = create_node(key);
    if (key < prev->data)
    {
        prev->left = new_node;
    }
    else
    {
        prev->right = new_node;
    }
}
node *min_node(node *root)
{
    node *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

node *delete_node(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (val < root->data)
    {
        root->left = delete_node(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = delete_node(root->right, val);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *ipre = min_node(root->right);
        root->data = ipre->data;
        root->right = delete_node(root->right, ipre->data);
    }
    return root;
}

int main()
{
    node *p = new node();
    p = create_node(9);
    p->left = create_node(5);
    p->right = create_node(10);
    p->left->left = create_node(3);
    p->left->right = create_node(8);
    preOrder(p);
    cout << endl;
    postOrder(p);
    cout << endl;
    inOrder(p);
    cout << endl;
    if (isBST(p))
        cout << "YES\n";
    else
        cout << "NO\n";
    search(p, 0);
    searchintr(p, 5);
    add_node(p, 1);
    inOrder(p);
    cout << endl;
    delete_node(p, 10);
    inOrder(p);
    return 0;
}