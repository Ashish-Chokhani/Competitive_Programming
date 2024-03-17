#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll value(ll c)
{
    if (c == 0)
        return 1;
    if (c == 1)
        return 10;
    if (c == 2)
        return 100;
    if (c == 3)
        return 1000;
    return 10000;
}

void solve()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll n = s.size();
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(6, vector<ll>(3, 0)));
    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll maxi = 4; maxi >= 0; maxi--)
        {
            for (ll j = 0; j <= 1; j++)
            {
                ll v1 = -1e9, v2 = -1e9;
                if (j)
                {
                    ll val;
                    for (ll k = 0; k < 5; k++)
                    {
                        if (k < maxi)
                            val = -value(k) + dp[i + 1][max(maxi, k)][0];
                        else
                            val = value(k) + dp[i + 1][max(maxi, k)][0];
                        v1 = max(v1, val);
                    }
                }
                if (s[i] - 65 < maxi)
                    v2 = -value(s[i] - 65) + dp[i + 1][maxi][j];
                else
                    v2 = value(s[i] - 65) + dp[i + 1][s[i] - 65][j];
                dp[i][maxi][j]=max(v1, v2);
            }
        }
    }
    cout << dp[0][0][1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
