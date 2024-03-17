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

void DFS(ll cur,vector<ll>&vis,set<ll>*adj){
	vis[cur]=1;
	for(auto it:adj[cur]){
		if(vis[it]) continue;
		DFS(it,vis,adj);
	}
}

void solve(){
  ll n,m;
  cin>>n>>m;
  set<ll>adj[n+1];
  vector<ll>outdegree(n,0),indegree(n,0);
  for(ll i=0;i<m;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
  	adj[u].insert(v);
  	outdegree[u]++;
  	indegree[v]++;
  }
  if(outdegree[0]-indegree[0]!=1 || indegree[n-1]-outdegree[n-1]!=1){
  	cout<<"IMPOSSIBLE\n";
  	return;
  }
  for(ll i=1;i<n-1;i++){
  	if(outdegree[i]!=indegree[i]){
  		cout<<"IMPOSSIBLE\n";
  		return;
  	}
  }
  vector<ll>vis(n,0);
  DFS(0,vis,adj);
  for(ll i=0;i<n;i++){
  	if(!vis[i] && (indegree[i]!=0 || outdegree[i]!=0)){
  		cout<<"IMPOSSIBLE\n";
  		return;
  	}
  }
  stack<ll>st;
  vector<ll>order;
  st.push(0);
  while(!st.empty()){
  	ll node=st.top();
  	if(outdegree[node]==0){
  		order.push_back(node);
  		vis[node]=1;
  		st.pop();
  	}
  	else{
  		auto it_to=adj[node].begin();
  		ll to=*it_to;
  		adj[node].erase(it_to);
  		outdegree[node]--;
  		st.push(to);
  	}
  }
  reverse(order.begin(),order.end());
  for(ll node:order) cout<<node+1<<" ";
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