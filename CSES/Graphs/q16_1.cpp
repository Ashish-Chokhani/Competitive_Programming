 #include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e8;
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

void DFS(ll cur,vector<ll>*adj,vector<ll>&vis,vector<ll>&dp,vector<ll>&next){
	vis[cur]=1;
	for(ll child:adj[cur]){
		if(!vis[child]) DFS(child,adj,vis,dp,next);
		if(dp[child]!=0 && dp[cur]<1+dp[child]){
			next[cur]=child;
			dp[cur]=1+dp[child];
		}
	}
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
  vector<ll>dp(n,0),vis(n,0),next(n,-1);
  dp[n-1]=1;
  DFS(0,adj,vis,dp,next);
  if(!vis[n-1]){
  	cout<<"IMPOSSIBLE\n";
  	return;
  }
  vector<ll>ans;
  ll cur=0;
  while(cur!=n-1){
  	if(cur!=-1) ans.push_back(cur);
  	cur=next[cur];
  }
  ans.push_back(n-1);
  cout<<ans.size()<<endl;
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