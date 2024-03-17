#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
bool isBipartite(ll cur, ll par, vector<ll> *adj, vector<ll> &vis, vector<ll> &c)
{
    for (auto it : adj[cur])
    {
        if (it == par)
            continue;
        if (vis[it]==-1 && c[it] != c[cur])
        {
            vis[it]=vis[cur];
            if (isBipartite(it, cur, adj, vis, c))
            {
                return true;
            }
        }
        else if (vis[it]==vis[cur] && (it != par) && (c[it] == c[cur]))
        {
            return true;
        }
    }
    return false;
}
 
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 1];
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    vector<ll> vis(n, -1);
    for (ll i=0;i<n;i++)
    {
        if (vis[i]==-1)
        {
            vis[i]=i;
            if (isBipartite(i, -1, adj, vis, c))
            {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}