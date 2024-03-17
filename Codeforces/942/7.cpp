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

void DFS(ll cur,ll par,vector<ll>*adj,string &s,vector<vector<ll>>&dp){
	dp[cur][0]=dp[cur][1]=0;
	for(auto it:adj[cur]){
		if(it==par) continue;
		DFS(it,cur,adj,s,dp);
		dp[cur][0]+=min(dp[it][0],1+dp[it][1]);
		dp[cur][1]+=min(dp[it][1],1+dp[it][0]);
	}
	if(s[cur]=='P') dp[cur][1]=1e9;
	if(s[cur]=='S') dp[cur][0]=1e9;
}

void solve(){
  ll n;
  cin>>n;
  vector<ll>adj[n];
  for(ll i=1;i<n;i++){
  	ll u;
  	cin>>u;
  	--u;
  	adj[u].push_back(i);
  	adj[i].push_back(u);
  }
  string s;
  cin>>s;
  vector<vector<ll>>dp(n+1,vector<ll>(2,0));
  DFS(0,-1,adj,s,dp);
  cout<<min(dp[0][0],dp[0][1])<<endl;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}