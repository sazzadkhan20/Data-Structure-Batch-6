#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    int queries;
    cin >> queries;
    while (queries--)
    {
        int c;
        cin >> c;
        if (c == 0)
        {
            int x;
            cin >> x;
            pq.push(x);
            cout << pq.top() << endl;
        }
        else if (c == 1)
        {
            if (pq.empty())
                cout << "Empty\n";
            else
                cout << pq.top() << endl;
        }
        else
        {
            if (pq.empty())
                cout << "Empty\n";
            else
            {
                pq.pop();
                if (pq.empty())
                    cout << "Empty\n";
                else
                    cout << pq.top() << endl;
            }
        }
    }
}
