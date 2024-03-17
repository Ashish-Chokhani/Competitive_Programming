#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
//              tree_order_statistics_node_update>ordered_set;
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for set use less instead of less_equals
// for erase use: st.erase(st.find_by_order(val);

bool DFS(ll cur,vector<ll>*adj,vector<bool>&isCyclic,vector<ll>&vis){
	if(isCyclic[cur]) return true;
	vis[cur]=1;
	for(auto it:adj[cur]){
		if(vis[it]) continue;
		if(DFS(it,adj,isCyclic,vis)) return true;
	}
	return false;
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<pair<ll,pair<ll,ll>>>edges;
  vector<ll>rev_graph[n+1];
  for(ll i=0;i<m;i++){
  	ll u,v,wt;
  	cin>>u>>v>>wt;
  	--u;--v;
  	edges.push_back({u,{v,-wt}});
  	rev_graph[v].push_back(u);
  }
  vector<ll>dist(n,INF);
  dist[0]=0;
  for(ll i=0;i<n-1;i++){
  	for(auto it:edges){
  		ll u=it.first;
  		ll v=it.second.first;
  		ll wt=it.second.second;
  		if(dist[u]!=INF && dist[u]+wt<dist[v]) dist[v]=dist[u]+wt;
  	}
  }
  vector<bool>isCyclic(n,false);
  for(auto it:edges){
  		ll u=it.first;
  		ll v=it.second.first;
  		ll wt=it.second.second;
  		if(dist[u]!=INF && dist[u]+wt<dist[v]){
  			isCyclic[u]=isCyclic[v]=true;
  		}
  }
  vector<ll>vis(n,0);
  if(DFS(n-1,rev_graph,isCyclic,vis)){
  	cout<<"-1\n";
  	return;
  }
  cout<<-dist[n-1]<<"\n";
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("error.txt","w",stderr);
    //#endif
    
    ll t;
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}