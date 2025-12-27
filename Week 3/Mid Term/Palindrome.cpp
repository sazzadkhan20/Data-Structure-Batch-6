#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next, *prev;
    Node(int val) : val(val), next(0), prev(0)
    {
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
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

bool palindrome(Node *head, Node *tail)
{
    if (head == tail)
        return true;
    while (head != tail && tail->next != head)
    {
        if (head->val != tail->val)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
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
    Node *head = 0;
    Node *tail = 0;
    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        insert_at_tail(head, tail, x);
    }
    if (palindrome(head, tail))
        cout << "YES\n";
    else
        cout << "NO\n";
}