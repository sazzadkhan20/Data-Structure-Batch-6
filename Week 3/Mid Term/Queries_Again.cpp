#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_position(Node *&head, Node *&tail, int pos, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL && pos == 0)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    if (pos == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    if (head == 0)
        return;
    Node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            return;
        }
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    if (newNode->next == 0)
    {
        tail = newNode;
        return;
    }
    newNode->next->prev = newNode;
}

int size(Node *head)
{
    int sz = 0;
    while (head != NULL)
    {
        head = head->next;
        sz++;
    }
    return sz;
}
void print_linkedlist(Node *head)
{
    if (head == 0)
        return;
    cout << "L -> ";
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void reverse_linkedlist(Node *tail)
{
    if (tail == 0)
        return;
    cout << "R -> ";
    while (tail != NULL)
    {
        cout << tail->val << " ";
        tail = tail->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int queries, x, v;
    cin >> queries;
    while (queries--)
    {
        cin >> x >> v;
        if (x == 0)
        {
            insert_at_position(head, tail, x, v);
        }
        else if (x > size(head))
        {
            cout << "Invalid\n";
            continue;
        }
        else if (x <= size(head))
        {
            insert_at_position(head, tail, x, v);
        }
        print_linkedlist(head);
        reverse_linkedlist(tail);
    }
}