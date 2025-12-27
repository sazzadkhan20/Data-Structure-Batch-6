#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val) : val(val), next(NULL)
    {
    }
};

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == 0)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == 0)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void delete_at_head(Node *&head, Node *&tail)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        Node *deleteNode = head;
        head = NULL;
        tail = NULL;
        delete deleteNode;
        return;
    }
    Node *deletNode = head;
    head = head->next;
    delete deletNode;
}

void delete_at_position(Node *&head, Node *&tail, int index)
{
    if (head == 0)
        return;
    if (index == 0)
    {
        delete_at_head(head, tail);
        return;
    }
    if (index == 1 && head->next == NULL)
        return;
    Node *temp = head;
    // 50 10 30
    for (int i = 1; i < index; i++)
    {
        if (temp->next == NULL)
            return;
        temp = temp->next;
    }
    if (temp->next == NULL)
        return;
    if (temp->next->next == NULL)
    {
        Node *deleteNode = tail;
        temp->next = NULL;
        tail = temp;
        delete deleteNode;
        return;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int queries;
    cin >> queries;
    while (queries--)
    {
        int x, v;
        cin >> x >> v;
        if (x == 0)
            insert_at_head(head, tail, v);
        else if (x == 1)
            insert_at_tail(head, tail, v);
        else if (x == 2)
            delete_at_position(head, tail, v);
        print(head);
    }
}