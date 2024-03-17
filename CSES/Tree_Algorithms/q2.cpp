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
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

const ll maxN=2e5+2;
vector<ll>adj[maxN];
vector<vector<ll>>dp(maxN,vector<ll>(2,0));

void DFS(ll cur,ll par){
	for(auto child:adj[cur]){
		if(child==par) continue;
		DFS(child,cur);
    dp[cur][0]+=max(dp[child][0],dp[child][1]);
	}
  for(auto child:adj[cur]){
    if(child==par) continue;
    dp[cur][1]=max(dp[cur][1],dp[cur][0]-max(dp[child][0],dp[child][1])+1+dp[child][0]);
  }
}

void solve(){
  ll n;
  cin>>n;
  
  for(ll i=0;i<n-1;i++){
  	ll u,v;
  	cin>>u>>v;
  	--v;--u;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  DFS(0,-1);
  cout<<max(dp[0][0],dp[0][1])<<endl;
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