#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll DFS(ll cur, ll par, vector<ll> *adj, vector<ll> &vis)
{
    vis[cur] = 1;
    ll cnt = 0;
    for (auto it : adj[cur])
    {
        if (!vis[it])
        {
            cnt += 1 + DFS(it, cur, adj, vis);
        }
    }
    return cnt;
}

void Cut(ll cur, ll par, vector<ll> *adj, vector<ll> &vis, vector<ll> &degree)
{
    vis[cur] = 1;
    for (auto it : adj[cur])
    {
        if (degree[it] == 4 && degree[cur] == 4)
        {
            auto it1 = find(adj[it].begin(), adj[it].end(),cur);
            if(it1!=adj[it].end())
            adj[it].erase(it1);
            auto it2 = find(adj[cur].begin(), adj[cur].end(),it);
            if(it2!=adj[cur].end())
            adj[cur].erase(it2);
        }
        if (!vis[it])
        {
            Cut(it, cur, adj, vis, degree);
        }
    }
}

void solve()
{
    ll n, m;
        cin >> n >> m;
        vector<ll> adj[n + 1];
        vector<ll> vis(n + 1, 0), degree(n + 1, 0);
        for (ll i = 0; i < m; ++i)
        {
            ll u, v;
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        ll k = sqrt(n);
        if ((k * k) != n || m != (n + k))
        {
            cout << "NO\n";
            return;
        }
        for (ll i = 0; i < n; i++)
        {
            if (adj[i].size() != 4 && adj[i].size() != 2)
            {
                cout << "NO\n";
                return;
            }
        }
        if (DFS(0, -1, adj, vis) != n - 1)
        {
            cout << "NO\n";
            return;
        }
        for (ll i = 0; i <= n; i++)
        {
            vis[i] = 0;
        }
        Cut(0, -1, adj, vis, degree);
        for (ll i = 0; i <= n; i++)
        {
            vis[i] = 0;
        }
        for (ll i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (DFS(i, -1, adj, vis) != k-1)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
        cout << "YES\n";
        return;
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
