#include <bits/stdc++.h>
using namespace std;

typedef int ll;

ll DFS(ll cur, ll par, vector<ll> &vis, vector<ll> *adj,vector<ll> &arr)
{
    vis[cur] = 1;
    ll mini=arr[cur];
    for (auto it : adj[cur])
    {
        if (it != par && !vis[it])
        {
            mini=min(mini,DFS(it, cur, vis, adj,arr));
        }
    }
    return mini;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    set<ll> st[n];
    vector<ll> adj[n];
    vector<ll> vis(n, 0);
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ans+=DFS(i, -1, vis, adj,arr);
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
