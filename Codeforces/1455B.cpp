#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x;
    cin >> x;
    int n = 1;
    while (n * (n + 1) / 2 < x)
    {
        n++;
    }
    int y = n * (n + 1) / 2;
    if (y-x==1)
        cout << n+1 << "\n";
    else
        cout << n<< "\n";
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