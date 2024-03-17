#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur, ll par, vector<ll> *adj, vector<vector<ll>> &dp, ll k, vector<vector<ll>> &dp2)
{
    dp[cur][0] = 1;
    dp2[cur][0] = 1;
    dp2[cur][1] = par != -1;
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            dp2[cur][1]++;
            DFS(it, cur, adj, dp, k, dp2);
            for (ll i = 1; i <= k; i++)
            {
                dp[cur][i] += dp[it][i - 1];
                if (cur == 0)
                    dp2[cur][i] = dp[cur][i];
            }
        }
    }
}

void DFS2(ll cur, ll par, vector<ll> *adj, vector<vector<ll>> &dp, ll k, vector<vector<ll>> &dp2)
{
    for (ll i = 2; i <= k && cur != 0; i++)
    {
        dp2[cur][i]=dp[cur][i]+dp2[par][i-1]-dp[cur][i-2];
    }
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            DFS2(it, cur, adj, dp, k, dp2);
        }
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> adj[n + 1];
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0)), dp2(n + 1, vector<ll>(k + 1, 0));
    DFS(0, -1, adj, dp, k, dp2);
    DFS2(0, -1, adj, dp, k, dp2);
    ll ans = 0;
    for(ll i=0;i<n;i++)
    {
        ans+=dp2[i][k];
    }
    cout << ans/2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}