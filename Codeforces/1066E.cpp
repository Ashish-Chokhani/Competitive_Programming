#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

void solve()
{
    long long int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    long long int curp = 1, ans = 0, count = 0,j=m-1;
    vector<long long int> dp(m + 1, 0);
    for (int i = 0; i < m; i++)
    {
        if (b[i] == '1')
        {
            count++;
        }
        dp[i] = count;
    }
    for (long long int i = n-1; (i >=0) && (j>=0); i--)
    {
        if (a[i] - '0' == 1)
        {
            ans += (((curp % MOD) * dp[j]) % MOD) % MOD;
            ans = ans % MOD;
        }
        curp = (curp << 1) % MOD;
        j--;
    }
    cout << ans % MOD << "\n";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
