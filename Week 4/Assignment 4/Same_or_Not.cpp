#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    stack<int> st;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    if (n != m)
        cout << "NO\n";
    else
    {
        bool flag = true;
        while (!st.empty() && !q.empty())
        {
            if (st.top() != q.front())
            {
                cout << "NO\n";
                flag = false;
                break;
            }
            st.pop();
            q.pop();
        }
        if (flag)
            cout << "YES\n";
    }
}