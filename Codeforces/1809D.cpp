#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    ll v1 = 1e12 + 1, v2 = 1e12;
    ll n = s.size();
    vector<ll> dp(n, 0);
    dp[0] = (s[0] - '0') == 1;
    for (ll i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + ((s[i] - '0') == 1);
    }
    ll tot = dp[n - 1];
    ll ans = min(tot, n - tot) * v1;
    for (ll i = 0; i < n - 1; i++)
    {
        if (((s[i] - '0') == 1) && ((s[i + 1] - '0') == 0))
        {
            ll left_ones = dp[i]-1;
            ll left_zeros = n-dp[n-1]-i - 2 + dp[i];
            ll right_ones = tot - dp[i]+1;
            ans = min(ans, ((left_ones + right_ones) * v1)+v2);
            right_ones--;
            ans = min(ans, ((left_ones + left_zeros) * v1)+v2);
        }
        ll left_ones = dp[i];
        ll left_zeros = n-dp[n-1] -i - 1 + dp[i];
        ll right_ones = tot - dp[i];
        ans = min(ans, (left_ones + right_ones) * v1);
        ans = min(ans, (left_ones + left_zeros) * v1);
    }
    cout << ans << "\n";
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
}