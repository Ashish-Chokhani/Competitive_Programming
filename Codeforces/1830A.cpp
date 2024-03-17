#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur, ll par, vector<ll> *adj, ll &ans, map<pair<ll, ll>, ll> &mp, vector<ll> &parent,vector<ll>&dp)
{
    parent[cur] = par;
    ll val=0;
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            DFS(it, cur, adj, ans, mp, parent,dp);
            if((parent[cur] == -1) || (mp[{parent[cur], cur}] > mp[{cur, it}]))
            dp[it]++;
            val=max(val,dp[it]);
        }
    }
    dp[cur]+=val;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> adj[n + 1];
    vector<ll> parent(n + 1, 0),dp(n+1,0);
    //dp[0]=1;
    map<pair<ll, ll>, ll> mp;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{v, u}]=mp[{u, v}] = i + 1;
    }
    ll ans = 0;
    DFS(0, -1, adj, ans, mp, parent,dp);
    cout <<dp[0]<< "\n";
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
