#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll s = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2,0)));
    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = 1; j <=n; j++)
        {
            if((i>j-1))
            continue;

            for (ll isTurn = 0; isTurn <= 1; isTurn++)
            {
                if (isTurn)
                    dp[i][j][isTurn] = max(arr[i] + dp[i + 1][j][!isTurn],arr[j-1] + dp[i][j - 1][!isTurn]);

                else
                    dp[i][j][isTurn] = min(dp[i + 1][j][!isTurn],dp[i][j - 1][!isTurn]);
            }
        }
    }
    ll val = dp[0][n][1];
    cout << 2 * val - s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}