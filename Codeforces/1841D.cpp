#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool doesIntersect(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second >= b.first;
}

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    arr.push_back({-1,-1});
    sort(arr.begin(), arr.end());
    vector<vector<vector<ll>>> dp(n + 2, vector<vector<ll>>(n + 2, vector<ll>(2, -1)));
    for (ll lastPick = 0; lastPick <= n; lastPick++)
    {
        dp[n+1][lastPick][1] = 1e9 + 2;
    }
    for (ll ind = n; ind >= 1; ind--)
    {
        for (ll lastPick = n; lastPick>=0 ; lastPick--)
        {
            for (ll isIntersecting = 1; isIntersecting >= 0; isIntersecting--)
            {
                ll pick = 1e9, not_pick = 1e9;
                if (isIntersecting)
                {
                    if (doesIntersect(arr[lastPick],arr[ind]))
                        pick = dp[ind + 1][arr[lastPick].second>arr[ind].second?lastPick:ind][!isIntersecting];
                    not_pick = 1 + dp[ind + 1][lastPick][isIntersecting];
                }
                else
                {
                    if (!doesIntersect(arr[lastPick],arr[ind]))
                        pick = dp[ind + 1][ind][!isIntersecting];
                    not_pick = 1 + dp[ind + 1][lastPick][isIntersecting];
                }
                dp[ind][lastPick][isIntersecting]=min(pick, not_pick);
            }
        }
    }
    cout << dp[1][0][0]+1<< "\n";
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
