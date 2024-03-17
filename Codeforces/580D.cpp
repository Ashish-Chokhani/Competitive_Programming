#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> a(19);
ll n, m, k;
map<pair<ll, ll>, ll> mp;
ll dp[(1 << 18)][19];

void solve()
{
    cin >> n >> m >> k;
    ll mask = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < k; i++)
    {
        ll x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        mp[{x, y}] = c;
    }
    for (ll i = 0; i < (1 << n); i++)
    {
        for (ll j = 0; j < n; j++)
        {
            dp[i][j] = -1e17;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        dp[1 << i][i] = a[i];
    }

    for (ll i = 1; i < (1 << n); i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                for (ll k = 0; k < n; k++)
                {
                    if (!((i >> k) & 1))
                    {
                        ll new_mask = i | (1 << k);

                        ll val = dp[i][j] + a[k] + mp[{j,k}];

                        dp[new_mask][k] = max(dp[new_mask][k], val);
                    }
                }
            }
        }
    }
    ll ans = 0;
	for (ll i = 0; i < (1 << n); i++) {
		if (__builtin_popcount(i) == m) {
			for (ll j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					ans = max(ans, dp[i][j]);
				}
			}
		}
	}
	cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
