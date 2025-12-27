#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    getchar();
    while (testCase--)
    {
        string x;
        getline(cin, x);
        map<string, int> mp;
        string s;
        int mx = 0;
        stringstream ss(x);
        string word;
        while (ss >> word)
        {
            mp[word]++;
            if (mp[word] > mx)
            {
                s = word;
                mx = mp[word];
            }
        }
        cout << s << " " << mp[s] << endl;
    }
}