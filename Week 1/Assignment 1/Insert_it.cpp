#include <bits/stdc++.h>

using namespace std;
const int N = 1005;

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cin >> m;
    int B[N];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    int x;
    cin >> x;
    A.insert(A.begin() + x, B, B + m);
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
}