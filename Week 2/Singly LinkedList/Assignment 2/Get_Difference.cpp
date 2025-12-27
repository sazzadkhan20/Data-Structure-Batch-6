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

int max_value(Node *head)
{
    int maxValue = INT_MIN;
    if (head == 0)
        return maxValue;
    while (head != NULL)
    {
        if (head->val > maxValue)
            maxValue = head->val;
        head = head->next;
    }
    return maxValue;
}

int min_value(Node *head)
{
    int minValue = INT_MAX;
    if (head == 0)
        return minValue;
    while (head != NULL)
    {
        if (head->val < minValue)
            minValue = head->val;
        head = head->next;
    }
    return minValue;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
int main()
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
    // print(head);
    int maxValue = max_value(head);
    int minValue = min_value(head);
    cout << maxValue - minValue << endl;
}
