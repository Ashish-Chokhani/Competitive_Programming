#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur, ll par, vector<ll> &parent, vector<ll> *adj)
{
    parent[cur] = par;
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            DFS(it, cur, parent, adj);
        }
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll x, y;
    cin >> x >> y;
    --x;
    --y;
    vector<ll> arr(k);
    map<ll, ll> mp;
    vector<ll> adj[n + 1];
    for (ll i = 0; i < k; i++)
    {
        cin >> arr[i];
        --arr[i];
        mp[arr[i]]++;
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> parent(n + 1, -1);
    DFS(x, -1, parent, adj);
    ll ans = 0;
    ll cur = y;
    map<ll, ll> alreadyVisited;
    alreadyVisited[y] = 1;
    while (cur != x)
    {
        ans++;
        cur = parent[cur];
        alreadyVisited[cur] = 1;
    }
    for (auto it : arr)
    {
        ll flag = 0, dist = 0, cur = it;
        while (!alreadyVisited[cur])
        {
            alreadyVisited[cur] = 1;
            if (mp[cur])
                flag = 1;
            if (flag)
                dist++;
            cur = parent[cur];
        }
        ans += 2 * dist;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    ll cnt = 0;
    while (t--)
    {
        solve();
    }
}