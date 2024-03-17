#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void DFS(ll u, ll p, vector<ll> &par, vector<ll> *adj, vector<ll> &color, vector<vector<ll>> &cycles,vector<ll> &vis)
{
    vis[u]=1;
    if (color[u] == 2)
        return;

    if (color[u] == 1)
    {
        vector<ll> cyc;
        ll cur = p;
        cyc.push_back(cur);

        while (cur != u)
        {
            cur = par[cur];
            cyc.push_back(cur);
        }
        cycles.push_back(cyc);
        return;
    }

    color[u] = 1;

    par[u] = p;

    for (auto it : adj[u])
    {
        if (it == p)
            continue;

        DFS(it, u, par, adj, color, cycles,vis);
    }

    color[u] = 2;
}

ll isPresent(vector<ll> &arr, map<ll, ll> &mp, vector<ll> *adj)
{
    for (ll i = 0; i < arr.size(); i++)
    {
        ll node = arr[i];
        ll cnt = 0;
        for (auto it : adj[node])
        {
            if (!mp[it])
                cnt++;
        }
        if (cnt >= 2)
            return node;
    }
    return -1;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 1];
    vector<ll> color(n + 1, 0), par(n + 1, 0),vis(n+1);
    for (ll i = 0; i < m; ++i)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<ll>> cycles;
    for(ll i=0;i<n;i++)
    {
    if(!vis[i])
    DFS(i, -1, par, adj, color, cycles,vis);
    }
    vector<pair<ll, ll>> ans;
    for (auto V : cycles)
    {
        map<ll, ll> mp;
        for (auto it : V)
        {
            mp[it] = 1;
        }
        ll node = isPresent(V, mp, adj);
        if (node != -1)
        {
            ll sz = V.size();
            ans.push_back({V[0], V[sz - 1]});
            for (ll i = 0; i < sz - 1; i++)
            {
                ans.push_back({V[i], V[i + 1]});
            }
            ll cnt = 0;
            for (auto it : adj[node])
            {
                if (!mp[it] && cnt < 2)
                {
                    ans.push_back({node, it});
                    cnt++;
                }
            }
            cout << "YES\n";
            cout << ans.size() << "\n";
            for (auto it : ans)
            {
                cout << it.first + 1 << " " << it.second + 1 << "\n";
            }
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ll t;
    cin >> t;
    ll cnt = 0;
    while (t--)
    {
        solve();
    }
    return 0;
}
