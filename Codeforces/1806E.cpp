#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>arr(100002);
map<pair<ll,ll>,ll>mp;
map<pair<ll,ll>,ll>vis;
vector<ll> parent(100002);
vector<ll>to_lca(100002,0);

struct lca_lift {
  const ll lg = 18;
  ll n;
  vector<ll> depth;
  vector<vector<ll> > edges;
  vector<vector<ll> > lift;

  void init(ll sz) {
    n = sz;
    depth = vector<ll>(n);
    edges = vector<vector<ll> >(n, vector<ll>());
    lift = vector<vector<ll> >(n, vector<ll>(lg, -1));
  }

  void edge(ll a, ll b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  void attach(ll node_to_attach, ll node_to_attach_to) {
    ll a = node_to_attach, b = node_to_attach_to;
    edge(a, b);

    lift[a][0] = b;

    for (ll i = 1; i < lg; i++) {
      if (lift[a][i - 1] == -1) lift[a][i] = -1;
      else lift[a][i] = lift[lift[a][i - 1]][i - 1];
    }

    depth[a] = depth[b] + 1;
  }

  void init_lift(ll v = 0) {
    depth[v] = 0;
    dfs(v, -1);
  }

  void dfs(ll v, ll par) {
    lift[v][0] = par;
    parent[v]=par;
    if(par!=-1)
    to_lca[v]=(arr[v]*arr[v])+to_lca[par];
    else
    to_lca[v]=(arr[v]*arr[v]);
    for (ll i = 1; i < lg; i++) {
      if (lift[v][i - 1] == -1) lift[v][i] = -1;
      else lift[v][i] = lift[lift[v][i - 1]][i - 1];
    }

    for (ll x: edges[v]) {
      if (x != par) {
        depth[x] = depth[v] + 1;
        dfs(x, v);
      }
    }
  }

  ll get(ll v, ll k) {
    for (ll i = lg - 1; i >= 0; i--) {
      if (v == -1) return v;
      if ((1 << i) <= k) {
        v = lift[v][i];
        k -= (1 << i);
      }
    }
    return v;
  }

  ll get_lca(ll a, ll b) {
    if (depth[a] < depth[b]) swap(a, b);
    ll d = depth[a] - depth[b];
    ll v = get(a, d);
    if (v == b) {
      return v;
    } else {
      for (ll i = lg - 1; i >= 0; i--) {
        if (lift[v][i] != lift[b][i]) {
          v = lift[v][i];
          b = lift[b][i];
        }
      }
      return lift[b][0];
    }
  }
  
  ll get_dist(ll a, ll b) {
      ll v = get_lca(a, b);
      return depth[a] + depth[b] - 2 * depth[v];
  }
};

ll fun(ll u,ll v)
{
    if(u==v)
    return 0;

    if(vis[{u,v}])
    return mp[{u,v}];

    vis[{u,v}]=1;
    vis[{v,u}]=1;

    mp[{u,v}]=(arr[u]*arr[v])+fun(parent[u],parent[v]);
    mp[{v,u}]=mp[{u,v}];

    return mp[{u,v}];

}

void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>adj[n+1];
    lca_lift lca;
    lca.init(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(ll i=1;i<n;i++)
    {
        ll par;
        cin>>par;
        --par;
        adj[par].push_back(i);
        lca.edge(par,i);
    }
    lca.dfs(0,-1);

    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        --x;
        --y;
        ll LCA=lca.get_lca(x,y);
        ll ans=to_lca[LCA];
        for(ll i=0;i<2000;i++)
        {
            if(x==y)
            break;
            ans+=arr[x]*arr[y];
            x=parent[x];
            y=parent[y];
        }
        ans+=fun(x,y);
        cout<<ans<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
