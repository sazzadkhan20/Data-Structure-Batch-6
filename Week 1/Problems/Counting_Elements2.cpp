#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // Binary Search
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (v[mid] == v[i] + 1)
            {
                count++;
                break;
            }
            else if (v[i] + 1 > v[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    cout << count << endl;
}