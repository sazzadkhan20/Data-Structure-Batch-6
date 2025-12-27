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

void remove_duplicate(Node *head)
{
    while (head != NULL && head->next != NULL)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (head->val == temp->next->val)
            {
                Node *deleteNode = temp->next;
                temp->next = temp->next->next;
                delete deleteNode;
            }
            else
                temp = temp->next;
        }
        head = head->next;
    }
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
    remove_duplicate(head);
    print(head);
}
