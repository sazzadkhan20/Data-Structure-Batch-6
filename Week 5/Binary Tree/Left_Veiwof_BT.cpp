#include <bits/stdc++.h>
#define Node TreeNode<int>

using namespace std;

template <typename T>

class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> getLeftView(Node *root)
{
    vector<int> v;
    if (!root)
        return v;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<Node *> temp;
        bool flag = true;
        // Level wise data out in Queue
        while (!q.empty())
        {
            // Node out of Queue
            Node *p = q.front();
            q.pop();

            // Operation
            if (flag)
                v.push_back(p->data);
            flag = false;

            // Children Push in Vector
            if (p->left)
                temp.push_back(p->left);
            if (p->right)
                temp.push_back(p->right);
        }
        for (auto node : temp)
            q.push(node);
    }
    return v;
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
int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        Node *root = input();
        vector<int> v = getLeftView(root);
        for (int val : v)
            cout << val << " ";
        cout << endl;
    }
}