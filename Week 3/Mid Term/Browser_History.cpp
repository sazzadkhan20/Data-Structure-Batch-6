#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    string s;
    Node *next;
    Node *prev;
    Node(string s)
    {
        this->s = s;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert(Node *&head, Node *&tail, string s)
{
    Node *newNode = new Node(s);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}
void visit_address(Node *head, vector<string> v)
{
    // string s1;
    Node *temp = head;
    Node *curr = head;
    int i = 0;
    bool flag = false;
    while (temp != NULL)
    {
        while (i < v.size())
        {
            if (v[i] == "prev")
            {
                if (temp->prev != 0)
                {
                    temp = temp->prev;
                    curr = temp;
                    cout << temp->s << endl;
                }
                else
                    cout << "Not Available\n";
                i++;
            }
            else if (v[i] == "next")
            {
                if (temp->next != 0)
                {
                    temp = temp->next;
                    curr = temp;
                    cout << temp->s << endl;
                }
                else
                    cout << "Not Available\n";
                i++;
            }
            else
            {
                if (temp == NULL)
                    break;
                if (i != 0 && !flag)
                {
                    temp = head;
                    flag = true;
                    // cout<<"Asi\n";
                    break;
                }
                if (temp->s == v[i])
                {
                    cout << temp->s << endl;
                    curr = temp;
                    flag = false;
                    i++;
                    continue;
                }
                temp = temp->next;
            }
        }
        if (i == v.size())
        {
            break;
        }
        if (temp == NULL && i != v.size())
        {
            cout << "Not Available\n";
            temp = curr;
            flag = false;
            i++;
        }
    }
}

string find(string s)
{
    if (s == "prev")
        return s;
    else if (s == "next")
        return s;
    string s1 = "";
    for (int i = 6; i < s.size(); i++)
    {
        s1 += s[i];
    }
    return s1;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    string s;
    while (true)
    {
        cin >> s;
        if (s == "end")
            break;
        insert(head, tail, s);
    }
    int queries;
    string command;
    cin >> queries;
    vector<string> v;
    cin.ignore();
    while (queries--)
    {
        getline(cin, command);
        command = find(command);
        v.push_back(command);
    }
    visit_address(head, v);
}