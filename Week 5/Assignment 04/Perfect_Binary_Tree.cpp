#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = 0;
        this->right = 0;
    }
};

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

int levelOrder(Node *root, int &nodeCount)
{
    if (!root)
        return 0;
    queue<pair<Node *, int>> q;
    q.push({root, 1});
    int level = 1;
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();

        if (level == p.second)
            level++;
        nodeCount++;
        if (p.first->left)
            q.push({p.first->left, p.second + 1});
        if (p.first->right)
            q.push({p.first->right, p.second + 1});
    }
    level--;
    return level;
}

int main()
{
    Node *root = input();
    int nodeCount = 0;
    int level = levelOrder(root, nodeCount);
    if (pow(2, level) - 1 == nodeCount)
        cout << "YES\n";
    else
        cout << "NO\n";
}