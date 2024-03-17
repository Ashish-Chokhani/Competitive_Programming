#include <bits/stdc++.h>
using namespace std;

vector<pair<long long int, long long int>> findFactors(long long int n)
{
    vector<pair<long long int, long long int>> V;
    for (long long int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            V.push_back({i, n / i});
            V.push_back({n / i, i});
        }
    }
    return V;
}

void solve()
{
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<pair<long long int, long long int>> afactors, bfactors;
    afactors = findFactors(a);
    bfactors = findFactors(b);
    for (auto adiv : afactors)
    {
        for (auto bdiv : bfactors)
        {
            long long int a1 = adiv.first, a2 = adiv.second;
            long long int b1 = bdiv.first, b2 = bdiv.second;
            long long int x = a1 * b1, y = a2 * b2;
            long long int k1 = a / x + 1, k2 = b / y + 1;
            if (k1 * x <= c && k2 * y <= d)
            {
                cout << k1 * x << " " << k2 * y << "\n";
                return;
            }
        }
    }
    cout << "-1 -1\n";
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