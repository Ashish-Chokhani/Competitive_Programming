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

void DFS(ll cur,ll par,vector<ll>&parent,vector<ll>&vis,vector<ll>*adj,vector<ll>&ans){
	vis[cur]=1;
	parent[cur]=par;
	for(auto it:adj[cur]){
		if(!vis[it]){
			DFS(it,cur,parent,vis,adj,ans);
			continue;
		}
		if(vis[it]==2) continue;
		if(ans.size()>0) continue;
		ll node=cur;
		while(node!=it){
			ans.push_back(node);
			node=parent[node];
		}
		ans.push_back(it);
	}
	vis[cur]=2;
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<ll>adj[n+1];
  for(ll i=0;i<m;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
  	adj[u].push_back(v);
  }
  vector<ll>vis(n,0),parent(n,-1),ans;
  for(ll i=0;i<n;i++){
  	if(!vis[i]) DFS(i,-1,parent,vis,adj,ans);
  }
  if(ans.size()==0){
  	cout<<"IMPOSSIBLE\n";
  	return;
  }
  reverse(ans.begin(),ans.end());
  ans.push_back(ans.front());
  cout<<ans.size()<<"\n";
  for(auto it:ans){
  	cout<<it+1<<" ";
  }
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