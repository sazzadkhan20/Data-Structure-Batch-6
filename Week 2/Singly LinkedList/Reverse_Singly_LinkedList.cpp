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

Node *reverse_singly_linkedList(Node *&head, Node *node)
{
    if (node->next == NULL)
    {
        return head = node;
    }
    Node *temp = reverse_singly_linkedList(head, node->next);
    temp->next = node;
    return node;
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
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert(head, tail, val);
    }
    print(head);
    tail = reverse_singly_linkedList(head, head);
    tail->next = NULL;
    print(head);
}
