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

void DFS(ll cur,vector<ll>*adj,vector<ll>&vis,stack<ll>&st){
	vis[cur]=1;
	for(auto it:adj[cur]){
		if(vis[it]) continue;
		DFS(it,adj,vis,st);
	}
	st.push(cur);
}

void DFS3(ll cur,vector<ll>*adj,vector<ll>&vis,ll &id,vector<ll>&ans){
	vis[cur]=1;
  ans[cur]=id;
	for(auto it:adj[cur]){
		if(vis[it]) continue;
		DFS3(it,adj,vis,id,ans);
	}
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<ll>adj[n+1],adjT[n+1];
  for(ll i=0;i<m;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
  	adj[u].push_back(v);
  	adjT[v].push_back(u);
  }
  vector<ll>vis(n,0);
  stack<ll>st;
  for(ll i=0;i<n;i++){
  	if(!vis[i]) DFS(i,adj,vis,st);
  }
  vis.clear();
  vis.assign(n,0);
  vector<ll>ans(n);
  ll nhead=0,id=0;
  while(!st.empty()){
  	ll node=st.top();
  	st.pop();
  	if(vis[node]) continue;
    nhead++;
    id++;
  	DFS3(node,adjT,vis,id,ans);
  }
  cout<<nhead<<endl;
  for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
  cout<<endl;
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