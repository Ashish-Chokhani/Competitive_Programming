#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=70;
const ll MAXNBits=30;

struct lca_lift {
  const ll lg = 24;
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

  ll findNode(ll cur,ll dist){
    
  }
};

bool isInPath(ll u,ll x,ll y,ll lca,lca_lift &lc){
    ll LCA1=lc.get_lca(u,x);
    ll LCA2=lc.get_lca(u,y);
    return LCA1==lca || LCA2==lca;
}

void DFS(ll cur,ll par,ll bit,vector<vector<ll>>&cnt,vector<ll>*adj,vector<ll>&arr,vector<ll>&parent){
    parent[cur]=par;
    for(auto it:adj[cur]){
        if(it==par) continue;
        cnt[cur][bit]=(arr[cur]&(1LL<<bit))!=0;
        if(cur!=0){
            cnt[cur][bit]+=cnt[par][bit];
        }
        DFS(it,cur,bit,cnt,adj,arr,parent);
    }    
}

bool isPossible(ll cur,ll bit,ll x,ll y,lca_lift &lc,ll lca,vector<vector<ll>>&cnt){
    ll v1=cnt[cur][bit];
    ll v2=cnt[x][bit];
    ll v3=cnt[y][bit];
    ll v4=cnt[lca][bit];
    if(lc.get_lca(x,cur)==lca)
    return (v1+v2-(2*v4))>0;
    return v2-v1>0;
}

ll findVertex(ll x,ll y,vector<vector<ll>>&cnt,lca_lift &lc,ll bit){
    ll dist=lc.get_dist(x,y);
    ll lca= lc.get_lca(x,y);
    ll low=1,high=dist,ans=-1;
    while(low<=high){
        ll mid=(low+high)/2;
        ll newNode = lc.findNode(x,dist)
        if(isPossible(newNode,bit,x,y,lc,lca,cnt))
        {
            high=mid-1;
            ans=newNode;
        }
        else{
            low=mid-1;
        }
    }
    return ans;
}

void solve()
{
    ll n;
    cin>>n;
    lca_lift lc;
    lc.init(n+1);
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>adj[n+1];
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        lca.edge(u,v);
    }
    vector<vector<ll>>cnt(n+1,vector<ll>(MAXNBits,0));
    vector<ll>parent(n+1)
    for(ll bit=0;bit<MAXNBits;bit++){
        DFS(0,-1,bit,cnt,adj,arr,parent);
    }
    ll q;
    cin>>q;
    while(q--){
        set<ll>st;
        ll x,y;
        cin>>x>>y;
        --x;
        --y;
        for(ll bit=0;bit<MAXNBits;bit++){
            ll node1=findVertex(x,y,cnt,lc,bit);
            ll node2=findVertex(y,x,cnt,lc,bit);
            st.insert(node1);
            st.insert(node2);
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}