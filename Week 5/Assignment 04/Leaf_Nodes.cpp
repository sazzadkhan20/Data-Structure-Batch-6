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

void leafNodes(Node *root, vector<int> &v)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        v.push_back(root->val);
        return;
    }
    else
    {
        leafNodes(root->left, v);
        leafNodes(root->right, v);
    }
}

int main()
{
    Node *root = input();
    vector<int> v;
    leafNodes(root, v);
    sort(v.begin(), v.end(), greater<int>());
    for (int val : v)
        cout << val << " ";
    cout << endl;
}