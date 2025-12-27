#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int forward = 0, backward = n - 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= forward; j++)
        {
            if (j == forward && i <= n / 2)
            {
                if (i == n / 2)
                    break;
                cout << "\\";
                break;
            }
            if (j == forward && i > n / 2)
            {
                cout << "/";
                break;
            }
            cout << " ";
        }
        for (int j = 0; j <= backward; j++ && i != n / 2)
        {
            if (j == backward && i <= n / 2)
            {
                cout << "/\n";
                break;
            }
            if (j == backward && i > n / 2)
            {
                cout << "\\\n";
                break;
            }
            cout << " ";
        }
        if (i == n / 2)
        {
            cout << "X\n";
        }
        if (i < n / 2)
        {
            forward++;
            backward -= 2;
            continue;
        }
        forward--;
        backward += 2;
    }
}