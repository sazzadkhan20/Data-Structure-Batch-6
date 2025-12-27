#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        string s;
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (!st.empty() && s[i] == '1' && st.top() == '0')
                st.pop();
            else
                st.push(s[i]);
        }
        if (st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}