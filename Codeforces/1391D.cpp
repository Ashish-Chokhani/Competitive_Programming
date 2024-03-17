#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<ll>> dp(1e6 + 2, vector<ll>(8, 0));

ll differs(ll mask, ll col, vector<string> &arr, ll n)
{
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        ll bit = (mask >> i) & 1;
        cnt += bit != (arr[n - 1 - i][col] - '0');
    }
    return cnt;
}

bool isCorrect(ll cur_mask, ll mask, ll n)
{
    ll cnt_ones = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        cnt_ones += (mask >> i) & 1 == 1;
        cnt_ones += (mask >> i + 1) & 1 == 1;
        cnt_ones += (cur_mask >> i) & 1 == 1;
        cnt_ones += (cur_mask >> i + 1) & 1 == 1;
        if (cnt_ones % 2 == 0)
            return false;
        cnt_ones = 0;
    }
    return true;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr[i] = s;
    }
    if (n >= 4)
    {
        cout << "-1\n";
        return;
    }
    if (n == 1 || m == 1)
    {
        cout << "0\n";
        return;
    }
    ll ans = 1e6;
    for (ll col = 1; col <= m; col++)
    {
        for (ll mask = 0; mask < (1 << n); mask++)
        {
            ll val, ans = 1e6;
            for (ll cur_mask = 0; cur_mask < (1 << n); cur_mask++)
            {
                if (isCorrect(mask, cur_mask, n))
                {
                    val = differs(cur_mask, col-1, arr, n) + dp[col - 1][cur_mask];
                    ans = min(ans, val);
                }
            }
            dp[col][mask] = ans;
        }
    }
    for (ll cur_mask = 0; cur_mask < (1 << n); cur_mask++)
    {
        ans = min(ans, differs(cur_mask, m - 1, arr, n) + dp[m - 1][cur_mask]);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
