#include <bits/stdc++.h>

using namespace std;
const int N = 1005;

int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n;
        cin >> n;
        int arr[N];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        bool flag = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                cout << "NO\n";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "YES\n";
    }
}