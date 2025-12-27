#include <bits/stdc++.h>

using namespace std;

class Compare
{
public:
    bool operator()(pair<string, int> l, pair<string, int> r)
    {
        if (l.first == r.first)
            return l.second < r.second;
        return l.first > r.first;
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
    while (n--)
    {
        string s;
        int x;
        cin >> s >> x;
        pq.push({s, x});
    }
    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
}