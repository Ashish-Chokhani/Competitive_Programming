#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    long long int l = 3;
    long long int r = sqrt(2 * n - 1);
    if (l > r)
        cout << "0\n";
    else
        cout << ((r - l) / 2) + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
