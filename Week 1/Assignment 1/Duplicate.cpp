#include <bits/stdc++.h>

using namespace std;
const int N = 100005;

int main()
{
    int n;
    cin >> n;
    int arr[N];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}