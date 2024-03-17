#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct lca_lift
{
    const ll lg = 18;
    ll n;
    vector<ll> depth;
    vector<vector<ll>> edges;
    vector<vector<ll>> lift;

    void init(ll sz)
    {
        n = sz;
        depth = vector<ll>(n);
        edges = vector<vector<ll>>(n, vector<ll>());
        lift = vector<vector<ll>>(n, vector<ll>(lg, -1));
    }

    void edge(ll a, ll b)
    {
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    void attach(ll node_to_attach, ll node_to_attach_to)
    {
        ll a = node_to_attach, b = node_to_attach_to;
        edge(a, b);

        lift[a][0] = b;

        for (ll i = 1; i < lg; i++)
        {
            if (lift[a][i - 1] == -1)
                lift[a][i] = -1;
            else
                lift[a][i] = lift[lift[a][i - 1]][i - 1];
        }

        depth[a] = depth[b] + 1;
    }

    void init_lift(ll v = 0)
    {
        depth[v] = 0;
        dfs(v, -1);
    }

    void dfs(ll v, ll par)
    {
        lift[v][0] = par;

        for (ll i = 1; i < lg; i++)
        {
            if (lift[v][i - 1] == -1)
                lift[v][i] = -1;
            else
                lift[v][i] = lift[lift[v][i - 1]][i - 1];
        }

        for (ll x : edges[v])
        {
            if (x != par)
            {
                depth[x] = depth[v] + 1;
                dfs(x, v);
            }
        }
    }

    ll get(ll v, ll k)
    {
        for (ll i = lg - 1; i >= 0; i--)
        {
            if (v == -1)
                return v;
            if ((1 << i) <= k)
            {
                v = lift[v][i];
                k -= (1 << i);
            }
        }
        return v;
    }

    ll get_lca(ll a, ll b)
    {
        if (depth[a] < depth[b])
            swap(a, b);
        ll d = depth[a] - depth[b];
        ll v = get(a, d);
        if (v == b)
        {
            return v;
        }
        else
        {
            for (ll i = lg - 1; i >= 0; i--)
            {
                if (lift[v][i] != lift[b][i])
                {
                    v = lift[v][i];
                    b = lift[b][i];
                }
            }
            return lift[b][0];
        }
    }

    ll get_dist(ll a, ll b)
    {
        ll v = get_lca(a, b);
        return depth[a] + depth[b] - 2 * depth[v];
    }
};

void calcDepth(ll cur, ll par, vector<ll> &depth, vector<ll> *adj)
{
    if (par == -1)
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

void solve()
{
    ll n, k, c;
    cin >> n >> k >> c;
    lca_lift lca;
    lca.init(n);
    vector<ll> adj[n + 1];
    vector<ll> dist(n + 1, 0), depth(n + 1, 0);
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        lca.edge(u, v);
    }
    lca.dfs(0, -1);
    calcDepth(0, -1, depth, adj);
    ll node = -1, cur_depth = 0;
    for (ll i = 0; i < n; i++)
    {
        if (depth[i] > cur_depth)
        {
            cur_depth = depth[i];
            node = i;
        }
    }
    ll ans = 0;
    for (ll cur = 0; cur < n; cur++)
    {
        ll dis_cost = depth[cur] * c;
        ll LCA = lca.get_lca(node, cur);
        ll dis_gain = k*(depth[cur] + depth[node] - 2 * depth[LCA]);
        ans = max(ans, dis_gain - dis_cost);
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
    while (t--)
    {
        solve();
    }
    return 0;
}