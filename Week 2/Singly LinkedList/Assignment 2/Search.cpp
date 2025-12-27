#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int search_x(Node *head, int x)
{
    int index = -1;
    while (head != NULL)
    {
        index++;
        if (head->val == x)
            return index;
        head = head->next;
    }
    return -1;
}
int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        Node *head = NULL;
        Node *tail = NULL;
        int val;
        while (true)
        {
            cin >> val;
            if (val == -1)
                break;
            insert(head, tail, val);
        }
        int x;
        cin >> x;
        int value = search_x(head, x);
        cout << value << endl;
    }
}
