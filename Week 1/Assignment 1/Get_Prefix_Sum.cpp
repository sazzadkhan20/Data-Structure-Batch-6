#include <bits/stdc++.h>

using namespace std;
const int N = 100005;

int main()
{
    int n;
    cin >> n;
    int arr[N];
    long long int prefixSum[N];
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        prefixSum[i] = sum;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout << prefixSum[i] << " ";
    }
}