#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, x;
    cin >> n >> x;
    int bits = 0;
    long long int c = 0,temp=n;
    while (n >= x)
    {
        if (n == x)
        {
            cout << temp << "\n";
            return;
        }
        c = 1LL << bits;
        bits++;
        temp=n+c;
        n = n & (n + c);
    }
    cout<<"-1\n";
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
