#include <bits/stdc++.h>

using namespace std;
const int N = 100;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void levelOrder(Node *root)
{
    if (!root)
        return;
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
            cout << p->val << " ";

            // Children Push in Vector
            if (p->left)
                temp.push_back(p->left);
            if (p->right)
                temp.push_back(p->right);
        }
        cout << endl;
        for (auto node : temp)
            q.push(node);
    }
}

Node *convert_array_to_BST(int *arr, int l, int r)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        Node *root = new Node(arr[mid]);
        root->left = convert_array_to_BST(arr, l, mid - 1);
        root->right = convert_array_to_BST(arr, mid + 1, r);
        return root;
    }
    return NULL;
}
int main()
{
    int n;
    cin >> n;
    int arr[N];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    Node *root = convert_array_to_BST(arr, 0, n - 1);
    levelOrder(root);
    cout << endl;
    inOrder(root);
}