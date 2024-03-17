#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll c, ll p, vector<ll> *adj, vector<ll> &vis)
{
    vis[c] = 1;
    for (auto it : adj[c])
    {
        if (!vis[it])
            DFS(it, c, adj, vis);
    }
}

bool isCyclic(ll c, ll p, vector<ll> *adj, vector<ll> &vis)
{
    vis[c] = 1;
    for (auto it : adj[c])
    {
        if (!vis[it])
        {
            if(isCyclic(it, c, adj, vis))
            return true;
        }
        else if(it!=p)
        return true;
    }
    return false;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> adj[n + 1];
    map<pair<ll, ll>, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll v;
        cin >> v;
        --v;
        if (!mp[{i, v}])
        {
            mp[{i, v}] = 1;
            mp[{v, i}] = 1;
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
    }
    vector<ll> vis(n, 0), vis1(n, 0);
    ll mini = 0, maxi = 0;
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            maxi++;
            DFS(i, -1, adj, vis);
        }
    }
    ll cyclic = 0;
    bool non_cyclic = false;
    for (ll i = 0; i < n; i++)
    {
        if (!vis1[i])
        {
            if (isCyclic(i, -1, adj, vis1))
                cyclic++;
            else
                non_cyclic = true;
        }
    }
    mini = cyclic + (non_cyclic == true);
    cout << mini << " " << maxi << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}