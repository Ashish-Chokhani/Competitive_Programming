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
        // edges[b].push_back(a);
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

    pair<ll, ll> get_diameter(vector<ll>&arr)
    {
        ll m=arr.size();
        ll first = -1, second = -1;
        ll dist = 0;
        for (ll i = 1; i < m; i++)
        {
            if (get_dist(arr[0], arr[i]) >= dist)
            {
                if (get_dist(arr[0], arr[i]) == dist)
                    first = min(arr[i], first);
                else
                    first = arr[i];
                dist = get_dist(arr[0], arr[i]);
            }
        }
        dist = 0;
        for (ll i = 0; i < m; i++)
        {
            if (arr[i] != first && get_dist(first, arr[i]) >= dist)
            {
                if (get_dist(first, arr[i]) == dist)
                    second = min(arr[i], second);
                else
                    second = arr[i];
                dist = get_dist(first, arr[i]);
            }
        }
        return {first,second};
    }
};

void Cut(ll u, ll v, vector<ll> *adj)
{
    auto it = lower_bound(adj[u].begin(), adj[u].end(), v);
    adj[u].erase(it);
}

void DFS(ll cur, ll par, vector<ll> *adj, vector<ll> &dp, map<ll, ll> &mp, vector<ll> *temp)
{
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            DFS(it, cur, adj, dp, mp, temp);
            dp[cur] = dp[cur] | dp[it];
            if (!dp[it])
            {
                Cut(it, cur, temp);
                Cut(cur, it, temp);
            }
        }
    }
    dp[cur] = dp[cur] | mp[cur];
}

void edges(ll cur, ll par, vector<ll> *adj, ll &nedges)
{
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            nedges++;
            edges(it, cur, adj, nedges);
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n], temp[n];
    vector<ll> dp(n, 0);
    map<ll, ll> mp;
    lca_lift lca;
    lca.init(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        temp[u].push_back(v);
        temp[v].push_back(u);
    }
    vector<ll> cities(m, 0);
    for (ll i = 0; i < m; i++)
    {
        cin >> cities[i];
        --cities[i];
        mp[cities[i]] = 1;
    }
    if (m == 1)
    {
        cout << cities[0] + 1 << "\n"
             << "0\n";
        return;
    }
    for (ll i = 0; i < n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
        sort(temp[i].begin(), temp[i].end());
    }
    DFS(cities[0], -1, adj, dp, mp, temp);
    ll nedges = 0;
    edges(cities[0], -1, temp, nedges);
    for (ll i = 0; i < n; i++)
    {
        for (auto it : temp[i])
        {
            lca.edge(i, it);
        }
    }
    lca.dfs(cities[0], -1);
    ll first=lca.get_diameter(cities).first;
    ll second=lca.get_diameter(cities).second;
    ll node = min(first, second);
    cout << node + 1 << "\n";
    ll L = lca.get_dist(first, second);
    // Root node has to be more than once
    if (temp[node].size() > 1)
        cout << 2 * nedges << "\n";
    else
        cout << (2 * nedges) - L << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
