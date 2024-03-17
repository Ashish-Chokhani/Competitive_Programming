#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, m;
    cin >> n >> m;
    long long ans = 0, neg;
    long long pos = (long long)(n * (n - 1)) / 2;
    if (n % 2 == 0)
        neg = (long long)(n * n) / 4;
    else
        neg = (long long)((n - 1) * (n + 1)) / 4;
    for (long long i = 1; i <= m; i++)
    {
        long long x, d;
        cin >> x >> d;
        ans += (n * x);
        if (d >= 0)
        {
            ans += pos * d;
        }
        else
        {
            ans += neg * d;
        }
    }
    cout << setprecision(16) << (double)ans / n << "\n";
}

int main()
{
    solve();
    return 0;
}
