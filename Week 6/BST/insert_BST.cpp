#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node *input()
{
    Node *root;
    int val;
    cin >> val;
    if (val == -1)
    {
        root = 0;
        return root;
    }
    else
        root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *myLeft = 0;
        Node *myRight = 0;
        if (l != -1)
            myLeft = new Node(l);
        if (r != -1)
            myRight = new Node(r);
        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

// Node *insert_BST(Node *root, int data)
// {
//     if (!root)
//         return new Node(data);
//     if (root->data > data)
//         root->left = insert_BST(root->left, data);
//     else
//         root->right = insert_BST(root->right, data);
//     return root;
// }

void insert_BST(Node *&root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return;
    }
    if (root->data > data)
    {
        if (!root->left)
        {
            root->left = new Node(data);
            return;
        }
        insert_BST(root->left, data);
    }
    else
    {
        if (!root->right)
        {
            root->right = new Node(data);
            return;
        }
        insert_BST(root->right, data);
    }
}

int main()
{
    Node *root = 0;
    inOrder(root);
    cout << endl;
    insert_BST(root, 7);
    inOrder(root);
    cout << endl;
    insert_BST(root, 1);
    inOrder(root);
    cout << endl;
}