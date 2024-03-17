#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> dp(46, 0);

bool isPossible(ll x1, ll y1, ll x2, ll y2, ll x, ll y, ll ind, bool isLeft)
{
    if (ind == 0)
        return true;

    ll val = dp[ind];

    if (isLeft)
    {
        if (y1 + val - 1 >= y && y >= y2 - val + 1)
            return false;
    }
    else 
    {
        if (x1 + val - 1 >= x && x >= x2 - val + 1)
        return false;
    }
    if (isLeft)
    {
        if (y1 + val - 1 < y)
        {
            if (!isPossible(x1, y1 + val, x2, y2, x, y, ind - 1,!isLeft))
                return false;
        }
        else
        {
            if (!isPossible(x1, y1, x2, y2 - val, x, y, ind - 1,!isLeft))
                return false;
        }
    }
    else
    {
        if (x1 + val - 1 < x)
        {
            if (!isPossible(x1+val, y1, x2, y2, x, y, ind - 1,!isLeft))
                return false;
        }
        else
        {
            if (!isPossible(x1, y1, x2 - val, y2, x, y, ind - 1,!isLeft))
                return false;
        }
    }
    return true;
}

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    if (isPossible(1, 1, dp[n], dp[n + 1], x, y, n, true))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[0] = dp[1] = 1;
    for (ll i = 2; i <= 45; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
