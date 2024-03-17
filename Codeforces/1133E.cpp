#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = 1; j <= k; j++)
        {
            ll pick = 0, not_pick = 0;
            ll ind = lower_bound(arr.begin(), arr.end(), arr[i] + 6) - arr.begin();
            pick = (ind - i) + dp[ind][j - 1];
            not_pick = dp[i + 1][j];
            dp[i][j] = max(pick, not_pick);
        }
    }
    cout << dp[0][k] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
