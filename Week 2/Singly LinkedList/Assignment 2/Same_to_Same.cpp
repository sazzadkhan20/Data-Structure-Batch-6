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

bool check(Node *head1, Node *head2)
{
    while (head1 != NULL)
    {
        if (head1->val != head2->val)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *tail1 = NULL;
    Node *tail2 = NULL;
    int size1 = 0;
    int size2 = 0;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert(head1, tail1, val);
        size1++;
    }
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert(head2, tail2, val);
        size2++;
    }
    if (size1 == size2)
    {
        if (check(head1, head2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";
}
