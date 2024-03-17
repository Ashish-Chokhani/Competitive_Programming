#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flagR = 0, flagB = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            flagR = 1;
        else if (s[i] == 'B')
            flagB = 1;
        else
        {
            if (flagR ^ flagB == 1)
            {
                cout << "NO\n";
                return;
            }
            flagB = flagR = 0;
        }
    }
    if (flagR ^ flagB == 1)
    {
        cout << "NO\n";
        return;
    }
    else
    cout<<"YES\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}