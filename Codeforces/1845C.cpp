#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    ll n = s.length();
    vector<ll> adj[10];
    for (ll i = 0; i < n; i++)
    {
        adj[s[i] - '0'].push_back(i);
    }
    ll m;
    cin >> m;
    vector<vector<ll>> dp(n + 5, vector<ll>(m + 5, 0));
    string L, R;
    cin >> L >> R;
    vector<ll> l(m), r(m);
    for (int i = 0; i < m; i++)
    {
        l[i] = L[i] - '0';
        r[i] = R[i] - '0';
    }
    for(int j=0;j<m;j++){
        dp[n][j]=1;
    }
    for (ll i = n-1; i >= 0; i--)
    {
        for (ll j = m - 1; j >= 0; j--)
        {
            ll flag=0;
            for (ll k = l[j]; k <= r[j]; k++)
            {
                ll ind = lower_bound(adj[k].begin(), adj[k].end(), i) - adj[k].begin();
                ll sz = adj[k].size();
                if (ind == sz){
                    dp[i][j]=1;
                    break;
                }
                if (dp[adj[k][ind] + 1][j + 1]){
                    dp[i][j]=1;
                    break;
                }
            }
        }
    }
    if (dp[0][0])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();
}