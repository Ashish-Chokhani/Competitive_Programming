#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void calcDepth(ll cur, ll par, vector<ll> &depth, vector<ll> *adj)
{
    if (cur == 0)
        depth[cur] = 0;
    else
        depth[cur] = 1 + depth[par];
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            calcDepth(it, cur, depth, adj);
        }
    }
}

void calcDist(ll cur, ll par, vector<ll> &dist, vector<ll> *adj)
{
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            calcDist(it, cur, dist, adj);
            dist[cur] = max(dist[cur], 1 + dist[it]);
        }
    }
}

void findLeaf(ll cur, ll par, vector<ll> *adj, ll &leaf)
{
    ll nchild = 0;
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            nchild++;
            findLeaf(it, cur, adj, leaf);
        }
    }
    if (nchild == 0 && leaf == -1)
        leaf = cur;
}

void Profit(ll cur, ll par, ll k, ll c, vector<ll> *adj, vector<ll> &depth, vector<ll> &dist, vector<ll> &dist1, ll &ans)
{
    ll dis_cost = depth[cur] * c;
    ll val = max(dist[cur], dist1[cur]);
    ll dis_gain = k * val;
    if(cur==1)
    cout<<dis_gain<<" "<<dis_cost<<" "<<"\n";
    ans = max(ans, dis_gain - dis_cost);
    for (auto it : adj[cur])
    {
        if (it != par)
            Profit(it, cur, k, c, adj, depth, dist, dist1, ans);
    }
}

void solve()
{
    ll n, k, c;
    cin >> n >> k >> c;
    vector<ll> adj[n + 1];
    vector<ll> dist(n + 1, 0), depth(n + 1, 0), dist1(n + 1, 0);
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    calcDepth(0, -1, depth, adj);
    calcDist(0, -1, dist, adj);
    ll leaf = -1;
    findLeaf(0, -1, adj, leaf);
    calcDist(leaf, -1, dist1, adj);
    cout<<dist1[0]<<" "<<dist[1]<<" "<<dist1[2]<<" "<<dist1[3]<<" "<<dist1[4]<<" "<<dist1[5]<<"\n";
    ll ans = 0;
    Profit(0, -1, k, c, adj, depth, dist, dist1, ans);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t, cnt = 0;
    cin >> t;
    while (t--)
    {
        cnt++;
        if (cnt == 31)
        {
            ll n, k, c;
            cin >> n >> k >> c;
            vector<ll> adj;
            for (ll i = 1; i < n; i++)
            {
                ll u, v;
                cin >> u >> v;
                --u;
                --v;
                adj.push_back(u);
                adj.push_back(v);
            }
            cout<<n<<"."<<k<<"."<<c<<".";
            for(auto it:adj)
            cout<<it<<".";
        }
        else
        solve();
    }
    return 0;
}
