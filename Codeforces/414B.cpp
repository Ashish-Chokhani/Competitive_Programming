#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long int findACM(long long int index, long long int prev, long long int k, vector<long long int> *factors, vector<vector<long long int>> &dp)
{
    if (index > k - 1)
        return 1;

    if (dp[index][prev] != -1)
        return dp[index][prev];

    long long int ans = 0;
    for (auto it : factors[prev])
    {
        ans = (ans % MOD + findACM(index + 1, it, k, factors, dp) % MOD) % MOD;
    }
    return dp[index][prev] = ans % MOD;
}

void solve()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> factors[n + 1];
    long long int l = max(n, k);
    vector<vector<long long int>> dp(l + 1, vector<long long int>(l + 1, -1));
    for (long long int i = 1; i <= n; i++)
    {
        for (long long int j = i; j <= n; j += i)
        {
            factors[j].push_back(i);
        }
    }
    long long int ans = 0;
    for (long long int i = 1; i <= n; i++)
    {
        ans = (ans % MOD + findACM(1, i, k, factors, dp) % MOD) % MOD;
    }
    cout << ans << "\n";
}

int main()
{
    solve();
    return 0;
}
