#include <bits/stdc++.h>

using namespace std;

int main()
{
    int queries;
    cin >> queries;
    queue<string> q;
    while (queries--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            string s;
            cin >> s;
            q.push(s);
        }
        else
        {
            if (!q.empty())
            {
                cout << q.front() << endl;
                q.pop();
            }
            else
                cout << "Invalid\n";
        }
    }
}