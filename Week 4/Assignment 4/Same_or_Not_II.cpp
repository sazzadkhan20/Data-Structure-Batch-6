#include <bits/stdc++.h>

using namespace std;

class StackNode
{
public:
    int val;
    StackNode *next;
    StackNode *prev;
    StackNode(int val) : val(val), next(NULL), prev(NULL)
    {
    }
};

class QueueNode
{
public:
    int val;
    QueueNode *next;
    QueueNode(int val) : val(val), next(NULL)
    {
    }
};

class myStack
{
private:
    StackNode *head = NULL;
    StackNode *tail = NULL;
    int sz = 0;

public:
    void push(int val)
    {
        sz++;
        StackNode *newNode = new StackNode(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void pop()
    {
        sz--;
        StackNode *node = tail;
        tail = tail->prev;
        if (tail == NULL)
            head = NULL;
        else
            tail->next = NULL;
        delete node;
    }
    int top()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return sz == 0;
    }
};

class myQueue
{
private:
    QueueNode *head = NULL;
    QueueNode *tail = NULL;
    int sz = 0;

public:
    void push(int val)
    {
        sz++;
        QueueNode *newNode = new QueueNode(val);
        if (head == 0)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void pop()
    {
        sz--;
        QueueNode *node = head;
        head = head->next;
        if (head == 0)
            tail = 0;
        delete node;
    }
    int front()
    {
        return head->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return sz == 0;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    myStack st;
    myQueue q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    if (n != m)
        cout << "NO\n";
    else
    {
        bool flag = true;
        while (!st.empty() && !q.empty())
        {
            if (st.top() != q.front())
            {
                cout << "NO\n";
                flag = false;
                break;
            }
            st.pop();
            q.pop();
        }
        if (flag)
            cout << "YES\n";
    }
}