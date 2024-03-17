#include <bits/stdc++.h>
using namespace std;

int countfactors(long long int n,long long int k)
{
    long long int maxi = 1;
    for (long long int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i <= k)
                maxi = max(maxi, i);
            if ((n / i) <= k)
                maxi = max(maxi, n / i);
        }
    }
    return maxi;
}

void solve()
{
    long long int n, k;
    cin >> n >> k;
    long long int j = n;
    cout << n / countfactors(n, k) << "\n";
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