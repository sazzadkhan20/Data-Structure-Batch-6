#include <bits/stdc++.h>

using namespace std;

int main()
{
    list<int> l;
    int queries;
    cin >> queries;
    while (queries--)
    {
        int x, v;
        cin >> x >> v;
        if (x == 0)
            l.push_front(v);
        else if (x == 1)
            l.push_back(v);
        else
        {
            if (l.size() > v)
                l.erase(next(l.begin(), v));
        }
        cout << "L -> ";
        for (auto val : l)
            cout << val << " ";
        cout << endl;
        l.reverse();
        cout << "R -> ";
        for (auto val : l)
            cout << val << " ";
        cout << endl;
        l.reverse();
    }
}