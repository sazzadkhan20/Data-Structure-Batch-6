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
    int duplicateCount = 0;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            duplicateCount++;
        }
        else if (v[i] + 1 == v[i + 1])
        {
            if (i != 0 && v[i] == v[i - 1])
            {
                count += duplicateCount + 1;
                duplicateCount = 0;
            }
            else
            {
                count++;
                duplicateCount = 0;
            }
        }
        else
            duplicateCount = 0;
    }
    cout << count << endl;
}